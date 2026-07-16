#!/usr/bin/env python3
"""Export the Gen 1-5 Pokémon species list, including Mega forms but excluding non-Mega special forms."""

from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
OUTPUT_DIR = ROOT / "Change Frank" / "Facts"
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

SPECIES_HEADER = ROOT / "include" / "constants" / "species.h"
POKEDEX_HEADER = ROOT / "include" / "constants" / "pokedex.h"
SPECIES_INFO_DIR = ROOT / "src" / "data" / "pokemon" / "species_info"


def parse_stat_value(value: str) -> int | None:
    value = value.strip()
    if not value:
        return None
    ternary_match = re.search(r"\?\s*(\d+)\s*:\s*(\d+)", value)
    if ternary_match:
        return int(ternary_match.group(1))
    digits = re.findall(r"\d+", value)
    return int(digits[0]) if digits else None


def load_species_bst(path: Path) -> dict[str, int]:
    bst_by_species: dict[str, int] = {}
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
                    stats: dict[str, int] = {}
                    for stat_name in ["baseHP", "baseAttack", "baseDefense", "baseSpeed", "baseSpAttack", "baseSpDefense"]:
                        stat_match = re.search(rf"\.{stat_name}\s*=\s*([^,}}]+)", body)
                        if stat_match:
                            stat_value = parse_stat_value(stat_match.group(1))
                            if stat_value is not None:
                                stats[stat_name] = stat_value
                    if len(stats) == 6:
                        bst_by_species[entry_species] = sum(stats.values())
                    entry_species = None
                    entry_lines = []
                    brace_depth = 0
    return bst_by_species


def extract_species_constants(path: Path) -> list[str]:
    text = path.read_text(encoding="utf-8")
    return re.findall(r"#define\s+(SPECIES_[A-Z0-9_]+)\s+\d+", text)


def extract_national_dex_order(path: Path) -> list[str]:
    text = path.read_text(encoding="utf-8")
    entries = re.findall(r"NATIONAL_DEX_([A-Z0-9_]+)", text)
    cutoff = "UNFEZANT"
    if cutoff in entries:
        entries = entries[: entries.index(cutoff) + 1]
    return [f"SPECIES_{name}" for name in entries if name != "NONE"]


def should_include(species: str) -> bool:
    name = species.removeprefix("SPECIES_")
    if "MEGA" in name:
        return True
    if "_" in name:
        return False
    return True


def main() -> None:
    species_constants = set(extract_species_constants(SPECIES_HEADER))
    dex_order = extract_national_dex_order(POKEDEX_HEADER)

    bst_by_species = load_species_bst(SPECIES_INFO_DIR)

    final_species = []
    seen = set()
    for species in dex_order:
        if species in species_constants and species not in seen and should_include(species):
            seen.add(species)
            final_species.append(species)

    final_species.sort(key=lambda species: (bst_by_species.get(species, float("inf")), species))

    output_path = OUTPUT_DIR / "gen_1_to_gen_5_pokemon_list.txt"
    with output_path.open("w", encoding="utf-8") as handle:
        handle.write("Gen 1-5 Pokémon lijst\n")
        handle.write("====================\n")
        handle.write(f"Aantal: {len(final_species)}\n\n")
        for species in final_species:
            bst = bst_by_species.get(species)
            if bst is not None:
                handle.write(f"{species} — BST {bst}\n")
            else:
                handle.write(f"{species}\n")

    print(f"Wrote {output_path}")
    print(f"Count: {len(final_species)}")


if __name__ == "__main__":
    main()
