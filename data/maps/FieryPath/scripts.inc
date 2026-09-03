# 1 "data/maps/FieryPath/scripts.pory"

# 2 "data/maps/FieryPath/scripts.pory"
FieryPath_MapScripts::
# 3 "data/maps/FieryPath/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
# 4 "data/maps/FieryPath/scripts.pory"
	.byte 0
# 5 "data/maps/FieryPath/scripts.pory"

# 6 "data/maps/FieryPath/scripts.pory"
FieryPath_OnTransition:
# 7 "data/maps/FieryPath/scripts.pory"
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
# 8 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_LANDMARK_FIERY_PATH
# 9 "data/maps/FieryPath/scripts.pory"
	end
# 10 "data/maps/FieryPath/scripts.pory"

# 11 "data/maps/FieryPath/scripts.pory"
FieryPath_EventScript_MoveScottToFallarbor::
# 12 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 13 "data/maps/FieryPath/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 14 "data/maps/FieryPath/scripts.pory"
	return

FieryPath_Battle_Moltres::
# 18 "data/maps/FieryPath/scripts.pory"
	lockall
# 19 "data/maps/FieryPath/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 20 "data/maps/FieryPath/scripts.pory"
	delay 40
# 21 "data/maps/FieryPath/scripts.pory"
	waitmoncry
# 22 "data/maps/FieryPath/scripts.pory"
	setwildbattle SPECIES_MOLTRES, 32, ITEM_SKY_PLATE
# 23 "data/maps/FieryPath/scripts.pory"
	dowildbattle
# 24 "data/maps/FieryPath/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 25 "data/maps/FieryPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FieryPath_Battle_Moltres_2
FieryPath_Battle_Moltres_1:
# 28 "data/maps/FieryPath/scripts.pory"
	waitmessage
# 29 "data/maps/FieryPath/scripts.pory"
	releaseall
	return

FieryPath_Battle_Moltres_2:
# 26 "data/maps/FieryPath/scripts.pory"
	call Moltres_Caught
	goto FieryPath_Battle_Moltres_1


Moltres_Caught::
# 33 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_STATIC_MOLTRES
# 34 "data/maps/FieryPath/scripts.pory"
	fadescreen FADE_TO_BLACK
# 35 "data/maps/FieryPath/scripts.pory"
	removeobject 8
# 36 "data/maps/FieryPath/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

