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

EGC_Eventscript_BattleIlse::
# 42 "data/maps/EverGrandeCity/scripts.pory"
	trainerbattle_single TRAINER_ILSE_EGC, EGC_Eventscript_BattleIlse_Text_0, EGC_Eventscript_BattleIlse_Text_1, EGC_GIVEMEWTWO
# 43 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_Eventscript_BattleIlse_Text_2, MSGBOX_NPC
	end


EGC_GIVEMEWTWO::
# 49 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEWTWO_MEGA_Y
# 50 "data/maps/EverGrandeCity/scripts.pory"
	givemon SPECIES_MEWTWO_MEGA_Y, 90, ITEM_LIFE_ORB, ITEM_LOVE_BALL, NATURE_MODEST, , , , , , , , , 31, 31, 31, 31, 31, 31, MOVE_PSYSTRIKE, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, TRUE
# 51 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq EGC_GIVEMEWTWO_2
EGC_GIVEMEWTWO_1:
# 54 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq EGC_GIVEMEWTWO_5
EGC_GIVEMEWTWO_4:
# 57 "data/maps/EverGrandeCity/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 59 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_PARTY:
# 60 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_0, MSGBOX_AUTOCLOSE
# 61 "data/maps/EverGrandeCity/scripts.pory"
	showmonpic SPECIES_MEWTWO_MEGA_Y, 0, 0
# 62 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_1, MSGBOX_YESNO
# 63 "data/maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 64 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EGC_GIVEMEWTWO_8
EGC_GIVEMEWTWO_7:
# 67 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 68 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 69 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_DONE
# 71 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_PC:
# 72 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_0, MSGBOX_AUTOCLOSE
# 73 "data/maps/EverGrandeCity/scripts.pory"
	showmonpic SPECIES_MEWTWO_MEGA_Y, 0, 0
# 74 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EGC_GIVEMEWTWO_Text_1, MSGBOX_YESNO
# 75 "data/maps/EverGrandeCity/scripts.pory"
	hidemonpic
# 76 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq EGC_GIVEMEWTWO_11
EGC_GIVEMEWTWO_10:
# 79 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 80 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_TRANSFERRED
# 82 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_TRANSFERRED:
# 83 "data/maps/EverGrandeCity/scripts.pory"
	call Common_EventScript_TransferredToPC
# 84 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_DONE
# 86 "data/maps/EverGrandeCity/scripts.pory"
EGC_GIVEMEWTWO_DONE:
	end

EGC_GIVEMEWTWO_2:
# 52 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_PARTY
	goto EGC_GIVEMEWTWO_1

EGC_GIVEMEWTWO_5:
# 55 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_PC
	goto EGC_GIVEMEWTWO_4

EGC_GIVEMEWTWO_8:
# 65 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_DONE
	goto EGC_GIVEMEWTWO_7

EGC_GIVEMEWTWO_11:
# 77 "data/maps/EverGrandeCity/scripts.pory"
	goto EGC_GIVEMEWTWO_TRANSFERRED
	goto EGC_GIVEMEWTWO_10


EGC_Eventscript_BattleIlse_Text_0:
# 42 "data/maps/EverGrandeCity/scripts.pory"
	.string "Hey my name is Ilse,\n and i will beat you!$"

EGC_Eventscript_BattleIlse_Text_1:
# 42 "data/maps/EverGrandeCity/scripts.pory"
	.string "Ah.. you are so lucky!$"

EGC_Eventscript_BattleIlse_Text_2:
# 43 "data/maps/EverGrandeCity/scripts.pory"
	.string "Behind Victory Road lies the\n"
	.string "Pokemon League!\p"
	.string "I think you can defeat the champion!$"

EGC_GIVEMEWTWO_Text_0:
# 60 "data/maps/EverGrandeCity/scripts.pory"
	.string "Mewtwo wants to help you.\nPlease take good care of him.$"

EGC_GIVEMEWTWO_Text_1:
# 62 "data/maps/EverGrandeCity/scripts.pory"
	.string "Give Mewtwo a nickname?$"
