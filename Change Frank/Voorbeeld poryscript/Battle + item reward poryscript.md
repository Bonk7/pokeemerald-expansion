script Route119_Eventscript_BattleFrank {
    trainerbattle_single(TRAINER_FRANK_119, "It has been a while.\n", "I lost again?", Route119_GiveExpCharm)
	msgbox(format("You've got some potential.\n Next time i will beat you!"), MSGBOX_NPC)
	end
}	

script Route119_GiveExpCharm {
	giveitem(ITEM_EXP_CHARM)
	msgbox("This is a gift for you. \nIt will help you gain more experience\p in battle.", MSGBOX_AUTOCLOSE)
	setflag(FLAG_RECEIVED_EXP_CHARM)
	end
}