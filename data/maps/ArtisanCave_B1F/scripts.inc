# 1 "data/maps/ArtisanCave_B1F/scripts.pory"

# 2 "data/maps/ArtisanCave_B1F/scripts.pory"
ArtisanCave_B1F_MapScripts::
# 3 "data/maps/ArtisanCave_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
# 4 "data/maps/ArtisanCave_B1F/scripts.pory"
	.byte 0
# 5 "data/maps/ArtisanCave_B1F/scripts.pory"

# 6 "data/maps/ArtisanCave_B1F/scripts.pory"
ArtisanCave_B1F_OnTransition:
# 7 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_LANDMARK_ARTISAN_CAVE
# 8 "data/maps/ArtisanCave_B1F/scripts.pory"
	end

AC_Battle_Cobalion::
# 12 "data/maps/ArtisanCave_B1F/scripts.pory"
	lockall
# 13 "data/maps/ArtisanCave_B1F/scripts.pory"
	playmoncry SPECIES_COBALION, CRY_MODE_ENCOUNTER
# 14 "data/maps/ArtisanCave_B1F/scripts.pory"
	delay 40
# 15 "data/maps/ArtisanCave_B1F/scripts.pory"
	waitmoncry
# 16 "data/maps/ArtisanCave_B1F/scripts.pory"
	setwildbattle SPECIES_COBALION, 65, ITEM_FIST_PLATE
# 17 "data/maps/ArtisanCave_B1F/scripts.pory"
	dowildbattle
# 18 "data/maps/ArtisanCave_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 19 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq AC_Battle_Cobalion_2
AC_Battle_Cobalion_1:
# 22 "data/maps/ArtisanCave_B1F/scripts.pory"
	waitmessage
# 23 "data/maps/ArtisanCave_B1F/scripts.pory"
	releaseall
	return

AC_Battle_Cobalion_2:
# 20 "data/maps/ArtisanCave_B1F/scripts.pory"
	call Cobalion_Caught
	goto AC_Battle_Cobalion_1


Cobalion_Caught::
# 27 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_STATIC_COBALION
# 28 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 29 "data/maps/ArtisanCave_B1F/scripts.pory"
	removeobject 2
# 30 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


AC_Battle_Virizion::
# 35 "data/maps/ArtisanCave_B1F/scripts.pory"
	lockall
# 36 "data/maps/ArtisanCave_B1F/scripts.pory"
	playmoncry SPECIES_VIRIZION, CRY_MODE_ENCOUNTER
# 37 "data/maps/ArtisanCave_B1F/scripts.pory"
	delay 40
# 38 "data/maps/ArtisanCave_B1F/scripts.pory"
	waitmoncry
# 39 "data/maps/ArtisanCave_B1F/scripts.pory"
	setwildbattle SPECIES_VIRIZION, 65, ITEM_FIST_PLATE
# 40 "data/maps/ArtisanCave_B1F/scripts.pory"
	dowildbattle
# 41 "data/maps/ArtisanCave_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 42 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq AC_Battle_Virizion_2
AC_Battle_Virizion_1:
# 45 "data/maps/ArtisanCave_B1F/scripts.pory"
	waitmessage
# 46 "data/maps/ArtisanCave_B1F/scripts.pory"
	releaseall
	return

AC_Battle_Virizion_2:
# 43 "data/maps/ArtisanCave_B1F/scripts.pory"
	call Virizion_Caught
	goto AC_Battle_Virizion_1


Virizion_Caught::
# 50 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_STATIC_VIRIZION
# 51 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 52 "data/maps/ArtisanCave_B1F/scripts.pory"
	removeobject 3
# 53 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

