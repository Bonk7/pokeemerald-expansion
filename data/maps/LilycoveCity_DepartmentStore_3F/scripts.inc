# 1 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
# 6 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 10 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
# 11 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 13 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 15 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 16 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
# 17 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTEIN
# 18 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALCIUM
# 19 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON
# 20 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZINC
# 21 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CARBOS
# 22 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HP_UP
# 23 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 24 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 25 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 26 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 27 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 28 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 29 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LAX_MINT
# 30 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 31 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 32 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MILD_MINT
# 33 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RASH_MINT
# 34 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 35 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALM_MINT
# 36 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 37 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 38 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 39 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_TIMID_MINT
# 40 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 41 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 42 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 43 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
# 44 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 45 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 46 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
# 47 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 48 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 49 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 50 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 51 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
# 52 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 53 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 54 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 55 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 56 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 57 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
# 58 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SPEED
# 59 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 60 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 61 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 62 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 63 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 64 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 65 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 66 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 67 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
# 68 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
# 69 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 70 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 71 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
# 72 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
# 73 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 74 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 75 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_Woman::
# 76 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
# 77 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 78 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 79 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
# 80 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "For quickly toughening up POKéMON,\n"
# 81 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "items are the best.\p"
# 82 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "PROTEIN boosts ATTACK,\n"
# 83 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and CALCIUM raises SP. ATK.$"
# 84 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 85 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
# 86 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I want my POKéMON to have more\n"
# 87 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "endurance.\p"
# 88 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I'm trying to decide whether to raise\n"
# 89 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"
# 90 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 91 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
# 92 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I gave a CARBOS to my POKéMON,\n"
# 93 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and its SPEED went up.$"
