bal_fild17,95,133,3	script	Dark Snake Lord	1418,5,5,{
if(instance_id()) {
	switch('Snake) {
	case 3:
		// Collecting Drops
		if(!getd("'Snake_" + getcharid(0))) {
			callfunc "F_GD",1418;
			dispbottom "Looting done. Got anything?";
			achieve(109);
			setd("'Snake_" + getcharid(0)), 1;
			sleep2 10000;
			warp "bal_fild17",83,131;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
end;
}

OnTouch_:
	if(strnpcinfo(4) == "bal_fild17") {
		if(checkquest(69504) > -1) erasequest 69504;
		if(instance_id()) {
			if('Snake < 3) {
				callfunc("F_GPL", getcharid(1));
//				callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'rate;
			}
		}
		callfunc "F_CreateInstance",69504,"Snake Lord [Normal]",60,$@MAXLEVEL,3,5,"Snake";
	}

	if(instance_id()) {
		switch('Snake) {
		case 1:
			callfunc("F_GPL", getcharid(1));
//			callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'Snake_pl;
			monster instance_mapname(strnpcinfo(4)),95,133,"Dark Snake Lord",1418,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
			set 'Snake, 2;
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
	set 'Snake, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
	end;
}