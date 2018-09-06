-	script	MyInfo	-1,{
OnInit:
	bindatcmd "myinfo",strnpcinfo(3)+"::OnAtcommand";
	end;
OnAtcommand:
	switch(getcharid(5)) {
	case 1:
	case 4:
		set .@charsize$, "Small";
		break;
	case 2:
	case 5:
		set .@charsize$, "Median";
		break;
	case 3:
	case 6:
		set .@charsize$, "Broad";
		break;
	}
	
	mes "Origin : " + FACTION$;
	mes "Size   : " + .@charsize$;
	mes (##CASHPOINTS)?"Cashpoints: ^0000FF" +##CASHPOINTS+ "^000000.":"##CASHPOINTS: ^FF00000" + "^000000.";
	mes (#MANIAS)?"Mania$: ^0000FF" +#MANIAS+ "^000000.":"Mania$: ^FF00000" + "^000000.";
	mes (HONOR)?"Pontos de Honra: ^0000FF" +HONOR+ "^000000.":"Pontos de Honra: ^FF00000" + "^000000.";
	mes "-- Hunting --";
	mes "Missions Completed: ^0000FF" + Mission_Completed + "^000000";
	mes "Mission Points: ^0000FF" + Mission_Points + "^000000";
	mes " ";
	
	if( Mission_Tick > 0 ) {
		for(.@i=1; .@i < 6; .@i++ )
			set .@sql$, .@sql$ + getd("Mission_ID" + .@i) + ",";
		set .@sql$, .@sql$ + "0";
		query_sql("SELECT `id`,`oname`,`lv` FROM `mob_oblivion` WHERE `id` in ("+ .@sql$ + ")",.@id,.@oname$,.@lv);
		mes "[^FFA500Mission Contracts^000000]";
		for( .@i=1; .@i < 6; .@i++ ) {
			set .@MobID, getd("Mission_ID" + .@i);
			for( .@j=0; .@j < 5; .@j++ ) {
				if(.@id[.@j] == .@MobID) {
					mes "^0000FF" + getd("Mission_Count" + .@i) + "^000000 x ^FFA500" + .@oname$[(.@j)] + "^000000 (Lv " + strmobinfo(3, .@MobID) + ")";
					if(getd("Mission_Count" + .@i) == 0) .@finished++;
				}
			}
		}
		
		if(.@finished == 5){
			if(select("Return to the Village:Cancel") == 2) {
				close;
			} else {
				if(getcharid(5) < 4 ) // Midgardian
					warp "rent_mb", 157,73;
				else
					warp "rent_ma", 157,73;
				end;
			}
		}
	}
	
	mes " ";
	mes "[ Instances Check ]";

	set .@playtime, checkquest(69500,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "Eddga Normal ^FF0000[LOCKED]^000000";
	else
		mes "Eddga Normal ^009900[FREE]^000000";

	set .@playtime, checkquest(69501,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "GTB Normal ^FF0000[LOCKED]^000000";
	else
		mes "GTB Normal ^009900[FREE]^000000";
		
	set .@playtime, checkquest(69502,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "Mistress Normal ^FF0000[LOCKED]^000000";
	else
		mes "Mistress Normal ^009900[FREE]^000000";

	set .@playtime, checkquest(69503,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "Phreoni Normal ^FF0000[LOCKED]^000000";
	else
		mes "Phreoni Normal ^009900[FREE]^000000";

	set .@playtime, checkquest(69504,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "Snake Lord Normal ^FF0000[LOCKED]^000000";
	else
		mes "Snake Lord Normal ^009900[FREE]^000000";

	set .@playtime, checkquest(69505,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "Lady Tanee Normal ^FF0000[LOCKED]^000000";
	else
		mes "Lady Tanee Normal ^009900[FREE]^000000";

	set .@playtime, checkquest(69506,PLAYTIME);
	if(.@playtime == 0 || .@playtime == 1)
		mes "Orc Hero Normal ^FF0000[LOCKED]^000000";
	else
		mes "Orc Hero Normal ^009900[FREE]^000000";
		
	close;
}



function	script	F_GD	{
	// arg0 = mob_id;
	if (getmobdrops(getarg(0))) {
		.@count = $@MobDrop_count;
		copyarray .@ids[0],$@MobDrop_item[0],.@count;
		copyarray .@per[0],$@MobDrop_rate[0],.@count;

		for( set .@i, 0; .@i < getarraysize(.@ids) -1; set .@i, .@i++ ) {
			.@ratio = .@per[.@i] * (1 + $@MAXLEVEL - BaseLevel);
			if(.@ratio > 100000) set .@ratio, 100000;
			if(.@ratio == 0) set .@ratio, .@per[.@i];
			if(rand(1,.@ratio) == 1) {
				getitem .@ids[.@i],1;
				dispbottom "You got " + getitemname(.@ids[.@i]);
			}
			debugmes "Sorteando " + .@i + "o item - " + getitemname(.@ids[.@i]) + " com rates a " + .@ratio;
		}
		getitem 26557,1;
		getitem 617,1;
		if(rand(1000) == 1) getitem 13953,1;
	}
	return; 
}



function	script	F_GPL	{
	// arg0 = party id;
	// arg1 = redutor (0..99) de dificuldade
	
	.@redutor = getarg(1,0);
	set $@partymembercount, 0;
	deletearray $@partymembername$[0],128;

	getpartymember getarg(0),0;
	set 'members, $@partymembercount;
	copyarray 'names$[0], $@partymembername$[0], 'members;

	set 'baselevel, readparam(11,'names$[0]);
	for( .@i=1; .@i < 'members; .@i++ ) {
		if('baselevel < readparam(11,'names$[.@i]))
			set 'baselevel, readparam(11,'names$[.@i]);
	}
	set 'rate, 'baselevel * 100 / $@MAXLEVEL;
	
	setmapflag instance_mapname(strnpcinfo(4)), mf_dmgratio, 'rate - .@redutor;
	setmapflag instance_mapname(strnpcinfo(4)), mf_bexp, 'rate;
	setmapflag instance_mapname(strnpcinfo(4)), mf_jexp, 'rate;

	dispbottom "Instance dificulty adjusted to " + ('rate - .@redutor) + "% of its original difficulty.";
	debugmes "Iniciado Instancia com ratio " + ('rate - .@redutor);
	
	return;
}



function	script	F_CreateInstance	{
// Arguments
// arg0 = quest_id for the PLAYTIME
// arg1 = Instance's name as per instance_db
// arg2 = minimum level to enter
// arg3 = max level enter
// arg4 = minimum number of party members to enter
// arg5 = maximum number of party members to enter
// arg6 = variavel de controle maximo da instancia
// arg7 = Redutor de dificuldade

	if(getarg(6,"") != "" && getarg(6,"") != "null") {
		switch(getcharid(1)) {
		case 0:
			end;
			break;
		default:
			getmapxy(@map$,@x,@y, 0);
			if( @map$ == instance_mapname(strnpcinfo(4)) )
				@map$ = strnpcinfo(4);
			
			getpartymember(getcharid(1));
			set .@count,$@partymembercount;
			if ( (checkquest(.quest,PLAYTIME) == -1 || checkquest(.quest,PLAYTIME) == 2) &&
			     (instance_check_party(getcharid(1),getarg(4),getarg(2),getarg(3)) && .@count < getarg(5)) ) {
				mes "^990000[ ! W A R N I N G ! ]^000000";
				mes "You are about to start/enter";
				mes "an instance and by doing that";
				mes "it will get locked for a certain";
				mes "period of time.";
				close2;
				if(select("^990000Cancel the Instancing:^009900Proceed with the Instancing^000000") == 2) {
					set .var$, getarg(6);
					if(select("Save here:Continue without saving") == 1)
						if( @map$ == instance_mapname(strnpcinfo(4)) ) {
						 	mes "Sorry, you cannot save on this map.";
							close2;
						} else
							save @map$,@x,@y;
				} else {
					pushpc DIR_SOUTH, 3;
					end;
				}
			}
			break;
		}
	 } else	
	 	debugmes "Instancia "+ .md_name$ +" criada sem variavel de controle.";
		
	if (getcharid(1) == 0) {
		atcommand "@party " + strcharinfo(0); //Cria party com o nome do proprio char;
		sleep2 3000;
	}
	
	set .@party_id,getcharid(1);
	set .@staytime,checkquest(.quest,PLAYTIME);
	set .quest, getarg(0,"");
	set .md_name$, getarg(1);
	set .redutor, getarg(7,0);

	getpartymember(.@party_id);
	set .@count,$@partymembercount;

	if (.@party_id > 0 && .@count > getarg(5)) {
		dispbottom "Sorry, but this instance is limited to a maximum of " + .@count + "member(s) per party.";
		end;
	}
	
	if (!instance_check_party(.@party_id,getarg(4),getarg(2),getarg(3))) {
		dispbottom "This instance requires at least " + getarg(4) + " members with Base level range of "+getarg(2)+" ~ "+getarg(3)+".";
		end;
	}
	
	if (.@staytime == -1) { //Quest nao inicializada ainda. Nao tem a quest.
		if (getcharid(0) == getpartyleader(.@party_id,2)) { //se eh o lider da party.... booka e entra
			if (instance_create(.md_name$) < 0) {
				if (instance_create(.md_name$) == -3) 
					callsub L_Enter;
				else {
					debugmes .md_name$+" - Reservation Failed.";
					end;
				}

			}
		} 
		callsub L_Enter;
	} else if (.@staytime == 0 || .@staytime == 1) { //Ainda tem tempo de estadia na instancia (quest ativa)
		callsub L_Enter;
	} else if (.@staytime == 2) { //O tempo de estadia esgotou. Quest Completa
		erasequest getarg(0);
		end;
	}

	dispbottom "Impossible to create instance.";
	end;
	
L_Enter:
	if(.var$ != "" && .var$ !="null") {
		if(getd("'" + .var$) == 3) { // MVP Ja Morto. Quem esta fora da instancia nao entra mais.
			dispbottom "Instance is locked. You are no longer allowed to enter.";
			end;
		}
	}
	switch(instance_enter(.md_name$)) {
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
		set 'partyid, getcharid(1);
		if(checkquest(.quest) == -1) setquest .quest;
		if(.var$ != "null" && .var$ != "") {
			if(getd("'" + .var$) < 1) setd("'" + .var$), 1; // Variavel de controle principal da instancia
			setmapflag instance_mapname(strnpcinfo(4)), mf_nomobloot;
			setmapflag instance_mapname(strnpcinfo(4)), mf_nomvploot;
			callfunc("F_GPL", getcharid(1), .redutor);
		}
	}
	return;
}


function	script	F_HouseAllocate	{
	if(getcharid(5) < 4) {
		set HOUSE_NUMBER, rand(1,23);
		savepoint "rent_mb",$@HDRespMx[HOUSE_NUMBER -1],$@HDRespMy[HOUSE_NUMBER -1];
	} else if(getcharid(5) > 3) {
		set HOUSE_NUMBER, rand(1,23);
		savepoint "rent_ma",$@HDRespMx[HOUSE_NUMBER -1],$@HDRespMy[HOUSE_NUMBER -1];
	}
	return;
}



function	script	F_BumpStats	{
	if(getarg(0) == "str") set .@i, 0;
	if(getarg(0) == "agi") set .@i, 1;
	if(getarg(0) == "vit") set .@i, 2;
	if(getarg(0) == "int") set .@i, 3;
	if(getarg(0) == "dex") set .@i, 4;
	if(getarg(0) == "luk") set .@i, 5;
	
	switch(.@i) {
		case 0:
			statusup2 bStr,getarg(1);
			if(BONUS_STR < 99) set BONUS_STR, BONUS_STR + getarg(1);
			break;
		case 1:
			statusup2 bAgi,getarg(1);
			if(BONUS_AGI < 99) set BONUS_AGI, BONUS_AGI + getarg(1);
			break;
		case 2:
			statusup2 bVit,getarg(1);
			if(BONUS_VIT < 99) set BONUS_VIT, BONUS_VIT + getarg(1);
			break;
		case 3:
			statusup2 bInt,getarg(1);
			if(BONUS_INT < 99) set BONUS_INT, BONUS_INT + getarg(1);
			break;
		case 4:
			statusup2 bDex,getarg(1);
			if(BONUS_DEX < 99) set BONUS_DEX, BONUS_DEX + getarg(1);
			break;
		case 5:
			statusup2 bLuk,getarg(1);
			if(BONUS_LUK < 99) set BONUS_LUK, BONUS_LUK + getarg(1);
			break;
	}
	specialeffect2 568;
	dispbottom "Your " +getarg(0)+ " got increased by " +getarg(1)+ ".";
	
	return;
}




function	script	F_HouseInstancing	{
	if(((getcharid(5) < 4) && (strnpcinfo(4) == "rent_ma")) || ((getcharid(5) > 3) && (strnpcinfo(4) == "rent_mb"))) {
		dispbottom "You cannot enter other people's house";
		end;
	} 
	
	if (getcharid(1) == 0 && (HOUSE_NUMBER == atoi(strnpcinfo(2)) || strnpcinfo(4) == "1@ma_h")) {
		atcommand "@party " + strcharinfo(0); //Cria party com o nome do proprio char;
		sleep2 2000;
	}
	
	if (isbegin_quest(69300) == 1)
		erasequest 69300;
	
	set .@party_id,getcharid(1);
	set .@p_name$,getpartyname(.@party_id);
	set .@staytime,checkquest(69300,PLAYTIME);
	set .@doornumber, getarg(0);
	if (getcharid(5) < 4)
		set .md_name$,"Midgardian Home";
	else
		set .md_name$,"Baldurian Home";
	
	getpartymember(.@party_id);
	set .@count,$@partymembercount;
	if(getarg(1) == 0)
		set .@max, 1;
	else
		set .@max, getarg(1);
		
	if (.@party_id > 0 && .@count > .@max) {
		dispbottom "Sorry, but you need to be the only one in your party.";
		end;
	}
		
	if (!instance_check_party(.@party_id)) {
		dispbottom "Omg... Hold on... This is not my house! I live at number " + HOUSE_NUMBER;
		end;
	}
	
	if (.@staytime == -1) {
		//Quest nao inicializada ainda. Nao tem a quest.
		if (getcharid(0) == getpartyleader(.@party_id,2)) { //se eh o lider da party.... booka e entra
			if (HOUSE_NUMBER == .@doornumber) {
				if (instance_create(.md_name$) < 0) {
					if (instance_create(.md_name$) == -3)
						callsub L_Enter;
					debugmes .md_name$+" - Reservation Failed.";
					end;
				}

				set getvariableofnpc(.house,(getcharid(5)<4)?"FrontGate#rent_mb":"FrontGate#rent_ma"),HOUSE_NUMBER -1;
				
				callfunc "F_CheckServices";
				callsub L_Enter;
			}
					
		} else {
			set .@hostid,getcharid(0,getpartyleader(.@party_id));  // retrieve rid of party leader
			query_sql("SELECT value FROM global_reg_value WHERE char_id = " + .@hostid + " AND str = 'HOUSE_NUMBER'",.@hostdoornumber);
			if(.@hostdoornumber == .@doornumber) 
				callsub L_Enter;
		}

	} else if (.@staytime == 0 || .@staytime == 1) { 		//Ainda tem tempo de estadia na casa (quest ativa)
		if(HOUSE_NUMBER == .@doornumber) { 
			callsub L_Enter;
		} else if(getcharid(0) != getpartyleader(.@party_id,2)) {
			set .@hostid,getcharid(0,getpartyleader(.@party_id));  // retrieve rid of party leader
			query_sql("SELECT value FROM global_reg_value WHERE char_id = " + .@hostid + " AND str = 'HOUSE_NUMBER'",.@hostdoornumber);
			if(.@hostdoornumber == .@doornumber) 
				callsub L_Enter;
		}

	} else if (.@staytime == 2) { 		//O tempo de estadia na casa esgotou. Quest Completa
		erasequest 69300;
		end;
	}
	
	if (getcharid(0) == getpartyleader(.@party_id,2))
		dispbottom "Oops.... What am I doing! This is not my house!! I live at #" + HOUSE_NUMBER + ".";
	else
		dispbottom "Oh Gosh... I should leave this group first (use /leave to leave the party)";
		
	emotion e_ag,1;
	end;
	
L_Enter:
	switch(instance_enter(.md_name$)) {
	case 3:
		dispbottom "An unknown error has occurred.";
		end;
	case 2:
		dispbottom "Instance has been destroyed by the Party Leader, or because of the time limit.";
		end;
	case 1:
		mes "Only a member of the party can enter the house.";
		end;
	case 0:
		if (checkquest(69300) == -1) setquest 69300;
	//	set getvariableofnpc(.house,instance_npcname("FrontGate#rent_mb")),atoi(strnpcinfo(2)) -1;
		end;
	}
}


function	script	F_CheckServices	{
	if(getcharid(5) < 4) {
		if(intro < 11) { 
			donpcevent instance_npcname("#b1")+"::OnEnable";
			donpcevent instance_npcname("Manager#inb")+"::OnEnable";
			donpcevent instance_npcname("Maia#rentb1")+"::OnEnable";
			donpcevent instance_npcname("#Housekeeper")+"::OnEnable";
		} else {
//			donpcevent instance_npcname("Inscription Books#Mid")+"::OnEnable";
			if (HOUSE_GARDENER) {
				donpcevent instance_npcname("Maia#rentb1")+"::OnEnable";
			} 
			if (HOUSE_KEEPER) {
				donpcevent instance_npcname("#Housekeeper")+"::OnEnable";
			}
			if (HOUSE_STORAGE) donpcevent instance_npcname("#Storage")+"::OnEnable";
			if (HOUSE_BEDS) donpcevent instance_npcname("#Beds")+"::OnEnable";
			if (HOUSE_OVEN) donpcevent instance_npcname("#Oven")+"::OnEnable";
		}
	} else {
		if(intro < 11) { 
			donpcevent instance_npcname("#a1")+"::OnEnable";
			donpcevent instance_npcname("Maia#renta1")+"::OnEnable";
			donpcevent instance_npcname("#HousekeeperB")+"::OnEnable";
			donpcevent instance_npcname("Manager#ina")+"::OnEnable";
		} else {
//			donpcevent instance_npcname("Inscription Books#Bal")+"::OnEnable";
			if (HOUSE_GARDENER) {
				donpcevent instance_npcname("Maia#renta1")+"::OnEnable";
			}
			if (HOUSE_KEEPER) {
				donpcevent instance_npcname("#HousekeeperB")+"::OnEnable";
			} 
			if (HOUSE_STORAGE) donpcevent instance_npcname("#StorageB")+"::OnEnable";
			if (HOUSE_BEDS) donpcevent instance_npcname("#BedsB")+"::OnEnable";
			if (HOUSE_OVEN) donpcevent instance_npcname("#OvenB")+"::OnEnable";
		}
	}
	return;	
}


// ** Main NPC / Function to Call the Street Dealers
// Usada Para sumonar shops e npcs que fazem parte do sistema de defesa das vilas
// ************************

-	script	StreetDealer	-1,{
	if(getd(".noflood"+strnpcinfo(3)) == 1) end;
	
	if(getd(".noflood"+strnpcinfo(3)) == 2) {
			mes "[ Tomb ]";
		mes "*~~ R.I.P ~~*";
		close;
	}
	

	if(((getcharid(5) > 3) && (strnpcinfo(4) == "rent_mb")) || ((getcharid(5) < 4) && (strnpcinfo(4) == "rent_ma"))) {
		mes "^0000FF[" +strnpcinfo(1)+" ]^000000";
		mes "Get away from me,";
		mes "you little piece of shit!";
		mes " ";
		mes "^FF0000The guards will be here soon";
		mes "and teach you a good lesson!^000000";
		close;
	}
	if(charat(strnpcinfo(2),0) == "S")
		callshop strnpcinfo(2),0;
	else
		callfunc strnpcinfo(2);
	end;

OnTouch:
	if(((getcharid(5) > 3) && (strnpcinfo(4) == "rent_mb")) || ((getcharid(5) < 4) && (strnpcinfo(4) == "rent_ma"))) {
		if(!getd(".noflood"+strnpcinfo(3))) {
			setd(".name"+strnpcinfo(3)+"$"), strnpcinfo(1);
			setd(".noflood"+strnpcinfo(3)), 1; // Controle para q so dispare o alerta uma vez.
			emotion e_hlp;
			npctalk "Heeeeelp!!! Heeeeelp!! HEEEEEEEEEELP!";
//			sleep2 2000;
			soundeffectall "sirens.wav",0,strnpcinfo(4);
			npctalk "CALL THE GUARDS!!!";
			emotion e_hlp;
			mapannounce strnpcinfo(4), "Killing the guards will kill the "+ strnpcinfo(1) + " NPC",bc_area,"0xDD0000",FW_BOLD,18;
			
			getmapxy(.map$,.x,.y,1,strnpcinfo(3)); 

			callfunc "F_CallTheGuards",.x,.y,3, strnpcinfo(3), 5505;

			initnpctimer;
			setd(".oldclass"+strnpcinfo(3)), setnpcdisplay(strnpcinfo(3), 844); 
			
			// Aqui foi preciso editar a funcao setnpcdisplay no source (script.c)
			// para que ela retorne o nd->class_ anterior/original do npc.
			// por default essa funcao retorn 1 ou 0 para sucesso ou nao.
		}
	}
end;

OnTimer60000: // 3 minutos
	if(getd(".noflood"+strnpcinfo(3)) == 2)
		end;
	stopnpctimer;
	setd(".noflood"+strnpcinfo(3)), 0;
	killmonster strnpcinfo(4), strnpcinfo(3)+"::OnMyMobDead";
	mapannounce strnpcinfo(4), "The "+ strnpcinfo(1) + " is back to work. Threats are under control at the moment in the area.",bc_map,"0xffff00";
	setnpcdisplay(strnpcinfo(3), getd(".oldclass"+strnpcinfo(3))); // De volta ao Sprite Original
	end;

OnMyMobDead:
	stopnpctimer;
	set .@mob_dead_num,mobcount("this",strnpcinfo(3)+"::OnMyMobDead");
	if (.@mob_dead_num < 1) {
		achieve(105); // Tough than Tougher
		mapannounce strnpcinfo(4), "The "+ strnpcinfo(1) + " is dead.",bc_map,"0xffff00";
		initnpctimer;
		setd(".noflood"+strnpcinfo(3)), 2;
		setnpcdisplay(strnpcinfo(3), 565); // Sprite quando Morto (801 = Caixao)
	}
	end;

OnTimer10800000: // 3 hours
	stopnpctimer;
	mapannounce strnpcinfo(4), "The "+strnpcinfo(1)+" has been replaced.",bc_map,"0xffff00";
	setd(".noflood"+strnpcinfo(3)), 0;
	setnpcdisplay(strnpcinfo(3), getd(".oldclass"+strnpcinfo(3))); // De volta ao Sprite Original
	callfunc "F_Respawn",strnpcinfo(3);
	end;
}


// *** Function that Summons the guards
// and control de life and death of NPCs
// arg0 = x, arg1 = y, arg2 = amount, arg3 = npc name, arg4 = guard id

function	script	F_CallTheGuards	{
	set .@ally, 0;
	
	if(strnpcinfo(4) == "rent_mb")
		set .@ally, 1;
	else if(strnpcinfo(4) == "rent_ma")
		set .@ally, 4;
	
//	debugmes " ----- Function F_CallTheGuards -----";
//	debugmes "x: " + getarg(0);
//	debugmes "y: " + getarg(1);
//	debugmes "amount: " + getarg(2);
//	debugmes "npc name: " + getarg(3);
//	debugmes "npc id: " + getarg(4);
//	debugmes " ------------------------------------";
	
	//	mobevent <map>,<x>,<y>,<fakename>,<mobid>,<size>,<amount>,<teamid>,<showhp>,<increasehp>,<allied>,<noslaves>,<noexpnodrop>,<poringcoins>,<event>
	mobevent strnpcinfo(4),getarg(0),getarg(1),"Dandelion Soldier",getarg(4),0,getarg(2),.@ally,0,0,0,0,0,0,0,0,0,0,getarg(3)+"::OnMyMobDead";
	return;	
}



function	script	F_OblivionBox	{
//	Base job = classe sem a frescura de baby, high etc.
//	set .@basejob, getarg(0);
//	set .@blvl, getarg(1);
	
//	Rate fixa eh 200
//	e diminui conforme o base level
//	set .@rates, 200 + (2 * BaseLevel);

	set .@equip, rand(1,4); //Decide qual array usar
//	set $@MAXLEVEL, 65;
	
	switch(BaseClass) {
	case Job_Swordman:
		switch(.@equip) {
		case 1:
			// define qual item na array vai ser escolhido baseado no ratio baseLevel / tamanho da array
			// sendo q os itens mais fodao estao sempre no final da array, so level alto terao chance de dropa-los
			
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@SwordmanFoot))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@SwordmanFoot[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@SwordmanFoot[.@i]) + "("+$@SwordmanFoot[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@SwordmanFoot[.@i],1;
				dispbottom "You've got " + getitemname($@SwordmanFoot[.@i]) +"("+$@SwordmanFoot[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
			
		case 2:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@SwordmanArmor))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@SwordmanArmor[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@SwordmanArmor[.@i]) + "("+$@SwordmanArmor[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@SwordmanArmor[.@i],1;
				dispbottom "You've got " + getitemname($@SwordmanArmor[.@i]) +"("+$@SwordmanArmor[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 3:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@SwordmanNeck))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@SwordmanNeck[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@SwordmanNeck[.@i]) + "("+$@SwordmanNeck[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@SwordmanNeck[.@i],1;
				dispbottom "You've got " + getitemname($@SwordmanNeck[.@i]) +"("+$@SwordmanNeck[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 4:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@SwordmanHead))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@SwordmanHead[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@SwordmanHead[.@i]) + "("+$@SwordmanHead[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@SwordmanHead[.@i],1;
				dispbottom "You've got " + getitemname($@SwordmanHead[.@i]) +"("+$@SwordmanHead[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		}
		break;
	
	case Job_Mage:
		switch(.@equip) {
		case 1:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MageFoot))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MageFoot[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MageFoot[.@i]) + "("+$@MageFoot[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MageFoot[.@i],1;
				dispbottom "You've got " + getitemname($@MageFoot[.@i]) +"("+$@MageFoot[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
			
		case 2:
			//set .@range,((getarraysize($@MageArmor) * BaseLevel) / $@MAXLEVEL) * getarraysize($@MageArmor);
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MageArmor))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MageArmor[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MageArmor[.@i]) + "("+$@MageArmor[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MageArmor[.@i],1;
				dispbottom "You've got " + getitemname($@MageArmor[.@i]) +"("+$@MageArmor[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
			
		case 3:
			//set .@range,((getarraysize($@MageNeck) * BaseLevel) / $@MAXLEVEL) * getarraysize($@MageNeck);
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MageNeck))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MageNeck[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MageNeck[.@i]) + "("+$@MageNeck[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MageNeck[.@i],1;
				dispbottom "You've got " + getitemname($@MageNeck[.@i]) +"("+$@MageNeck[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
			
		case 4:
			//set .@range,((getarraysize($@MageHead) * BaseLevel) / $@MAXLEVEL) * getarraysize($@MageHead);
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MageHead))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MageHead[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MageHead[.@i]) + "("+$@MageHead[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MageHead[.@i],1;
				dispbottom "You've got " + getitemname($@MageHead[.@i]) +"("+$@MageHead[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		}
		break;			
	
	case Job_Archer: //		3
		switch(.@equip) {
		case 1:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ArcherFoot))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ArcherFoot[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ArcherFoot[.@i]) + "("+$@ArcherFoot[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ArcherFoot[.@i],1;
				dispbottom "You've got " + getitemname($@ArcherFoot[.@i]) +"("+$@ArcherFoot[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		
		case 2:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ArcherArmor))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ArcherArmor[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ArcherArmor[.@i]) + "("+$@ArcherArmor[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ArcherArmor[.@i],1;
				dispbottom "You've got " + getitemname($@ArcherArmor[.@i]) +"("+$@ArcherArmor[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 3:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ArcherNeck))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ArcherNeck[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ArcherNeck[.@i]) + "("+$@ArcherNeck[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ArcherNeck[.@i],1;
				dispbottom "You've got " + getitemname($@ArcherNeck[.@i]) +"("+$@ArcherNeck[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 4:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ArcherHead))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ArcherHead[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ArcherHead[.@i]) + "("+$@ArcherHead[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ArcherHead[.@i],1;
				dispbottom "You've got " + getitemname($@ArcherHead[.@i]) +"("+$@ArcherHead[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		}
		break;

	case Job_Acolyte: //	4
		switch(.@equip) {
		case 1:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@AcolyteFoot))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@AcolyteFoot[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@AcolyteFoot[.@i]) + "("+$@AcolyteFoot[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@AcolyteFoot[.@i],1;
				dispbottom "You've got " + getitemname($@AcolyteFoot[.@i]) +"("+$@AcolyteFoot[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
	
		case 2:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@AcolyteArmor))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@AcolyteArmor[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@AcolyteArmor[.@i]) + "("+$@AcolyteArmor[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@AcolyteArmor[.@i],1;
				dispbottom "You've got " + getitemname($@AcolyteArmor[.@i]) +"("+$@AcolyteArmor[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 3:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@AcolyteNeck))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@AcolyteNeck[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@AcolyteNeck[.@i]) + "("+$@AcolyteNeck[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@AcolyteNeck[.@i],1;
				dispbottom "You've got " + getitemname($@AcolyteNeck[.@i]) +"("+$@AcolyteNeck[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 4:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@AcolyteHead))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@AcolyteHead[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@AcolyteHead[.@i]) + "("+$@AcolyteHead[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@AcolyteHead[.@i],1;
				dispbottom "You've got " + getitemname($@AcolyteHead[.@i]) +"("+$@AcolyteHead[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		}
		break;

	case Job_Merchant: //	5
		switch(.@equip) {
		case 1:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MerchantFoot))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MerchantFoot[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MerchantFoot[.@i]) + "("+$@MerchantFoot[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MerchantFoot[.@i],1;
				dispbottom "You've got " + getitemname($@MerchantFoot[.@i]) +"("+$@MerchantFoot[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
	
		case 2:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MerchantArmor))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MerchantArmor[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MerchantArmor[.@i]) + "("+$@MerchantArmor[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MerchantArmor[.@i],1;
				dispbottom "You've got " + getitemname($@MerchantArmor[.@i]) +"("+$@MerchantArmor[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 3:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MerchantNeck))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MerchantNeck[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MerchantNeck[.@i]) + "("+$@MerchantNeck[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MerchantNeck[.@i],1;
				dispbottom "You've got " + getitemname($@MerchantNeck[.@i]) +"("+$@MerchantNeck[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 4:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@MerchantHead))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@MerchantHead[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@MerchantHead[.@i]) + "("+$@MerchantHead[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@MerchantHead[.@i],1;
				dispbottom "You've got " + getitemname($@MerchantHead[.@i]) +"("+$@MerchantHead[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		}
		break;

	case Job_Thief: //		6
		switch(.@equip) {
		case 1:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ThiefFoot))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ThiefFoot[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ThiefFoot[.@i]) + "("+$@ThiefFoot[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ThiefFoot[.@i],1;
				dispbottom "You've got " + getitemname($@ThiefFoot[.@i]) +"("+$@ThiefFoot[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
	
		case 2:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ThiefArmor))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ThiefArmor[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ThiefArmor[.@i]) + "("+$@ThiefArmor[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ThiefArmor[.@i],1;
				dispbottom "You've got " + getitemname($@ThiefArmor[.@i]) +"("+$@ThiefArmor[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 3:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ThiefNeck))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ThiefNeck[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ThiefNeck[.@i]) + "("+$@ThiefNeck[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ThiefNeck[.@i],1;
				dispbottom "You've got " + getitemname($@ThiefNeck[.@i]) +"("+$@ThiefNeck[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		case 4:
			set .@range, (((BaseLevel * 100) / $@MAXLEVEL) * (getarraysize($@ThiefHead))) / 100;
			if(.@range < 3) set .@range, 3;
			set .@i, rand(0,(.@range-1));
			if(BaseLevel >= 50 ) { // apartir do level 50 todos os equips sao bounded ao personagem
				getitembound $@ThiefHead[.@i],1,Bound_Account;
				dispbottom "You've got " +getitemname($@ThiefHead[.@i]) + "("+$@ThiefHead[.@i]+")" + " (bounded) from the Oblivion Box";
			} else {
				getitem $@ThiefHead[.@i],1;
				dispbottom "You've got " + getitemname($@ThiefHead[.@i]) +"("+$@ThiefHead[.@i]+")"+ " (unbound) from the Oblivion Box";
			}
			break;
		}
		break;

	case Job_Knight: //		7
	end; break;

	case Job_Priest: //		8
	end; break;

	case Job_Wizard: //		9
	end; break;

	case Job_Blacksmith: //	10
	end; break;

	case Job_Hunter: //		11
	end; break;

	case Job_Assassin: //	12
	end; break;

	case Job_Knight2: //	13
	end; break;

	case Job_Crusader: //	14
	end; break;

	case Job_Monk: //		15
	end; break;

	case Job_Sage: //		16
	end; break;

	case Job_Rogue: //		17
	end; break;

	case Job_Alchemist: //	18
	end; break;

	case Job_Bard: //		19
	end; break;

	case Job_Dancer: //		20
	end; break;

	case Job_Crusader2: //	21
	end; break;

	case Job_Wedding: //	22
	end; break;

	case Job_SuperNovice: //23
	end; break;

	case Job_Gunslinger: //	24
	end; break;

	case Job_Ninja: //		25
	end; break;
	}
	
	if(.@i == 0) { 
		getitem 617,1;
		set Zeny, Zeny + BaseLevel * 100;
		dispbottom "You've got " + BaseLevel * 100 + "z from the Oblivion Box";
		dispbottom "You've got a " + getitemname(617) + " from the Oblivion Box";
		if(rand(10+BaseLevel) == 0) {
			callfunc "F_BumpStats", "luk",1;
		}
	}
}





function	script	myAlly	{
	if(getarg(0) < 4)
		return 1;
	else
		return 2;
}

function	script	F_CheckHostile	{
	if((getarg(0) == "rent_mb") && (myAlly(getcharid(5)) != getarg(1)))
		return true;
	else
		return false;
}



-	script	NPCVarsN	-1,{
	end;


OnInit:
	bindatcmd "setvar",strnpcinfo(3)+"::OnAtcommand";
	end;
OnAtcommand:
OnWhisperGlobal:
	if (getgmlevel() < 80) end; // No acepta Players ni Cops
	set @Nombre$, @whispervar0$ + .@atcmd_parameters$[0];
	if (getstrlen(@whispervar1$) > 0) set @Nombre$, @whispervar1$;
	if (getstrlen(@Nombre$) < 4 || getstrlen(@Nombre$) > 24) {
		dispbottom "[El nombre ingresado es incorrecto]";
		end;
	}
	set @RID, getcharid(3,@Nombre$);
	if (@RID < 1) {
		dispbottom "[El personaje no existe o no está conectado]";
		end;
	}
	// Encontrado el Personaje

L_Consulta:
	mes "^0000FF[NPC Vars Info]^000000";
	mes "Ha solicitado información de Variables.";
	mes "Personaje: ^0000FF" + @Nombre$ + "^000000";
	mes "¿Que variable deseas consultar (solamente numéricos)?";
	next;
	input @Variable$;

L_Verificar:
	set $@GMid, playerattached(); // El ID del GM para regresar al proceso luego de la consulta
	set $@Variable$, @Variable$;
	if (attachrid(@RID) > 0) {
		set $@Valor, getd($@Variable$); // Obtiene el Valor
		if (attachrid($@GMid)) {
			set @Resultado, $@Valor;
			mes "^0000FF[NPC Vars Info]^000000";
			mes "El valor de " + @Variable$ + " es de " + @Resultado + ".";
			mes "Que deseas hacer con esto?";
			next;
			menu "Consultar otra variable",L_Consulta,"Cambiar el valor actual",L_Cambiar,"Finalizar consultas",-;
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Utiliza la herramienta cuando lo necesites";			
			close;
		} else end; // El GM se desconectó
	} else {
		// Se desconectó
		if (attachrid($@GMid)) {
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Lo lamento, el jugador se ha desconectado.";
			mes "Si quieres consultar a alguien más vuelve a whispearme";
			close;
		} else end; // El GM se desconectó
	}
	end;

L_Cambiar:
	if( @Variable$ == "##CASHPOINTS" || @Variable$ == "#KAFRAPOINTS" )
	{
		mes "^0000FF[NPC Vars Info]^000000";
		mes "Estas variables están bloqueadas por seguridad!!";
		mes "Evita problemas con la Administración.";
		close;
	}

	mes "^0000FF[NPC Vars Info]^000000";
	mes "Que valor deseas ponerle a la variable ^0000FF" + @Variable$ + "^000000 para el jugador ^0000FF" + @Nombre$ + "^000000";
	mes "(Valor Actual: ^0000FF" + @Resultado + "^000000)";
	next;
	input @Valor; // Solo numerico permite
	set $@GMid, playerattached(); // El ID del GM para regresar al proceso luego de la consulta
	set $@Variable$, @Variable$;
	set $@OldValor, @Resultado;
	set $@Valor, @Valor;
	if (attachrid(@RID) > 0) {
		setd $@Variable$, $@Valor; // Actualiza el Valor
		logmes "Variable " + $@Variable$ + " de " + strcharinfo(0) + " cambio de " + $@OldValor + " a " + $@Valor + " por " + $@GMid + ".";
		if (attachrid($@GMid)) {
			mes "^0000FF[NPC Vars Info]^000000";
			mes "El Valor ha sido cambiado a " + @Valor + ".";
			mes "Que deseas hacer ahora?";
			next;
			menu "Verificar el cambio",L_Verificar,"Volver a cambiar",L_Cambiar,"Consultar otra Variable",L_Consulta,"Finalizar consultas",-;
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Utiliza la herramienta cuando lo necesites";			
			close;
		} else end; // El GM se desconectó
	} else {
		// Se desconectó
		if (attachrid($@GMid)) {
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Lo lamento, el jugador se ha desconectado.";
			mes "Si quieres consultar a alguien más vuelve a whispearme";
			close;
		} else end; // El GM se desconectó
	}
}





// Inscription System
// ********************************************************

// Main Inscription Engine
// arg(0) = Book Level
// arg(1) = Posicao na array da carta a ser criada.

function	script	Inscription_Work	{
	
	// Check Requeriments
	if( getarg(0) < 0 || getarg(0) > 7 ) end;
	if( getarg(1) < 0 ) end;
	
	set @Book_Lvl, getarg(0); 
	set @pos, getarg(1);
	set @Carta_ID, getd("$@Cartas_" + @Book_Lvl + "_ID[" + @pos + "]");
	set @Carta_RT, getd("$@Cartas_" + @Book_Lvl + "_RT[" + @pos + "]");

	// * Working Level
	if( InscriptionLvl < @Book_Lvl ) {
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "Your scribe skills are not high enough to handle this book.";
		mes "Required Level: ^FF0000" + $@InscriptionTitle$[@Book_Lvl] + " Scribe^000000";
		mes " ";
		mes ">> ^FF0000" + $@InscriptionTitle$[InscriptionLvl] + "^000000 <<";
		set @Progress, (InscriptionExp * 30) / $@InscriptionLUp[InscriptionLvl];
		progressbar "0000FF",@progress;
		close;
	}
	
	/////////////////////////////////////////////
	// Checking items necessary to write cards //
	/////////////////////////////////////////////
	
	set .@tmp1, 0;
	set .@tmp2, 0;
	set .@tmp3, 0;
	
	if( countitem(7433) < 1 ) 							set .@tmp1, 1;  // Blank Scroll
	if( countitem($@InscriptionDyeID[@Book_Lvl]) < 1 ) 	set .@tmp2, 1; // Dyestuff
	if( countitem(@Carta_RT) < 1 ) 						set .@tmp3, 1; // Reagent for the card

	if (.@tmp1 > 0) || (.@tmp2 > 0) || (.@tmp3 > 0) {
		next;
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "Oh, crap! I've ran out of ";
		mes "[ ^FF0000";
		if (.@tmp1 > 0) mes getitemname(7433);
		if (.@tmp2 > 0) mes getitemname($@InscriptionDyeID[@Book_Lvl]);
		if (.@tmp3 > 0) mes getitemname(@Carta_RT); 
		mes "^000000 ]";
		close;
	}


//	mes ">> ^FF0000" + $@InscriptionTitle$[InscriptionLvl] + "^000000 <<";
//	if( InscriptionLvl < 7 ) {
//		set @Progress, (InscriptionExp * 30) / $@InscriptionLUp[InscriptionLvl];
//		progressbar "0000FF",@progress;
//	}

//	next;
	

L_CardConfection:
	next;
	// Success
	mes "[^0000FF" + strcharinfo(0) + "^000000]";
	mes "Ok, lets see the outcome of my hard work...";
	close2;
	set @casting, (InscriptionLvl + 1) * 5;
	progressbar "0x0000FF",@casting;
	
	soundeffect "the_paper_die.wav",0;
	specialeffect 135;
	emotion e_grat,1;
	
	delitem 7433,1;								// Blank Scroll
	delitem $@InscriptionDyeID[@Book_Lvl],1;	// Dye accordingly to the scribe level
	delitem @Carta_RT,1;						// Reagent for the desired Card
	getitem @Carta_ID,1;	
	
	// Exp Progress
	if( InscriptionLvl < 7 )
	{
		set InscriptionExp, InscriptionExp + $@Inscription_Exp[@Book_Lvl];
		if( InscriptionExp >= $@InscriptionLUp[InscriptionLvl] ) {
			// Level Up
			set InscriptionLvl, InscriptionLvl + 1;
			set InscriptionExp, 0;
	//		specialeffect2 568;
			specialeffect2 409;
			dispbottom "[You've become a " + $@InscriptionTitle$[InscriptionLvl] + " Scribe.]";
		} else {
			set @Progress, (InscriptionExp * 100) / $@InscriptionLUp[InscriptionLvl];
			dispbottom "[ Current: " + $@InscriptionTitle$[InscriptionLvl] + " Scribe [" + @Progress + "%] -> Next: " + $@InscriptionTitle$[InscriptionLvl + 1] + " Scribe ]";
		}
		end;
	}
	
	goto L_CardConfection;
}


function	script	Inscription_DropInfo	{
	set @Book_Lvl, getarg(0);
	if (@Book_Lvl > InscriptionLvl) {
	L_Start:
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "Oh dear... Wrong book!";
		mes "This is the ^0000FF" + $@InscriptionTitle$[@Book_Lvl] + " Scribe Book^000000";
		mes "and I am still a ^FF0000" + $@InscriptionTitle$[InscriptionLvl] + " Scribe^000000.";
		close;
	}
	if (select("^888800Chapter I DyeStuff:^FF0099Chapter II Inscription^000000") == 1) { 
		callfunc "F_DyeMaking";
		end;
	}
		
	set .@menu$, "^FF0000Close The Book^000000:" + implode(getd("$@Cartas_" + @Book_Lvl + "_NM$"),":"); //Menu
	if (select(.@menu$) == 1) { 
		close;
	} else {
		set @choice, @menu-2;
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "The book says:"; 
		mes "Card : ^0000FF [ " + getitemname(getd("$@Cartas_" + @Book_Lvl + "_NM$["+ @choice +"]")) + " ] ^000000";
		mes "Materials:";
		mes "  1x" + (countitem(7433)?"^0000FF [ ":"^FF0000 [ ") + getitemname(7433) + " ]^000000";
		mes "  1x" + (countitem($@InscriptionDyeID[(@Book_Lvl)])?"^0000FF [ ":"^FF0000 [ ") + getitemname($@InscriptionDyeID[(@Book_Lvl)]) + " ]^000000";
		mes "  1x" + (countitem(getd("$@Cartas_" + @Book_Lvl + "_RT["+ @choice +"]"))?"^0000FF [ ":"^FF0000 [ ") + getitemname(getd("$@Cartas_" + @Book_Lvl + "_RT["+ @choice +"]")) + " ]^000000.";
	
		if (select("^FF0000Cancel^000000:Create Card") == 1) {
		goto L_Start;
		//	close;
		} else {
			callfunc "Inscription_Work", @Book_Lvl, @choice;
		}
	}
	
		
//		if (countitem(getd("$@Cartas_" + @Book_Lvl + "_RT["+ @choice +"]")) ) > 0 {
//			if (select("^FF0000Cancel^000000:Create Card") == 1) {
//				close;
//			} else {
//				next;
//				callfunc "Inscription_Work", @Book_Lvl, @choice;
//			}
//		} else {
//			mes "Do you know how to get it?";
//			if( isPremium() == 1 )
//				atcommand "@whodrops " + getd("$@Cartas_" + getarg(0) + "_RT["+ @choice +"]");
//			close;
//		}
//	}
//	return;
	
//	while(.@i++-1<.@len)
//		if(!countitem(.@items[.@i-1]))
//			break;
//
//	if (.@i==.@len)
//		npctalk "You have all the items!";
//
//	end;
	
	
	
//	set @Size, getarraysize(getd("$@Cartas_" + getarg(0) + "_ID"));
//	set .@Return$, "";
//	set .@Comma$, "";
//	for( set @i, 40; @i < @Size; set @i, @i + 1 )
//	{
//		//set .@Return$, .@Return$ + .@Comma$ + "^0000FF" + getitemname(getd("$@Cartas_" + getarg(0) + "_ID[" + @i + "]")) + "^000000";
//		set .@Return$, .@Return$ + .@Comma$ + "^0000FF" + getitemname(getd("$@Cartas_" + getarg(0) + "_ID[" + @i + "]")) + "^000000";
//		set .@Comma$, ", ";
//	}
//	
//	return .@Return$;
}


// Information NPCs
// arg(0) Inscription Level


function	script	Inscription_Info	{
	set @Inscription_Lvl, $@Inscription_Lvl[getarg(0)];
	set @Book_Lvl, getarg(0);
	
	mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
	mes "I can centainly help you to craft some ^FF0000" + $@InscriptionTitle$[@Inscription_Lvl] + "^000000 cards.";
	if( @Inscription_Lvl < 7 )
		mes "I am working hard to become a ^FF0000" + $@InscriptionTitle$[@Inscription_Lvl + 1] + "^000000 Scribe just like you...";
	else
		mes "I'm an Illustrious scribe and I can pretty much craft any card in the world.";
	next;
	mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
	mes "Can I help you?";
	next;
	switch( select("Open Shop:Tell me about Inscription:Tell me about Card Types:Dye Making:No thanks.") )
	{
		case 1:
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			close2;
			callshop "Inscription Shop",1;
			end;
			break;

		case 2:
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			mes "Since the Ragnarok, Scribes've been passing their knowledge generation after generation.";
			next;
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			mes "Scribes are the only ones capable of mimic ancient cards and enchant them with magical powers.";
			next;
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			mes "Anyone can become a Scribe. You just need patience and practice.";
			next;
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			mes "More you practice, more experience you'll get, more skilled you'll become.";
			next;
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Mine^000000]";
			mes "There are 8 different levels for Inscrption:";
			mes "- Lvl 0 : ^009900Apprentice^000000";
			mes "- Lvl 1 : ^669900Journeyman^000000";
			mes "- Lvl 2 : ^999900Skilled^000000";
			mes "- Lvl 3 : ^CC9900Expert^000000";
			mes "- Lvl 4 : ^FFCC00Artisan^000000";
			mes "- Lvl 5 : ^FF9900Master^000000";
			mes "- Lvl 6 : ^FF6600Grand Master^000000";
			mes "- Lvl 7 : ^FF0000Illustrious^000000";
			break;

		case 3:
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			mes "Depending on your Inscription level, you can craft different sets of cards:";
			set @InfoCards, 0;
			while( @InfoCards != 9 )
			{
				next;
				set @InfoCards, select("Apprentice:Journeyman:Skilled:Expert:Artisan:Master:Grand Master:Illustrious:Thanks for the Info");
				switch( @InfoCards )
				{
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
						mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
						mes "For [^0000FF" + $@InscriptionTitle$[(@InfoCards-1)] + " Cards]^000000";
						mes "you'll need:";
						mes "1x " + $@InscriptionTitle$[(@InfoCards-1)] + " Scribe Book;";
						mes "1x ^FF0000"+getitemname($@InscriptionDyeID[(@InfoCards-1)])+"^000000;";
						mes "1x Blank Scroll;";
						
						set .@menu$, implode(getd("$@Cartas_" + (@InfoCards-1) + "_NM$"),":"); //Menu
						select(.@menu$);
						
						mes "1x " + getitemname(getd("$@Cartas_" + (@InfoCards-1) + "_RT["+ (@menu-1) +"]"));
						break;
					case 9:
						mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
						mes "A pleasure to help.";
						break;
				}
			}
			break;
		case 4:
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			close2;
			callfunc "F_DyeMaking";
			end;
			break;
		case 5:
			mes "[^0000FF" + $@InscriptionTitle$[@Inscription_Lvl] + " Scribe^000000]";
			mes "Then get to work!!";
			break;
	}
	close;
}


function	script	F_DyeMaking	{
	if ((MaxWeight-Weight) < 200 || checkweight(1201,1) == 0) {
		mes "- Wait a moment! -";
		mes "- I have too many items with me -";
		mes "- I'll need to free up some space -";
		mes "- before I can go ahead with this -";
		close;
	}
	mes "^0000FF[" + strcharinfo(0) + "]^000000";
	mes "Humm... I wonder this is a good time to mix a few dyestuffs...";
	next;
	switch(select("Yes... I'm in a good mood:Nah... Maybe later")) {

	case 1:
		mes "^0000FF[" + strcharinfo(0) + "]^000000";
		mes "Which colour should I start with? Let me see...";
		next;
		switch(select("Scarlet Dyestuffs:Lemon Dyestuffs:Cobaltblue Dyestuffs:Darkgreen Dyestuffs:Orange Dyestuffs:Violet Dyestuffs:White Dyestuffs:Black Dyestuffs:Cancel")) {
		case 1: callsub S_MakeDye,1,1; break;
		case 2: callsub S_MakeDye,2,1; break;
		case 3: callsub S_MakeDye,3,2; break;
		case 4: callsub S_MakeDye,4,3; break;
		case 5: callsub S_MakeDye,5,4; break;
		case 6: callsub S_MakeDye,6,4; break;
		case 7: callsub S_MakeDye,7,4; break;
		case 8: callsub S_MakeDye,8,4; break;
		case 9:
			mes "^0000FF[" + strcharinfo(0) + "]^000000";
			mes "I've changed my mind... I'll do this later.";
			close;
		}

	case 2:
		mes "^0000FF[" + strcharinfo(0) + "]^000000";
		mes "Yeah... that's what I thought: Later.";
		close;
	}

S_MakeDye:
	mes "^0000FF[" + strcharinfo(0) + "]^000000";
	switch(getarg(0)) {
	case 1:
		mes "Mmm... I need"; 
		mes "30x Red Herbs,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Red Dyestuffs.";
		setarray .@item[0], 507, 973, 713;
		setarray .@count[0], 30,   1,   1;
		set .@cost,3000;
		set .@dyestuff,975;
		break;
	case 2:
		mes "Mmm... I need"; 
		mes "30x Yellow Herbs,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Lemon Dyestuffs.";
		setarray .@item[0], 508, 973, 713;
		setarray .@count[0], 30,   1,   1;
		set .@cost,3000;
		set .@dyestuff,976;
		break;
	case 3:
		mes "Mmm... I need"; 
		mes "20x Blue Herbs,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Cobaltblue Dyestuffs.";
		setarray .@item[0], 510, 973, 713;
		setarray .@count[0], 20,   1,   1;
		set .@cost,3500;
		set .@dyestuff,978;
		break;
	case 4:
		mes "Mmm... I need"; 
		mes "5x Blue Herbs,";
		mes "20x Green Herbs,";
		mes "20x Yellow Herbs";
		mes "1x Mixture,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Darkgreen Dyestuffs.";
		setarray .@item[0], 510, 511, 508, 974, 973, 713;
		setarray .@count[0],  5,  20,  20,   1,   1,   1;
		set .@cost,5000;
		set .@dyestuff,979;
		break;
	case 5:
		mes "Mmm... I need"; 
		mes "20x Red Herbs,";
		mes "20x Yellow Herbs";
		mes "1x Mixture,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Orange Dyestuffs.";
		setarray .@item[0], 507, 508, 974, 973, 713;
		setarray .@count[0], 20,  20,   1,   1,   1;
		set .@cost,5000;
		set .@dyestuff,980;
		break;
	case 6:
		mes "Mmm... I need"; 
		mes "10x Blue Herbs";
		mes "30x Red Herbs,";
		mes "1x Mixture,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Violet Dyestuffs.";
		setarray .@item[0], 510, 507, 974, 973, 713;
		setarray .@count[0], 10,  30,   1,   1,   1;
		set .@cost,5000;
		set .@dyestuff,981;
		break;
	case 7:
		mes "Mmm... I need"; 
		mes "30x White Herbs,";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make White Dyestuffs.";
		setarray .@item[0], 509, 973, 713;
		setarray .@count[0], 30,   1,   1; 
		set .@cost,3000;
		set .@dyestuff,982;
		break;
	case 8:
		mes "Mmm... I need"; 
		mes "30x of each Red, Yellow and Green Herb";
		mes "5x Blue Herbs";
		mes "1x Mixture";
		mes "1x Counteragent, and";
		mes "1x Empty Bottle";
		mes "to make Red Dyestuffs.";
		setarray .@item[0], 507, 508, 511, 510, 974, 973, 713;
		setarray .@count[0], 30,  30,  30,   5,   1,   1,   1;
		set .@cost,7000;
		set .@dyestuff,983;
		break;
	}
	next;
	mes "^0000FF[" + strcharinfo(0) + "]^000000";
	mes "Ah! I think I've got everything ready. Should I start the process?";

	next;
	if (select("Make Dyestuffs:Cancel") == 1) {
		set .@size, getarraysize(.@item);
		// check requirements
		for( set .@i,0 ; .@i < .@size ; set .@i,.@i+1 )
			if( countitem(.@item[.@i]) < .@count[.@i] )
				break;
		if( .@i < .@size) {
			mes "^0000FF[" + strcharinfo(0) + "]^000000";
			mes "Hmmm... Crap! Something is missing...";
			close;
		}
		// delete items
		for (set .@i, 0; .@i < .@size ; set .@i, .@i+1)
			delitem .@item[.@i], .@count[.@i];
		// get dyestuff
		getitem .@dyestuff,1;
		
		mes "^0000FF[" + strcharinfo(0) + "]^000000";
		mes "Hmm... It came out pretty well. A very rich color. Of course I'll be trying harder to make a more charming color...";
		close;
	}
	mes "^0000FF[" + strcharinfo(0) + "]^000000";
	mes "Eeeehhhh!! What's this?";
	mes "I g2g! I am so late!";
	return;
}
