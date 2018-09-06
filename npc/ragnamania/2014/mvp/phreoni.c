bal_fild05,89,97,0	script	Phreoni	1159,5,5,{
if(instance_id()) {
	switch('Phreoni) {
	case 3:
		// Collecting Drops
		if(!getd("'Phreoni_" + getcharid(0))) {
			callfunc "F_GD",1159;
			dispbottom "Looting done. Got anything?";
			achieve(108);
			setd("'Phreoni_" + getcharid(0)), 1;
			sleep2 10000;
			warp "bal_fild05",98,102;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
end;
}

OnTouch_:
	if(strnpcinfo(4) == "bal_fild05") {
//		if(checkquest(69503) > -1) erasequest 69503;
		if(instance_id()) {
			if('Phreoni < 3) {
				callfunc("F_GPL", getcharid(1));
//				callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'rate;
			}
		}
		callfunc "F_CreateInstance",69503,"Phreoni [Normal]",50,$@MAXLEVEL,3,5,"Phreoni";
	}

	if(instance_id()) {
		switch('Phreoni) {
		case 1:
			callfunc("F_GPL", getcharid(1));
//			callfunc "F_AdjustRatio",instance_mapname(strnpcinfo(4)),'Phreoni_pl;
			monster instance_mapname(strnpcinfo(4)),89,97,"Phreoni",1159,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
			set 'Phreoni, 2;
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
	set 'Phreoni, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
	end;
}