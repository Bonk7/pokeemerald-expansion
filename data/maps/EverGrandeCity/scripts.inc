# 1 "data/maps/EverGrandeCity/scripts.pory"

# 2 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 3 "data/maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 4 "data/maps/EverGrandeCity/scripts.pory"
	.byte 0
# 5 "data/maps/EverGrandeCity/scripts.pory"

# 6 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 7 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 8 "data/maps/EverGrandeCity/scripts.pory"
	end
# 9 "data/maps/EverGrandeCity/scripts.pory"

# 10 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 11 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 12 "data/maps/EverGrandeCity/scripts.pory"
	end
# 13 "data/maps/EverGrandeCity/scripts.pory"

# 14 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 15 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 16 "data/maps/EverGrandeCity/scripts.pory"
	end
# 17 "data/maps/EverGrandeCity/scripts.pory"

# 18 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 19 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 20 "data/maps/EverGrandeCity/scripts.pory"
	end
# 21 "data/maps/EverGrandeCity/scripts.pory"

# 22 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 23 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 24 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 25 "data/maps/EverGrandeCity/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity/scripts.pory"

# 27 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 28 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING VICTORY ROAD$"
# 29 "data/maps/EverGrandeCity/scripts.pory"

# 30 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 31 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING POKéMON LEAGUE\n"
# 32 "data/maps/EverGrandeCity/scripts.pory"
	.string "CENTER GATE$"
# 33 "data/maps/EverGrandeCity/scripts.pory"

# 34 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 35 "data/maps/EverGrandeCity/scripts.pory"
	.string "EVER GRANDE CITY\p"
# 36 "data/maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 37 "data/maps/EverGrandeCity/scripts.pory"
	.string "and POKéMON.”$"
# 38 "data/maps/EverGrandeCity/scripts.pory"

# 39 "data/maps/EverGrandeCity/scripts.pory"
BattleFrankAfterChampion_Intro:
# 40 "data/maps/EverGrandeCity/scripts.pory"
	.string "I am so proud of you!\nYou are the best trainer in the world!\pThat is... if i did not exist\pNow it is time for your final test!\pI won't hold back!$"
# 41 "data/maps/EverGrandeCity/scripts.pory"

# 42 "data/maps/EverGrandeCity/scripts.pory"
BattleFrankAfterChampion_Defeat:
# 43 "data/maps/EverGrandeCity/scripts.pory"
	.string "Will you...$"
# 44 "data/maps/EverGrandeCity/scripts.pory"

# 45 "data/maps/EverGrandeCity/scripts.pory"
BattleFrankAfterChampion_NotEnough:
# 46 "data/maps/EverGrandeCity/scripts.pory"
	.string "You need at least two Pokémon to battle!$"

BattleFrankAfterChampion::
# 50 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_set FLAG_IS_CHAMPION, BattleFrankAfterChampion_4
BattleFrankAfterChampion_3:
# 54 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_unset FLAG_IS_CHAMPION, BattleFrankAfterChampion_2
	return

BattleFrankAfterChampion_1:
# 51 "data/maps/EverGrandeCity/scripts.pory"
	msgbox BattleFrankAfterChampion_Text_0, MSGBOX_AUTOCLOSE
# 52 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_double TRAINER_FRANK_EGC, BattleFrankAfterChampion_Intro, BattleFrankAfterChampion_Defeat, BattleFrankAfterChampion_NotEnough, BattleFrankAfterChampionAfterBattle
	return

BattleFrankAfterChampion_2:
# 55 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_unset FLAG_TEMP_5, BattleFrankAfterChampion_7
	return

BattleFrankAfterChampion_4:
# 50 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_unset FLAG_FRANK_EGC_DEFEATED, BattleFrankAfterChampion_1
	goto BattleFrankAfterChampion_3

BattleFrankAfterChampion_7:
# 56 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_TEMP_5
# 57 "data/maps/EverGrandeCity/scripts.pory"
	msgbox BattleFrankAfterChampion_Text_1, MSGBOX_AUTOCLOSE
	return


EGC_Eventscript_BattleIlse::
# 63 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_double TRAINER_ILSE_EGC, EGC_Eventscript_BattleIlse_Text_0, EGC_Eventscript_BattleIlse_Text_1, EGC_Eventscript_BattleIlse_Text_2, EGC_GIVEMEWTWO
# 64 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_Eventscript_BattleIlse_Text_3, MSGBOX_NPC
	end


EGC_GIVEMEWTWO::
# 70 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEWTWO_MEGA_Y
# 71 "data/maps/EverGrandeCity/scripts.pory"
	givemon SPECIES_MEWTWO_MEGA_Y, 90, ITEM_LIFE_ORB, ITEM_LOVE_BALL, NATURE_MODEST, , , , , , , , , 31, 31, 31, 31, 31, 31, MOVE_PSYSTRIKE, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, TRUE
# 72 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EGC_GIVEMEWTWO_2
EGC_GIVEMEWTWO_1:
# 75 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EGC_GIVEMEWTWO_5
EGC_GIVEMEWTWO_4:
# 78 "data/maps/EverGrandeCity/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 80 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_PARTY:
# 81 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_0, MSGBOX_AUTOCLOSE
# 82 "data/maps/EverGrandeCity/scripts.pory"
	showmonpic SPECIES_MEWTWO_MEGA_Y, 0, 0
# 83 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_1, MSGBOX_YESNO
# 84 "data/maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 85 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EGC_GIVEMEWTWO_8
EGC_GIVEMEWTWO_7:
# 88 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 89 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 90 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_DONE
# 92 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_PC:
# 93 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_0, MSGBOX_AUTOCLOSE
# 94 "data/maps/EverGrandeCity/scripts.pory"
	showmonpic SPECIES_MEWTWO_MEGA_Y, 0, 0
# 95 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_1, MSGBOX_YESNO
# 96 "data/maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 97 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EGC_GIVEMEWTWO_11
EGC_GIVEMEWTWO_10:
# 100 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 101 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_TRANSFERRED
# 103 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_TRANSFERRED:
# 104 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_TransferredToPC
# 105 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_DONE
# 107 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_DONE:
	end

EGC_GIVEMEWTWO_2:
# 73 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_PARTY
	goto EGC_GIVEMEWTWO_1

EGC_GIVEMEWTWO_5:
# 76 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_PC
	goto EGC_GIVEMEWTWO_4

EGC_GIVEMEWTWO_8:
# 86 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_DONE
	goto EGC_GIVEMEWTWO_7

EGC_GIVEMEWTWO_11:
# 98 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_TRANSFERRED
	goto EGC_GIVEMEWTWO_10


BattleFrankAfterChampionAfterBattle::
BattleFrankAfterChampionAfterBattle_3:
# 113 "data/maps/EverGrandeCity/scripts.pory"
	msgbox BattleFrankAfterChampionAfterBattle_Text_0, MSGBOX_YESNO
# 114 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq BattleFrankAfterChampionAfterBattle_3
# 115 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_SWEET_HEART
# 116 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_HEART_SCALE
# 117 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_MEGA_RING
# 118 "data/maps/EverGrandeCity/scripts.pory"
	msgbox BattleFrankAfterChampionAfterBattle_Text_1, MSGBOX_AUTOCLOSE
# 119 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_FRANK_EGC_DEFEATED
	return


BattleFrankAfterChampion_Text_0:
# 51 "data/maps/EverGrandeCity/scripts.pory"
	.string "Frank: You really became\nthe Champion, {PLAYER}!$"

BattleFrankAfterChampion_Text_1:
# 57 "data/maps/EverGrandeCity/scripts.pory"
	.string "Talk to me when you have \nbecome the champion!$"

EGC_Eventscript_BattleIlse_Text_0:
# 63 "data/maps/EverGrandeCity/scripts.pory"
	.string "Hey my name is Ilse,\n and i will beat you!$"

EGC_Eventscript_BattleIlse_Text_1:
# 63 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ah.. you are so lucky!$"

EGC_Eventscript_BattleIlse_Text_2:
# 63 "data/maps/EverGrandeCity/scripts.pory"
	.string "You need at least\ntwo Pokémon to battle!$"

EGC_Eventscript_BattleIlse_Text_3:
# 64 "data/maps/EverGrandeCity/scripts.pory"
	.string "Behind Victory Road lies the\n"
	.string "Pokemon League!\p"
	.string "I think you can defeat the champion!$"

EGC_GIVEMEWTWO_Text_0:
# 81 "data/maps/EverGrandeCity/scripts.pory"
	.string "Mewtwo wants to help you.\nPlease take good care of him.$"

EGC_GIVEMEWTWO_Text_1:
# 83 "data/maps/EverGrandeCity/scripts.pory"
	.string "Give Mewtwo a nickname?$"

BattleFrankAfterChampionAfterBattle_Text_0:
# 113 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}, will you marry me?$"

BattleFrankAfterChampionAfterBattle_Text_1:
# 118 "data/maps/EverGrandeCity/scripts.pory"
	.string "{PLAYER}, ik hou van jou!\pDe mega ring had je al,\nmaar je krijgt nu een echte.$"
