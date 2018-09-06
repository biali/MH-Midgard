bal_fild15,349,183,3	script	Lady Tanee	1688,8,8,{
if(instance_id()) {
	switch('Tanee) {
	case 3:
		// Collecting Drops
		if(!getd("'Tanee_" + getcharid(0))) {
			callfunc "F_GD",1688;
			dispbottom "Looting done. Got anything?";
			achieve(110);
			setd("'Tanee_" + getcharid(0)), 1;
			sleep2 10000;
			warp "bal_fild15",339,181;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
end;
}

OnTouch_:
	if(strnpcinfo(4) == "bal_fild15") {
//		if(checkquest(69505) > -1) erasequest 69505;
		if(instance_id()) {
			if('Tanee < 3) {
				callfunc("F_GPL", getcharid(1));
//				callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'rate;
			}
		}
		callfunc "F_CreateInstance",69505,"Lady Tanee [Normal]",40,$@MAXLEVEL,3,5,"Tanee";
	}

	if(instance_id()) {
		switch('Tanee) {
		case 1:
			callfunc("F_GPL", getcharid(1));
//			callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'Tanee_pl;
			monster instance_mapname(strnpcinfo(4)),349,183,"Lady Tanee",1688,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
			set 'Tanee, 2;
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
	set 'Tanee, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
	end;
}