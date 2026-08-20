#!/usr/bin/env python3
"""Register a Pokemon overworld sprite as a selectable Porymap object graphic."""

from __future__ import annotations

import argparse
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
POKEMON_GRAPHICS_DIR = ROOT / "graphics" / "pokemon"
EVENT_OBJECT_CONSTANTS = ROOT / "include" / "constants" / "event_objects.h"
GRAPHICS_DATA = ROOT / "src" / "data" / "object_events" / "object_event_graphics.h"
GRAPHICS_INFO = ROOT / "src" / "data" / "object_events" / "object_event_graphics_info.h"
GRAPHICS_POINTERS = ROOT / "src" / "data" / "object_events" / "object_event_graphics_info_pointers.h"
PIC_TABLES = ROOT / "src" / "data" / "object_events" / "object_event_pic_tables.h"
PALETTE_TABLE = ROOT / "src" / "event_object_movement.c"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Register a Pokemon overworld sprite for use in Porymap."
    )
    parser.add_argument(
        "map_json",
        type=Path,
        nargs="?",
        help="Target map.json; used to validate the destination map and show its name.",
    )
    parser.add_argument(
        "--gui",
        action="store_true",
        help="Open the graphical interface.",
    )
    return parser.parse_args()


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def write_text(path: Path, text: str) -> None:
    path.write_text(text, encoding="utf-8")


def choose_pokemon() -> Path:
    choices = available_pokemon()
    if not choices:
        raise RuntimeError(f"No Pokemon overworld folders found in {POKEMON_GRAPHICS_DIR}")

    print("Available Pokemon overworld sprites:")
    for index, path in enumerate(choices, start=1):
        print(f"{index:3}: {path.name}")

    while True:
        selection = input("Select a number or enter a folder name: ").strip().lower()
        if selection.isdigit() and 1 <= int(selection) <= len(choices):
            return choices[int(selection) - 1]
        matches = [path for path in choices if path.name.lower() == selection]
        if len(matches) == 1:
            return matches[0]
        print("Invalid selection.")


def available_pokemon() -> list[Path]:
    return sorted(
        path
        for path in POKEMON_GRAPHICS_DIR.iterdir()
        if path.is_dir() and (path / "overworld.png").exists()
    )


def available_maps() -> list[Path]:
    return sorted((ROOT / "data" / "maps").glob("**/map.json"))


def validate_source(pokemon_dir: Path) -> tuple[Path, Path, Path | None]:
    overworld_png = pokemon_dir / "overworld.png"
    normal_palette = pokemon_dir / "overworld_normal.pal"
    shiny_palette = pokemon_dir / "overworld_shiny.pal"
    width, height = read_png_size(overworld_png)
    if (width, height) != (192, 32):
        raise ValueError(
            f"{overworld_png} is {width}x{height}; expected 192x32 "
            "(six 32x32 frames)."
        )
    if not normal_palette.exists():
        raise FileNotFoundError(f"Missing palette: {normal_palette}")
    return overworld_png, normal_palette, shiny_palette if shiny_palette.exists() else None


def read_png_size(path: Path) -> tuple[int, int]:
    with path.open("rb") as handle:
        if handle.read(8) != b"\x89PNG\r\n\x1a\n":
            raise ValueError(f"Not a PNG file: {path}")
        length = struct.unpack(">I", handle.read(4))[0]
        if handle.read(4) != b"IHDR" or length < 8:
            raise ValueError(f"Invalid PNG header: {path}")
        width, height = struct.unpack(">II", handle.read(8))
        return width, height


def convert_assets(pokemon_dir: Path, overworld_png: Path, normal_palette: Path, shiny_palette: Path | None) -> None:
    gbagfx = ROOT / "tools" / "gbagfx" / "gbagfx"
    if not gbagfx.exists():
        gbagfx = ROOT / "tools" / "gbagfx"
    if not gbagfx.exists() and shutil.which("gbagfx"):
        gbagfx = Path(shutil.which("gbagfx") or "gbagfx")
    if not gbagfx.exists():
        raise FileNotFoundError("Could not find the gbagfx executable.")

    commands = [
        [str(gbagfx), str(overworld_png), str(pokemon_dir / "overworld.4bpp")],
        [str(gbagfx), str(normal_palette), str(pokemon_dir / "overworld_normal.gbapal")],
    ]
    if shiny_palette is not None:
        commands.append(
            [str(gbagfx), str(shiny_palette), str(pokemon_dir / "overworld_shiny.gbapal")]
        )
    for command in commands:
        subprocess.run(command, cwd=ROOT, check=True)


def snake_to_pascal(name: str) -> str:
    return "".join(part.capitalize() for part in name.split("_"))


def species_names(pokemon_dir: Path) -> tuple[str, str, str]:
    folder_name = pokemon_dir.name.lower()
    constant_name = re.sub(r"[^a-z0-9]+", "_", folder_name).strip("_").upper()
    pascal_name = snake_to_pascal(constant_name.lower())
    return constant_name, f"OBJ_EVENT_GFX_{constant_name}", pascal_name


def next_graphics_id(text: str) -> tuple[int, int]:
    definitions = [
        int(value)
        for value in re.findall(r"#define\s+OBJ_EVENT_GFX_[A-Z0-9_]+\s+(\d+)", text)
    ]
    current_count = int(re.search(r"#define\s+NUM_OBJ_EVENT_GFX\s+(\d+)", text).group(1))
    return max(definitions) + 1, current_count


def next_palette_tag(text: str) -> int:
    text = text.split("#if OW_FOLLOWERS_POKEBALLS", 1)[0]
    tags = [
        int(value, 16)
        for value in re.findall(r"#define\s+OBJ_EVENT_PAL_TAG_[A-Z0-9_]+\s+0x([0-9A-Fa-f]+)", text)
    ]
    return max(tags) + 1


def ensure_newline(text: str) -> str:
    return text if text.endswith("\n") else text + "\n"


def insert_before(text: str, anchor: str, addition: str) -> str:
    if anchor not in text:
        raise ValueError(f"Could not find insertion anchor: {anchor}")
    if addition.strip() in text:
        return text
    return text.replace(anchor, addition + "\n" + anchor, 1)


def update_constants(graphics_constant: str, graphics_id: int, palette_constant: str, palette_tag: int) -> None:
    text = read_text(EVENT_OBJECT_CONSTANTS)
    if graphics_constant not in text:
        text = insert_before(
            text,
            "// NOTE: The maximum amount of object events",
            f"#define {graphics_constant:<40} {graphics_id}\n",
        )
    current_count = re.search(r"(#define\s+NUM_OBJ_EVENT_GFX\s+)(\d+)", text)
    if current_count is None:
        raise ValueError("Could not find NUM_OBJ_EVENT_GFX.")
    if graphics_id >= int(current_count.group(2)):
        text = text[: current_count.start(2)] + str(graphics_id + 1) + text[current_count.end(2) :]
    if palette_constant not in text:
        text = insert_before(
            text,
            "#if OW_FOLLOWERS_POKEBALLS",
            f"#define {palette_constant:<40} 0x{palette_tag:04X}\n",
        )
    write_text(EVENT_OBJECT_CONSTANTS, text)


def update_graphics_data(pascal_name: str, folder_name: str) -> None:
    text = read_text(GRAPHICS_DATA)
    addition = (
        f'const u32 gObjectEventPic_{pascal_name}[] = '
        f'INCBIN_U32("graphics/pokemon/{folder_name}/overworld.4bpp");\n'
        f'const u16 gObjectEventPal_{pascal_name}[] = '
        f'INCBIN_U16("graphics/pokemon/{folder_name}/overworld_normal.gbapal");\n'
    )
    text = insert_before(text, "const u32 gObjectEventPic_GroudonOld[]", addition)
    write_text(GRAPHICS_DATA, text)


def update_pic_tables(pascal_name: str) -> None:
    text = read_text(PIC_TABLES)
    addition = (
        f"static const struct SpriteFrameImage sPicTable_{pascal_name}[] = {{\n"
        f"    overworld_ascending_frames(gObjectEventPic_{pascal_name}, 4, 4),\n"
        "};\n"
    )
    text = insert_before(text, "static const struct SpriteFrameImage sPicTable_RubySapphireBrendan[]", addition)
    write_text(PIC_TABLES, text)


def update_graphics_info(pascal_name: str, graphics_constant: str, palette_constant: str) -> None:
    text = read_text(GRAPHICS_INFO)
    addition = f"""const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_{pascal_name} = {{
    .tileTag = TAG_NONE,
    .paletteTag = {palette_constant},
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
    .size = 512,
    .width = 32,
    .height = 32,
    .paletteSlot = PALSLOT_NPC_1,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .compressed = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Following,
    .images = sPicTable_{pascal_name},
    .affineAnims = gDummySpriteAffineAnimTable,
}};
"""
    text = insert_before(text, "const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PokeBall", addition)
    write_text(GRAPHICS_INFO, text)

    pointers = read_text(GRAPHICS_POINTERS)
    extern = f"extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_{pascal_name};\n"
    pointers = insert_before(pointers, "// Begin pokemon event objects", extern)
    entry = f"    [{graphics_constant}] =                 &gObjectEventGraphicsInfo_{pascal_name},\n"
    pointers = insert_before(pointers, "    [OBJ_EVENT_GFX_POKE_BALL]", entry)
    write_text(GRAPHICS_POINTERS, pointers)


def update_palette_table(pascal_name: str, palette_constant: str) -> None:
    text = read_text(PALETTE_TABLE)
    entry = f"    {{gObjectEventPal_{pascal_name},              {palette_constant}}},\n"
    text = insert_before(text, "    {gObjectEventPal_Lugia,", entry)
    write_text(PALETTE_TABLE, text)


def register_sprite(map_json: Path, pokemon_dir: Path) -> str:
    if not map_json.exists() or map_json.name != "map.json":
        raise FileNotFoundError(f"Expected an existing map.json: {map_json}")

    overworld_png, normal_palette, shiny_palette = validate_source(pokemon_dir)
    constant_name, graphics_constant, pascal_name = species_names(pokemon_dir)
    constants_text = read_text(EVENT_OBJECT_CONSTANTS)
    graphics_id, _ = next_graphics_id(constants_text)
    palette_tag = next_palette_tag(constants_text)

    convert_assets(pokemon_dir, overworld_png, normal_palette, shiny_palette)

    update_constants(graphics_constant, graphics_id, f"OBJ_EVENT_PAL_TAG_{constant_name}", palette_tag)
    update_graphics_data(pascal_name, pokemon_dir.name)
    update_pic_tables(pascal_name)
    update_graphics_info(
        pascal_name,
        graphics_constant,
        f"OBJ_EVENT_PAL_TAG_{constant_name}",
    )
    update_palette_table(pascal_name, f"OBJ_EVENT_PAL_TAG_{constant_name}")

    return (
        f"Registered {pokemon_dir.name} successfully.\n"
        f"Graphics ID: {graphics_constant} ({graphics_id})\n"
        f"Palette tag: 0x{palette_tag:04X}\n"
        "The map itself was not modified."
    )


def launch_gui() -> None:
    try:
        import tkinter as tk
        from tkinter import filedialog, messagebox, ttk
    except ModuleNotFoundError as error:
        raise RuntimeError(
            "Tkinter is not installed. Install it with: sudo apt install python3-tk"
        ) from error

    root = tk.Tk()
    root.title("Register overworld sprite")
    root.geometry("760x330")
    root.minsize(640, 280)

    maps = available_maps()
    pokemon = available_pokemon()
    map_labels = [str(path.relative_to(ROOT)) for path in maps]
    pokemon_labels = [path.name for path in pokemon]

    selected_map = tk.StringVar(value=map_labels[0] if map_labels else "")
    selected_pokemon = tk.StringVar(value=pokemon_labels[0] if pokemon_labels else "")
    status = tk.StringVar(value="Choose a map and a Pokemon overworld sprite.")

    frame = ttk.Frame(root, padding=16)
    frame.pack(fill="both", expand=True)
    frame.columnconfigure(1, weight=1)

    ttk.Label(frame, text="Target map.json").grid(row=0, column=0, sticky="w", pady=6)
    map_box = ttk.Combobox(frame, textvariable=selected_map, values=map_labels, state="readonly")
    map_box.grid(row=0, column=1, sticky="ew", padx=(12, 6), pady=6)

    def browse_map() -> None:
        chosen = filedialog.askopenfilename(
            title="Select target map.json",
            initialdir=ROOT / "data" / "maps",
            filetypes=[("Map JSON", "map.json"), ("JSON files", "*.json")],
        )
        if chosen:
            path = Path(chosen).resolve()
            if path.name != "map.json" or ROOT not in path.parents:
                messagebox.showerror("Invalid map", "Choose a map.json inside this repository.")
                return
            selected_map.set(str(path.relative_to(ROOT)))

    ttk.Button(frame, text="Browse...", command=browse_map).grid(row=0, column=2, pady=6)

    ttk.Label(frame, text="Pokemon sprite").grid(row=1, column=0, sticky="w", pady=6)
    pokemon_box = ttk.Combobox(
        frame,
        textvariable=selected_pokemon,
        values=pokemon_labels,
        state="readonly",
    )
    pokemon_box.grid(row=1, column=1, sticky="ew", padx=(12, 6), pady=6)

    ttk.Label(
        frame,
        text="Expected source: graphics/pokemon/<name>/overworld.png (192x32)",
    ).grid(row=2, column=1, sticky="w", padx=(12, 6), pady=(0, 12))

    status_label = ttk.Label(frame, textvariable=status, wraplength=680)
    status_label.grid(row=3, column=0, columnspan=3, sticky="w", pady=12)

    def register_from_gui() -> None:
        map_path = ROOT / selected_map.get()
        pokemon_path = POKEMON_GRAPHICS_DIR / selected_pokemon.get()
        if not selected_map.get() or not selected_pokemon.get():
            messagebox.showerror("Missing selection", "Select both a map and a Pokemon.")
            return
        try:
            result = register_sprite(map_path, pokemon_path)
        except (FileNotFoundError, RuntimeError, ValueError, subprocess.CalledProcessError) as error:
            status.set(str(error))
            messagebox.showerror("Registration failed", str(error))
            return
        status.set(result)
        messagebox.showinfo("Registration complete", result)

    ttk.Button(frame, text="Register overworld sprite", command=register_from_gui).grid(
        row=4, column=1, sticky="e", padx=6, pady=12
    )
    ttk.Button(frame, text="Close", command=root.destroy).grid(row=4, column=2, pady=12)

    if not maps:
        status.set("No data/maps/**/map.json files found.")
    if not pokemon:
        status.set("No Pokemon folders with overworld.png found.")
    root.mainloop()


def main() -> None:
    args = parse_args()
    if args.gui or args.map_json is None:
        try:
            launch_gui()
        except RuntimeError as error:
            print(error, file=sys.stderr)
            raise SystemExit(1) from error
        return

    map_json = (ROOT / args.map_json).resolve() if not args.map_json.is_absolute() else args.map_json
    pokemon_dir = choose_pokemon()
    print(f"Target map: {map_json.relative_to(ROOT)}")
    print(f"Pokemon: {pokemon_dir.name}")
    print("Converting sprite assets and updating registration files...")
    print(register_sprite(map_json, pokemon_dir))


if __name__ == "__main__":
    main()
