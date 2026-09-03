# 1 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_MapScripts::
# 3 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	.byte 0

AbandonedShip_Battle_Victini::
# 7 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	lockall
# 8 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
# 9 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	delay 40
# 10 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	waitmoncry
# 11 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setwildbattle SPECIES_VICTINI, 58, ITEM_CHARCOAL
# 12 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	dowildbattle
# 13 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq AbandonedShip_Battle_Victini_2
AbandonedShip_Battle_Victini_1:
# 17 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	waitmessage
# 18 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	releaseall
	return

AbandonedShip_Battle_Victini_2:
# 15 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	call Victini_Caught
	goto AbandonedShip_Battle_Victini_1


Victini_Caught::
# 22 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setflag FLAG_STATIC_VICTINI
# 23 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 24 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	removeobject 2
# 25 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

