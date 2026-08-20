# Overworld sprite registreren

Gebruik vanuit de repository-root:

## GUI

Installeer op Linux eenmalig Tkinter:

```bash
sudo apt install python3-tk
```

Start daarna de GUI zonder argumenten:

```bash
python3 "Change Frank/Scripts Frank/register_overworld_sprite.py"
```

Je kunt ook expliciet de GUI-optie gebruiken:

```bash
python3 "Change Frank/Scripts Frank/register_overworld_sprite.py" --gui
```

## Terminal

Gebruik vanuit de repository-root:

```bash
python3 "Change Frank/Scripts Frank/register_overworld_sprite.py" data/maps/Route101/map.json
```

Het script doet daarna het volgende:

1. Het toont de Pokemon-mappen onder `graphics/pokemon` die een `overworld.png` bevatten.
2. Je kiest de Pokemon interactief.
3. Het leest de afmetingen van `overworld.png` uit. Ondersteund zijn zes frames van 32x32 (`192x32`) en zes frames van 64x64 (`384x64`).
4. Het maakt `overworld.4bpp` en de palettebestanden aan met `gbagfx`.
5. Het verhoogt automatisch het eerstvolgende object-graphics-ID en palette-tag.
6. Het vult de graphics include, pictable, graphics-info, pointer table en palette table aan.

De opgegeven `map.json` wordt gecontroleerd en in de uitvoer vermeld, maar niet gewijzigd. Daardoor wordt de nieuwe graphics-ID globaal beschikbaar in Porymap. Een object-event, coordinaten, script of flag moet je daarna zelf op de kaart toevoegen.

Vereiste bestanden in de gekozen Pokemon-map:

- `overworld.png`
- `overworld_normal.pal`
- optioneel: `overworld_shiny.pal`

De registratie is bedoeld voor Pokemonmappen zoals `graphics/pokemon/meloetta` en `graphics/pokemon/celebi`. Grotere legendaries zoals Groudon, Kyogre, Lugia, Palkia, Regigigas en Rayquaza worden automatisch met 64x64 OAM- en frame-instellingen geregistreerd.
