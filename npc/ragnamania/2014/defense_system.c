-	script	Defense#ma	46,{
end;
OnPCLoginEvent:
	getmapxy(@map$,@x,@y,0);
	if(((getcharid(5) > 3) && (@map$ == "rent_mb")) || ((getcharid(5) < 4) && (@map$ == "rent_ma"))) {
		if(getcharid(5) > 3)
			warp "rent_ma",134,56;
		else
			warp "rent_mb",134,56;
	}
end;
}


// Guards
//============================================================


// *** Guarda Vivo
rent_mb,154,13,5	script	Dandelion Guard#M1	456,2,4,{
	end;

OnTouch:
	if(((getcharid(5) > 3) && (strnpcinfo(4) == "rent_mb")) || ((getcharid(5) < 4) && (strnpcinfo(4) == "rent_ma"))) {
		if(!getd(".noflood"+strnpcinfo(2))) {
			setd(".name"+strnpcinfo(2)+"$"), strnpcinfo(0);
			setd(".noflood"+strnpcinfo(2)), 1; // Controle para q so dispare o alerta uma vez.
			emotion e_hlp;
			npctalk "Intruders!! Sound the alarm!!";
			mapannounce strnpcinfo(4), "The Village's Entrance is unser atack!! ",bc_map,"0xDD0000",FW_BOLD,18;
			set .@x, atoi(delchar(strnpcinfo(2),0)) -1;
			if(strnpcinfo(4) == "rent_mb")
				callfunc "F_CallTheGuards",$@mx[.@x],$@my[0],1,getd(".name"+strnpcinfo(2)+"$"),2026;
			else
				callfunc "F_CallTheGuards",$@bx[.@x],$@by[0],1,getd(".name"+strnpcinfo(2)+"$"),2026;
			initnpctimer;
			setnpcdisplay(getd(".name"+strnpcinfo(2)+"$"), getd(".name"+strnpcinfo(2)+"$"), 844);
		}
	}
end;

OnTimer180000:
	stopnpctimer;
	setd (".noflood"+strnpcinfo(2)), 0;
	killmonster strnpcinfo(4),getd(".name"+strnpcinfo(2)+"$")+"::OnMyMobDead";
	setnpcdisplay(getd(".name"+strnpcinfo(2)+"$"), getd(".name"+strnpcinfo(2)+"$"), 456);
	end;

OnMyMobDead:
	stopnpctimer;
	soundeffectall "sirens.wav",0,strnpcinfo(4);
	set .@mob_dead_num,mobcount("this",getd(".name"+strnpcinfo(2)+"$")+"::OnMyMobDead");
	if (.@mob_dead_num < 1) {
		initnpctimer;
		setnpcdisplay(getd(".name"+strnpcinfo(2)+"$"), getd(".name"+strnpcinfo(2)+"$"), 565);
	}
	end;
	
OnTimer10800000: // 3 hours
	stopnpctimer;
	setd(".noflood"+strnpcinfo(2)), 0;
	setnpcdisplay(getd(".name"+strnpcinfo(2)+"$"), getd(".name"+strnpcinfo(2)+"$"), 456);
	end;
}


// Midgardian Village
rent_mb,158,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M2	456,2,4
rent_mb,162,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M3	456,2,4
rent_mb,166,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M4	456,2,4
rent_mb,170,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M5	456,2,4
rent_mb,174,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M6	456,2,4
rent_mb,178,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M7	456,2,4
rent_mb,182,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M8	456,2,4
rent_mb,186,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M9	456,2,4
rent_mb,190,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M10	456,2,4
rent_mb,194,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M11	456,2,4
rent_mb,198,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M12	456,2,4
rent_mb,202,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M13	456,2,4
rent_mb,206,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M14	456,2,4
rent_mb,210,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M15	456,2,4
rent_mb,214,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M16	456,2,4
rent_mb,218,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M17	456,2,4
rent_mb,222,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M18	456,2,4
rent_mb,226,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M19	456,2,4
rent_mb,230,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M20	456,2,4
rent_mb,234,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M21	456,2,4
rent_mb,238,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M22	456,2,4
rent_mb,242,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M23	456,2,4
rent_mb,246,13,5	duplicate(Dandelion Guard#M1)	Dandelion Guard#M24	456,2,4


// Baldurian Village
rent_ma,114,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B1	456,2,4
rent_ma,110,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B2	456,2,4
rent_ma,106,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B3	456,2,4
rent_ma,102,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B4	456,2,4
rent_ma,98,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B5	456,2,4
rent_ma,94,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B6	456,2,4
rent_ma,90,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B7	456,2,4
rent_ma,86,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B8	456,2,4
rent_ma,82,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B9	456,2,4
rent_ma,78,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B10	456,2,4
rent_ma,74,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B11	456,2,4
rent_ma,70,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B12	456,2,4
rent_ma,66,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B13	456,2,4
rent_ma,62,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B14	456,2,4
rent_ma,58,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B15	456,2,4
rent_ma,54,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B16	456,2,4
rent_ma,50,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B17	456,2,4
rent_ma,46,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B18	456,2,4
rent_ma,42,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B19	456,2,4
rent_ma,38,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B20	456,2,4
rent_ma,34,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B21	456,2,4
rent_ma,30,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B22	456,2,4
rent_ma,26,12,4	duplicate(Dandelion Guard#M1)	Dandelion Guard#B23	456,2,4