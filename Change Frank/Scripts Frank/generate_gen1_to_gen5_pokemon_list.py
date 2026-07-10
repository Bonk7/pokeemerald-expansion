#!/usr/bin/env python3
"""Export the Gen 1-5 Pokémon species list, including Mega forms but excluding non-Mega special forms."""

from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
OUTPUT_DIR = ROOT / "Change Frank" / "Facts"
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

SPECIES_HEADER = ROOT / "include" / "constants" / "species.h"
POKEDEX_HEADER = ROOT / "include" / "constants" / "pokedex.h"


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

    final_species = []
    seen = set()
    for species in dex_order:
        if species in species_constants and species not in seen and should_include(species):
            seen.add(species)
            final_species.append(species)

    output_path = OUTPUT_DIR / "gen_1_to_gen_5_pokemon_list.txt"
    with output_path.open("w", encoding="utf-8") as handle:
        handle.write("Gen 1-5 Pokémon lijst\n")
        handle.write("====================\n")
        handle.write(f"Aantal: {len(final_species)}\n\n")
        for species in final_species:
            handle.write(f"{species}\n")

    print(f"Wrote {output_path}")
    print(f"Count: {len(final_species)}")


if __name__ == "__main__":
    main()
