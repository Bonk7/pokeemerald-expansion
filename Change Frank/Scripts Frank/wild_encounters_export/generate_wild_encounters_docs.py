#!/usr/bin/env python3
"""Generate structured wild encounter documentation from src/data/wild_encounters.json."""

from pathlib import Path
import json
import re

ROOT = Path(__file__).resolve().parents[2]
DATA_FILE = ROOT / "src/data/wild_encounters.json"
OUTPUT_DIR = Path(__file__).resolve().parent.parent


def format_species(species: str) -> str:
    if not isinstance(species, str):
        return str(species)
    name = species.replace("SPECIES_", "")
    special_names = {
        "NIDORAN_M": "Nidoran♂",
        "NIDORAN_F": "Nidoran♀",
        "MR_MIME": "Mr. Mime",
        "HO_OH": "Ho-Oh",
        "MIME_JR": "Mime Jr.",
        "PORYGON2": "Porygon2",
        "MAGIKARP": "Magikarp",
        "GROUDON": "Groudon",
        "KYOGRE": "Kyogre",
        "RAYQUAZA": "Rayquaza",
        "LUGIA": "Lugia",
    }
    if name in special_names:
        return special_names[name]

    return re.sub(r"_+", " ", name).title()


def format_map(map_key: str) -> str:
    if not isinstance(map_key, str):
        return str(map_key)

    name = map_key.replace("MAP_", "")
    replacements = {
        "ROUTE101": "Route 101",
        "ROUTE102": "Route 102",
        "ROUTE103": "Route 103",
        "ROUTE104": "Route 104",
        "ROUTE105": "Route 105",
        "ROUTE106": "Route 106",
        "ROUTE107": "Route 107",
        "ROUTE108": "Route 108",
        "ROUTE109": "Route 109",
        "ROUTE110": "Route 110",
        "ROUTE111": "Route 111",
        "ROUTE112": "Route 112",
        "ROUTE113": "Route 113",
        "ROUTE114": "Route 114",
        "ROUTE115": "Route 115",
        "ROUTE116": "Route 116",
        "ROUTE117": "Route 117",
        "ROUTE118": "Route 118",
        "ROUTE119": "Route 119",
        "ROUTE120": "Route 120",
        "ROUTE121": "Route 121",
        "ROUTE122": "Route 122",
        "ROUTE123": "Route 123",
        "ROUTE124": "Route 124",
        "ROUTE125": "Route 125",
        "ROUTE126": "Route 126",
        "ROUTE127": "Route 127",
        "ROUTE128": "Route 128",
        "ROUTE129": "Route 129",
        "ROUTE130": "Route 130",
        "ROUTE131": "Route 131",
        "ROUTE132": "Route 132",
        "ROUTE133": "Route 133",
        "ROUTE134": "Route 134",
        "PETALBURG_WOODS": "Petalburg Woods",
        "RUSTURF_TUNNEL": "Rusturf Tunnel",
        "GRANITE_CAVE_1F": "Granite Cave 1F",
        "GRANITE_CAVE_B1F": "Granite Cave B1F",
        "GRANITE_CAVE_B2F": "Granite Cave B2F",
        "MT_PYRE_1F": "Mt. Pyre 1F",
        "MT_PYRE_2F": "Mt. Pyre 2F",
        "MT_PYRE_3F": "Mt. Pyre 3F",
        "MT_PYRE_4F": "Mt. Pyre 4F",
        "MT_PYRE_5F": "Mt. Pyre 5F",
        "MT_PYRE_6F": "Mt. Pyre 6F",
        "MT_PYRE_EXTERIOR": "Mt. Pyre Exterior",
        "MT_PYRE_SUMMIT": "Mt. Pyre Summit",
        "SAFARI_ZONE_SOUTH": "Safari Zone South",
        "SAFARI_ZONE_SOUTHWEST": "Safari Zone Southwest",
        "SAFARI_ZONE_NORTH": "Safari Zone North",
        "SAFARI_ZONE_NORTHWEST": "Safari Zone Northwest",
        "SAFARI_ZONE_SOUTHEAST": "Safari Zone Southeast",
        "SAFARI_ZONE_NORTHEAST": "Safari Zone Northeast",
        "UNDERWATER_ROUTE126": "Underwater Route 126",
        "UNDERWATER_ROUTE124": "Underwater Route 124",
        "CAVE_OF_ORIGIN_ENTRANCE": "Cave of Origin Entrance",
        "CAVE_OF_ORIGIN_1F": "Cave of Origin 1F",
        "BATTLE_PYRAMID_1": "Battle Pyramid 1",
        "BATTLE_PYRAMID_2": "Battle Pyramid 2",
        "BATTLE_PYRAMID_3": "Battle Pyramid 3",
        "BATTLE_PYRAMID_4": "Battle Pyramid 4",
        "BATTLE_PYRAMID_5": "Battle Pyramid 5",
        "BATTLE_PYRAMID_6": "Battle Pyramid 6",
        "BATTLE_PYRAMID_7": "Battle Pyramid 7",
        "BATTLE_PIKE_1": "Battle Pike 1",
        "BATTLE_PIKE_2": "Battle Pike 2",
        "BATTLE_PIKE_3": "Battle Pike 3",
        "BATTLE_PIKE_4": "Battle Pike 4",
    }
    if name in replacements:
        return replacements[name]
    return re.sub(r"_+", " ", name).title()


def collect_data(data: dict):
    encounter_docs = []
    unique_species = []
    seen_species = set()

    for group in data.get("wild_encounter_groups", []):
        for encounter in group.get("encounters", []):
            if group.get("for_maps", False):
                title = format_map(encounter.get("map", ""))
            else:
                title = format_map(encounter.get("base_label", "")) or "Unnamed encounter group"

            sections = []
            for key in ["land_mons", "water_mons", "rock_smash_mons", "fishing_mons"]:
                section = encounter.get(key)
                if not section:
                    continue
                species_list = [mon.get("species") for mon in section.get("mons", []) if mon.get("species")]
                if species_list:
                    sections.append((key, section.get("encounter_rate"), species_list))
                    for species in species_list:
                        if species not in seen_species:
                            seen_species.add(species)
                            unique_species.append(species)

            if sections:
                encounter_docs.append((title, sections))

    return encounter_docs, unique_species


def write_unique_species(path: Path, species: list[str]) -> None:
    with path.open("w", encoding="utf-8") as handle:
        handle.write("# Wild Encounters – unieke Pokémon\n\n")
        handle.write(f"Gegenereerd uit {DATA_FILE.relative_to(ROOT)}\n\n")
        handle.write(f"Totaal unieke Pokémon: {len(species)}\n\n")
        handle.write("## Lijst\n\n")
        for index, species_name in enumerate(species, 1):
            handle.write(f"{index}. {species_name} ({format_species(species_name)})\n")


def write_location_docs(path: Path, encounter_docs: list[tuple[str, list[tuple[str, int | None, list[str]]]]]) -> None:
    with path.open("w", encoding="utf-8") as handle:
        handle.write("# Wild Encounters – locatieoverzicht\n\n")
        handle.write(f"Gegenereerd uit {DATA_FILE.relative_to(ROOT)}\n\n")
        handle.write(f"Aantal locaties met encounters: {len(encounter_docs)}\n\n")
        handle.write("## Per locatie\n\n")

        for title, sections in sorted(encounter_docs, key=lambda item: item[0].lower()):
            handle.write(f"### {title}\n\n")
            for key, rate, species_list in sections:
                label = {
                    "land_mons": "Land",
                    "water_mons": "Water",
                    "rock_smash_mons": "Rock Smash",
                    "fishing_mons": "Fishing",
                }[key]
                formatted_species = [format_species(species) for species in species_list]
                handle.write(f"- {label} (rate: {rate}): {', '.join(formatted_species)}\n")
            handle.write("\n")


def main() -> None:
    if not DATA_FILE.exists():
        raise FileNotFoundError(f"Kon data niet vinden: {DATA_FILE}")

    with DATA_FILE.open(encoding="utf-8") as handle:
        data = json.load(handle)

    encounter_docs, species = collect_data(data)

    unique_path = OUTPUT_DIR / "wild_encounters_unique_pokemon.md"
    location_path = OUTPUT_DIR / "wild_encounters_locaties.md"

    write_unique_species(unique_path, species)
    write_location_docs(location_path, encounter_docs)

    print(f"Updated {unique_path.relative_to(ROOT)}")
    print(f"Updated {location_path.relative_to(ROOT)}")
    print(f"Unique species count: {len(species)}")
    print(f"Encounter docs count: {len(encounter_docs)}")


if __name__ == "__main__":
    main()
