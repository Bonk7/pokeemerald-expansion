#!/usr/bin/env python3
"""Compare the Gen 1-5 Pokémon list against the existing wild encounter export."""

from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
FACTS_DIR = ROOT / "Change Frank" / "Facts"
OUTPUT_DIR = ROOT / "Change Frank"

GEN_LIST = FACTS_DIR / "gen_1_to_gen_5_pokemon_list.txt"
WILD_ENCOUNTERS = OUTPUT_DIR / "wild_encounters_unique_pokemon.md"
SPECIES_INFO_DIR = ROOT / "src" / "data" / "pokemon" / "species_info"


def read_species_list(path: Path) -> list[str]:
    if not path.exists():
        raise FileNotFoundError(f"Missing file: {path}")
    species = []
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line or line.startswith("Gen") or line.startswith("=") or line.startswith("Aantal"):
            continue
        if line.startswith("SPECIES_"):
            species.append(line)
    return species


def load_species_name_map(path: Path) -> dict[str, str]:
    names: dict[str, str] = {}
    for file_path in sorted(path.glob("*.h")):
        text = file_path.read_text(encoding="utf-8")
        lines = text.splitlines()
        entry_species: str | None = None
        entry_lines: list[str] = []
        brace_depth = 0

        for line in lines:
            if entry_species is None:
                match = re.match(r"\s*\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*\{", line)
                if match:
                    entry_species = match.group(1)
                    entry_lines = [line]
                    brace_depth = line.count("{") - line.count("}")
                    continue
            else:
                entry_lines.append(line)
                brace_depth += line.count("{") - line.count("}")
                if brace_depth <= 0:
                    body = "\n".join(entry_lines)
                    name_match = re.search(r'\.speciesName\s*=\s*_\("([^"]+)"\)', body)
                    if name_match:
                        names[entry_species] = name_match.group(1)
                    entry_species = None
                    entry_lines = []
                    brace_depth = 0
    return names


def read_wild_encounter_entries(path: Path) -> list[tuple[str, str]]:
    if not path.exists():
        raise FileNotFoundError(f"Missing file: {path}")
    entries: list[tuple[str, str]] = []
    for line in path.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if re.match(r"^\d+\.\s*", line):
            line = re.sub(r"^\d+\.\s*", "", line)
        if line.startswith("SPECIES_"):
            species = line.split("(", 1)[0].strip()
            name = ""
            if "(" in line and line.endswith(")"):
                name = line.split("(", 1)[1].rsplit(")", 1)[0].strip()
            entries.append((species, name))
    return entries


def format_entry(species: str, name_map: dict[str, str], fallback_name: str | None = None) -> str:
    if fallback_name:
        return f"{fallback_name} — {species}"
    if species in name_map:
        return f"{name_map[species]} — {species}"
    return f"{species.removeprefix('SPECIES_').replace('_', ' ').title()} — {species}"


def write_species_export(path: Path, species: list[str], name_map: dict[str, str], fallback_names: dict[str, str] | None = None) -> None:
    if fallback_names is None:
        fallback_names = {}
    with path.open("w", encoding="utf-8") as handle:
        handle.write(f"Count: {len(species)}\n\n")
        for item in species:
            handle.write(f"{format_entry(item, name_map, fallback_names.get(item))}\n")


def main() -> None:
    gen_species = read_species_list(GEN_LIST)
    wild_entries = read_wild_encounter_entries(WILD_ENCOUNTERS)
    wild_species = [species for species, _ in wild_entries]
    wild_name_map = {species: name for species, name in wild_entries if name}
    species_name_map = load_species_name_map(SPECIES_INFO_DIR)

    wild_set = set(wild_species)
    gen_set = set(gen_species)

    missing_from_wild = sorted(gen_set - wild_set)
    present_in_wild = sorted(gen_set & wild_set)
    extra_in_wild = sorted(wild_set - gen_set)

    output_path = FACTS_DIR / "gen1_to_gen5_vs_wild_encounters_report.txt"
    with output_path.open("w", encoding="utf-8") as handle:
        handle.write("Gen 1-5 vs Wild Encounters Report\n")
        handle.write("================================\n\n")
        handle.write(f"Gen 1-5 lijst: {len(gen_species)}\n")
        handle.write(f"Wild encounters: {len(wild_species)}\n")
        handle.write(f"Overlap: {len(present_in_wild)}\n")
        handle.write(f"Gen 1-5 zonder wild-encounter: {len(missing_from_wild)}\n")
        handle.write(f"Wild encounters zonder Gen 1-5: {len(extra_in_wild)}\n\n")

        handle.write("## Gen 1-5 lijst\n")
        for species in gen_species:
            handle.write(f"- {format_entry(species, species_name_map)}\n")
        handle.write("\n## Wild encounters\n")
        for species in wild_species:
            handle.write(f"- {format_entry(species, species_name_map, wild_name_map.get(species))}\n")
        handle.write("\n## Overlap\n")
        for species in present_in_wild:
            handle.write(f"- {format_entry(species, species_name_map, wild_name_map.get(species))}\n")
        handle.write("\n## Gen 1-5 zonder wild-encounter\n")
        for species in missing_from_wild:
            handle.write(f"- {format_entry(species, species_name_map)}\n")
        handle.write("\n## Wild encounters zonder Gen 1-5\n")
        for species in extra_in_wild:
            handle.write(f"- {format_entry(species, species_name_map, wild_name_map.get(species))}\n")

    write_species_export(
        FACTS_DIR / "gen1_to_gen5_missing_from_wild_encounters.txt",
        missing_from_wild,
        species_name_map,
    )
    write_species_export(
        FACTS_DIR / "wild_encounters_missing_from_gen1_to_gen5.txt",
        extra_in_wild,
        species_name_map,
        wild_name_map,
    )
    write_species_export(
        FACTS_DIR / "gen1_to_gen5_overlap.txt",
        present_in_wild,
        species_name_map,
        wild_name_map,
    )

    print(f"Wrote {output_path}")
    print(f"Wild encounter count: {len(wild_species)}")
    print(f"Overlap: {len(present_in_wild)}")
    print(f"Wild encounter species missing from Gen 1-5 list: {len(extra_in_wild)}")


if __name__ == "__main__":
    main()
