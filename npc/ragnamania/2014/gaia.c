// ********************************************
// Mapflags
// ********************************************

gaia	mapflag	nobranch
gaia	mapflag	noicewall
gaia	mapflag	nomemo
gaia	mapflag	nopenalty
gaia	mapflag	pvp	off
gaia	mapflag	partylock
gaia	mapflag	nodrop
gaia	mapflag	nomobloot

bif_fild01	mapflag	nobranch
bif_fild01	mapflag	nomemo
bif_fild01	mapflag	pvp	off
bif_fild01	mapflag	noreturn
bif_fild01	mapflag	nowarp
bif_fild01	mapflag	nowarpto
bif_fild01	mapflag	partylock

bif_fild02	mapflag	nobranch
bif_fild02	mapflag	nomemo
bif_fild02	mapflag	pvp	off
bif_fild02	mapflag	noreturn
bif_fild02	mapflag	nowarp
bif_fild02	mapflag	nowarpto
bif_fild02	mapflag	partylock

1@ma_h	mapflag	nobranch
1@ma_h	mapflag	nomemo
1@ma_h	mapflag	pvp	off
1@ma_h	mapflag	noreturn
1@ma_h	mapflag	nowarp
1@ma_h	mapflag	nowarpto
1@ma_h	mapflag	partylock


gaia,89,99,0	script	WelcomeMessage	-1,3,3,{
	end;
OnTouch:
	getmapxy(@mapname$,@mapx,@mapy,0);
	if((@mapname$ == "gaia") && (!intro)) {
		mes "^FF0000Bem vindo ao";
		mes "Ragnamania Oblivion!";
		mes "Este eh provavelmente o unico";
		mes "dialogo em Portugues que";
		mes "voce vera ingame, portanto";
		mes "por favor leia com atencao.";
		next;
		mes "^FF0000Ragnamania Oblivion eh um";
		mes "servidor altamente customizado.";
		mes "A ideia eh simples:";
		mes "Para comemorarmos os 10 anos";
		mes "de Ragnamania,";
		next;
		mes "^FF0000Decidi lancar um servidor";
		mes "para resgatar o feeling de 2004";
		mes "e deixar todo mundo noob.";
		next;
		mes "^FF0000DICAS:";
		mes "Nada de Pro-Play: Ligue o Som!";
		mes "Muitas dicas serao passadas por audio. E com o audio desligado voce pode ter a impressao de que esta travado ou algo do tipo.";
		next;
		mes "^FF0000Animacao rolando...";
		mes "nao clique! O emulador tem suas limitacoes e, se estiver rolando uma animacao com NPCs andando ou seu char, nao clique no seu char ou no NPC... Voce vai bugar e nao vai pro ceu.";
		next;
		mes "^FF0000Cartas";
		mes "Em Oblivion cartas nao dropam de monstros. Voce confecciona cartas com Inscription. Voce entendera melhor logo mais.";
		next;
		mes "^FF0000Oblivion Boxes";
		mes "Em Oblivion todos os monstros dropam Oblivion Boxes com alguma chance. Agora, fique atento sobre Oblivion Boxes:";
		next;
		mes "^FF0000Elas podem ser vendidas;";
		mes "Elas SEMPRE lhe darao um equipamento para sua Classe (Arma ou Armadura)";
		mes "Ate o level 49, os itens vindos das Oblivion Boxes nao sao presos ao seu char;";
		next;
		mes "^FF0000Apartir do level 50, se voce abrir uma Oblivion Box, o equipamento vai ser 'Bounded' e so podera ser usado char que abriu a caixa.";
		next;
		mes "^FF0000Instancias";
		mes "Quase todos os mapas de up podem ser instanciados para voce e sua party. Ao entrar no mapa, se em party, lhe sera mostrado a opcao se voce gostaria de instanciar o mapa ou nao.";
		next;
		mes "^FF0000Midgardians e Baldurians";
		mes "Muitos mapas sao hostis e PvP entre as duas tribos. Fique atento!";
		next;
		mes "^FF0000Tamanho dos personagens";
		mes "Voce pode optar por fazer seu char Pequeno, Medio ou Grande. Visualmente nada muda mas, para o calculo de dano sim. Use com sabedoria";
		next;
		mes "^FF0000Fora isso, fique ligado... incluimos MUITOS Easter-Eggs e muita passagem secreta, achievements, etc.";
		next;
		mes "^FF0000Espero que voces se divirtam jogando tanto quanto eu me diverti criando este server =D";
		next;
		mes "^FF0000Agradecimentos especiais a todos que colaboraram na criacao do servidor, direta ou indiretamente e a toda a comunidade Ragnamania. Muah!^000000";
		intro = -1;
		close;
	}
end;
}

gaia,89,139,4	script	Gaia	624,15,15,{
	mes "^ff0000[Gaia]^000000";
	if(SkillPoint != 0) {
		mes "My Goodness!! I've said: Distribute your S-K-I-L-L  P-O-I-N-T-S before coming to talk to me!!";
		mes "Now begone!";
		npctalk "Who's the next dumbhead in the queue?";
		close;
	}
	
	if(getcharid(5) == 0) {
		mes "It is time for you to choose your path in the World of the Living...";
		next;
		mes "^ff0000[Gaia]^000000";
		mes "You need to choose if you're gonna represent the ^FF9900Baldurians^000000 or the ^00CCFFMidgardians^000000 ";
		next;
		mes "^ff0000[Gaia]^000000";
		mes "Also, you'll choose the size of your character.";
		mes " ";
		mes "^FF0000The size does not actually change they way your character is shown ingame. It only affects the formula when calculating damage.^000000";
		next;
		switch(select("^FF9900Baldurian - Small^000000:^FF9900Baldurian - Median^000000:^FF9900Baldurian - Broad^000000:^00CCFFMidgardian - Small^000000:^00CCFFMidgardian - Median^000000:^00CCFFMidgardian - Broad^000000::I need more time to decide")) {
		case 1:
			setfaction 4;
			set FACTION$, "Baldurian";
//			set CHARSIZE$, "Small";
			next;
			break;
		case 2:
			setfaction 5;
			set FACTION$, "Baldurian";
//			set CHARSIZE$, "Median";
			next;
			break;
		case 3:
			setfaction 6;
			set FACTION$, "Baldurian";
//			set CHARSIZE$, "Broad";
			next;
			break;
		case 4:
			setfaction 1;
			set FACTION$, "Midgardian";
//			set CHARSIZE$, "Small";
			next;
			break;
		case 5:
			setfaction 2;
			set FACTION$, "Midgardian";
//			set CHARSIZE$, "Median";
			next;
			break;
		case 6:
			setfaction 3;
			set FACTION$, "Midgardian";
//			set CHARSIZE$, "Broad";
			next;
			break;
		case 7:
			mes "^ff0000[Gaia]^000000";
			mes "Sure... no problem.";
			close;
		}
		mes "^ff0000[Gaia]^000000";
		mes "All set... Please head to the Gate Keeper... She will pass you further instructions.";
		close;
	}
	
	if (Class != Job_Novice) { 
		mes "Please, talk to the Gate Keeper.";
		close;
	} else {
		mes "Hello, ^0000FF" + strcharinfo(0) + "^000000.";
		mes "Are you ready to embrace your adventure in the world of the living?";
		next;
		if(select("No","Yes") == 2) {
			if(Class == Job_Novice) && (JobLevel == 10) {
				mes "^ff0000[Gaia]^000000";
				mes "I am glad to hear that!  We are almost there...";
				next;
				mes "^ff0000[Gaia]^000000";
				mes "You must decide which role you're gonna play in the Game of Life:";
//				switch(select("Swordsman","Mage","Archer","Acolyte","Merchant","Thief",
//				"Super Novice","Taekwon","Gunslinger","Ninja"))
				switch(select("Swordsman","Mage","Archer","Acolyte","Merchant","Thief"))
				{
					case 7:
						set @target_job, Job_SuperNovice;
						break;
					case 8:
						set @target_job, Job_Taekwon;
						break;
					case 9:
					case 10:
						set @target_job, @menu + 15;
						break;
					default:
						set @target_job, @menu;
					break;
				}
			} else {
				mes "No Donuts for you today! Something just went wrong I am afraid to tell...";
				logmes "ERROR. NPC: Gaia. Character:" + getcharid(0) + ". Impossible to choose first class.";
				next;
				mes "^ff0000[Gaia]^000000";
				mes "^FF0000A log has been generated and the Staff has been notified. Please ask for support.^000000";
				close;
			}
			next;
			mes "^ff0000[Gaia]^000000";
			mes "Are you sure you want to become an " + jobname(@target_job) + "? Are you sure you have the guts for that?";
			if(select("No","Yes") == 2) {
				soundeffect "jobchange.wav",0;
				sleep2 2000;
				specialeffect2 908;
				sleep2 7000;
				specialeffect2 908;
				sleep2 5500;
				callfunc "Job_Change", @target_job;
				
				if(@target_job == Job_Gunsliger || @target_job == Job_Ninja || @target_job == Job_Taekwon) {
					callfunc "F_ClearJobVar";
				} else {
					if($@JC_Plat) goto L_GivePlat;
				}
			} else {
				next;
				mes "^ff0000[Gaia]^000000";
				mes "I can't believe.... What now?";
				next;
				mes "^ff0000[Gaia]^000000";
				mes "Hurry up! I don't want you buzzing here for the whole eternity!";
			}
			close;
		} else {
			mes "What is so difficult about this?";
			next;
			mes "^ff0000[Gaia]^000000";
			mes "Who do you think you are? The Queen of Denmark?";
			next;
			mes "^ff0000[Gaia]^000000";
			mes "Hurry up! I don't want you buzzing here for the whole eternity!";
		}
		close;

	L_GivePlat:
		if (BaseClass==Job_SuperNovice) goto L_sSuperN;
		if (BaseClass==Job_Swordman) goto L_sSword;
		if (BaseClass==Job_Mage) goto L_sMage;
		if (BaseClass==Job_Archer) goto L_sArcher;
		if (BaseClass==Job_Acolyte) goto L_sAcolyte;
		if (BaseClass==Job_Merchant) goto L_sMerchant;
		if (BaseClass==Job_Thief) goto L_sThief;
		close;
	L_sSuperN:
		skill 142,1,0;
		close;
	L_sSword:
		skill 142,1,0;
		skill 144,1,0;
		skill 145,1,0;
		skill 146,1,0;
		close;
	L_sMage:
		skill 142,1,0;
		skill 157,1,0;
		close;
	L_sArcher:
		skill 142,1,0;
		skill 147,1,0;
		skill 148,1,0;
		close;
	L_sAcolyte:
		skill 142,1,0;
		skill 156,1,0;
		close;
	L_sMerchant:
		skill 142,1,0;
		skill 153,1,0;
		skill 154,1,0;
		skill 155,1,0;
		close;
	L_sThief:
		skill 142,1,0;
		skill 149,1,0;
		skill 150,1,0;
		skill 151,1,0;
		skill 152,1,0;
		close;
	
	OnTouch:
		if (Class == Job_Novice) && (JobLevel == 1) {
			atcommand "@joblevel 9";
			skill 142,1,0;
			skill 143,1,0;
			announce "Gaia: Check your Skill Points before you get any closer!",bc_self, 0x00ff00,0,18;
		}
		end;
	}
}



// Beams of light
gaia,80,145,1	script	Beamsoflight	111,{
OnInit:
	initnpctimer;
	set .x, rand(80,99);
	set .y, rand(99,127);
	set .pilar, rand(322,324);
	movenpc "Beamsoflight",.x,.y;
	specialeffect(.pilar);
	end;

OnEnable:
	initnpctimer;
	end;

OnTimer12000:
	stopnpctimer;
	set .x, rand(80,99);
	set .y, rand(99,127);
	set .pilar, rand(322,324);
	movenpc "Beamsoflight",.x,.y;
	specialeffect(.pilar);
	donpcevent "Beamsoflight::OnEnable";
	end;
}



// Guardiao do Portal
gaia,98,136,4	script	Gate Keeper	403,{

	if(Class == Job_Novice) {
		mes "^ff0000[Gate Keeper]^000000";
		mes "I am sorry but Gaia has undergoing tasks with you... Please talk to her first.";
		close;
	}
	
	if(intro == 1) {
		mes "^ff0000[Gate Keeper]^000000";
		mes "Are you lost? Already?";
		mes "Head to the end of the room";
		mes "and get yourself into the portal.";
		mes "Then good luck crossing";
		mes "the Misty Woods.";
		close;
	}
	
	mes "^ff0000[Gate Keeper]^000000";
	mes "Remember... You'll be sent to the World of the Living as a " + FACTION$ + ".";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "People there take you for dead";
	mes "since you've entered the";
	mes "Misty Woods searching for";
	mes "a way to leave the islands.";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "You were just a young child";
	mes "by then... Keep that in mind.";
	mes "Gaia has transformed you.";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "You must never try that again, though.";
	mes "Misty Woods is a dangerous place.";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "It hides Bifrost, that is true";
	mes "but we always make sure it is";
	mes "out of reach for any human.";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "Wish you good luck...";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "Now, head to the portal";
	mes "and rembember:";
	mes "find the way out of Misty Woods";
	mes "as quick as you can!";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "There would be human guards";
	mes "at its entrance...";
	next;
	mes "^ff0000[Gate Keeper]^000000";
	mes "You talk to them... they";
	mes "will help you to settle again";
	mes "in the world of the living.";
	next;
	
	intro = 1;
	
	mes "^ff0000[Gate Keeper]^000000";
	mes "Here, before you go,";
	mes "take these... it can bocome handy.";
	next;
	getitem 12323,30; 	//Wing_Of_Fly
	getitem 12325,5; 	//Magnifier
	getitem 569,200; 	//Novice_Potion
	getitem 2393,1; 	//Novice Suit
	getitem 2112,1; 	//Novice Guard
	if (Class == Job_Mage) getitem 1639,1; 			//Rod
	if (Class == Job_SuperNovice) getitem 13041,1; 	//Main Gauche
	if (Class == Job_Thief) getitem 13041,1; 		//Main Gauche
	if (Class == Job_Swordman) getitem 1381,1; 		//Battle Axe
	if (Class == Job_Merchant) getitem 1381,1; 		//Battle_Axe
	if (Class == Job_Archer) getitem 13041,1; 		//Main Gauche
	if (Class == Job_Acolyte) getitem 1545,1; 		//Mace

	set .@rp,rand(4);
	switch(rp) {
		case 0: savepoint "gaia",81,120;
		case 1: savepoint "gaia",97,120;
		case 2: savepoint "gaia",97,105;
		case 3: savepoint "gaia",81,105;
	}
	mes "^ff0000[Gate Keeper]^000000";
	mes "Enjoy your stay!";
	close;
	
//	callfunc "F_HouseInstancing",HOUSE_NUMBER,1;
}

// Misty Woods

// ********************************************************************
// Misty Woods - Gaia > Misty Woods lvl 2
// ********************************************************************

gaia,61,61,0	script	Gaia-Woods	45,2,2,{
	end;

OnTouch:

	if(intro) {
		if (getcharid(1) == 0) {
			atcommand "@party " + strcharinfo(0); //Cria party com o nome do proprio char;
			sleep2 3000;
		}
		if(checkquest(69351) > -1) erasequest 69351;
		callfunc "F_CreateInstance",69351,"Misty Woods",1,99,1,1;
	}
	end;
}


// ********************************************************************
// Misty Woods - Level 2 > Level 1
// ********************************************************************

bif_fild02,67,112,0	script	mw-2to1	 -1,2,2,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch_:
	if(select("Enter the hole:Ignore it") == 1)
		warp instance_mapname("bif_fild01"),161,352;
	end;
}



// ********************************************************************
// Misty Woods - Guards
// ********************************************************************

bif_fild01,47,69,0	script	Guard#mw1	 413,3,3,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

//OnTouch_:
//	if(intro == 1)
//		donpcevent instance_npcname("#guardstrigger")+"::OnTouch_";
//	end;

OnTalk:
	attachrid 'id;
	npctalk "Hey you!! FREEZE!";
	pcblock 0,1; // impede o char de se mover
	sleep2 2000;
	mes "^0000FF[ Guard ]^000000";
	mes "Holy Crap! Are you ok?";
	mes "What are you doing here?";
	mes "How did you get here?!?";
	next;
	pcblock 0,0;
	select("I am fine... Just need some water.");
	pcblock 0,1;
	mes "^0000FF[ Guard ]^000000";
	mes "No worries,";
	mes "You are safe now.";
	next;
	mes "^0000FF[ Guard ]^000000";
	mes "Can you still walk?";
	mes "We're gonna bring you";
	mes "to a safer place.";
	next;
	select("Yes... I think so.");
	close2;
	pcblock 0,0; 
	unitwalk 'id,40,70;
	sleep2 500;
	npcwalkto 40,70;
	sleep2 2000;
	pcblock 0,1; // impede o char de se mover
	
	if(killedrid == 0) {
		mes "^0000FF[ Guard ]^000000";
		mes "You know what... You were";
		mes "very brave out there";
		mes "all alone... You deserve something";
		mes "to show off to your friends.";
		next;
		achieve(102); // Live and Let Live achievement
		getitembound 5075,1,Bound_Char;
	} 
	
	mes "^0000FF[ Guard ]^000000";
	mes "What is happening?";
	mes "Are you still ok?";
	close2;
	specialeffect2 334;
	for( .@i = Hp; .@i > 1; .@i-- ) {
		sleep2 300;
		set HP, HP - 1;
		if(hp == 10) npctalk "Hey, hey! C'mon!";
		if(hp == 5) npctalk "Stay with us!!";
	}
	pcblock 0,0;
	switch(rand(1,9)) {
		case 1:
			savepoint "1@ma_h", 43,44;
			warp "1@ma_h", 43,44;
			break;
		case 2:
			savepoint "1@ma_h", 82,76;
			warp "1@ma_h", 82,76;
			break;
		case 3:
			savepoint "1@ma_h", 58,87;
			warp "1@ma_h", 58,87;
			break;
		case 4:
			savepoint "1@ma_h", 60,78;
			warp "1@ma_h", 60,78;
			break;
		case 5:
			savepoint "1@ma_h", 45,85;
			warp "1@ma_h", 45,85;
			break;
		case 6:
			savepoint "1@ma_h", 104,47;
			warp "1@ma_h", 104,47;
			break;
		case 7:
			savepoint "1@ma_h", 89,40;
			warp "1@ma_h", 89,40;
			break;
		case 8:
			savepoint "1@ma_h", 89,52;
			warp "1@ma_h", 89,52;
			break;
		case 9:
			savepoint "1@ma_h", 96,54;
			warp "1@ma_h", 96,54;
			break;
	}
	end;
	
}


bif_fild01,43,76,0	script	Guard#mw2	 413,3,3,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

//OnTouch_:
//	if(intro == 1)
//		donpcevent instance_npcname("#guardstrigger")+"::OnTouch_";
//	end;

OnTalk:
	npctalk "Hey you!! FREEZE!";
	end;
}


bif_fild01,47,74,0	script	#guardstrigger	 -1,3,3,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	setcell instance_mapname("bif_fild01"),43,79,51,69,cell_basilica,1;
	end;

OnTouch_:
	'id = getcharid(3);
	donpcevent instance_npcname("Guard#mw1")+"::OnTalk";
	donpcevent instance_npcname("Guard#mw2")+"::OnTalk";
	intro = 2;
	end;
}



1@ma_h,32,63,5	script	Guard#hosp	413,{
	if(instance_id() > 0)
		instance_destroy;
	mes "^0000FF[ Guard ]^000000";
	mes strcharinfo(0)+", hurry!";
	mes "I am glad to see you";
	mes "are better and walking!";
	next;
	mes "^0000FF[ Guard ]^000000";
	mes "Unfortunatelly things are bad";
	mes "and we need to leave this";
	mes "place right now!";
	next;
	mes "^0000FF[ Guard ]^000000";
	mes "Here, come with me...";
	mes "This place is about to";
	mes "become a living nightmare.";
	close2;
	
	if (getcharid(1) == 0) {
		atcommand "@party " + strcharinfo(0); //Cria party com o nome do proprio char;
		sleep2 2000;
	}
	
	callfunc "F_HouseAllocate";
	callfunc "F_HouseInstancing",HOUSE_NUMBER,1;
	end;
}

bif_fild01,237,58,0	script	#mobs_bf01	-1,{
end;

OnInstanceInit:
	monster instance_mapname("bif_fild01"),0,0,"Luciola Vespa",1994,29,instance_npcname("#mobs_bf01")+"::OnMobDead_1994";
	monster instance_mapname("bif_fild01"),0,0,"Cornus",1992,5,instance_npcname("#mobs_bf01")+"::OnMobDead_1992";
	monster instance_mapname("bif_fild01"),0,0,"Miming",2137,58,instance_npcname("#mobs_bf01")+"::OnMobDead_2137";
	monster instance_mapname("bif_fild01"),0,0,"Little Fatum",2136,34,instance_npcname("#mobs_bf01")+"::OnMobDead_2136";
	monster instance_mapname("bif_fild01"),0,0,"Angra Mantis",2133,15,instance_npcname("#mobs_bf01")+"::OnMobDead_2133";
	monster instance_mapname("bif_fild01"),0,0,"Pom Spider",2132,15,instance_npcname("#mobs_bf01")+"::OnMobDead_2132";
	end;

OnMobDead_1994:
	monster instance_mapname("bif_fild01"),0,0,"Luciola Vespa",1994,1,instance_npcname("#mobs_bf01")+"::OnMobDead_1994";
	end;

OnMobDead_1992:
	monster instance_mapname("bif_fild01"),0,0,"Cornus",1992,1,instance_npcname("#mobs_bf01")+"::OnMobDead_1992";
	end;

OnMobDead_2137:
	monster instance_mapname("bif_fild01"),0,0,"Miming",2137,1,instance_npcname("#mobs_bf01")+"::OnMobDead_2137";
	end;

OnMobDead_2136:
	monster instance_mapname("bif_fild01"),0,0,"Little Fatum",2136,1,instance_npcname("#mobs_bf01")+"::OnMobDead_2136";
	end;
				
OnMobDead_2133:
	monster instance_mapname("bif_fild01"),0,0,"Angra Mantis",2133,1,instance_npcname("#mobs_bf01")+"::OnMobDead_2133";
	end;
					
OnMobDead_2132:
	monster instance_mapname("bif_fild01"),0,0,"Pom Spider",2132,1,instance_npcname("#mobs_bf01")+"::OnMobDead_2132";
	end;
						
}



bif_fild02,151,122,0	script	#mobs_bf02	-1,{
end;

OnInstanceInit:
	monster instance_mapname("bif_fild02"),0,0,"Luciola Vespa",1994,27,instance_npcname("#mobs_bf02")+"::OnMobDead_1994";
	monster instance_mapname("bif_fild02"),0,0,"Cornus",1992,5,instance_npcname("#mobs_bf02")+"::OnMobDead_1992";
	monster instance_mapname("bif_fild02"),0,0,"Miming",2137,33,instance_npcname("#mobs_bf02")+"::OnMobDead_2137";
	monster instance_mapname("bif_fild02"),0,0,"Little Fatum",2136,55,instance_npcname("#mobs_bf02")+"::OnMobDead_2136";
	monster instance_mapname("bif_fild02"),0,0,"Angra Mantis",2133,15,instance_npcname("#mobs_bf02")+"::OnMobDead_2133";
	monster instance_mapname("bif_fild02"),0,0,"Pom Spider",2132,15,instance_npcname("#mobs_bf02")+"::OnMobDead_2132";
	end;

OnMobDead_1994:
	monster instance_mapname("bif_fild02"),0,0,"Luciola Vespa",1994,1,instance_npcname("#mobs_bf02")+"::OnMobDead_1994";
	end;

OnMobDead_1992:
	monster instance_mapname("bif_fild02"),0,0,"Cornus",1992,1,instance_npcname("#mobs_bf02")+"::OnMobDead_1992";
	end;

OnMobDead_2137:
	monster instance_mapname("bif_fild02"),0,0,"Miming",2137,1,instance_npcname("#mobs_bf02")+"::OnMobDead_2137";
	end;

OnMobDead_2136:
	monster instance_mapname("bif_fild02"),0,0,"Little Fatum",2136,1,instance_npcname("#mobs_bf02")+"::OnMobDead_2136";
	end;
				
OnMobDead_2133:
	monster instance_mapname("bif_fild02"),0,0,"Angra Mantis",2133,1,instance_npcname("#mobs_bf02")+"::OnMobDead_2133";
	end;
					
OnMobDead_2132:
	monster instance_mapname("bif_fild02"),0,0,"Pom Spider",2132,1,instance_npcname("#mobs_bf02")+"::OnMobDead_2132";
	end;
						
}
