#!/usr/bin/env python3
"""Interactive helper to place an overworld Pokémon sprite on a map.

Usage:
  python3 Change\ Frank/Scripts\ Frank/MonInOverworld.py
  python3 Change\ Frank/Scripts\ Frank/MonInOverworld.py --species pikachu --map OldaleTown --x 10 --y 8

The script:
  1. Lists available Pokémon sprites from graphics/pokemon/*/overworld.4bpp.
  2. Lists available map.json files under data/maps/*/map.json.
  3. Adds a new object event to the selected map.json.

The generated object event uses the object-graphics macro form:
  OBJ_EVENT_GFX_SPECIES(NAME)
  OBJ_EVENT_GFX_SPECIES_SHINY(NAME)
  OBJ_EVENT_GFX_SPECIES_FEMALE(NAME)
  OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE(NAME)
"""

from __future__ import annotations

import argparse
import json
import re
import shutil
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


REPO_ROOT = Path(__file__).resolve().parents[2]
MAPS_DIR = REPO_ROOT / "data" / "maps"
GRAPHICS_DIR = REPO_ROOT / "graphics" / "pokemon"
SPECIES_HEADER = REPO_ROOT / "include" / "constants" / "species.h"

SPECIES_ENUM_RE = re.compile(r"\bSPECIES_([A-Z0-9_]+)\b")

PREFERRED_VARIANTS = (
    "normal",
    "shiny",
    "female",
    "shiny_female",
)


@dataclass(frozen=True)
class SpeciesChoice:
    enum_name: str
    display_name: str
    graphics_dir_name: str


def discover_species() -> list[SpeciesChoice]:
    """Return all Pokémon species that have a base overworld sprite available."""
    enum_names = []
    for line in SPECIES_HEADER.read_text(encoding="utf-8").splitlines():
        match = SPECIES_ENUM_RE.search(line)
        if not match:
            continue
        name = match.group(1)
        if name in {"NONE", "EGG", "UNOWN", "MAX", "COUNT"}:
            continue
        enum_names.append(name)

    species_choices: list[SpeciesChoice] = []
    seen: set[str] = set()
    for enum_name in enum_names:
        gfx_dir_name = enum_name.lower().replace("_", "_")
        base_path = GRAPHICS_DIR / gfx_dir_name / "overworld.4bpp"
        if not base_path.exists():
            continue

        display_name = enum_name.replace("SPECIES_", "").lower().replace("_", " ")
        if enum_name in seen:
            continue
        seen.add(enum_name)
        species_choices.append(
            SpeciesChoice(
                enum_name=enum_name,
                display_name=display_name,
                graphics_dir_name=gfx_dir_name,
            )
        )

    species_choices.sort(key=lambda item: item.display_name)
    return species_choices


def discover_maps() -> list[tuple[Path, str]]:
    results: list[tuple[Path, str]] = []
    for map_file in sorted(MAPS_DIR.glob("*/map.json")):
        try:
            data = json.loads(map_file.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        map_name = data.get("name") or map_file.parent.name
        results.append((map_file, map_name))
    return results


def prompt_choice(title: str, choices: Iterable[str]) -> str:
    choice_list = list(choices)
    print(f"\n{title}")
    for idx, choice in enumerate(choice_list, start=1):
        print(f"  {idx}. {choice}")

    while True:
        raw = input("Select a number: ").strip()
        if raw.isdigit():
            selection = int(raw)
            if 1 <= selection <= len(choice_list):
                return choice_list[selection - 1]
        print("Please pick a valid number.")


def prompt_coord(label: str, default: int) -> int:
    while True:
        raw = input(f"{label} [{default}]: ").strip()
        if not raw:
            return default
        if raw.lstrip("-").isdigit():
            return int(raw)
        print("Please enter an integer.")


def build_graphics_id(enum_name: str, variant: str) -> str:
    if variant == "normal":
        return f"OBJ_EVENT_GFX_SPECIES({enum_name})"
    if variant == "shiny":
        return f"OBJ_EVENT_GFX_SPECIES_SHINY({enum_name})"
    if variant == "female":
        return f"OBJ_EVENT_GFX_SPECIES_FEMALE({enum_name})"
    if variant == "shiny_female":
        return f"OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE({enum_name})"
    raise ValueError(f"Unsupported variant: {variant}")


def prompt_species(species_choices: list[SpeciesChoice]) -> SpeciesChoice:
    display_names = [item.display_name for item in species_choices]
    display_name = prompt_choice("Available Pokémon sprites", display_names)
    return next(item for item in species_choices if item.display_name == display_name)


def prompt_map(map_choices: list[tuple[Path, str]]) -> tuple[Path, str]:
    choices = [f"{map_path.parent.name} - {map_name}" for map_path, map_name in map_choices]
    selected = prompt_choice("Available maps", choices)
    for map_path, map_name in map_choices:
        entry = f"{map_path.parent.name} - {map_name}"
        if entry == selected:
            return map_path, map_name
    raise RuntimeError("Selected map could not be resolved")


def add_object_event(map_file: Path, event: dict, force: bool = False) -> None:
    data = json.loads(map_file.read_text(encoding="utf-8"))

    object_events = data.get("object_events")
    if not isinstance(object_events, list):
        raise ValueError(f"{map_file.relative_to(REPO_ROOT)} does not contain an object_events array.")

    existing_count = len(object_events)
    local_id = f"LOCALID_MON_IN_OVERWORLD_{existing_count + 1}"
    event["local_id"] = local_id

    backup_path = map_file.with_suffix(".bak")
    if backup_path.exists():
        backup_path.unlink()
    shutil.copy2(map_file, backup_path)

    object_events.append(event)
    map_file.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def resolve_cli_choice(args: argparse.Namespace, species_choices: list[SpeciesChoice], map_choices: list[tuple[Path, str]]) -> tuple[SpeciesChoice, tuple[Path, str], int, int, str]:
    species = None
    if args.species:
        lower = args.species.strip().lower()
        for item in species_choices:
            if lower == item.enum_name.lower().replace("species_", "") or lower == item.display_name:
                species = item
                break
        if species is None:
            raise SystemExit(f"Unknown species '{args.species}'.")
    else:
        species = prompt_species(species_choices)

    map_file, map_name = None, None
    if args.map:
        lower = args.map.strip().lower()
        for item in map_choices:
            path, name = item
            if lower in {path.parent.name.lower(), name.lower()}:
                map_file, map_name = path, name
                break
        if map_file is None:
            raise SystemExit(f"Unknown map '{args.map}'.")
    else:
        map_file, map_name = prompt_map(map_choices)

    x = args.x if args.x is not None else prompt_coord("X coordinate", 0)
    y = args.y if args.y is not None else prompt_coord("Y coordinate", 0)

    variant = args.variant or "normal"
    if variant not in PREFERRED_VARIANTS:
        raise SystemExit(f"Unsupported variant '{variant}'. Choose from: {', '.join(PREFERRED_VARIANTS)}")

    return species, (map_file, map_name), x, y, variant


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Add a Pokémon overworld object event to a map JSON file.")
    parser.add_argument("--species", help="Species name such as pikachu or SPECIES_PIKACHU")
    parser.add_argument("--map", help="Map name or folder name such as OldaleTown or MAP_OLDALE_TOWN")
    parser.add_argument("--x", type=int, help="Object x coordinate")
    parser.add_argument("--y", type=int, help="Object y coordinate")
    parser.add_argument(
        "--variant",
        choices=PREFERRED_VARIANTS,
        default="normal",
        help="Graphics variant to use for the object.",
    )
    parser.add_argument("--dry-run", action="store_true", help="Preview the object event without writing to disk.")
    return parser


def main() -> int:
    species_choices = discover_species()
    map_choices = discover_maps()

    if not species_choices:
        raise SystemExit("No Pokémon overworld sprites were found in graphics/pokemon.")
    if not map_choices:
        raise SystemExit("No map.json files were found under data/maps.")

    parser = build_parser()
    args = parser.parse_args()

    species, (map_file, map_name), x, y, variant = resolve_cli_choice(args, species_choices, map_choices)
    graphics_id = build_graphics_id(species.enum_name, variant)

    event = {
        "graphics_id": graphics_id,
        "x": x,
        "y": y,
        "elevation": 0,
        "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
        "movement_range_x": 0,
        "movement_range_y": 0,
        "trainer_type": "TRAINER_TYPE_NONE",
        "trainer_sight_or_berry_tree_id": "0",
        "script": "NULL",
        "flag": "0",
    }

    print(f"\nSelected Pokémon sprite: {species.display_name} ({species.enum_name})")
    print(f"Selected map: {map_name} ({map_file.relative_to(REPO_ROOT)})")
    print(f"Planned location: x={x}, y={y}")
    print(f"Graphics ID: {graphics_id}")
    print(json.dumps(event, indent=2))

    if args.dry_run:
        print("\nDry run only. No files were modified.")
        return 0

    add_object_event(map_file, event)
    print(f"\nInserted object event in {map_file.relative_to(REPO_ROOT)}")
    print("Backup file written to:", map_file.with_suffix(".bak"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
