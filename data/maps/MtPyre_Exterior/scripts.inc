# 1 "data/maps/MtPyre_Exterior/scripts.pory"

# 2 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_MapScripts::
# 3 "data/maps/MtPyre_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
# 4 "data/maps/MtPyre_Exterior/scripts.pory"
	.byte 0
# 5 "data/maps/MtPyre_Exterior/scripts.pory"

# 6 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_OnTransition:
# 7 "data/maps/MtPyre_Exterior/scripts.pory"
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
# 8 "data/maps/MtPyre_Exterior/scripts.pory"
	end
# 9 "data/maps/MtPyre_Exterior/scripts.pory"

# 10 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_CheckEnterFromSummit::
# 11 "data/maps/MtPyre_Exterior/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 12 "data/maps/MtPyre_Exterior/scripts.pory"
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
# 13 "data/maps/MtPyre_Exterior/scripts.pory"
	return
# 14 "data/maps/MtPyre_Exterior/scripts.pory"

# 15 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_EnterFromSummit::
# 16 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 17 "data/maps/MtPyre_Exterior/scripts.pory"
	return
# 18 "data/maps/MtPyre_Exterior/scripts.pory"

# 19 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_FogTrigger::
# 20 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_FOG_HORIZONTAL
# 21 "data/maps/MtPyre_Exterior/scripts.pory"
	doweather
# 22 "data/maps/MtPyre_Exterior/scripts.pory"
	end
# 23 "data/maps/MtPyre_Exterior/scripts.pory"

# 24 "data/maps/MtPyre_Exterior/scripts.pory"
MtPyre_Exterior_EventScript_SunTrigger::
# 25 "data/maps/MtPyre_Exterior/scripts.pory"
	setweather WEATHER_SUNNY
# 26 "data/maps/MtPyre_Exterior/scripts.pory"
	doweather
# 27 "data/maps/MtPyre_Exterior/scripts.pory"
	end

MtPyreExterior_Battle_Zapdos::
# 31 "data/maps/MtPyre_Exterior/scripts.pory"
	lockall
# 32 "data/maps/MtPyre_Exterior/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 33 "data/maps/MtPyre_Exterior/scripts.pory"
	delay 40
# 34 "data/maps/MtPyre_Exterior/scripts.pory"
	waitmoncry
# 35 "data/maps/MtPyre_Exterior/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, 65, ITEM_MAGNET
# 36 "data/maps/MtPyre_Exterior/scripts.pory"
	dowildbattle
# 37 "data/maps/MtPyre_Exterior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data/maps/MtPyre_Exterior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MtPyreExterior_Battle_Zapdos_2
MtPyreExterior_Battle_Zapdos_1:
# 41 "data/maps/MtPyre_Exterior/scripts.pory"
	waitmessage
# 42 "data/maps/MtPyre_Exterior/scripts.pory"
	releaseall
	return

MtPyreExterior_Battle_Zapdos_2:
# 39 "data/maps/MtPyre_Exterior/scripts.pory"
	call Zapdos_Caught
	goto MtPyreExterior_Battle_Zapdos_1


Zapdos_Caught::
# 46 "data/maps/MtPyre_Exterior/scripts.pory"
	setflag FLAG_STATIC_ZAPDOS
# 47 "data/maps/MtPyre_Exterior/scripts.pory"
	fadescreen FADE_TO_BLACK
# 48 "data/maps/MtPyre_Exterior/scripts.pory"
	removeobject 4
# 49 "data/maps/MtPyre_Exterior/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

