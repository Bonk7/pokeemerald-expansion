# 1 "data/maps/MauvilleCity_Mart/scripts.pory"

# 2 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_MapScripts::
# 3 "data/maps/MauvilleCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_Mart/scripts.pory"

# 5 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_Clerk::
# 6 "data/maps/MauvilleCity_Mart/scripts.pory"
	lock
# 7 "data/maps/MauvilleCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/MauvilleCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/MauvilleCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemart MauvilleCity_Mart_Pokemart
# 11 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/MauvilleCity_Mart/scripts.pory"
	release
# 13 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 14 "data/maps/MauvilleCity_Mart/scripts.pory"

# 15 "data/maps/MauvilleCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Pokemart:
# 17 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 18 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 19 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 20 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 21 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_FAST_BALL
# 22 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 23 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_WATER_STONE
# 24 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 25 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 26 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 27 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_ICE_STONE
# 28 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_SUN_STONE
# 29 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_MOON_STONE
# 30 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 31 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 32 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 33 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 34 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 35 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_UPGRADE
# 36 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_UP_GRADE
# 37 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_PROTECTOR
# 38 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 39 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 40 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_METAL_COAT
# 41 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 42 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 43 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 44 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemartlistend
# 45 "data/maps/MauvilleCity_Mart/scripts.pory"

# 46 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_ExpertM::
# 47 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
# 48 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 49 "data/maps/MauvilleCity_Mart/scripts.pory"

# 50 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_Man::
# 51 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
# 52 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 53 "data/maps/MauvilleCity_Mart/scripts.pory"

# 54 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
# 55 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "There are items that temporarily\n"
# 56 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "elevate the stats of POKéMON.\p"
# 57 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "The ones I know you use in battle\n"
# 58 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "are X ATTACK and X DEFEND…\p"
# 59 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "I do believe that there are others\n"
# 60 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "like them.$"
# 61 "data/maps/MauvilleCity_Mart/scripts.pory"

# 62 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Text_DecisionsDetermineBattle:
# 63 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "Use a certain move, or use an item\n"
# 64 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "instead…\p"
# 65 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "The TRAINER's decisions determine how\n"
# 66 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "battles turn out, I think.$"
