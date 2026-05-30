# 1 "data/maps/SlateportCity_Mart/scripts.pory"

# 2 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_MapScripts::
# 3 "data/maps/SlateportCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SlateportCity_Mart/scripts.pory"

# 5 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_EventScript_Clerk::
# 6 "data/maps/SlateportCity_Mart/scripts.pory"
	lock
# 7 "data/maps/SlateportCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/SlateportCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/SlateportCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/SlateportCity_Mart/scripts.pory"
	pokemart SlateportCity_Mart_Pokemart
# 11 "data/maps/SlateportCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/SlateportCity_Mart/scripts.pory"
	release
# 13 "data/maps/SlateportCity_Mart/scripts.pory"
	end
# 14 "data/maps/SlateportCity_Mart/scripts.pory"

# 15 "data/maps/SlateportCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_Pokemart:
# 17 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 19 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_WATER_STONE
# 20 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 21 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_THUNDERSTONE
# 22 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 23 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_ICE_STONE
# 24 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_SUN_STONE
# 25 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_MOON_STONE
# 26 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 27 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 28 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 29 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 30 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 31 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_UPGRADE
# 32 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_UP_GRADE
# 33 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_PROTECTOR
# 34 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 35 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 36 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 37 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 38 "data/maps/SlateportCity_Mart/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 39 "data/maps/SlateportCity_Mart/scripts.pory"
	pokemartlistend
# 40 "data/maps/SlateportCity_Mart/scripts.pory"

# 41 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_EventScript_BlackBelt::
# 42 "data/maps/SlateportCity_Mart/scripts.pory"
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
# 43 "data/maps/SlateportCity_Mart/scripts.pory"
	end
# 44 "data/maps/SlateportCity_Mart/scripts.pory"

# 45 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_EventScript_Man::
# 46 "data/maps/SlateportCity_Mart/scripts.pory"
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
# 47 "data/maps/SlateportCity_Mart/scripts.pory"
	end
# 48 "data/maps/SlateportCity_Mart/scripts.pory"

# 49 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
# 50 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "The MARKET does have some interesting\n"
# 51 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "merchandise.\p"
# 52 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "But there are some items you can only\n"
# 53 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "get at a POKéMON MART.$"
# 54 "data/maps/SlateportCity_Mart/scripts.pory"

# 55 "data/maps/SlateportCity_Mart/scripts.pory"
SlateportCity_Mart_Text_GreatBallIsBetter:
# 56 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "A GREAT BALL is better than a POKé BALL\n"
# 57 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "at catching POKéMON.\p"
# 58 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "With this, I should be able to get that\n"
# 59 "data/maps/SlateportCity_Mart/scripts.pory"
	.string "elusive POKéMON…$"
