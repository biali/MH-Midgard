// ********************************************
// Mapflags
// ********************************************

rent_mb	mapflag	town
rent_mb	mapflag	fvf
rent_mb	mapflag	noteleport
rent_mb	mapflag	nomemo
rent_mb	mapflag	nobranch

rent_ma	mapflag	town
rent_ma	mapflag	fvf
rent_ma	mapflag	noteleport
rent_ma	mapflag	nomemo
rent_ma	mapflag	nobranch

rentb1	mapflag	nobranch
rentb1	mapflag	noicewall
rentb1	mapflag	nomemo
rentb1	mapflag	nopenalty
rentb1	mapflag	pvp	off
rentb1	mapflag	fvf
rentb1	mapflag	pvp_noparty
rentb1	mapflag	pvp_noguild
rentb1	mapflag	noreturn
rentb1	mapflag	nosave
rentb1	mapflag	noteleport
rentb1	mapflag	nowarp
rentb1	mapflag	nowarpto
rentb1	mapflag	partylock
rentb1	mapflag	sakura
rentb1	mapflag	nodrop
rentb1	mapflag	nomobloot
rentb1	mapflag	nobaseexp
rentb1	mapflag	nojobexp
rentb1	mapflag	monster_noteleport
rentb1	mapflag	noemergencycall

rentinb1	mapflag	noicewall
rentinb1	mapflag	nomemo
rentinb1	mapflag	nopenalty
rentinb1	mapflag	pvp	off
rentinb1	mapflag	noreturn
rentinb1	mapflag	nosave
rentinb1	mapflag	noteleport
rentinb1	mapflag	nowarp
rentinb1	mapflag	nowarpto
rentinb1	mapflag	partylock
rentinb1	mapflag	nodrop
rentinb1	mapflag	nomobloot
rentinb1	mapflag	nobaseexp
rentinb1	mapflag	nojobexp
rentinb1	mapflag	monster_noteleport
rentinb1	mapflag	noemergencycall

renta1	mapflag	nobranch
renta1	mapflag	noicewall
renta1	mapflag	nomemo
renta1	mapflag	nopenalty
renta1	mapflag	pvp	off
renta1	mapflag	fvf
renta1	mapflag	pvp_noparty
renta1	mapflag	pvp_noguild
renta1	mapflag	noreturn
renta1	mapflag	nosave
renta1	mapflag	noteleport
renta1	mapflag	nowarp
renta1	mapflag	nowarpto
renta1	mapflag	partylock
renta1	mapflag	leaves
renta1	mapflag	nodrop
renta1	mapflag	nomobloot
renta1	mapflag	nobaseexp
renta1	mapflag	nojobexp
renta1	mapflag	monster_noteleport
renta1	mapflag	noemergencycall

rentina1	mapflag	noicewall
rentina1	mapflag	nomemo
rentina1	mapflag	nopenalty
rentina1	mapflag	pvp	off
rentina1	mapflag	noreturn
rentina1	mapflag	nosave
rentina1	mapflag	noteleport
rentina1	mapflag	nowarp
rentina1	mapflag	nowarpto
rentina1	mapflag	partylock
rentina1	mapflag	nodrop
rentina1	mapflag	nomobloot
rentina1	mapflag	nobaseexp
rentina1	mapflag	nojobexp
rentina1	mapflag	monster_noteleport
rentina1	mapflag	noemergencycall

// ********************************************
// Plaquinhas das casas
// ********************************************

rent_mb,111,45,1	script	House Plate#1	837,{
	mes "[Home Sweet Home]";
	mes "Welcome to my house!";
	mes " ";
	mes "House Number ^0000FF *~~ [" + strnpcinfo(2) + "] ~~* ^000000";
	if (checkquest(69300) != -1 && getcharid(1) > 0 && HOUSE_NUMBER == atoi(strnpcinfo(2))) {
		mes " ";
		mes "^FF0000Apparently you got locked outside your house.^000000";
		next;
		switch(select("Reset the lock system (500z):Cancel and Wait")) {
			case 1:
				if (Zeny < 500) {
					mes "Well... I'm sorry but we don't have enough funds. You're gonna have to wait.";
					close;
				}
				set zeny,zeny-500;
				erasequest 69300; 
			case 2:
				close;
		}
	}
close;
}



// ********************************************
// Housing PostBox
// ********************************************

-	script	MailBox#Mid	-1,{
	
	if(((getcharid(5) < 4) && (strnpcinfo(4) == "rent_ma")) || ((getcharid(5) > 3) && (strnpcinfo(4) == "rent_mb"))) {
		dispbottom "I have no interest in these bastards mails...";
		end;
	}
	
	if(HOUSE_NUMBER != atoi(strnpcinfo(2))) {
		dispbottom "I cannot read other people's mails... Shame on me!";
		end;
	}
  openmail;
  end;
}




// ********************************************************************
// Properties Manager
// ********************************************************************

function	script	Mng	{
	mes "^0000FF[ Properties Manager ]^000000";
	mes "Hello, " + strcharinfo(0) +"!";
	mes "How can I help you today?";
	next;
	switch(select("^009900House Maintenance^000000:Apologise and go")) {
		case 1:
			mes "^0000FF[ Properties Manager ]^000000";
			mes "Ok... And what exactly can I do for you?";
			next;
			L_Services:
			switch(select("^009900Hire/Dismiss Gardener:Hire/Dismiss Housekeeper^000000:Buy Furniture:Cancel")) {
			case 1: // Gardener
				if (HOUSE_GARDENER == 1) {
					mes "^0000FF[ Properties Manager ]^000000";
					mes "Now about the Gardener... Will you discharge him?";
					next;
					switch(select("Discharge:Cancel")) {
					case 1:
						mes "[ Hired Gardener ]";
						mes "I worked so hard... How can this be, Boss?... I'll work harder if you're displeased... Please reconsider, Boss.";
						next;
						switch(select("Discharge:Cancel")) {
						case 1:
							mes "[ Hired Gardener ]";
							mes "Oh, my god! This is nonsense!";
							next;
							goto L_GAR_CONTINUE;
						case 2:
							mes "[ Hired Gardener ]";
							mes "I'll work harder... Thank you!";
							next;
							break;
						}
					case 2:
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Those Gardeners are hard workers. I thought it would be best to keep the staff.";
						next;
						goto L_Services;
					}
					
					L_GAR_CONTINUE:
					if(instance_id() > 0) 
						donpcevent instance_npcname("Maia#rentb1")+"::OnDisable";
					
					set HOUSE_GARDENER,0;
					mes "^0000FF[ Properties Manager ]^000000";
					mes "....";
					mes "Discharged the Gardener... But... are you displeased with something?";
					next;
					goto L_Services;
				}
				else {
					mes "^0000FF[ Properties Manager ]^000000";
					mes "Will you contract with the Gardener to keep your gardens in order?";
					mes "^ff00003000zeny is needed to hire him. ";
					next;
					switch(select("Hire.:Cancel")) {
					case 1:
						mes "^0000FF[ Properties Manager ]^000000";
						if (Zeny < 3000) {
							mes "Well... I'm sorry but we don't have enough funds. We are unable to hire the Gardener.";
							next;
							goto L_Services;
						}
						set zeny,zeny-3000;
						
						if(instance_id() > 0) 
							donpcevent instance_npcname("Maia#rentb1")+"::OnEnable";
						set HOUSE_GARDENER,1;
						
						mes "We finished making the contract with the Gardener successfully. We hired a Gardener for your house.";
						next;
						mes "[ Hired Gardener ]";
						mes "How do you do?";
						mes "I'll do my best to keep your gardens beautiful and productive.";
						next;
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Don't forget to keep him busy or he may just walk home.";
						next;
						goto L_Services;
					case 2:
						mes "^0000FF[ Properties Manager ]^000000";
						mes "I did as you ordered, but not sure that was wise, though. It will be better to hire a Gardener quickly.";
						next;
						goto L_Services;
					}
				}
			case 2: // House Keeper
				if (HOUSE_KEEPER == 1) {
					mes "^0000FF[ Properties Manager ]^000000";
					mes "Now about the Housekeeper... Will you discharge him?";
					next;
					switch(select("Discharge:Cancel")) {
					case 1:
						mes "[ Hired Housekeeper ]";
						mes "I worked so hard... How can this be, Boss?... I'll work harder if you're displeased... Please reconsider, Boss.";
						next;
						switch(select("Discharge:Cancel")) {
						case 1:
							mes "[ Hired Housekeeper ]";
							mes "Oh, my god! This is nonsense!";
							next;
							goto L_KEEP_CONTINUE;
						case 2:
							mes "[ Hired Housekeeper ]";
							mes "I'll work harder... Thank you!";
							next;
							goto L_Services;
						}
					case 2:
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Those Housekeepers are hard workers. I thought it would be best to keep the staff.";
						next;
						goto L_Services;
					}
					
					L_KEEP_CONTINUE:
					if(instance_id() > 0) 
						donpcevent instance_npcname("#Housekeeper")+"::OnDisable";
						
					set HOUSE_KEEPER,0;
					mes "^0000FF[ Properties Manager ]^000000";
					mes "....";
					mes "Discharged the Housekeeper... But... are you displeased with something?";
					next;
					goto L_Services;
				}
				else {
					mes "^0000FF[ Properties Manager ]^000000";
					mes "Will you contract with the Housekeeper to keep your gardens in order?";
					mes "^ff00003000zeny is needed to hire one. ";
					next;
					switch(select("Hire.:Cancel")) {
					case 1:
						mes "^0000FF[ Properties Manager ]^000000";
						if (Zeny < 3000) {
							mes "Well... I'm sorry but we don't have enough funds. We are unable to hire the Housekeeper.";
							next;
							goto L_Services;
						}
						set zeny,zeny-3000;
						if(instance_id() > 0) 
							donpcevent instance_npcname("#Housekeeper")+"::OnEnable";
						set HOUSE_KEEPER,1;
						mes "We finished making the contract with the Housekeeper successfully. We hired a Housekeeper for your house.";
						next;
						mes "[ Hired Housekeeper ]";
						mes "How do you do?";
						mes "I'll do my best to keep your premisses clean and tidy.";
						next;
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Don't forget to keep him busy or he may just walk home.";
						next;
						goto L_Services;
					case 2:
						mes "^0000FF[ Properties Manager ]^000000";
						mes "I did as you ordered, but not sure that was wise, though. It will be better to hire a Housekeeper quickly.";
						next;
						goto L_Services;
					}
				}
			case 3: // Buy Furniture submenu
				L_Furniture:
				switch(select("Buy Storage:Buy Beds:Buy Oven:Cancel")) {
					case 1: // Storage
						if (HOUSE_STORAGE == 1){
							mes "^0000FF[ Properties Manager ]^000000";
							mes "Sorry, but it sounds like you've already got the best storage in the market.";
							next;
							goto L_Furniture;
						}
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Great! We have the right storage model to fit your kitchen.";
						mes "It will cost you^ff0000 5000zeny. One-off payment.";
						next;
						switch(select("Buy Storage.:Cancel")) {
						case 1:
							mes "^0000FF[ Properties Manager ]^000000";
							if (Zeny < 5000) {
								mes "Well... I'm sorry but we don't have enough funds.";
								close;
							}
							set zeny,zeny-5000;
							if(instance_id() > 0) 
								donpcevent instance_npcname("#Storage")+"::OnEnable";

							set HOUSE_STORAGE,1;
							mes "We will make the arrangements to have your new storage fitted ASAP.";
							next;
							goto L_Furniture;
						case 2:
							mes "^0000FF[ Properties Manager ]^000000";
							mes "Storage at home can be very convenient! Consider buying one soon.";
							next;
							goto L_Furniture;
						}
					case 2: // Beds
						if (HOUSE_BEDS == 1){
							mes "^0000FF[ Properties Manager ]^000000";
							mes "Sorry, but it sounds like you've already got the best beds in town.";
							next;
							goto L_Furniture;
						}
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Great! We have the right beds for you!.";
						mes "It will cost you^ff0000 2000zeny. One-off payment.";
						next;
						switch(select("Buy Beds.:Cancel")) {
						case 1:
							mes "^0000FF[ Properties Manager ]^000000";
							if (Zeny < 2000) {
								mes "Well... I'm sorry but we don't have enough funds.";
								close;
							}
							set zeny,zeny-2000;
							if(instance_id() > 0) 
								donpcevent instance_npcname("#Beds")+"::OnEnable";

							set HOUSE_BEDS,1;
							mes "We will make the arrangements to deliver your Beds as quick as possible.";
							next;
							goto L_Furniture;
						case 2:
							mes "^0000FF[ Properties Manager ]^000000";
							mes "Beds can be very convenient, don't you think?";
							next;
							goto L_Furniture;
						}
					case 3: //Oven
						if (HOUSE_OVEN == 1){
							mes "^0000FF[ Properties Manager ]^000000";
							mes "Sorry, but it sounds like you've already got the best oven available.";
							next;
							goto L_Furniture;
						}
						mes "^0000FF[ Properties Manager ]^000000";
						mes "Great! We have the right oven for you!.";
						mes "It will cost you^ff0000 10000zeny. One-off payment.";
						next;
						switch(select("Buy Oven.:Cancel")) {
						case 1:
							mes "^0000FF[ Properties Manager ]^000000";
							if (Zeny < 10000) {
								mes "Well... I'm sorry but we don't have enough funds.";
								close;
							}
							set zeny,zeny-10000;
							if(instance_id() > 0) 
								donpcevent instance_npcname("#Beds")+"::OnEnable";
							set HOUSE_OVEN,1;
							mes "We will make the arrangements to deliver your Oven as quick as possible.";
							next;
							goto L_Furniture;
						case 2:
							mes "^0000FF[ Properties Manager ]^000000";
							mes "Oven can become really handy!";
							next;
							goto L_Furniture;
						}
					case 4:
						close;
				}
				
			case 4:
				close;
		}
				
		case 2:
			mes "^FF0000 [ " + strcharinfo(0) + " ]^000000";
			mes "Sorry Mr. Smith... My mistake.";
			mes " ";
			mes "Have a nice day!";
			close;
	}
}


// ********************************************************************
// Properties Manager - Inside House
// ********************************************************************

rentb1,24,12,4	script	#b1	5500,3,5,{
end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
	set 'name$, instance_npcname(strnpcinfo(0));
	setnpcdisplay('name$, "??");
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch_:
//	if(intro < 6) intro = 2; // intro is 2 after the Misty Woods introduction
	switch('intro) {
	case 0:
//		set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
//		set 'name$, instance_npcname(strnpcinfo(0));
		pcblock 0,1; // impede o char de se mover
//		setnpcdisplay('name$, "??");
		sleep2 2000;
		npctalk "Welcome "+strcharinfo(0);
		sleep2 3000;
		unittalk getcharid(3), "... Sorry, do I know you?";
		sleep2 3000;
		npctalk "Pardon me.. I am Moreth, the Properties Manager. Nice to meet you!";
		sleep2 5000;
		unittalk getcharid(3), "Oh, of course! Sorry... Nice to meet you too, Mr. Moreth!";
		setnpcdisplay('name$, "Manager");
		sleep2 4000;
		npctalk "No Problem! Here... come closer, please...";
		sleep2 3000;
		pcblock 0,0;
		unitwalk getcharid(3),'gid;
		sleep2 2000;
		mes "^0000FF[ Manager ]^000000";
		mes "How are you doing?";
		mes "I mean, It must have been";
		mes "very difficult for you";
		mes "as it has been for the others";
		mes "to be forced to move";
		mes "to a new place, new house.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "But you will be allright!";
		mes "You are better here. Safer.";
		next;
		select("Thank you Mr. Moreth");
		mes "^0000FF[ Manager ]^000000";
		mes "No Worries...";
		mes "We take care of each other here.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "And the neighbourhood";
		mes "is really nice and welcomming.";
		mes (getcharid(5)<4)?"They are also ^0000FFMidgardians^000000, just like you.":"They are also ^0000FFBaldurians^000000 just like you.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "Ok! Lests move on!";
		mes "There are a couple of things";
		mes "I'd like to show you";
		mes "before I go and also";
		mes "you must be really tired.";
		close2;
		'intro = 1;
		pcblock 0,1;
		npcwalkto 32,15; //31,19
		sleep2 2000;
		pcblock 0,0;
		
		if(getcharid(5)<4)
			unitwalk getcharid(3),30,16;
		else
		 	pcfollow getcharid(3), 'gid;
		
		end;
		break;
	case 1:
		pcblock 0,1;
		npctalk "Oh! Hello Maia! You still here?";
		sleep2 2000;
		mes "^0000FF[ Manager ]^000000";
		mes "Maia is a ^990066Gardener^000000. A good one.";
		mes "She used to work for the previous";
		mes "owner of this house before he";
		mes "err...";
		mes "...died?!";
		next;
		donpcevent instance_npcname((getcharid(5)<4)?"Maia#rentb1":"Maia#renta1")+"::OnTalk";
		sleep2 4000;
		npctalk "That's what I've said, dear Maia...";
		sleep2 3000;
		mes "^0000FF[ Manager ]^000000";
		mes "Well, you'd may consider";
		mes "to hire a gardner to take care";
		mes "of your house...";
		mes "They are really handy.";
		next;
		npctalk "Maia... May I ask you to leave? Talk to you later.";
		sleep2 3000;
		donpcevent instance_npcname((getcharid(5)<4)?"Maia#rentb1":"Maia#renta1")+"::OnWalkAway";
		mes "^0000FF[ Manager ]^000000";
		mes "In case you're interested";
		mes "Come talk to me when it's";
		mes "convenient for you.";
		mes " ";
		mes "I am always around";
		mes "at the Village Centre.";
		close2;
		'intro = 2; // Pq ele passa pelo char enqto ta indo pra piscina. Senao buga tudo.
		npcwalkto 18,14;
		sleep2 1000;
		npctalk "The pool! What a lovely pool, huh? Do you like pool parties?";
		sleep2 1000;
		pcstopfollow getcharid(3); // Senao ele para antes de tocar no OnTouch
		pcblock 0,0;
		unitwalk getcharid(3),20,13;
//		unitwalk getcharid(3), 'gid;
		'intro = 3;
		end;
		break;
	
	case 2:
		end;
	break;
	
	case 3:
		pcblock 0,1;
		pcfollow getcharid(3), 'gid;  //so pra teste. qqr coisa deleta
		unittalk getcharid(3), "Oh yes! Sure thing!! Who doesn't, huh?";
//		sleep2 2000;
		mes "^0000FF[ Manager ]^000000";
		mes "Well, the gardeners don't";
		mes "mantain pools. So you'll need";
		mes "a ^990066Housekeeper^000000 for that";
		mes "... we can also provide it, though.";
//		next;
		close2;
		npcwalkto 7,14;
		sleep2 1000;
		'intro = 4;
		pcblock 0,0;
//		unitwalk getcharid(3), 'gid;
		unitwalk getcharid(3),10,14;
//		pcfollow getcharid(3), 'gid;

		end;
		break;
		
	case 4:
		mes "^0000FF[ Manager ]^000000";
		mes "Err... That is Borba.";
		next;
		donpcevent instance_npcname((getcharid(5)<4)?"#Housekeeper":"#HousekeeperB")+"::OnTalk";
		mes "^0000FF[ Manager ]^000000";
		mes "...";
		emotion e_pif;
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "What can I say...";
		mes "The housekeeper, he does his job.";
		mes "He will keep your pool clean";
		mes "and also the patio.";
		next;
		npctalk "Borba! I want you gone when I am back, got it?";
		sleep2 2000;
		mes "^0000FF[ Manager ]^000000";
		mes "If you want to hire a housekeeper,";
		mes "again, look for me at the";
		mes "Village's plaza.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "Now, come with me...";
		mes "Let's see inside the house.";
		close2;
		'intro = 5;
		pcstopfollow getcharid(3);
		pcblock 0,1;
		//npcwalkto 19,20;
		unitwalk 'gid, getnpcid(0,instance_npcname((getcharid(5)<4)?"PortaDeCasa#b1":"PortaDeCasa#a1"));
		sleep2 2000;
		'intro = 6;
		pcblock 0,0;
		unitwalk getcharid(3), getnpcid(0,instance_npcname((getcharid(5)<4)?"PortaDeCasa#b1":"PortaDeCasa#a1"));
		end;

	case 5:
		end;
		break;
	
	case 6:
//		pcstopfollow getcharid(3);
//		warp instance_mapname("rentinb1"),26,7;
//		setnpcdisplay(instance_npcname("Manager"), 'name$);
		disablenpc instance_npcname((getcharid(5)<4)?"#Housekeeper":"#HousekeeperB");
		disablenpc 'name$;
		end;
	}
}

// ********************************************************************
// Properties Manager - Inside House - Cont.
// ********************************************************************

rentinb1,30,12,4	script	Manager#inb	5500,3,3,{
end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
	
OnTouch_:
	switch('intro) {
	case 6:
		set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
		pcfollow getcharid(3),'gid; 
		mes "^0000FF[ Manager ]^000000";
		mes "Look at this place!";
		mes "Wonderful, isn't it?";
		mes "Are you impressed?";
		next;
		select("One could say so...");
		mes "^0000FF[ Manager ]^000000";
		mes "These new houses are imaculate!";
		mes "Hope you take care of yours";
		mes "specially during paries, huh?";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "Is is still missing some pieces";
		mes "of furniture though";
		mes " ";
		mes "Let me show you very quckily.";
		close2;
		
		if(getcharid(5)<4)
//		if(strnpcinfo(4) == "rentinb1")
			npcwalkto 10,5;
		else
			npcwalkto 31,26;
			
		sleep2 3000;
		'intro = 7;
	//	pcblock 0,1;
		end;
		break;
		
	case 7:
		'intro = 8; // O npc vai passar pelo char
		mes "^0000FF[ Manager ]^000000";
		mes "Here you have some enough space";
		mes "to install a ^990066Storage^000000";
		mes " ";
		mes "We can provide that. Just come";
		mes "and talk to me later if you want.";
		if(getcharid(5)<4){
//		if(strnpcinfo(4) == "rentinb1") {
			next;
			npcwalkto 6,8;	
		} else {
			next;
			set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
			unitwalk 'gid,37,23;
			sleep2 2000;
			mes "^0000FF[ Manager ]^000000";
			mes "These beds need to be replaced.";
			mes "We still have some in stock.";
			next;
			mes "^0000FF[ Manager ]^000000";
			mes "There is no illness that";
			mes "resist to a good sleeping,";
			mes "don't you agree?";
			next;
			emotion e_heh;
			close2;
			
			set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
			unitwalk 'gid, 25,23;
			sleep2 2000;
			unitwalk 'gid,11,15;
//			sleep2 1000;
			pcfollow getcharid(3),'gid; 
			sleep2 4000;
		}

		mes "^0000FF[ Manager ]^000000";
		mes "Here you can install an ^990066Oven^000000.";
		mes "I highly recommend that!";
		mes "With the famine at our door";
		mes "it is always good to stock";
		mes "suplies and cook your own food.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "Ah! We sell those too.";
		close2;
//		'intro = 8;
		
		if(getcharid(5)<4) {
			set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
			unitwalk 'gid,17,10;
			sleep2 2000;
			unitwalk 'gid,21,22;
			sleep2 1000;
			unitwalk 'gid,28,28;
			
		} else {
			set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
			unitwalk 'gid,29,32;
		}
		sleep2 3000;
		'intro = 9;
		end;
		break;
		
	case 8:
		end;
		break;
		
	case 9:
		if(getcharid(5)<4){
//		if(strnpcinfo(4) == "rentinb1") {
			mes "^0000FF[ Manager ]^000000";
			mes "These beds need to be replaced.";
			mes "We still have some in stock.";
			next;
			mes "^0000FF[ Manager ]^000000";
			mes "There is no illness that";
			mes "resist to a good sleeping,";
			mes "don't you agree?";
			next;
			emotion e_heh;
		}
		mes "^0000FF[ Manager ]^000000";
		mes "I think that is it, "+strcharinfo(0)+".";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "I shall leave now";
		mes "and visit the other new";
		mes "villagers that just arrived.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "Wish you all the best";
		mes "and that you enjoy your stay";
		mes "to its must!";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "If is there anything I can do";
		mes "for you, please, don't ";
		mes "hesitate to contact me.";
		mes "I am aways at the Village Plaza.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "Well... not aways.";
		mes " ";
		mes "^FF0000If you hear the sirens";
		mes "run to your house!!";
		mes "That means we are being atacked";
		mes (getcharid(5)<4)?"by the Baldurians.^000000":"by the Midgardians.^000000";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "You can help the ^990066Dandelions^000000";
		mes "to defend our Village, though.";
		next;
		mes "^0000FF[ Manager ]^000000";
		mes "I mean, if you feel strong and";
		mes "confident enough for that, of course.";
		close2;
		'intro = 10;
		pcstopfollow getcharid(3);
		pcblock 0,1;
		set 'gid, getnpcid(0,instance_npcname(strnpcinfo(0)));
		if(getcharid(5)<4) {
			unitwalk 'gid, 20,22;
			sleep2 2000;
			unitwalk 'gid, 21,12;
		} else {
			unitwalk 'gid, 22,22;
			sleep2 3000;
			unitwalk 'gid, 25,8;
		}
		sleep2 2000;
		intro = 11;
		pcblock 0,0;
		achieve(103);
		disablenpc instance_npcname(strnpcinfo(0));
		end;	
	}
}


// ********************************************************************
// Housing Warps 


// ********************************************************************
// House Entrance (door steps, outside -> in)
// ********************************************************************

renta1,19,27,0	script	PortaDeCasa#a1	45,2,2,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch_:
	if(intro == 11 || 'intro >= 5) warp instance_mapname("rentin"+strnpcinfo(2)),26,7;
	end;
}

// ********************************************************************
// House Entrance (door steps, inside -> out)
// ********************************************************************

rentina1,25,3,0	script	FrontDoorIn#a1	45,2,2,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch_:
	if(intro == 11) warp instance_mapname("rent"+strnpcinfo(2)),20,17;
	end;
}

// ********************************************************************
// Front Gate of the House (inside -> out)
// ********************************************************************
renta1,20,2,0	script	FrontGate#rent_ma	45,2,2,{
	end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnTouch_:
	if(intro < 11) end;
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
//		set .house, HOUSE_NUMBER -1;
		if(select("Lock the house:I'll be back soon")) == 1 {
//			instance_destroy;
			erasequest 69300;
		}
	}
	warp strnpcinfo(2),$@HDRespMx[.house],$@HDRespMy[.house];
	end;
}


// ********************************************************************
// Front Gate of the House (outside -> in)
// ********************************************************************

rent_ma,106,42,0	script	PortaoDaCasa#1	45,2,2,{
	end;

OnTouch:
	if(intro >= 11)
		callfunc "F_HouseInstancing",atoi(strnpcinfo(2)),MAX_PARTY;
	else
		callfunc "F_HouseInstancing",atoi(strnpcinfo(2)),1;
	end;
}





// ********************************************************************
// Gardener
// ********************************************************************

-	script	Maia::Gardener	-1,{
	if(intro < 11) end;
	if (getcharid(0) != getpartyleader(getcharid(1),2)) {
		mes "[ Gardener ]";
		mes "Sorry, I can't speak right now...";
		mes "... may the boss see us and I don't want problems. I get paid by hour, you know.";
		close;
	} else {
		L_Start:
		mes "[ Gardener ]";
		mes "Hello, " +strcharinfo(0)+ "!";
		mes "What a lovely day!";
		mes "How can I help you?";
		next;
		switch(select("Say Goodbye:Got anything for me?:Give some tips")) {
		case 2:
//			debugmes "GARDENER_LOOT$ == " + gettimestr("%Y%m%d",21);
			if(GARDENER_LOOT$ ==  gettimestr("%Y%m%d",21)) {
				mes "[ Gardener ]";
				mes "Oh, "+strcharinfo(0)+ ",";
				mes "I am afraid I've given";
				mes "everything for you earlier today.";
				next;
				mes "[ Gardener ]";
				mes "But let me check again...";
				next;
				
//				set 'dd, 10000;
//				if(GARDENER_TIPS > 0) {
//					if( Zeny / GARDENER_TIPS < 20 ) set 'dd, 'dd-25;
//					if( Zeny < GARDENER_TIPS) set 'dd, 'dd-25;
//					if(rand('dd) == 99) GARDENER_LOOT$ = ""; 
//					set 'lucky, 1;
//				}
			}
			
			if(GARDENER_LOOT$ != gettimestr("%Y%m%d",21)) {
//				if('lucky == 1) {
//					set 'lucky, 0;
//					GARDENER_TIPS = 0;
//				}
				mes "[ Gardener ]";
				mes "Actually we got something...";
				mes "Do you want to collect them now?";
				mes " ";
				mes "^FF0000Make sure you are not overweighted";
				mes "and have enough room in your inventory^000000.";
				next;
				if(select("Yes, please:No, I will do it later") == 2) {
					mes "[ Gardener ]";
					mes "Ok! Anytime.";
					next;
					goto L_Start;
				} else {
					mes "[ Gardener ]";
					mes "Ok! Here, "+strcharinfo(0);
					mes "Hope they can be helpful!";
					next;
					setarray .@commonitems[0],507,507,507,1032,905,949,991,921,510,508,508,508,509,509,7938,712,905,7935,711,905,7937,914,511,511,7934,906,7932,514,610,610,610;
					setarray .@rareitems[0],2253,704,521,629,748,970,971,630,710,608,607,631,703,707,621,704,522,604,607;
				
					for( .@i = 1; .@i <= rand(5,10); .@i++ ) {
						if(.@i % 5 == 0)
							if(rand(3) == 0) {
								getitem .@rareitems[rand(getarraysize(.@rareitems))],1;
							}
						getitem .@commonitems[rand(getarraysize(.@commonitems))],1;
						sleep2 500;
					}
				}
				mes "[ Gardener ]";
				mes "Got them all? ";
				GARDENER_LOOT$ = gettimestr("%Y%m%d",21);
//				GARDENER_TIPS = 0;
				next;
				goto L_Start;
			} else {
				mes "[ Gardener ]";
				mes "Really sorry, "+strcharinfo(0);
				mes "Maybe later?";
				mes "Or tomorrow, for sure!";
				mes "Weeds tend to grow over night.";
				next;
				goto L_Start;
			}
		
		case 3:
			mes "[ "+strcharinfo(0)+" ]";
			mes "Here, please take this...";
			mes "I know it is not much";
			mes "But it is more than 20%";
			mes "of all my money. Lol";
			input .@tips;
			next;
			if(Zeny < .@tips) {
				mes "[ Gardener ]";
				mes "But ...";
				mes "Seriously?";
				mes "... Thank you anyway.";
				next;
				emotion e_shy;
			} else {
				mes "[ Gardener ]";
				mes "Oh, Are you sure?";
				mes "It is very kind of you!";
				mes "Thank you very much, "+strcharinfo(0);
				set Zeny, Zeny - .@tips;
//				GARDENER_TIPS = GARDENER_TIPS + .@tips;
				next;
				emotion e_no1;
			}
			goto L_Start;
			break;
		
		case 1:
			mes "[ "+strcharinfo(0)+" ]";
			mes "Nah, Thanks...";
			mes "Talk to you later, ok?";
			close;
		}
	}
	
OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	if(compare(strnpcinfo(4), "rentb1")) {
		donpcevent instance_npcname("weed")+"::OnDisable";
		donpcevent instance_npcname("weed#2")+"::OnDisable";
		donpcevent instance_npcname("weed#3")+"::OnDisable";
		donpcevent instance_npcname("weed#4")+"::OnDisable";
		donpcevent instance_npcname("weed#5")+"::OnDisable";
		donpcevent instance_npcname("weed#6")+"::OnDisable";
		
	} else if(compare(strnpcinfo(4), "renta1")){
		donpcevent instance_npcname("weed#b1")+"::OnDisable";
		donpcevent instance_npcname("weed#b2")+"::OnDisable";
		donpcevent instance_npcname("weed#b3")+"::OnDisable";
		donpcevent instance_npcname("weed#b4")+"::OnDisable";
		donpcevent instance_npcname("weed#b5")+"::OnDisable";
		donpcevent instance_npcname("weed#b6")+"::OnDisable";
	}

	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
	
OnTalk:
//	setnpcdisplay(instance_npcname("Maia#rentb1::Gardener"), "Maia");
	npctalk "He didn't die! He went to Baldur Island!";
	end;

OnWalkAway:
	emotion e_pif;
	npcwalkto 25,3;
	sleep2 3000;
	//disablenpc instance_npcname((instance_mapname(strnpcinfo(4)) == "rentb1")?"Maia#rentb1::Gardener":"Maia#rentb1::GardenerB");;
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}


// ********************************************************************
// Housekeeper
// ********************************************************************

rentb1,5,5,6	script	#Housekeeper	5502,{
	if(intro < 11) end;
	if (getcharid(0) != getpartyleader(getcharid(1),2)) {
		mes "[ Housekeeper ]";
		mes "Sorry, I can't speak right now...";
		mes "... may the boss see us and I don't want problems. I get paid by hour, you know.";
		close;
	} else {
		L_Start:
		mes "[ Housekeeper ]";
		mes "Hello, " +strcharinfo(0)+ "!";
		mes "Gorgeous day, isn't it?";
		mes "Do you need something?";
		next;
		switch(select("Say Goodbye:Got anything for me?:Give some tips")) {
		case 2:
			if(KEEPER_LOOT$ == gettimestr("%Y%m%d",21)) {
				mes "[ Housekeeper ]";
				mes "But, "+strcharinfo(0)+ ",";
				mes "I am afraid I've given";
				mes "everything for you earlier today.";
				mes "Haven't I?!";
				next;
				mes "[ Housekeeper ]";
				mes "Let me check again...";
				next;
				
//				set 'dd, 10000;
//				if(KEEPER_TIPS > 0) {
//					if( Zeny / KEEPER_TIPS < 20 ) set 'dd, 'dd-25;
//					if( Zeny < KEEPER_TIPS) set 'dd, 'dd-25;
//					if(rand('dd) == 99) KEEPER_LOOT$ = "";
//					set 'lucky, 1;
//				}
			}
			
			if(KEEPER_LOOT$ != gettimestr("%Y%m%d",21)) {
//				if('lucky == 1) {
//					set 'lucky, 0;
//					KEEPER_TIPS = 0;
//				}
				mes "[ Housekeeper ]";
				mes "Actually I got something here...";
				mes "Do you want to collect them now?";
				mes " ";
				mes "^FF0000Make sure you are not overweighted";
				mes "and have enough room in your inventory^000000.";
				next;
				if(select("Yes, please:No, I will do it later") == 2) {
					mes "[ Housekeeper ]";
					mes "Ok! Anytime.";
					next;
					goto L_Start;
				} else {
					mes "[ Housekeeper ]";
					mes "Ok! Here, "+strcharinfo(0);
					mes "Hope they can be helpful!";
					next;
					setarray .@commonitems[0],962,938,517,7013,962,938,525,716,1052,910,938,713,1016,919,949,528,928,955,1010,915,938,716,1002;
					setarray .@rareitems[0],1011,971,525,719,970,630,645,701,1011,1152,729,1116,2102,737,2304,2303;
				
					for( .@i = 1; .@i <= rand(5,10); .@i++ ) {
						if(.@i % 5 == 0)
							if(rand(3) == 0) {
								getitem .@rareitems[rand(getarraysize(.@rareitems))],1;
							}
						getitem .@commonitems[rand(getarraysize(.@commonitems))],1;
						sleep2 500;
					}
				}
				mes "[ Housekeeper ]";
				mes "Got them all? ";
				mes "Neat stuff, huh?";
				KEEPER_LOOT$ = gettimestr("%Y%m%d",21);
//				KEEPER_TIPS = 0;
				next;
				goto L_Start;
			} else {
				mes "[ Housekeeper ]";
				mes "Really sorry, "+strcharinfo(0);
				mes "Maybe later?";
				mes "Or tomorrow, for sure!";
				mes "Weeds tend to grow over night.";
				next;
				goto L_Start;
			}
		
		case 3:
			mes "[ "+strcharinfo(0)+" ]";
			mes "Here, please take this...";
			mes "I know it is not much";
			mes "But it is more than 20%";
			mes "of all my money. Lol";
			input .@tips;
			next;
			if(Zeny < .@tips) {
				mes "[ Housekeeper ]";
				mes "What a joke...";
				mes "Seriously?";
				mes "Ok, thank you anyway.";
				next;
				emotion e_shy;
			} else {
				mes "[ Housekeeper ]";
				mes "Oh, Are you sure?";
				mes "It is very kind of you!";
				mes "Thank you very much, "+strcharinfo(0);
				set Zeny, Zeny - .@tips;
				KEEPER_TIPS = KEEPER_TIPS + .@tips;
				next;
				emotion e_no1;
			}
			goto L_Start;
			break;
		
		case 1:
			mes "[ "+strcharinfo(0)+" ]";
			mes "Nah, Thanks...";
			mes "Talk to you later, ok?";
			close;
		}
	}

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	if(compare(strnpcinfo(4), "rentb1")) {
		donpcevent instance_npcname("#rentb1")+"::OnDisable"; // Domestic Pest (rentb1 / renta1)
		donpcevent instance_npcname("seaweed")+"::OnDisable";
		donpcevent instance_npcname("seaweed#2")+"::OnDisable";
		donpcevent instance_npcname("seaweed#3")+"::OnDisable";
		donpcevent instance_npcname("seaweed#4")+"::OnDisable";
		donpcevent instance_npcname("seaweed#5")+"::OnDisable";
		donpcevent instance_npcname("seaweed#6")+"::OnDisable";
		
	} else if(compare(strnpcinfo(4), "renta1")){
		donpcevent instance_npcname("#renta1")+"::OnDisable"; // Domestic Pest (rentb1 / renta1)
		donpcevent instance_npcname("seaweed#b1")+"::OnDisable";
		donpcevent instance_npcname("seaweed#b2")+"::OnDisable";
		donpcevent instance_npcname("seaweed#b3")+"::OnDisable";
		donpcevent instance_npcname("seaweed#b4")+"::OnDisable";
		donpcevent instance_npcname("seaweed#b5")+"::OnDisable";
		donpcevent instance_npcname("seaweed#b6")+"::OnDisable";
	}
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
	
OnTalk:
	setnpcdisplay(instance_npcname("#Housekeeper"), "Borba");
	npctalk "Hello Boss! Lovely day, huh?";
	end;
}


// ********************************************************************
// Weed, Seaweed and Pest
// ********************************************************************

rentb1,30,15,0	script	weed	1083,{
end;

OnInstanceInit:
OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

//OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}



rentb1,16,12,0	script	seaweed	1579,{
end;

OnInstanceInit:
OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

//OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}



rentinb1,4,4,0	script	#rentb1	-1,{
	end;
OnInstanceInit:
	areamonster instance_mapname(strnpcinfo(4)),4,12,14,23,"Slug",1007,1,instance_npcname("#"+strnpcinfo(2))+"::OnMobDead";
	end;

OnMobDead:
	areamonster instance_mapname(strnpcinfo(4)),4,12,14,23,"Slug",1007,1,instance_npcname("#"+strnpcinfo(2))+"::OnMobDead";
	end;
	
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}



// ********************************************************************
// Storage
// ********************************************************************

rentinb1,9,5,0	script	#Storage	844,{
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
		callfunc("F_CheckKafCode");	//check your storage password, if set
		openstorage;
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}


// ********************************************************************
// Beds
// ********************************************************************

rentinb1,26,34,0	script	#Beds	844,{
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
		switch(select("Rest:Cancel")) {
		case 1:
			message strnpcinfo(0), "Hope I have one of those dreams....";
			sleep2 5000;
			percentheal 100,100;
			specialeffect2 EF_BLESSING; sc_start SC_BLESSING,600000,10;
			specialeffect2 EF_INCAGILITY; sc_start SC_INCREASEAGI,600000,10;
			if (countitem(521) >= 1){
				delitem 521,1;
				warp "dreamland",128,132;
			}
			end;
			break;
		case 2:
			end;
			break;
		}
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;
}



// ********************************************************************
// Oven
// ********************************************************************

rentinb1,6,7,0	script	#Oven	844,{
	if (getcharid(0) == getpartyleader(getcharid(1),2)) {
		if(countitem(6251) > 0){
			delitem 6251,1;
			cooking 16;
		} else {
			message strcharinfo(0), "Hum... I am afraid I'll need some " + getitemname(6251) + " first.";
		}
		end;
	} else {
		dispbottom "I shouldn't be messying with my friend's stuff...";
	}
	end;

OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnInstanceInit:
OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;

}


// ********************************************************************
// Library
// ********************************************************************
-	script	Books#inscription	-1,{
	callfunc "Inscription_Info",InscriptionLvl;
	end;

OnInstanceInit:
OnEnable:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnDisable:
	disablenpc instance_npcname(strnpcinfo(0));
	end;

}


// ********************************************************************
// Jukebox 
// ********************************************************************

-	script	Jukebox#rent	-1,{
	callsub L_Skip;
end;

//OnMinute03: // For this script, I didn't use array to set the song timer. So, you can just roughly add the timer to play the next song.
//OnMinute08:
//OnMinute13:
//OnMinute18:
//OnMinute23:
//OnMinute28:
//OnMinute33:
//OnMinute38:
//OnMinute43:
//OnMinute48:
//OnMinute53:
//OnMinute58:


L_Skip:
	switch(rand(1,4)) { 
		case 1: 
		announce "Now playing [ Various - La Legende du classique ]",bc_map,0xDA70D6;
		playBGMall "201", instance_mapname("rentinb1");
		break;

		case 2:
		announce "Now playing [ Judas Priest - Jawbreaker ]",bc_map,0xFFFF00;
		playBGMall "205", instance_mapname("rentinb1");
		break;

		case 3:
		announce "Now playing [ Helloween - Back on the Streets ]",bc_map,0xDA70D6;
		playBGMall "206", instance_mapname("rentinb1");
		break;

		case 4:
		announce "Now playing [ ZZ Top - La Grange ]",bc_map,0xDA70D6;
		playBGMall "208", instance_mapname("rentinb1");
		break;

		case 5:
		announce "Now playing [ Yoshi's Island OST - AKA Dreamland's Theme ]",bc_map,0xDA70D6;
		playBGMall "300", instance_mapname("rentinb1");
		break;

		//case 4:
		//announce "<YOUR ANNOUNCE HERE>",bc_map,0xDA70D6;
		//playBGMall "<YOUR MP3 FILENAME>";
		//break;

	}
}





// ** Duplications
// ********************************************************************


// Plaquinhas das casas
// ******************************************************************

// Midigardians Village
rent_mb,83,46,1	duplicate(House Plate#1)	House Plate#2	837
rent_mb,43,53,1	duplicate(House Plate#1)	House Plate#3	837
rent_mb,43,72,1	duplicate(House Plate#1)	House Plate#4	837
rent_mb,43,100,1	duplicate(House Plate#1)	House Plate#5	837
rent_mb,43,128,1	duplicate(House Plate#1)	 House Plate#6	837
rent_mb,43,156,1	duplicate(House Plate#1)	House Plate#7	837
rent_mb,43,184,1	duplicate(House Plate#1)	House Plate#8	837
rent_mb,44,222,1	duplicate(House Plate#1)	House Plate#9	837
rent_mb,72,222,1	duplicate(House Plate#1)	House Plate#10	837
rent_mb,100,222,1	duplicate(House Plate#1)	House Plate#11	837
rent_mb,128,222,1	duplicate(House Plate#1)	House Plate#12	837
rent_mb,156,222,1	duplicate(House Plate#1)	House Plate#13	837
rent_mb,184,222,1	duplicate(House Plate#1)	House Plate#14	837
rent_mb,212,222,1	duplicate(House Plate#1)	House Plate#15	837
rent_mb,222,193,1	duplicate(House Plate#1)	House Plate#16	837
rent_mb,222,165,1	duplicate(House Plate#1)	House Plate#17	837
rent_mb,222,137,1	duplicate(House Plate#1)	House Plate#18	837
rent_mb,222,109,1	duplicate(House Plate#1)	House Plate#19	837
rent_mb,222,81,1	duplicate(House Plate#1)	House Plate#20	837
rent_mb,222,53,1	duplicate(House Plate#1)	House Plate#21	837
rent_mb,193,45,1	duplicate(House Plate#1)	House Plate#22	837
rent_mb,165,45,1	duplicate(House Plate#1)	House Plate#23	837
//rent_mb,114,107,1	duplicate(House Plate#1)	House Plate#24	837
//rent_mb,108,154,1	duplicate(House Plate#1)	House Plate#25	837
//rent_mb,153,160,1	duplicate(House Plate#1)	House Plate#26	837
//rent_mb,159,113,1	duplicate(House Plate#1)	House Plate#27	837

// Baldurians Vilage
rent_ma,111,45,1	duplicate(House Plate#1)	House Number#1	837
rent_ma,83,46,1	duplicate(House Plate#1)	House Number#2	837
rent_ma,43,50,1	duplicate(House Plate#1)	House Number#3	837
rent_ma,43,69,1	duplicate(House Plate#1)	House Number#4	837
rent_ma,43,97,1	duplicate(House Plate#1)	House Number#5	837
rent_ma,43,125,1	duplicate(House Plate#1)	House Number#6	837
rent_ma,43,153,1	duplicate(House Plate#1)	House Number#7	837
rent_ma,43,181,1	duplicate(House Plate#1)	House Number#8	837
rent_ma,44,222,1	duplicate(House Plate#1)	House Number#9	837
rent_ma,72,222,1	duplicate(House Plate#1)	House Number#10	837
rent_ma,100,222,1	duplicate(House Plate#1)	House Number#11	837
rent_ma,128,222,1	duplicate(House Plate#1)	House Number#12	837
rent_ma,156,222,1	duplicate(House Plate#1)	House Number#13	837
rent_ma,184,222,1	duplicate(House Plate#1)	House Number#14	837
rent_ma,212,222,1	duplicate(House Plate#1)	House Number#15	837
rent_ma,222,193,1	duplicate(House Plate#1)	House Number#16	837
rent_ma,222,165,1	duplicate(House Plate#1)	House Number#17	837
rent_ma,222,137,1	duplicate(House Plate#1)	House Number#18	837
rent_ma,222,109,1	duplicate(House Plate#1)	House Number#19	837
rent_ma,222,81,1	duplicate(House Plate#1)	House Number#20	837
rent_ma,222,53,1	duplicate(House Plate#1)	House Number#21	837
rent_ma,193,45,1	duplicate(House Plate#1)	House Number#22	837
rent_ma,165,45,1	duplicate(House Plate#1)	House Number#23	837
//rent_ma,114,107,1	duplicate(House Plate#1)	House Number#24	837
//rent_ma,108,154,1	duplicate(House Plate#1)	House Number#25	837
//rent_ma,153,160,1	duplicate(House Plate#1)	House Number#26	837
//rent_ma,159,113,1	duplicate(House Plate#1)	House Number#27	837


// Caixas de Correio
// ******************************************************************

// *** Midgardian Village
rent_mb,102,45,0	duplicate(MailBox#Mid)	Mailbox#1	888
rent_mb,74,45,0	duplicate(MailBox#Mid)	Mailbox#2	888
rent_mb,43,44,0	duplicate(MailBox#Mid)	Mailbox#3	888
rent_mb,43,81,0	duplicate(MailBox#Mid)	Mailbox#4	888
rent_mb,44,109,0	duplicate(MailBox#Mid)	Mailbox#5	888
rent_mb,43,137,0	duplicate(MailBox#Mid)	Mailbox#6	888
rent_mb,43,165,0	duplicate(MailBox#Mid)	Mailbox#7	888
rent_mb,43,193,0	duplicate(MailBox#Mid)	Mailbox#8	888
rent_mb,53,222,0	duplicate(MailBox#Mid)	Mailbox#9	888
rent_mb,81,222,0	duplicate(MailBox#Mid)	Mailbox#10	888
rent_mb,109,222,0	duplicate(MailBox#Mid)	Mailbox#11	888
rent_mb,137,222,0	duplicate(MailBox#Mid)	Mailbox#12	888
rent_mb,165,222,0	duplicate(MailBox#Mid)	Mailbox#13	888
rent_mb,193,222,0	duplicate(MailBox#Mid)	Mailbox#14	888
rent_mb,221,222,0	duplicate(MailBox#Mid)	Mailbox#15	888
rent_mb,222,184,0	duplicate(MailBox#Mid)	Mailbox#16	888
rent_mb,222,156,0	duplicate(MailBox#Mid)	Mailbox#17	888
rent_mb,222,128,0	duplicate(MailBox#Mid)	Mailbox#18	888
rent_mb,222,100,0	duplicate(MailBox#Mid)	Mailbox#19	888
rent_mb,222,72,0	duplicate(MailBox#Mid)	Mailbox#20	888
rent_mb,222,44,0	duplicate(MailBox#Mid)	Mailbox#21	888
rent_mb,184,45,0	duplicate(MailBox#Mid)	Mailbox#22	888
rent_mb,156,45,0	duplicate(MailBox#Mid)	Mailbox#23	888
//rent_mb,108,113,0	duplicate(MailBox#Mid)	Mailbox#24	888
//rent_mb,113,159,0	duplicate(MailBox#Mid)	Mailbox#25	888
//rent_mb,159,154,0	duplicate(MailBox#Mid)	Mailbox#26	888
//rent_mb,154,108,0	duplicate(MailBox#Mid)	Mailbox#27	888

// *** Baldurian Village
rent_ma,102,45,0	duplicate(MailBox#Mid)	Postbox#1	888
rent_ma,74,45,0	duplicate(MailBox#Mid)	Postbox#2	888
rent_ma,43,44,0	duplicate(MailBox#Mid)	Postbox#3	888
rent_ma,43,81,0	duplicate(MailBox#Mid)	Postbox#4	888
rent_ma,44,109,0	duplicate(MailBox#Mid)	Postbox#5	888
rent_ma,43,137,0	duplicate(MailBox#Mid)	Postbox#6	888
rent_ma,43,165,0	duplicate(MailBox#Mid)	Postbox#7	888
rent_ma,43,193,0	duplicate(MailBox#Mid)	Postbox#8	888
rent_ma,53,222,0	duplicate(MailBox#Mid)	Postbox#9	888
rent_ma,81,222,0	duplicate(MailBox#Mid)	Postbox#10	888
rent_ma,109,222,0	duplicate(MailBox#Mid)	Postbox#11	888
rent_ma,137,222,0	duplicate(MailBox#Mid)	Postbox#12	888
rent_ma,165,222,0	duplicate(MailBox#Mid)	Postbox#13	888
rent_ma,193,222,0	duplicate(MailBox#Mid)	Postbox#14	888
rent_ma,221,222,0	duplicate(MailBox#Mid)	Postbox#15	888
rent_ma,222,184,0	duplicate(MailBox#Mid)	Postbox#16	888
rent_ma,222,156,0	duplicate(MailBox#Mid)	Postbox#17	888
rent_ma,222,128,0	duplicate(MailBox#Mid)	Postbox#18	888
rent_ma,222,100,0	duplicate(MailBox#Mid)	Postbox#19	888
rent_ma,222,72,0	duplicate(MailBox#Mid)	Postbox#20	888
rent_ma,222,44,0	duplicate(MailBox#Mid)	Postbox#21	888
rent_ma,184,45,0	duplicate(MailBox#Mid)	Postbox#22	888
rent_ma,156,45,0	duplicate(MailBox#Mid)	Postbox#23	888
//rent_ma,108,113,0	duplicate(MailBox#Mid)	Postbox#24	888
//rent_ma,113,159,0	duplicate(MailBox#Mid)	Postbox#25	888
//rent_ma,159,154,0	duplicate(MailBox#Mid)	Postbox#26	888
//rent_ma,154,108,0	duplicate(MailBox#Mid)	Postbox#27	888


// Portao da casa (main entrance warp)
// ******************************************************************

// Midgardian Village
rent_mb,106,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#1	45,2,2
rent_mb,78,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#2	45,2,2
rent_mb,40,49,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#3	45,2,2
rent_mb,40,77,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#4	45,2,2
rent_mb,40,105,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#5	45,2,2
rent_mb,40,133,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#6	45,2,2
rent_mb,40,161,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#7	45,2,2
rent_mb,40,189,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#8	45,2,2
rent_mb,49,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#9	45,2,2
rent_mb,77,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#10	45,2,2
rent_mb,105,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#11	45,2,2
rent_mb,133,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#12	45,2,2
rent_mb,161,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#13	45,2,2
rent_mb,189,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#14	45,2,2
rent_mb,217,225,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#15	45,2,2
rent_mb,225,188,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#16	45,2,2
rent_mb,225,160,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#17	45,2,2
rent_mb,225,132,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#18	45,2,2
rent_mb,225,104,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#19	45,2,2
rent_mb,225,76,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#20	45,2,2
rent_mb,225,48,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#21	45,2,2
rent_mb,189,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#22	45,2,2
rent_mb,161,42,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#23	45,2,2
//rent_mb,108,108,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#24	45,2,2
//rent_mb,108,159,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#25	45,2,2
//rent_mb,159,159,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#26	45,2,2
//rent_mb,159,108,0	duplicate(PortaoDaCasa#1)	PortalDaCasa#27	45,2,2

// Baldurian Village
rent_ma,78,42,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#2	45,2,2
rent_ma,40,49,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#3	45,2,2
rent_ma,40,77,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#4	45,2,2
rent_ma,40,105,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#5	45,2,2
rent_ma,40,133,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#6	45,2,2
rent_ma,40,161,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#7	45,2,2
rent_ma,40,189,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#8	45,2,2
rent_ma,49,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#9	45,2,2
rent_ma,77,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#10	45,2,2
rent_ma,105,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#11	45,2,2
rent_ma,133,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#12	45,2,2
rent_ma,161,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#13	45,2,2
rent_ma,189,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#14	45,2,2
rent_ma,217,225,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#15	45,2,2
rent_ma,225,188,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#16	45,2,2
rent_ma,225,160,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#17	45,2,2
rent_ma,225,132,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#18	45,2,2
rent_ma,225,104,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#19	45,2,2
rent_ma,225,76,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#20	45,2,2
rent_ma,225,48,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#21	45,2,2
rent_ma,189,42,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#22	45,2,2
rent_ma,161,42,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#23	45,2,2
//rent_ma,108,108,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#24	45,2,2
//rent_ma,108,159,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#25	45,2,2
//rent_ma,159,159,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#26	45,2,2
//rent_ma,159,108,0	duplicate(PortaoDaCasa#1)	PortaoDaCasa#27	45,2,2


// Portas e Portoes das casas
// ******************************************************************
rentb1,19,23,0	duplicate(PortaDeCasa#a1)	PortaDeCasa#b1	45,2,2
rentinb1,33,3,0	duplicate(FrontDoorIn#a1)	FrontDoorIn#b1	45,2,2
rentb1,25,2,0	duplicate(FrontGate#rent_ma)	FrontGate#rent_mb	45,2,2


// Properties Manager and House Appliances
// ******************************************************************
rent_mb,134,62,4	duplicate(StreetDealer)	Midgardian Manager#Mng::ManagerMid	5500,4,4
rent_ma,134,62,4	duplicate(StreetDealer)	Baldurian Manager#Mng::ManagerBal	5500,4,4
rentb1,34,17,4	duplicate(Gardener)	Maia#rentb1	5501	
renta1,34,17,4	duplicate(Gardener)	Maia#renta1	5501

renta1,4,17,4	duplicate(#Housekeeper)	#HousekeeperB	5502
rentina1,31,26,0	duplicate(#Storage)	#StorageB	844
rentina1,42,26,0	duplicate(#Beds)	#BedsB	844
rentina1,10,14,0	duplicate(#Oven)	#OvenB	844

rentina1,32,14,0	duplicate(Jukebox#rent)	Jukebox#rentina1	844
rentinb1,23,15,0	duplicate(Jukebox#rent)	Jukebox#rentinb1	844

// Weed
//rentb1,30,15,0	duplicate(weed)	weed#1	1083
rentb1,33,13,0	duplicate(weed)	weed#2	1078
rentb1,29,11,0	duplicate(weed)	weed#3	1081
rentb1,32,10,0	duplicate(weed)	weed#4	1084
rentb1,34,6,0	duplicate(weed)	weed#5	1083
rentb1,31,6,0	duplicate(weed)	weed#6	1118
//rentb1,15,10,0	duplicate(seaweed)	seaweed#1	1579
rentb1,15,10,0	duplicate(seaweed)	seaweed#2	1216
rentb1,13,8,0	duplicate(seaweed)	seaweed#3	1161
rentb1,9,9,0	duplicate(seaweed)	seaweed#4	1579
rentb1,7,10,0	duplicate(seaweed)	seaweed#5	1216
rentb1,7,6,0	duplicate(seaweed)	seaweed#6	1161

renta1,30,15,0	duplicate(weed)	weed#b1	1083
renta1,33,13,0	duplicate(weed)	weed#b2	1078
renta1,29,11,0	duplicate(weed)	weed#b3	1081
renta1,32,10,0	duplicate(weed)	weed#b4	1084
renta1,34,6,0	duplicate(weed)	weed#b5	1083
renta1,31,6,0	duplicate(weed)	weed#b6	1118
renta1,6,12,0	duplicate(seaweed)	seaweed#b1	1579
renta1,9,14,0	duplicate(seaweed)	seaweed#b2	1216
renta1,7,16,0	duplicate(seaweed)	seaweed#b3	1161
renta1,7,14,0	duplicate(seaweed)	seaweed#b4	1579
renta1,7,10,0	duplicate(seaweed)	seaweed#b5	1216
renta1,7,6,0	duplicate(seaweed)	seaweed#b6	1161
rentina1,4,4,0	duplicate(#rentb1)	#renta1	-1



// Inscription books in the house;
rentina1,32,7,0	duplicate(Books#inscription)	Inscription Books#Mid	844
rentinb1,17,33,0	duplicate(Books#inscription)	Inscription Books#Bal	844


// Intro Only NPCs
renta1,24,10,4	duplicate(#b1)	#a1	5500,4,4	
rentina1,30,12,4	duplicate(Manager#inb)	Manager#ina	5500,4,4