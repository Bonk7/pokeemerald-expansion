# 1 "data/maps/IlexShrine/scripts.pory"

# 2 "data/maps/IlexShrine/scripts.pory"
IlexShrine_MapScripts::
# 3 "data/maps/IlexShrine/scripts.pory"
	.byte 0

Route101_Battle_Celebi::
# 8 "data/maps/IlexShrine/scripts.pory"
	lockall
# 9 "data/maps/IlexShrine/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 10 "data/maps/IlexShrine/scripts.pory"
	delay 40
# 11 "data/maps/IlexShrine/scripts.pory"
	waitmoncry
# 12 "data/maps/IlexShrine/scripts.pory"
	setwildbattle SPECIES_CELEBI, 14, ITEM_TWISTEDSPOON
# 13 "data/maps/IlexShrine/scripts.pory"
	dowildbattle
# 14 "data/maps/IlexShrine/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/IlexShrine/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route101_Battle_Celebi_2
Route101_Battle_Celebi_1:
# 18 "data/maps/IlexShrine/scripts.pory"
	waitmessage
# 19 "data/maps/IlexShrine/scripts.pory"
	releaseall
	return

Route101_Battle_Celebi_2:
# 16 "data/maps/IlexShrine/scripts.pory"
	call Celebi_Caught
	goto Route101_Battle_Celebi_1


Celebi_Caught::
# 23 "data/maps/IlexShrine/scripts.pory"
	setflag FLAG_STATIC_CELEBI
# 24 "data/maps/IlexShrine/scripts.pory"
	fadescreen FADE_TO_BLACK
# 25 "data/maps/IlexShrine/scripts.pory"
	removeobject 9
# 26 "data/maps/IlexShrine/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

