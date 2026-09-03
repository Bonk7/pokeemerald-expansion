# 1 "data/maps/Route133/scripts.pory"

# 2 "data/maps/Route133/scripts.pory"
Route133_MapScripts::
# 3 "data/maps/Route133/scripts.pory"
	.byte 0
# 4 "data/maps/Route133/scripts.pory"

# 5 "data/maps/Route133/scripts.pory"
Route133_EventScript_Franklin::
# 6 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
# 7 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/Route133/scripts.pory"
	end
# 9 "data/maps/Route133/scripts.pory"

# 10 "data/maps/Route133/scripts.pory"
Route133_EventScript_Debra::
# 11 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
# 12 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/Route133/scripts.pory"
	end
# 14 "data/maps/Route133/scripts.pory"

# 15 "data/maps/Route133/scripts.pory"
Route133_EventScript_Linda::
# 16 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
# 17 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route133/scripts.pory"
	end
# 19 "data/maps/Route133/scripts.pory"

# 20 "data/maps/Route133/scripts.pory"
Route133_EventScript_Warren::
# 21 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
# 22 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route133/scripts.pory"
	end
# 24 "data/maps/Route133/scripts.pory"

# 25 "data/maps/Route133/scripts.pory"
Route133_EventScript_Beck::
# 26 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
# 27 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route133/scripts.pory"
	end
# 29 "data/maps/Route133/scripts.pory"

# 30 "data/maps/Route133/scripts.pory"
Route133_EventScript_Mollie::
# 31 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
# 32 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route133/scripts.pory"
	end
# 34 "data/maps/Route133/scripts.pory"

# 35 "data/maps/Route133/scripts.pory"
Route133_EventScript_Conor::
# 36 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
# 37 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route133/scripts.pory"
	end

Route133_Battle_Lugia::
# 43 "data/maps/Route133/scripts.pory"
	lockall
# 44 "data/maps/Route133/scripts.pory"
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
# 45 "data/maps/Route133/scripts.pory"
	delay 40
# 46 "data/maps/Route133/scripts.pory"
	waitmoncry
# 47 "data/maps/Route133/scripts.pory"
	setwildbattle SPECIES_LUGIA, 95, ITEM_MASTER_BALL
# 48 "data/maps/Route133/scripts.pory"
	dowildbattle
# 49 "data/maps/Route133/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 50 "data/maps/Route133/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Route133_Battle_Lugia_2
Route133_Battle_Lugia_1:
# 53 "data/maps/Route133/scripts.pory"
	waitmessage
# 54 "data/maps/Route133/scripts.pory"
	releaseall
	return

Route133_Battle_Lugia_2:
# 51 "data/maps/Route133/scripts.pory"
	call Lugia_Caught
	goto Route133_Battle_Lugia_1


Lugia_Caught::
# 58 "data/maps/Route133/scripts.pory"
	setflag FLAG_STATIC_LUGIA
# 59 "data/maps/Route133/scripts.pory"
	fadescreen FADE_TO_BLACK
# 60 "data/maps/Route133/scripts.pory"
	removeobject 11
# 61 "data/maps/Route133/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return

