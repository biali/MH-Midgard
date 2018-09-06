//
// Spawn Mushrooms
//

-	script	#Shrooms	-1,{
	.GID$ = ".G" + getnpcid(0,strnpcinfo(3));
	progressbar "00AA00",2;

	getitem atoi(strnpcinfo(2)), 1;


	//TODO : CHECK FOR SKILL GATHERER TO INCREASE THE NUMBER OF ITEMS

	if (getd(.GID$) >= 2) {
		set getd(.GID$), 0;
		disablenpc(strnpcinfo(3));
		initnpctimer;	
	} else
		set getd(.GID$), getd(.GID$)+1;

	end;
	
	OnTimer300000:
		enablenpc(strnpcinfo(3));
		stopnpctimer;
	end;

OnInit:
	disablenpc(strnpcinfo(3));
	end;
}

//Hidden part id the loot id (itemid), the unique name is to make sure the respawns work
pay_fild07,123,359,3	duplicate(#Shrooms)	Blue Mooshroom#19628::afbm_1	1084,0,0
pay_fild07,44,309,3	duplicate(#Shrooms)	Blue Mooshroom#19628::afbm_2	1084,0,0
pay_fild07,50,153,3	duplicate(#Shrooms)	Blue Mooshroom#19628::afbm_3	1084,0,0
pay_fild07,236,60,3	duplicate(#Shrooms)	Blue Mooshroom#19628::afbm_4	1084,0,0
pay_fild07,335,262,3	duplicate(#Shrooms)	Blue Mooshroom#19628::afbm_5	1084,0,0
pay_fild07,34,157,3	duplicate(#Shrooms)	Mandragora#19632::afmg_1	1085,0,0
pay_fild07,349,76,3	duplicate(#Shrooms)	Mandragora#19632::afmg_2	1085,0,0
pay_fild07,187,312,3	duplicate(#Shrooms)	Mandragora#19632::afmg_3	1085,0,0
pay_fild07,352,314,3	duplicate(#Shrooms)	Parashroom#19631::afps_1	1085,0,0
pay_fild07,212,261,3	duplicate(#Shrooms)	Parashroom#19631::afps_2	1085,0,0
pay_fild07,236,335,3	duplicate(#Shrooms)	Exciteshroom#19634::afes_1	1084,0,0
pay_fild07,218,352,3	duplicate(#Shrooms)	Exciteshroom#19634::afes_2	1084,0,0



//
// Spawn Plants
//

-	script	#Plants	-1,{
	.GID$ = ".G" + getnpcid(0,strnpcinfo(3));
	progressbar "00AA00",1;

	getitem atoi(strnpcinfo(2)), 2;

	//TODO : CHECK FOR SKILL GATHERER TO INCREASE THE NUMBER OF ITEMS

	disablenpc(strnpcinfo(3));
	initnpctimer;	

	end;
	
	OnTimer300000:
		enablenpc(strnpcinfo(3));
		stopnpctimer;
	end;

OnInit:
	disablenpc(strnpcinfo(3));
	end;
}

//Hidden part id the loot id (itemid), the unique name is to make sure the respawns work
pay_fild07,137,271,3	duplicate(#Plants)	Herb#19649::afhb_1	1080,0,0
pay_fild07,334,304,3	duplicate(#Plants)	Herb#19649::afhb_2	1080,0,0
pay_fild07,307,153,3	duplicate(#Plants)	Herb#19649::afhb_3	1080,0,0
pay_fild07,325,288,3	duplicate(#Plants)	Herb#19649::afhb_4	1080,0,0
pay_fild07,222,214,3	duplicate(#Plants)	Ivy#19648::afiv_1	1081,0,0
pay_fild07,182,126,3	duplicate(#Plants)	Ivy#19648::afiv_2	1081,0,0
pay_fild07,210,268,3	duplicate(#Plants)	Ivy#19648::afiv_3	1081,0,0
pay_fild07,67,113,3	duplicate(#Plants)	Antidote Herb#19651::afah_1	1079,0,0
pay_fild07,28,283,3	duplicate(#Plants)	Antidote Herb#19651::afah_2	1079,0,0



//
// Spawn Cristals
//

-	script	#Crystals	-1,{
	.GID$ = ".G" + getnpcid(0,strnpcinfo(3));
	progressbar "00AA00",2;

	//Drops from Ancient Forest (pay_fild);
	setarray .LRblue[0],19654,19655,19637;
	setarray .HRBlue[0],19656,19655,19637;
	setarray .HRRed[0],19657;

	switch('HRReq){ //'
		case 1:	case 2:	case 3:	case 4:	case 5:
			getitem .LRblue[rand(0,2)], 1;
		break;

		default:
			if(strnpcinfo(2) == "blue") {
				getitem .HRblue[rand(0,2)], 1;
			} else {
				getitem 19657, 1;
			}
		break;
	}

	//TODO : CHECK FOR SKILL GATHERER TO INCREASE THE NUMBER OF ITEMS

	if (getd(.GID$) >= 2) {
		set getd(.GID$), 0;
		disablenpc(strnpcinfo(3));
		initnpctimer;	
	} else
		set getd(.GID$), getd(.GID$)+1;

	end;
	
	OnTimer300000:
		enablenpc(strnpcinfo(3));
		stopnpctimer;
	end;

OnInit:
	disablenpc(strnpcinfo(3));
	end;

OnInstanceInit:
	sleep2 50;
	if ('HRReq < 6 && strnpcinfo(2) != "blue") //'
		disablenpc(strnpcinfo(3));
	end;
}

//Hidden part id the loot id (itemid), the unique name is to make sure the respawns work
pay_fild07,335,45,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_1	1907,0,0
pay_fild07,171,351,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_2	1907,0,0
pay_fild07,284,207,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_3	1907,0,0
pay_fild07,212,111,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_4	1907,0,0
pay_fild07,173,21,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_5	1907,0,0
pay_fild07,363,344,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_6	1907,0,0
pay_fild07,270,368,3	duplicate(#Crystals)	Blue Outcrop#blue::afbo_7	1907,0,0
pay_fild07,73,66,3	duplicate(#Crystals)	Red Outcrop#red::afro_1	1908,0,0
pay_fild07,232,272,3	duplicate(#Crystals)	Red Outcrop#red::afro_2	1908,0,0
pay_fild07,196,105,3	duplicate(#Crystals)	Red Outcrop#red::afro_3	1908,0,0
