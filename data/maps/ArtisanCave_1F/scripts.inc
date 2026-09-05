# 1 "data/maps/ArtisanCave_1F/scripts.pory"

# 2 "data/maps/ArtisanCave_1F/scripts.pory"
ArtisanCave_1F_MapScripts::
# 3 "data/maps/ArtisanCave_1F/scripts.pory"
	.byte 0

AC_Battle_Terrakion::
# 7 "data/maps/ArtisanCave_1F/scripts.pory"
	lockall
# 8 "data/maps/ArtisanCave_1F/scripts.pory"
	playmoncry SPECIES_TERRAKION, CRY_MODE_ENCOUNTER
# 9 "data/maps/ArtisanCave_1F/scripts.pory"
	delay 40
# 10 "data/maps/ArtisanCave_1F/scripts.pory"
	waitmoncry
# 11 "data/maps/ArtisanCave_1F/scripts.pory"
	setwildbattle SPECIES_TERRAKION, 65, ITEM_FIST_PLATE
# 12 "data/maps/ArtisanCave_1F/scripts.pory"
	dowildbattle
# 13 "data/maps/ArtisanCave_1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/ArtisanCave_1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq AC_Battle_Terrakion_2
AC_Battle_Terrakion_1:
# 17 "data/maps/ArtisanCave_1F/scripts.pory"
	waitmessage
# 18 "data/maps/ArtisanCave_1F/scripts.pory"
	releaseall
	return

AC_Battle_Terrakion_2:
# 15 "data/maps/ArtisanCave_1F/scripts.pory"
	call Terrakion_Caught
	goto AC_Battle_Terrakion_1


Terrakion_Caught::
# 22 "data/maps/ArtisanCave_1F/scripts.pory"
	setflag FLAG_STATIC_TERRAKION
# 23 "data/maps/ArtisanCave_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 24 "data/maps/ArtisanCave_1F/scripts.pory"
	removeobject 2
# 25 "data/maps/ArtisanCave_1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

