bal_fild11,337,140,3	script	Mistress	1059,5,5,{
if(instance_id()) {
	switch('mistress) {
	case 3:
		// Collecting Drops
		if(!getd("'mistress" + getcharid(0))) {
			callfunc "F_GD",1059;
			dispbottom "Looting done. Got anything?";
			achieve(107);
			setd("'mistress_" + getcharid(0)), 1;
			sleep2 10000;
			warp "bal_fild11",333,127;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
end;
}

OnTouch_:
	if(strnpcinfo(4) == "bal_fild11") {
//		if(checkquest(69502) > -1) erasequest 69502;
		if(instance_id()) {
			if('mistress < 3) {
				callfunc("F_GPL", getcharid(1));
			}
		}
		callfunc "F_CreateInstance",69502,"Mistress [Normal]",40,$@MAXLEVEL,3,5,"mistress";
	}

	if(instance_id()) {
		switch('mistress) {
		case 1:
			callfunc("F_GPL", getcharid(1));
			monster instance_mapname(strnpcinfo(4)),337,140,"Mistress",1059,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
			set 'mistress, 2;
			setnpcdisplay(instance_npcname(strnpcinfo(0)), 844);
			end;
			break;
		}
	}
end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
	end;

OnMobDead:
	set 'mistress, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
	end;
}