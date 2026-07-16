#!/usr/bin/env python3
"""Compare the Gen 1-5 Pokémon list against the existing wild encounter export."""

from pathlib import Path
import json
import re

ROOT = Path(__file__).resolve().parents[2]
FACTS_DIR = ROOT / "Change Frank" / "Facts"
OUTPUT_DIR = ROOT / "Change Frank"

GEN_LIST = FACTS_DIR / "gen_1_to_gen_5_pokemon_list.txt"
WILD_ENCOUNTERS_JSON = ROOT / "src" / "data" / "wild_encounters.json"
SPECIES_INFO_DIR = ROOT / "src" / "data" / "pokemon" / "species_info"

TYPE_NAME_MAP = {
    "TYPE_NONE": "None",
    "TYPE_NORMAL": "Normal",
    "TYPE_FIGHTING": "Fighting",
    "TYPE_FLYING": "Flying",
    "TYPE_POISON": "Poison",
    "TYPE_GROUND": "Ground",
    "TYPE_ROCK": "Rock",
    "TYPE_BUG": "Bug",
    "TYPE_GHOST": "Ghost",
    "TYPE_STEEL": "Steel",
    "TYPE_MYSTERY": "Mystery",
    "TYPE_FIRE": "Fire",
    "TYPE_WATER": "Water",
    "TYPE_GRASS": "Grass",
    "TYPE_ELECTRIC": "Electric",
    "TYPE_PSYCHIC": "Psychic",
    "TYPE_ICE": "Ice",
    "TYPE_DRAGON": "Dragon",
    "TYPE_DARK": "Dark",
    "TYPE_FAIRY": "Fairy",
    "TYPE_STELLAR": "Stellar",
}


def parse_stat_value(value: str) -> int | None:
    value = value.strip()
    if not value:
        return None
    ternary_match = re.search(r"\?\s*(\d+)\s*:\s*(\d+)", value)
    if ternary_match:
        return int(ternary_match.group(1))
    digits = re.findall(r"\d+", value)
    return int(digits[0]) if digits else None


def load_species_info(path: Path) -> tuple[dict[str, str], dict[str, dict[str, str | int | None]]]:
    names: dict[str, str] = {}
    details: dict[str, dict[str, str | int | None]] = {}
    for file_path in sorted(path.glob("*.h")):
        text = file_path.read_text(encoding="utf-8")
        lines = text.splitlines()
        entry_species: str | None = None
        entry_lines: list[str] = []
        brace_depth = 0

        for line in lines:
            if entry_species is None:
                match = re.match(r"\s*\[(SPECIES_[A-Z0-9_]+)\]\s*=", line)
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
                    name_match = re.search(r'\.speciesName\s*=\s*_\("([^\"]+)"\)', body)
                    if name_match:
                        names[entry_species] = name_match.group(1)

                    types_match = re.search(r"\.types\s*=\s*MON_TYPES\(([^\)]*)\)", body, re.S)
                    types: list[str] = []
                    if types_match:
                        raw_types = types_match.group(1)
                        for raw_type in raw_types.split(","):
                            raw_type = raw_type.strip()
                            if raw_type:
                                types.append(TYPE_NAME_MAP.get(raw_type, raw_type.replace("TYPE_", "").title()))

                    stats: dict[str, int] = {}
                    for stat_name in ["baseHP", "baseAttack", "baseDefense", "baseSpeed", "baseSpAttack", "baseSpDefense"]:
                        stat_match = re.search(rf"\.{stat_name}\s*=\s*([^,\}}]+)", body)
                        if stat_match:
                            stat_value = parse_stat_value(stat_match.group(1))
                            if stat_value is not None:
                                stats[stat_name] = stat_value

                    bst = None
                    if len(stats) == 6:
                        bst = sum(stats.values())

                    details[entry_species] = {
                        "types": "/".join(types) if types else "",
                        "bst": bst,
                    }

                    entry_species = None
                    entry_lines = []
                    brace_depth = 0
    return names, details


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


def read_wild_encounter_entries_from_json(path: Path) -> list[tuple[str, str]]:
    if not path.exists():
        raise FileNotFoundError(f"Missing file: {path}")
    with path.open(encoding="utf-8") as handle:
        data = json.load(handle)

    entries: list[tuple[str, str]] = []
    seen: set[str] = set()

    for group in data.get("wild_encounter_groups", []):
        for encounter in group.get("encounters", []):
            for section in encounter.values():
                if not isinstance(section, dict):
                    continue
                mons = section.get("mons")
                if not isinstance(mons, list):
                    continue
                for mon in mons:
                    species = mon.get("species")
                    if not isinstance(species, str):
                        continue
                    if species in seen:
                        continue
                    seen.add(species)
                    entries.append((species, ""))
    return entries


def sort_species_by_bst(species_list: list[str], details_map: dict[str, dict[str, str | int | None]]) -> list[str]:
    def sort_key(species: str) -> tuple[bool, int, str]:
        info = details_map.get(species, {})
        bst = info.get("bst")
        return (bst is None, bst if bst is not None else 0, species)

    return sorted(species_list, key=sort_key)


def format_entry(species: str, name_map: dict[str, str], details_map: dict[str, dict[str, str | int | None]], fallback_name: str | None = None) -> str:
    if fallback_name:
        display_name = fallback_name
    elif species in name_map:
        display_name = name_map[species]
    else:
        display_name = species.removeprefix('SPECIES_').replace('_', ' ').title()

    details = []
    info = details_map.get(species, {})
    types = info.get("types")
    bst = info.get("bst")
    if types:
        details.append(types)
    if bst is not None:
        details.append(f"BST {bst}")

    if details:
        return f"{display_name} ({', '.join(details)}) — {species}"
    return f"{display_name} — {species}"


def write_species_export(path: Path, species: list[str], name_map: dict[str, str], details_map: dict[str, dict[str, str | int | None]], fallback_names: dict[str, str] | None = None) -> None:
    if fallback_names is None:
        fallback_names = {}
    with path.open("w", encoding="utf-8") as handle:
        handle.write(f"Count: {len(species)}\n\n")
        for item in species:
            handle.write(f"{format_entry(item, name_map, details_map, fallback_names.get(item))}\n")


def write_checklist_export(path: Path, species: list[str], name_map: dict[str, str], details_map: dict[str, dict[str, str | int | None]], fallback_names: dict[str, str] | None = None) -> None:
    if fallback_names is None:
        fallback_names = {}
    with path.open("w", encoding="utf-8") as handle:
        handle.write("# Checklist: Pokémon die nog moeten worden toegevoegd aan wild encounters\n")
        handle.write(f"Count: {len(species)}\n\n")
        for item in species:
            handle.write(f"- [ ] {format_entry(item, name_map, details_map, fallback_names.get(item))}\n")


def main() -> None:
    gen_species = read_species_list(GEN_LIST)
    wild_entries = read_wild_encounter_entries_from_json(WILD_ENCOUNTERS_JSON)
    wild_species = [species for species, _ in wild_entries]
    wild_name_map = {species: name for species, name in wild_entries if name}
    species_name_map, species_details = load_species_info(SPECIES_INFO_DIR)

    wild_set = set(wild_species)
    gen_set = set(gen_species)

    missing_from_wild = sort_species_by_bst(sorted(gen_set - wild_set), species_details)
    present_in_wild = sort_species_by_bst(sorted(gen_set & wild_set), species_details)
    extra_in_wild = sort_species_by_bst(sorted(wild_set - gen_set), species_details)

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
        for species in sort_species_by_bst(gen_species, species_details):
            handle.write(f"- {format_entry(species, species_name_map, species_details)}\n")
        handle.write("\n## Wild encounters\n")
        for species in sort_species_by_bst(wild_species, species_details):
            handle.write(f"- {format_entry(species, species_name_map, species_details, wild_name_map.get(species))}\n")
        handle.write("\n## Overlap\n")
        for species in present_in_wild:
            handle.write(f"- {format_entry(species, species_name_map, species_details, wild_name_map.get(species))}\n")
        handle.write("\n## Gen 1-5 zonder wild-encounter\n")
        for species in missing_from_wild:
            handle.write(f"- {format_entry(species, species_name_map, species_details)}\n")
        handle.write("\n## Wild encounters zonder Gen 1-5\n")
        for species in extra_in_wild:
            handle.write(f"- {format_entry(species, species_name_map, species_details, wild_name_map.get(species))}\n")

    write_species_export(
        FACTS_DIR / "gen1_to_gen5_missing_from_wild_encounters.txt",
        missing_from_wild,
        species_name_map,
        species_details,
    )
    write_checklist_export(
        FACTS_DIR / "wild_encounters_missing_pokemon_checklist.md",
        missing_from_wild,
        species_name_map,
        species_details,
    )
    write_species_export(
        FACTS_DIR / "wild_encounters_missing_from_gen1_to_gen5.txt",
        extra_in_wild,
        species_name_map,
        species_details,
        wild_name_map,
    )
    write_species_export(
        FACTS_DIR / "gen1_to_gen5_overlap.txt",
        present_in_wild,
        species_name_map,
        species_details,
        wild_name_map,
    )

    print(f"Wrote {output_path}")
    print(f"Wild encounter count: {len(wild_species)}")
    print(f"Overlap: {len(present_in_wild)}")
    print(f"Wild encounter species missing from Gen 1-5 list: {len(extra_in_wild)}")


if __name__ == "__main__":
    main()
