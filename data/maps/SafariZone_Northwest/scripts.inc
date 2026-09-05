# 1 "data/maps/SafariZone_Northwest/scripts.pory"

# 2 "data/maps/SafariZone_Northwest/scripts.pory"
SafariZone_Northwest_MapScripts::
# 3 "data/maps/SafariZone_Northwest/scripts.pory"
	.byte 0
# 4 "data/maps/SafariZone_Northwest/scripts.pory"

# 5 "data/maps/SafariZone_Northwest/scripts.pory"
SafariZone_Northwest_EventScript_Man::
# 6 "data/maps/SafariZone_Northwest/scripts.pory"
	msgbox SafariZone_Northwest_Text_Man, MSGBOX_NPC
# 7 "data/maps/SafariZone_Northwest/scripts.pory"
	end

Safari_Battle_Landorus::
# 11 "data/maps/SafariZone_Northwest/scripts.pory"
	lockall
# 12 "data/maps/SafariZone_Northwest/scripts.pory"
	playmoncry SPECIES_LANDORUS, CRY_MODE_ENCOUNTER
# 13 "data/maps/SafariZone_Northwest/scripts.pory"
	delay 40
# 14 "data/maps/SafariZone_Northwest/scripts.pory"
	waitmoncry
# 15 "data/maps/SafariZone_Northwest/scripts.pory"
	setwildbattle SPECIES_LANDORUS, 65
# 16 "data/maps/SafariZone_Northwest/scripts.pory"
	dowildbattle
# 17 "data/maps/SafariZone_Northwest/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 18 "data/maps/SafariZone_Northwest/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Safari_Battle_Landorus_2
Safari_Battle_Landorus_1:
# 21 "data/maps/SafariZone_Northwest/scripts.pory"
	waitmessage
# 22 "data/maps/SafariZone_Northwest/scripts.pory"
	releaseall
	return

Safari_Battle_Landorus_2:
# 19 "data/maps/SafariZone_Northwest/scripts.pory"
	call Landorus_Caught
	goto Safari_Battle_Landorus_1


Landorus_Caught::
# 26 "data/maps/SafariZone_Northwest/scripts.pory"
	setflag FLAG_STATIC_LANDORUS
# 27 "data/maps/SafariZone_Northwest/scripts.pory"
	fadescreen FADE_TO_BLACK
# 28 "data/maps/SafariZone_Northwest/scripts.pory"
	removeobject 3
# 29 "data/maps/SafariZone_Northwest/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

