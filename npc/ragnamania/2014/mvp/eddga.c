bal_fild16,298,308,3	script	Eddga	1115,8,8,{
if(instance_id()) {
	switch('eddga) {
	case 3:
		// Collecting Drops
		if(!getd("'eddga_" + getcharid(0))) {
			callfunc "F_GD",1115;
			dispbottom "Looting done. Got anything?";
			achieve(104);
			setd("'eddga_" + getcharid(0)), 1;
			sleep2 10000;
			warp "bal_fild16",285,303;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
end;
}

OnTouch_:
	if(strnpcinfo(4) == "bal_fild16") {
//		if(checkquest(69500) > -1) erasequest 69500;
		if(instance_id()) {
			if('eddga < 3) {
				callfunc("F_GPL", getcharid(1));
//				callfunc "F_AdjustRatio",strnpcinfo(4),'eddga_pl;
			}
		}
		callfunc "F_CreateInstance",69500,"Eddga [Normal]",45,$@MAXLEVEL,3,5,"eddga";
	}

	if(instance_id()) {
		switch('eddga) {
		case 1:
			callfunc("F_GPL", getcharid(1));
//			callfunc "F_AdjustRatio",strnpcinfo(4),'eddga_pl;
			monster instance_mapname(strnpcinfo(4)),298,308,"Eddga",1115,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
			set 'eddga, 2;
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
	set 'eddga, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
	end;
}