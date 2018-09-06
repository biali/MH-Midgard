bal_fild14,347,304,6	script	Orc Hero	1087,5,5,{
if(instance_id()) {
	switch('Orchero) {
	case 3:
		// Collecting Drops
		if(!getd("'Orchero_" + getcharid(0))) {
			callfunc "F_GD",1087;
			dispbottom "Looting done. Got anything?";
			achieve(111);
			setd("'Orchero_" + getcharid(0)), 1;
			sleep2 10000;
			warp "bal_fild14",355,307;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
end;
}

OnTouch_:
	if(strnpcinfo(4) == "bal_fild14") {
//		if(checkquest(69506) > -1) erasequest 69506;
		if(instance_id()) {
			if('Orchero < 3) {
				callfunc("F_GPL", getcharid(1));
//				callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'rate;
			}
		}
		callfunc "F_CreateInstance",69506,"Orc Hero [Normal]",60,$@MAXLEVEL,3,5,"Orchero";
	}

	if(instance_id()) {
		switch('Orchero) {
		case 1:
			callfunc("F_GPL", getcharid(1));
//			callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'Orchero_pl;
			monster instance_mapname(strnpcinfo(4)),347,304,"Orc Hero",1087,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
			set 'Orchero, 2;
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
	set 'Orchero, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
	end;
}