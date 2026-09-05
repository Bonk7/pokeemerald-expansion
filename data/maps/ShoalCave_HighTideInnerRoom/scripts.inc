# 1 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"

# 2 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
ShoalCave_HighTideInnerRoom_MapScripts::
# 3 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	.byte 0

SC_Battle_Kyurem::
# 7 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	lockall
# 8 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
# 9 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	delay 40
# 10 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	waitmoncry
# 11 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	setwildbattle SPECIES_KYUREM, 68, ITEM_DNA_SPLICERS
# 12 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	dowildbattle
# 13 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SC_Battle_Kyurem_2
SC_Battle_Kyurem_1:
# 17 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	waitmessage
# 18 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	releaseall
	return

SC_Battle_Kyurem_2:
# 15 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	call Kyurem_Caught
	goto SC_Battle_Kyurem_1


Kyurem_Caught::
# 22 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	setflag FLAG_STATIC_KYUREM
# 23 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 24 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	removeobject 1
# 25 "data/maps/ShoalCave_HighTideInnerRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

