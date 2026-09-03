# 1 "data/maps/AlteringCave/scripts.pory"

# 2 "data/maps/AlteringCave/scripts.pory"
AlteringCave_MapScripts::
# 3 "data/maps/AlteringCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
# 4 "data/maps/AlteringCave/scripts.pory"
	.byte 0
# 5 "data/maps/AlteringCave/scripts.pory"

# 6 "data/maps/AlteringCave/scripts.pory"
AlteringCave_OnTransition:
# 7 "data/maps/AlteringCave/scripts.pory"
	setflag FLAG_LANDMARK_ALTERING_CAVE
# 8 "data/maps/AlteringCave/scripts.pory"
	end

AlteringCave_Battle_Cresselia::
# 12 "data/maps/AlteringCave/scripts.pory"
	lockall
# 13 "data/maps/AlteringCave/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
# 14 "data/maps/AlteringCave/scripts.pory"
	delay 40
# 15 "data/maps/AlteringCave/scripts.pory"
	waitmoncry
# 16 "data/maps/AlteringCave/scripts.pory"
	setwildbattle SPECIES_CRESSELIA, 60, ITEM_EXP_CHARM
# 17 "data/maps/AlteringCave/scripts.pory"
	dowildbattle
# 18 "data/maps/AlteringCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 19 "data/maps/AlteringCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq AlteringCave_Battle_Cresselia_2
AlteringCave_Battle_Cresselia_1:
# 22 "data/maps/AlteringCave/scripts.pory"
	waitmessage
# 23 "data/maps/AlteringCave/scripts.pory"
	releaseall
	return

AlteringCave_Battle_Cresselia_2:
# 20 "data/maps/AlteringCave/scripts.pory"
	call Cresselia_Caught
	goto AlteringCave_Battle_Cresselia_1


Cresselia_Caught::
# 27 "data/maps/AlteringCave/scripts.pory"
	setflag FLAG_STATIC_CRESSELIA
# 28 "data/maps/AlteringCave/scripts.pory"
	fadescreen FADE_TO_BLACK
# 29 "data/maps/AlteringCave/scripts.pory"
	removeobject 1
# 30 "data/maps/AlteringCave/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

