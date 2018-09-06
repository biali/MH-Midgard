new_1-1,129,128,1	script	Smithy	813,{
	function BuildMenu; function CheckDoableEquips;
	function CreateItem;

//	mes getequipsharpness(EQI_HAND_R);
//	if(select("Sharpen my"+getitemname(getequipid(EQI_HAND_R))+":Cancel") == 1)
//		sharpenequip(EQI_HAND_R);
//	mes getequipsharpness(EQI_HAND_R);

	getitembound 912,5,Bound_Char;

	mes blue("[ Smithy ]");
	mes "How is your gear holding?";
	while (1) {
		switch(select("Forge Equipment:Upgrade Equipment:"+red("Goodbye"))){
		case 1: // FORGE EQUIPMENT
			while (.@x = select("Forge Weapon:Forge Armor:Forge Charms:"+red("<<<")) < 4) {
				switch (.@x) {
				case 1: // FORGE WEAPON
					while(.@op = select("Daggers:Bows:"+red("<<<")) < 3){
						.@menu$ = BuildMenu(.@op) + red("<<<");
						//the function BuildMenu also feeds the var @forjable with the
						while(.@c = select(.@menu$) < getarraysize(@forjable)) {
							.@c = getelementofarray(@forjable,.@c);						
							.@mats$ = ".cra" + .@c;
							next;
							callsub L_MainScript,.@mats$,.@c,-1,@npc$;
						}
					}
				break;
				case 2:
				case 3:
			//	break;
				}
			} 
		break;
		case 2: // UPGRADE EQUIPMENT
			.@hand = EQI_HAND_R; //9; // Default to Right Hand;
			
			//TODO: Should we check on both hands?
			if(getequipid(EQI_HAND_R) == -1) {
				if(getequipid(EQI_HAND_L) == -1 || getiteminfo(getequipid(EQI_HAND_R),11) != W_DAGGER) {
					next;
					mes blue("[ Smithy ]");
					mes "Sorry, pal. You are wielding no weapons, how am I supposed to know what you want to upgrade?";
					close;
				} else if(getiteminfo(getequipid(EQI_HAND_R),11) == W_DAGGER)
					.@hand = EQI_HAND_L;//8;
			}

			switch(getiteminfo(getequipid(EQI_HAND_R),11)) {
				case W_BOW:
					.@list$ = "iron_bows";
					.@npc$ = "iron_bows_mats";
					break;
				case W_DAGGER:
					.@list$ = "iron_daggers";
					.@npc$ = "iron_daggers_mats";
					if(getequipid(EQI_HAND_L) > 0 && getiteminfo(getequipid(EQI_HAND_L),2) == 5) {
						next;
						mes "^0000AA[ Smithy ]^000000";
						mes "Which one you'd like to upgrade?";
						if(select(getitemname(getequipid(EQI_HAND_R)) + ":" + getitemname(getequipid(EQI_HAND_L))) == 2) 
							.@hand = EQI_HAND_L;//8;
					}
					break;
			}
			.@delme = getequipid(.@hand);
			.@c = callfunc(.@list$,.@delme); //Id do futuro equipamento
			while (.@c != -1){
				.@mats$ = ".upg" + .@c; 	// Array com os materiais para evoluir o equipamento
				next;
				callsub L_MainScript,.@mats$,.@c,.@hand,.@npc$;
			}
		break;
		case 3:
			close;
		}
	}
	end;


L_MainScript:
	.@mats$ = getarg(0);
	.@c 	= getarg(1,0);
	.@hand 	= getarg(2,-1);
	.@npc$	= getarg(3,strnpcinfo(1));

	mes blue("[ Smithy ]");
	mes "";
	mes "Weapon: " + getitemname(.@c);
	mes "Requests:";
	//getelementofarray(getvariableofnpc(getd(.@mats$), "iron_daggers_mats"),0)
	mes (Zeny >= getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),0))?
		green(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),0)) + " Zeny":
		red(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),0)) + " Zeny";
	for (.@l=1; .@l < getarraysize(getvariableofnpc(getd(.@mats$), .@npc$)); .@l=.@l+2) {
		.@qt=.@l+1;
		mes (countitem(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@l)) >= getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@qt))?
		green(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@qt) + "x " + getitemname(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@l))):
		red(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@qt) + "x " + getitemname(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@l)));
	}

	if(CheckDoableEquips(.@mats$,.@npc$) == 0) {
		next;
		mes "^0000AA[ Smithy ]^000000";
		mes "I am afraid you are short on Zeny or Materials for that one. Check what I've marked in "+red("Red")+"... Those are the ones you'd need to go after.";
		close;
	}

	if(select("Smithy, make me this one!:Nevermind, I will come back later.") == 1) {
		next;
		mes blue("[ Smithy ]");
		mes "Alright, lets do get into it.";
		mes " ";

		deletearray .@list[0],127;
		if (.@hand > -1)
			unequip .@hand;
		if (Zeny >= getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),0))
			setarray .@list[0],getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),0);

		for (.@i=1; .@i < getarraysize(getvariableofnpc(getd(.@mats$), .@npc$)); .@i=.@i+2) {
			if(countitem(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@i)) >= getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),(.@i+1))) {
				copyarray .@list[.@i], getvariableofnpc(getd(.@mats$+"["+.@i+"]"), .@npc$),2;
			}
		}
		if(getarraysize(.@list) == getarraysize(getvariableofnpc(getd(.@mats$), .@npc$))) {
			Zeny = Zeny - getelementofarray(.@list,0);
			logmes strcharinfo(0) + " pagou " + getelementofarray(.@list,0) + " pelo upgrade de " + .@c;
			for (.@i=1; .@i < getarraysize(.@list); .@i=.@i+2) {
				.@itemid	= getelementofarray(.@list,.@i);
				.@qt 		= getelementofarray(.@list,(.@i+1));
				delitem .@itemid,.@qt;
				logmes strcharinfo(0) + " pagou " + .@qt +"x " + .@itemid + " pelo upgrade de " + .@c;
			}
			if (CreateItem(.@c) > 0) {
				mes "All done! Thank you!";	
			} else {
				mes "Sorry, something went wrong in the end...";
				mes "Please tell a GM about this, I may need a day off.";
				mes "Regarding your items, no worries, they shall be able to refund you.";
				logmes "Smithy Crashed: Attached char:" + strcharinfo(0) + ". They will need refund for items and zenys. Check logs."; 
				close;
			}
			
			close;
		} else {
			mes "^0000AA[ Smithy ]^000000";
			mes "Err... Sorry but I thought we were pals? Get lost!";
			close;
		}
	}
	end;


	// =========
	// BUILD MENU
	// ===================
	function BuildMenu {
		.@op = getarg(0);
		deletearray @ids[0],127;
		deletearray @forjable[0],127;
		setarray @forjable[0],-1;

		switch(.@op) {
			case 1: //.@op 1 = Daggers
				@npc$ = "iron_daggers_mats";
				switch(HR){
					case 3:
						setarray @forjable[getarraysize(@forjable)],19827;
					case 2:
					case 1:
						setarray @forjable[getarraysize(@forjable)],19800;
						break;
					default:
						setarray @forjable[0],-1,19800,19827;
						break;
				}
				break;
			case 2: //.@op 2 = Bows
				@npc$ = "iron_bows_mats";
				switch(HR){
					case 3:
						setarray @forjable[getarraysize(@forjable)],19873;
					case 2:
					case 1:
						setarray @forjable[getarraysize(@forjable)],19860;
						break;
					default:
						setarray @forjable[0],-1,19860,19873;
						break;
				}
				break;
		}

		for (.@i=1; .@i < getarraysize(@forjable); .@i++) {
			.@mats$ = ".cra" + getelementofarray(@forjable,.@i);

			if(CheckDoableEquips(.@mats$,@npc$) == 1) 
				.@menu$ = .@menu$ + green(getitemname(getelementofarray(@forjable,.@i)))+":";
			else
				.@menu$ = .@menu$ + red(getitemname(getelementofarray(@forjable,.@i)))+":";
		}

		//it also returns the array @ids containing the item_ids in .@menu$;
		return .@menu$;
	}


	function	CheckDoableEquips	{
		.@mats$	= getarg(0);	//nome da array contendo os itens para evoluir o equip
		.@npc$ 	= getarg(1); 	//nome do npc contendo as listas de materiais

		if(getarraysize(getvariableofnpc(getd(.@mats$), .@npc$)) == 0)
			return 0;

		if (Zeny < getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),0))
			return 0;

		for(.@i=1; .@i < getarraysize(getvariableofnpc(getd(.@mats$), .@npc$)); .@i=.@i+2) {
			.@qt=.@i+1;
			if (countitem(getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@i)) < getelementofarray(getvariableofnpc(getd(.@mats$), .@npc$),.@qt))
				return 0;
		}

		return 1;
	}

	function	CreateItem	{
		.@c = getarg(0,-1);
		//To create elemental weapon, follow the recipe bellow:
		// That's the number of star crumbs in a weapon.
	    //.@sc = 2; //Very very strong
	    // That's the number of elemental property of the weapon.
	    // 1 - Ice, 2 - Earth 3 - Fire 4 - Wind
	    //.@ele = 1;
	    // And that's the wacky formula that makes them into
	    // a single number.    
	    //.@card2 = .@ele+((.@sc*5)<<8);
		//set(.@cID, getbattleflag("ferus"));
		//getitem2 1201,1,1,0,0,255,.@card2,.@cID&0xffff,(.@cID>>16)&0xffff;
		
		//getitembound2 <item id>,<amount>,<identify>,<refine>,<attribute>,<card1>,<card2>,<card3>,<card4>,<bound type>{,<account ID>};
		if(.@c > 0) {
			getitembound2 .@c,1,1,0,0,0,0,0,0,Bound_Char;
			deletearray @ids[0],127;
			specialeffect 154;
			sleep2 1000;
		}

		return .@c;
	}
}


new_1-1,130,133,1	shop	Armors and Weapons	63,503:500,19800:2500,19860:2500,12004:3000,1065:100;



