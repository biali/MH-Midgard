new_1-1,148,112,0	script	#HouseEntrance	45,1,1,{
	function EntrarNaCasa;
	end;

OnTouch:
	if(!CURRENT_HUNT)
		EntrarNaCasa(.QuestId,.QuestName$);
	else
		dispbottom "You you need to hand over your quest first.";
	end;

OnInit:
	.QuestId 	= 99999; 				// Quest id in the QuestDB to control the instance
	.QuestName$	= "Home Sweet Home";	// Instance name as per InstanceDB
	end;


// ================
// Enter the House
// =========================
	function EntrarNaCasa {
	set .@questid,		getarg(0);
	set .@md_name$, 	getarg(1);
	set .@staytime,		checkquest(.@questid,PLAYTIME);
	if (instance_create(.@md_name$,IM_CHAR,getcharid(0)) < 0) {
		if (instance_create(.@md_name$,IM_CHAR,getcharid(0)) == -3) { 
			callsub S_Enter, .@md_name$;
		}
	} else
		callsub S_Enter, .@md_name$;
	callsub S_Enter, .@md_name$;
	end;

	S_Enter:
		.@m$ = getarg(0);

		switch(instance_enter(.@m$)) {
		case 3:
			dispbottom "An unknown error has occurred.";
			end;
		case 2:
			dispbottom "Instance does not exist.";
			dispbottom "Instance has been destroyed by the Party Leader, or because of the time limit.";
			end;
		case 1:
			dispbottom "Only a member of the party can enter the instance.";
			end;
		case 0:
			//PETS$ =""; //DEBUG
			//PETS_UNITID$ = ""; //DEBUG
			//PETS_CAUGHT$ = ""; //DEBUG
			//debugmes "PETS$ = " + PETS$;
			//debugmes "PETS_UNITID$ = " + PETS_UNITID$;
			explode(.@petsid$,PETS$,"|");
			explode(.@pets$,PETS_UNITID$,"|");
			if(getarraysize(.@petsid$) > 0) {
				for (.@i=0; .@i < getarraysize(.@petsid$); .@i++){
					.@petid$ = getelementofarray(.@pets$,.@i);
					mobevent instance_mapname("prt_in"),77,99,getmonsterinfo(atoi(getelementofarray(.@petsid$,.@i)),MOB_NAME),atoi(getelementofarray(.@petsid$,.@i)),0,1,0,0,0,1,0,1,0,0,0,0,0,instance_npcname("Housekeeper")+"::"+.@petid$;
				}
			}
		}
		end;
	return;
	}
}

prt_in,80,113,0	script	#HouseExit	45,1,1,{	
	end;

OnTouch:
	warp "new_1-1", 142,111;
	instance_destroy;
	end;

OnInit:
	disablenpc(strnpcinfo(0));
	end;

OnInstanceInit:
	enablenpc(instance_npcname(strnpcinfo(0)));
	end;
}



// ================
// HOUSEKEEPER
// =========================
prt_in,80,96,2	script	Housekeeper	545,{	
	function PetHatchFromEgg; function PetHatchFromList; function RemovePetsFromRoom;

	mes "^0000AA[ Housekeeper ]^000000";
	mes "Hello, master!";
	mes "How can I help you?";

	PetHatchFromEgg;

	.@back = 0;
	while(!.@back){
		switch(select("Manage my Pets:Cancel")){
		case 1:
			switch(select("Hatch from Egg:Hatch One of My Pets:Remove a Pet From the Room:^AA0000<<<^000000")){
				case 1:
					PetHatchFromEgg;
					break;
				case 2:
					PetHatchFromList;
					break;
				case 3:
					RemovePetsFromRoom;
					break;
						
				case 4:
				case 255:
					break;
			}
		break;
		case 2:
			.@back=1;
			break;
		}
	}
	end;

OnInit:
	disablenpc(strnpcinfo(0));
	end;

OnInstanceInit:
	enablenpc(instance_npcname(strnpcinfo(0)));
	end;

// ================
// Hatch Pets From Egg
// =========================
	function PetHatchFromEgg {
		deletearray @inventorylist_id[0],127;
		getinventorylist(getcharid(0));
		for (.@i=0; .@i<getarraysize(@inventorylist_id); .@i++) {
			if(getiteminfo(@inventorylist_id[.@i],2) == 7) {
				.@menu$ = .@menu$ + replacestr(getitemname(@inventorylist_id[.@i]), " Egg", "",0) + ":";
				setarray .@eggs[.@j], @inventorylist_id[.@i];
				.@j++;
			}
		}
		.@menu$ = .@menu$ + "^AA0000<<<^000000";
		if(.@j > 0) {
			next;
			emotion e_gasp,0;
			misceffect 890;
			mes "^0000AA[ Housekeeper ]^000000";
			mes "Meow! I can see you've brought a new friend to our home!";
			mes "Should I hatch them, Prrrease?";
			.@c = select(.@menu$);
			.@c--;

			if(.@c >= .@j) {
				return;
			} else {
				if(countitem(.@eggs[.@c]) > 0) {
					.@name$ = replacestr(getitemname(.@eggs[.@c]), " Egg", "",0);
					.@name$ = replacestr(.@name$, " ", "_",0);
					
					//Stupid Petites need special attention :/
					if(.@name$ == "Green_Petite")
						.@name$ = "Petit";

					query_sql("SELECT id from `mob_db` WHERE `sprite` = '" + .@name$ + "' limit 1",.@id);
					.@petid$ = "OnPet_" + gettimetick(2);
					// mobevent <map>,<x>,<y>,<fakename>,<mobid>,<size>,<amount>,<teamid>,<showhp>,<increasehp>,<allied>,<noslaves>,<noexpnodrop>,<poringcoins>,<event>
					mobevent instance_mapname("prt_in"),77,99,getmonsterinfo(.@id,MOB_NAME),.@id,0,1,0,0,0,1,0,1,0,0,0,0,0,instance_npcname(strnpcinfo(1))+"::"+.@petid$;
					PETS$ = PETS$ + .@id + "|";						// This holds the mob_id of pets in the house;
					PETS_UNITID$ = PETS_UNITID$ + .@petid$ + "|";	// This holds the unit_id of pets in the house;
					delitem .@eggs[.@c],1;
					next;
				}
			}
		}
		return;
	}

// ================
// Hatch Pets From List
// =========================
	function PetHatchFromList {
		explode(.@pets$,PETS_CAUGHT$,"|");
		explode(.@petsid$,PETS$,"|");
		explode(.@petsGID$,PETS_UNITID$,"|");
		for(.@i=0; .@i<getarraysize(.@pets$); .@i++){
			.@menu$ = .@menu$ + getmonsterinfo(atoi(getelementofarray(.@pets$,.@i)),MOB_NAME) + ":";
		}
		.@menu$ = .@menu$ + "^AA0000Cancel^000000";

		.@c = select(.@menu$);
		if(.@c > getarraysize(.@pets$))
			return;
		else {
			.@c--;
			.@petid$ = "OnPet_" + gettimetick(2);
			mobevent instance_mapname(strnpcinfo(4)),77,99,getmonsterinfo(atoi(getelementofarray(.@pets$,.@c)),MOB_NAME),atoi(getelementofarray(.@pets$,.@c)),0,1,0,0,0,1,0,1,0,0,0,0,0,instance_npcname(strnpcinfo(1))+"::"+.@petid$;
			setarray .@petsid$[getarraysize(.@petsid$)], getelementofarray(.@pets$,.@c);
			setarray .@petsGID$[getarraysize(.@petsGID$)], .@petid$;
			PETS$ 			= implode(.@petsid$,"|");
			PETS_UNITID$ 	= implode(.@petsGID$,"|");
			deletearray .@pets$[.@c],1;
			deletearray .@petsid[0],127;
			deletearray .@petsGID[0],127;
			if(getarraysize(.@pets$) > 0)
				PETS_CAUGHT$ = implode(.@pets$,"|");
			else 
				PETS_CAUGHT$ = "";
		}
		return;
	}

// ================
// Remove Pets from the Room
// =========================
	function RemovePetsFromRoom {
		deletearray .@petsid$[0],127;
		deletearray .@pets$[0],127;
		explode(.@petsid$[0],PETS$,"|");
		explode(.@pets$[0],PETS_UNITID$,"|");
		if(getarraysize(.@petsid$) > 0) {
			for (.@i=0; .@i<getarraysize(.@petsid$); .@i++) {
				.@menu$ = .@menu$ + getmonsterinfo(atoi(getelementofarray(.@petsid$,.@i)),MOB_NAME) + ":";
			}
			.@c = select(.@menu$) -1;
			if(.@c < getarraysize(.@petsid$)) {
				PETS_CAUGHT$ = PETS_CAUGHT$ + getelementofarray(.@petsid$,.@c) + "|";
				killmonster instance_mapname(strnpcinfo(4)),instance_npcname(strnpcinfo(1))+"::"+.@pets$[.@c];
				deletearray getelementofarray(.@petsid$,.@c),1;
				deletearray getelementofarray(.@pets$,.@c),1;
				if(getarraysize(.@petsid$) > 0) {
					PETS_UNITID$ 	= implode(.@pets$,"|");
					PETS$ 			= implode(.@petsid$,"|");
				} else {
					PETS_UNITID$ 	= "";
					PETS$ 			= "";
				}
			}
		}
		return;
	}
}




