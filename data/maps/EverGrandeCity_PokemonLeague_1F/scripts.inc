# 1 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_MapScripts::
# 3 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
# 4 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.byte 0
# 6 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 7 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_OnTransition:
# 8 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
# 9 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
# 10 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
# 11 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 12 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 13 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
# 14 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_LEAGUE_GUARD_1, 9, 2
# 15 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_LEAGUE_GUARD_2, 10, 2
# 16 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 17 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 18 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
# 19 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_LEAGUE_NURSE
# 20 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 21 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 22 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitbuttonpress
# 23 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 24 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 25 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 26 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
# 27 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 28 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 29 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message gText_HowMayIServeYou
# 30 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 31 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
# 32 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 33 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 34 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 35 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 36 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.align 2
# 37 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Pokemart:
# 38 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 39 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 40 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 41 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 42 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 43 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 44 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 45 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 46 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_BRIGHTPOWDER
# 47 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_WHITE_HERB
# 48 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_QUICK_CLAW
# 49 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_SOOTHE_BELL
# 50 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 51 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 52 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_AMULET_COIN
# 53 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_CLEANSE_TAG
# 54 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_SMOKE_BALL
# 55 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FOCUS_BAND
# 56 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_LUCKY_EGG
# 57 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_SCOPE_LENS
# 58 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_LEFTOVERS
# 59 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_SHELL_BELL
# 60 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_WIDE_LENS
# 61 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MUSCLE_BAND
# 62 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_WISE_GLASSES
# 63 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_EXPERT_BELT
# 64 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_LIGHT_CLAY
# 65 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_LIFE_ORB
# 66 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_POWER_HERB
# 67 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FOCUS_SASH
# 68 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ZOOM_LENS
# 69 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_METRONOME
# 70 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_IRON_BALL
# 71 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_LAGGING_TAIL
# 72 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_DESTINY_KNOT
# 73 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_BLACK_SLUDGE
# 74 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_GRIP_CLAW
# 75 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_STICKY_BARB
# 76 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_SHED_SHELL
# 77 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_BIG_ROOT
# 78 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 79 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_RAZOR_FANG
# 80 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_EVIOLITE
# 81 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 82 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ROCKY_HELMET
# 83 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_AIR_BALLOON
# 84 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_RED_CARD
# 85 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_RING_TARGET
# 86 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_BINDING_BAND
# 87 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_EJECT_BUTTON
# 88 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_WEAKNESS_POLICY
# 89 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ASSAULT_VEST
# 90 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_SAFETY_GOGGLES
# 91 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ADRENALINE_ORB
# 92 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_TERRAIN_EXTENDER
# 93 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_PROTECTIVE_PADS
# 94 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_THROAT_SPRAY
# 95 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_EJECT_PACK
# 96 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_HEAVY_DUTY_BOOTS
# 97 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_BLUNDER_POLICY
# 98 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ROOM_SERVICE
# 99 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
# 100 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemartlistend
# 101 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 102 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
# 103 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ Its assumed the player has the remaining badges
# 104 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
# 105 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lockall
# 106 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
# 107 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 108 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
# 109 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
# 110 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
# 111 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 112 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 120
# 113 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
# 114 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 115 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_LEAGUE_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 116 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_LEAGUE_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 117 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 118 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 119 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 120 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
# 121 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 122 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitfanfare
# 123 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 124 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_1
# 125 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_2
# 126 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_ENTERED_ELITE_FOUR
# 127 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 128 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 129 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 130 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
# 131 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
# 132 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 133 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 134 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 135 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
# 136 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
# 137 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 138 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 139 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 140 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
# 141 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_FAILURE
# 142 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
# 143 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 144 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 145 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 146 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
# 147 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 148 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 149 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
# 150 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 151 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 152 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 153 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 154 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 155 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 156 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
# 157 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 158 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 159 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 160 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 161 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 162 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
# 163 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 164 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 165 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 166 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 167 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 168 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
# 169 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 170 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 171 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 172 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 173 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
# 174 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 175 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 176 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 177 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 178 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
# 179 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Beyond this point, only those TRAINERS\n"
# 180 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "who have collected all the GYM BADGES\l"
# 181 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "are permitted to enter.\p"
# 182 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "TRAINER, let us confirm that you have\n"
# 183 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "all the GYM BADGES.$"
# 184 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 185 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
# 186 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "You haven't obtained all the BADGES.\p"
# 187 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "If you're bound for the POKéMON\n"
# 188 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "LEAGUE, you must return with them.$"
# 189 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 190 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_GoForth:
# 191 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "TRAINER! Believe in yourself and your\n"
# 192 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "POKéMON, and go forth!$"
