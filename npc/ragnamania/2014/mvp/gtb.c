rent_mb,115,110,0	script	Young Lady#main	91,3,3,{
//	if(checkquest(69501) > -1) erasequest 69501;
	if (instance_id()) {
		switch('gtb) {
		case 1:
		case 2:
			mes "^0000FF[ Young Lady ]^000000";
			mes "Please, don't give up!";
			mes "You can head straight";
			mes "to the Bingo's House.";
			mes "The beast is still there!";
			close;
			break;
		case 3:
			mes "^0000FF[ Young Lady ]^000000";
			mes strcharinfo(0) + "!!";
			mes "Oh my God, you did it!";
			mes "Thank you so much!!";
			next;
			mes "^0000FF[ Young Lady ]^000000";
			mes "Here, please accept this";
			mes "as a gesture of gratitude";
			mes "for what you and your friends";
			mes "have done for us";
			close2;
			emotion e_kis;
			// Collecting Drops
			if(!getd("'gtb_" + getcharid(0))) {
				callfunc "F_GD",1086;
				dispbottom "Looting done. Got anything?";
				achieve(106);
				setd("'gtb_" + getcharid(0)), 1;
			} else
				dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
			end;
			break;
		case 4:
			mes "^0000FF[ Young Lady ]^000000";
			mes "Oh... Hi, " + strcharinfo(0) + "!";
			mes "I still remember what";
			mes "you and your friends";
			mes "have done for us, Thank you!";
			emotion e_kis;
			close;
			break;
		}
		end;
	}

	mes "^0000FF[ Young Lady ]^000000";
	mes "Oh Please, please, please!!";
	mes "I need help!";
	next;
	mes "^0000FF[ Young Lady ]^000000";
	mes "There is a huge bug";
	mes "inside the Bingo building";
	mes "and it looks pretty dangerous";
	mes "all golden in color an so.";
	next;
	mes "^0000FF[ Young Lady ]^000000";
	mes "I am afraid you will need";
	mes "a party of at least 3 members";
	mes "of a minimum level of 20";
	mes "to face that aberration!";
	if(select("I am sorry, I can't help right now:We are ready to help ma'am!") == 1)
		close;
	else 
		callfunc "F_CreateInstance",69501,"Golden Thief Bug [Normal]",20,$@MAXLEVEL,3,5,"gtb";
	end;

OnTouch:
	emotion e_hlp;
	end;
}

que_bingo,49,87,6	script	Golden Bug	1086,8,8,{
if(instance_id()) {
	switch('gtb) {
	case 3:
		// Collecting Drops
		if(!getd("'gtb" + getcharid(0))) {
			callfunc "F_GD",1086;
			dispbottom "Looting done. Got anything?";
			setd("'gtb" + getcharid(0)), 1;
			announce instance_mapname(strnpcinfo(4)), "Congratulations! Talk to the Young Lady for your Reward.", bc_self, bc_blue;
		} else
			dispbottom "You've already collected your loot. Please wait to be teleported out of the instance.";
		end;
		break;
	}
}
end;
OnInit:
	disablenpc strnpcinfo(0);
	end;

OnTouch_:
	if('gtb == 1) {
		callfunc("F_GPL", getcharid(1));
//		callfunc "F_AdjustRatio",strnpcinfo(4),'gtb_pl;
		monster instance_mapname("que_bingo"),48,87,"Golden Thief Bug",1086,1,instance_npcname(strnpcinfo(0))+"::OnMobDead";
		setnpcdisplay(instance_npcname(strnpcinfo(0)), 844);
		set 'gtb, 2;
		end; 
	}
end;

OnInstanceInit:
	enablenpc instance_npcname(strnpcinfo(0));
//	set 'gtb, 1;
//	removemapflag instance_mapname(strnpcinfo(4)), mf_noskill;
	end;

OnMobDead:
	set 'gtb, 3;
	specialeffect2 68,AREA;
	setnpcdisplay(instance_npcname(strnpcinfo(0)), 1324);
	specialeffect 900;
//	setmapflag instance_mapname("que_bingo"), mf_noskill;
	end;
}

rent_ma,115,110,3	duplicate(Young Lady#main)	Old Lady#ma	90,3,3