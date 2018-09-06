// =======================
// SETTINGS AND FUNCTIONS
// =============================

-	script	General Settings	-1,{
	end;

	OnInit:
		set .n$, "^FF0000[Hunting Quests]^000000"; 	// Npc Name

		// QuestID, Name, HRReq, MaxParty, TimeLimit(mins), MaxFaints
		setarray $@Assignments$[0],									//  Set Quest Menu
			100000,"Ferus of Payon",1,5,50,3,						//  HR1 - Slay 7 Ferus
			100001,"A Driller Kerfuffle",2,5,50,3,					//  HR2 - Slay 5 Frilldoras and 3 Drillers
			100002,"The Great Ferus Hunt",2,5,50,3,					//  HR2 - Hunt a Great Ferus (1714)
			100003,"The Slimmy Thief",2,5,50,3,						//  HR2 - Hunt a Phreeoni
			100004,"Urgent! Eddga Hunt",3,5,50,3,					//  HR3 - Hunt am Eddga
			100005,"The Best Kind of Quest",3,5,50,3,				//  HR3 - Keep the Scholars safe
			100006,"Sinister Shadow in the Swamp",3,5,50,3,			//  HR3 - Rescue the Scholar and Neutralize the Threat (Boitata)
			100007,"Flying Sparks! Garm",3,5,50,3,					//  HR3 - Hunt a Garm
			100008,"The Encroaching Morroc",4,5,50,3,				//  HR4 - Hunt a Morroc
			100009,"One for the History Books",4,5,50,3;			//  HR4 - Hunt a Root of Corruption
		// QuestID, MapName, Map
		setarray $@Assignments_$[0],
			100000,"Payon Forest","pay_fild07",
			100001,"Payon Forest","pay_fild07",
			100002,"Payon Forest","pay_fild07",
			100003,"Morroc Desert","moc_fild02",
			100004,"Payon Forest","pay_fild07",
			100005,"Morroc Forest","moc_fild02",
			100006,"Payon Forest","pay_fild07",			
			100007,"Payon Forest","pay_fild07",
			100008,"Morroc Desert","moc_fild02",
			100009,"Yuno Plateau","yuno_fild02";
		// QuestID, ZenyReward, Rewards (drops)
		setarray $@Assignments__$[0],
			100000,720,19600,19601,19602,19600,19601,19602,
			100001,1200,19624,19625,19626,19627,19624,19626,19624,19626,
			100002,1200,19604,19605,19606,19607,19608,19604,19605,19608,
			100003,1800,
			100004,2520,
			100005,2520,
			100006,3240,		
			100007,3240,
			100008,4320,
			100009,4320;
		// Main Monsters
		// Quest ID, MobID, Qty, MobID2, Qty2, etc
		setarray $@Assignments___$[0],
			100000,1717,30,
			100001,1119,50,1380,30,
			100002,1714,1,
			100003,1159,1,
			100004,
			100005,
			100006,		
			100007,
			100008,
			100009;
		// Secondary Monsters
		// Quest ID, MobID, Qty, MobID2, Qty2, etc
		setarray $@Assignments____$[0],
			100000,
			100001,
			100002,
			100003,
			100004,
			100005,
			100006,		
			100007,
			100008,
			100009;
	

		// QuestID, Name, HRReq, MaxParty, TimeLimit(mins), MaxFaints
		setarray $@Optionals$[0],									// 1    Set Quest Menu
			100030,"Butting Heads with Nature",1,5,50,3,			// HR1 - Slay 7 Frilldoras and 5 Drillers
			100031,"A Thicket of Thugs",1,5,50,3,					// HR1 - Slay 7 Ferus
			100032,"Fungal Flexin' in the Ancient Forest",1,1,50,3,	// HR1 - Deliver 20 Black Mushrooms
			100033,"The Great Glutton",2,5,50,3,					// HR2 - Hunt a Great Ferus
			100034,"Camp Crasher",2,5,50,3,							// HR2 - Hunt a Hydrolancer (1720)
			100035,"Snatch the Snatcher",2,5,50,3,					// HR2 - Capture a Hydrolancer (1720)
			100036,"The Pain from Gains",2,5,50,3,					// HR2 - Slay 7 Deep Sea Sword Fish (2181)
			100037,"Exterminator of the Waste ",2,5,50,3,			// HR2 - Slay 14 Dragon Tail (1321)
			100038,"Scatternut Shortage",3,5,50,3,					// HR3 - Hunt a Chimera (1283)
			100039,"The Current Situation",3,5,50,3;				// HR3 - Hunt a Tendrillion (1991)
		// QuestID, MapName, Map
		setarray $@Optionals_$[0],
			100030,"Payon Forest","pay_fild07",
			100031,"Payon Forest","pay_fild07",
			100032,"Payon Forest","pay_fild07",
			100033,"Payon Forest","pay_fild07",
			100034,"Payon Forest","pay_fild07",
			100035,"Morroc Forest","moc_fild02",
			100036,"Morroc Forest","moc_fild02",			
			100037,"Morroc Forest","moc_fild02",
			100038,"Payon Forest","pay_fild07",
			100039,"Payon Forest","pay_fild07";
		// QuestID, ZenyReward, Rewards (drops)
		setarray $@Optionals__$[0],
			100030,720,19624,19625,19626,19627,19624,19625,19626,
			100031,720,19600,19601,19602,19600,19601,19602,
			100032,720,
			100033,1200,
			100034,1800,
			100035,2520,
			100036,1080,
			100037,1080,
			100038,2520,
			100039,3240;
		// Main Monsters
		// Quest ID, MobID, Qty, MobID2, Qty2, etc
		setarray $@Optionals___$[0],
			100030,1119,50,1380,30,
			100031,1717,30,
			100032,
			100033,
			100034,
			100035,
			100036,		
			100037,
			100038,
			100039;
		// Secondary Monsters
		// Quest ID, MobID, Qty, MobID2, Qty2, etc
		setarray $@Optionals____$[0],
			100030,
			100031,
			100032,
			100033,
			100034,
			100035,
			100036,		
			100037,
			100038,
			100039;


		//Quests Constants
		$@MaxAssignments 	= 100029;		// Quests 100000 a 100029 
		$@MaxOptionals 		= 100129;  		// Quests 100030 a 100129
		$@MaxInvestigations = 0;			// Quests geradas randomicamente;
		$@MaxEvents 		= 100249;		// Quests 100150 a 100250


		// Hunter Rank Experience Constants
		.FirstLevel = 5000;// Exp cost to get from level 0 -> 1
		.expcurve = 25000;	// Exp curve Lv * Lv * .expcurve + .FirstLevel + Lv
		$@MaxRank = 100;	// Sets the max Weapon Mastery Level (max 127)
		// Exp Formula
		for(.@i = 1; .@i < $@MaxRank; .@i++)
			$@NeededExp[.@i] = (.@i * .@i * .expcurve) + (.@i * 100) + .FirstLevel;


		// Endemic Life - Pets List
		setarray $@pets[0],	1002,1013,1031,1063,1049,1042,1035,1167,1107,1052,1014,1077,1019,1056,1057,1155,
							1109,1245,1879,1122,1123,1125,1385,1382,1289,1586,1837;


		// Statistics Variables Definition
		setarray $@Stats$[0],
			"HR_MVP_KILLED",			//	0	Large Monsters Count
			"HR_SMALLMONSTER_KILLED",	//	1	Regular Monsters Count
			"HR_ASSIGNMENTS_COUNT",		//	2	Total Assisgnment Quests Completed
			"HR_OPTIONALS_COUNT",		//	3	Total Optional Quests Completed
			"HR_INVESTIGATIONS_COUNT",	//	4	Total Investigation Quests Completed
			"HR_EVENTS_COUNT",			//	5	Total Event Quests Completed
			"HR_ARENA_COUNT",			//	6	Total Arena Quests Completed
			"HR_ZENY_COUNT";			//	7	Total Zeny Accumulated from Quests
	end;


	OnPCLoadMapEvent:
		percentheal 100,100;
		end;

	OnPCDieEvent:
		if(instance_id() && CURRENT_HUNT > 0) {
			'cart++; //'
			if(getmapxy(.@map$,.@x,.@y,UNITTYPE_PC) == 0) {
				instance_announce 0, strcharinfo(0)+" fainted. ("+ 'cart + "/" + 'MaxFaints + ")",0,0xDD0000,FW_BOLD,24;
			}			
			warp instance_mapname("que_hugel"),163,177;
			
			if('cart >= 'MaxFaints) {
				callfunc "QuestFailed",.@map$;
				end;
			}
		}
		end;


	OnPcLoginEvent:
		//Inicializa a variavel de Hunter Rank 
		if (!HR) 
			HR = 1;

		if(BaseLevel < 99) {
			jobchange 4012;
			BaseLevel = 99;
			JobLevel = 70;
			SkillPoint = 0;
			StatusPoint = 0;
			atcommand "@allstats";
			recalculatestat;
			save "new_1-1", 143,114;
			//Initial Skills
			skill 4001,1,SKILL_PERM_GRANT;	//Capture Net
			skill 4002,1,SKILL_PERM_GRANT;	//Whetstone
			skill 142,1,SKILL_PERM_GRANT; 	//First Aid
			skill 143,1,SKILL_PERM_GRANT; 	//Play Dead
			skill 151,1,SKILL_PERM_GRANT; 	//Find Stone
			skill 152,1,SKILL_PERM_GRANT; 	//Stone Fling
			//Initial Items and Equips - Included in the conf/char_athena.conf
		}

		RemoveQuest(getcharid(0));		
	end;


	// Remove membros da Party caso desloguem
	// Remove a party caso o lider deslogue com uma party vazia
	// Transfere a lideranca para o proximo membro online caso o lider deslogue
	OnPCLogoutEvent:
		//AbandonQuest();
		RemoveFromJoinList(getcharid(0));
		LeaveParty(getcharid(1));
		end;
}


// MAPFLAGS
// ----------------------------------------------
new_1-1	mapflag	loadevent
new_1-1	mapflag	noteleport
new_1-1	mapflag	noicewall
new_1-1	mapflag	nowarp
new_1-1	mapflag	nowarpto
new_1-1	mapflag	nomemo
new_1-1	mapflag	noreturn
new_1-1	mapflag	partylock
new_1-1	mapflag	equiplock
new_1-1	mapflag	notrade
new_1-1	mapflag	nodrop

que_hugel	mapflag	noteleport
que_hugel	mapflag	noicewall
que_hugel	mapflag	nowarp
que_hugel	mapflag	nowarpto
que_hugel	mapflag	nomemo
que_hugel	mapflag	noreturn
que_hugel	mapflag	partylock
que_hugel	mapflag	equiplock
que_hugel	mapflag	notrade
que_hugel	mapflag	nodrop

pay_fild07	mapflag	noteleport
pay_fild07	mapflag	noicewall
pay_fild07	mapflag	nowarp
pay_fild07	mapflag	nowarpto
pay_fild07	mapflag	nomemo
pay_fild07	mapflag	noreturn
pay_fild07	mapflag	partylock
pay_fild07	mapflag	equiplock
pay_fild07	mapflag	notrade
pay_fild07	mapflag	nodrop
