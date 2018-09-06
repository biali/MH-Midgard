//new_1-1,130,134,1	script	#SmithyControl	413,{
//	checkresist; 
//	for (.@i=0; .@i<11; .@i++) {
//		debugmes "Resistencias : " + $@elementalresistance[.@i];
//	}	
//	end;
//}


new_1-1,129,128,1	script	Smithy	813,{
	function BuildMenu; function BuildMenuItemIds; function GetUpgradeList; function CheckDoableEquips;
	function CreateItem;

	mes getequipsharpness(EQI_HAND_R);
	if(select("Sharpen my"+getitemname(getequipid(EQI_HAND_R))+":Cancel") == 1)
		sharpenequip(EQI_HAND_R);
	mes getequipsharpness(EQI_HAND_R);

//		.@sc = 0;
//		  // 1 - Ice, 2 - Earth 3 - Fire 4 - Wind
//	    .@ele = 1;
//	    // And that's the wacky formula that makes them into
//	    // a single number.    
//	    .@card2 = .@ele+((.@sc*5)<<8);
//		//set(.@cID, getbattleflag("ferus"));
//		getitem2 1202,1,1,0,0,255,.@card2,0,0;
		
		//getitembound2 <item id>,<amount>,<identify>,<refine>,<attribute>,<card1>,<card2>,<card3>,<card4>,<bound type>{,<account ID>};
		//getitembound2 .@c,1,1,0,0,0,0,0,0,Bound_Char;

	mes blue("[ Smithy ]");
	mes "How is your gear holding?";
	while (1) {
		switch(select("Forge Equipment:Upgrade Equipment:"+red("Goodbye"))){
		case 1: // FORGE EQUIPMENT
			while (.@x = select("Forge Weapon:Forge Armor:Forge Charms:"+red("<<<")) < 4) {
				switch (.@x) {
				case 1: // FORGE WEAPON
					while ((.@op = select("Daggers:Bows:"+red("<<<"))) < getarraysize(.weapons$)) {
						.@menu$ = BuildMenu(getelementofarray(.weapons$,.@op)) + red("<<<");
						//the function BuildMenu also feeds the var @ids with the
						//item_ids of equips in .@menu$
						.@c = select(.@menu$);
						while(.@c < getarraysize(@ids)) {
							.@c--;
							.@mats$ = ".upg" + getelementofarray(@ids,.@c);
							.@c = getelementofarray(@ids,.@c);
							next;
							callsub L_MainScript,.@mats$,.@c;
						}
					}
				break;
				case 2:
				case 3:
				break;
				}
			} 
		break;
		case 2: // UPGRADE EQUIPMENT
			.@c = GetUpgradeList;
			while (.@c > 0) {
				.@mats$ = ".upg" + .@c; 	// Array com os materiais para evoluir o equipamento

				if ((getequipid(EQI_HAND_R) == getelementofarray(getd(.@mats$),1)) || (getequipid(EQI_HAND_L) == getelementofarray(getd(.@mats$),1))) {
					next;
					mes "^0000AA[ Smithy ]^000000";
					mes "Please unnequip your " + green(getitemname(getelementofarray(getd(.@mats$),1))) + " first because I am gonna need that.";
					close;
				}
				next;
				callsub L_MainScript,.@mats$,.@c;
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

	mes blue("[ Smithy ]");
	mes "";
	mes "Weapon: " + getitemname(.@c);
	mes "Requests:";
	mes (Zeny >=getelementofarray(getd(.@mats$),0))?
		"^00AA00"+getelementofarray(getd(.@mats$),0) + " Zeny ^000000":
		"^AA0000"+getelementofarray(getd(.@mats$),0) + " Zeny ^000000";
	for (.@l=1; .@l < getarraysize(getd(.@mats$)); .@l=.@l+2) {
		.@qt=.@l+1;
		mes (countitem(getelementofarray(getd(.@mats$),.@l))>=getelementofarray(getd(.@mats$),.@qt))?
		"^00AA00"+getelementofarray(getd(.@mats$),.@qt) + "x " + getitemname(getelementofarray(getd(.@mats$),.@l))+"^000000":
		"^AA0000"+getelementofarray(getd(.@mats$),.@qt) + "x " + getitemname(getelementofarray(getd(.@mats$),.@l))+"^000000";
	}

	if(CheckDoableEquips(.@c) == 0) {
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
		if (Zeny >= getelementofarray(getd(.@mats$),0))
			setarray .@list[0],getelementofarray(getd(.@mats$),0);

		for (.@i=1; .@i<getarraysize(getd(.@mats$)); .@i=.@i+2) {
			if(countitem(getelementofarray(getd(.@mats$),.@i)) >= getelementofarray(getd(.@mats$),(.@i+1))) {
				copyarray .@list[.@i], getd(.@mats$+"["+.@i+"]"),2;
			}
		}
		if(getarraysize(.@list) == getarraysize(getd(.@mats$))) {
			Zeny = Zeny - getelementofarray(.@list,0);
			for (.@i=1; .@i < getarraysize(.@list); .@i=.@i+2) {
				.@itemid	= getelementofarray(.@list,.@i);
				.@qt 		= getelementofarray(.@list,(.@i+1));
				delitem .@itemid,.@qt;
			}
			
			CreateItem(.@c);

			mes "All done! Thank you!";
			close;
		} else {
			mes "^0000AA[ Smithy ]^000000";
			mes "Err... Sorry but I thought we were pals? Get lost!";
			close;
		}
	}
	end;


OnInit:
	//Forge Equipments List
	//setarray .Daggers,1201,1202,1204,1205,1207,1208,1210,1211,1213,1214,1216,1217,1219,1220,1222,1226;
	//HR 2
	setarray .d2[0],1206,1209;		//Daggers
	setarray .b2[0],1706;			//Composite Bow
	setarray .a2[0],2303,2305;		//armor
	//HR 3
	setarray .b3[0],1709;			//Great Bow
	//HR 4
	setarray .b4[0],1712;			//Cross Bow

	//Upgrade Tree
	setarray .1203[0],1201,1202; 	//Knife
	setarray .1206[0],1204,1205; 	//Cutter
	setarray .1209[0],1207,1208; 	//Main Gauche
	setarray .1703[0],1701,1702;	//Bow
	setarray .1706[0],1704,1705;	//Composite Bow
	setarray .1709[0],1707,1708;	//Great Bow
	setarray .1712[0],1710,1711;	//Cross Bow
	setarray .2101[0],2102;			//Guard

	//List of materials for Upgrade
	setarray .upg1201[0],200,1203,1,19655,1;					//Knife[3]
	setarray .upg1202[0],1000,1201,1,19655,5,19635,2,19654,2;	//Knife[4]
	setarray .upg1701[0],200,1703,1,19655,1;					//Bow[3]
	setarray .upg1702[0],1000,1701,1,19655,5,19635,2,19654,2;	//Bow[4]
	setarray .upg2102[0],1000,2101,1,19655,5,19654,5;			//Guard[1]

	//List of materials to forge
	setarray .upg1206[0],200,19655,3;							//Cutter[0]
	setarray .upg1209[0],200,19655,3;							//Main Gauche[0]
	

	//Dynamic Menus
	//--------------------
	// Forge > Weapons
	setarray .weapons$[1],"d","b"; //[d]aggers,[b]ows
	end;


	// =========
	// BUILD MENU
	// ===================
	function BuildMenu {
		.@v$ = "." + getarg(0);
		deletearray @ids[0],127;
		for (.@hr=1; .@hr<=HR; .@hr++){
			.@mats$ = .@v$+.@hr;
			.@j=0;
			if(getarraysize(.@mats$) > 0) {
				while(.@j < getarraysize(getd(.@mats$))) {				

					if(CheckDoableEquips(getelementofarray(getd(.@mats$),.@j)) == 1)
						.@menu$ = .@menu$ + green(getitemname(getelementofarray(getd(.@mats$),.@j)))+":";
					else 
						.@menu$ = .@menu$ + red(getitemname(getelementofarray(getd(.@mats$),.@j)))+":";

					
					setarray @ids[getarraysize(@ids)], getelementofarray(getd(.@mats$),.@j);
					.@j++;
				}
			}
		}

		//it also returns the array @ids containing the item_ids in .@menu$;
		return .@menu$;
	}


	// =========
	// BUILD MENUITEMIDS
	// ===================
	function BuildMenuItemIds {
		.@mats$ = "." + getarg(0);
		if(getarraysize(getd(.@mats$)) > 0) {
			for (.@i=0; .@i<getarraysize(getd(.@mats$)); .@i++){
				.@items$ = .@items$ + getelementofarray(getd(.@mats$),.@i) + "|";			
			}
			return .@items$;
		} else
			return -1;	
	}



	function	GetUpgradeList	{
	//	@inventorylist_id[]        - array of item ids.
	//	@inventorylist_amount[]    - their corresponding item amounts.
	//	@inventorylist_equip[]     - on which position the item is equipped (see EQP_* constants)
	//	                             It will contain 0 if the item is not equipped.
	//	@inventorylist_refine[]    - for how much it is refined.
	//	@inventorylist_identify[]  - whether it is identified.
	//	@inventorylist_attribute[] - whether it is broken.
	//	@inventorylist_card1[]     - These four arrays contain card data for the items.
	//	@inventorylist_card2[]       These data slots are also used to store names
	//	@inventorylist_card3[]       inscribed on the items, so you can explicitly check
	//	@inventorylist_card4[]       if the character owns an item made by a specific 
	//	                             craftsman.
	//	@inventorylist_expire[]    - expire time (Unix time stamp). 0 means never expires.
	//	@inventorylist_bound[]     - the bound type of the items (see BOUND_* constants)
	//	@inventorylist_count       - the number of items in these lists.
	
		getinventorylist;
		deletearray .@ids[0],127;
		for (.@i=0; .@i < @inventorylist_count; .@i++) {
			if (getiteminfo(getelementofarray(@inventorylist_id,.@i),2) == 5 ||
			    getiteminfo(getelementofarray(@inventorylist_id,.@i),2) == 4) {
				deletearray .@equips$[0],127;
				.@lista$ = BuildMenuItemIds(getelementofarray(@inventorylist_id,.@i));
				if(.@lista$ != "-1") {
					explode(.@equips$,.@lista$,"|");
					for(.@j=0; .@j < getarraysize(.@equips$); .@j++) {
						if( (CheckDoableEquips(atoi(getelementofarray(.@equips$,.@j)))) == 1)
							.@menu$ = .@menu$ + green(getitemname(atoi(getelementofarray(.@equips$,.@j)))) + ":";
						else 
							.@menu$ = .@menu$ + red(getitemname(atoi(getelementofarray(.@equips$,.@j)))) + ":";

						setarray .@ids[.@k], atoi(getelementofarray(.@equips$,.@j));
						.@k++;
					}					
				}
			}
		}
		.@menu$ = .@menu$ + ":" + red("<<<");
		.@c = select(.@menu$);

		if(.@c > getarraysize(.@ids))
			return 0;

		.@c--;
		.@c = getelementofarray(.@ids,.@c);
		
		return .@c; 
	}


	function	CheckDoableEquips	{
		.@mats$ = ".upg" + getarg(0);

		if(getarraysize(getd(.@mats$)) == 0)
			return 0;

		if (Zeny < getelementofarray(getd(.@mats$),0))
			return 0;

		for(.@i=1; .@i < getarraysize(getd(.@mats$)); .@i=.@i+2) {
			.@qt=.@i+1;
			if (countitem(getelementofarray(getd(.@mats$),.@i)) < getelementofarray(getd(.@mats$),.@qt))
				return 0;
		}

		return 1;
	}

	function	CreateItem	{
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
		getitembound2 .@c,1,1,0,0,0,0,0,0,Bound_Char;
//		getitem .@c,1;
		deletearray @ids[0],127;
		specialeffect 154;
		sleep2 1000;

		return;
	}
}




new_1-1,130,133,1	shop	Armors and Weapons	63,1203:2500,1703:2500,2101:2500,12004:3000,1758:10,1065:100;



