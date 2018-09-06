pay_fild07,103,371,3	script	#QuestPayon	111,{
end;
function SummonMonster; 

OnInit:
	disablenpc(strnpcinfo(0));
	end;

OnInstanceInit:
	setmapflag instance_mapname(strnpcinfo(4)), mf_nomobloot;
	setmapflag instance_mapname(strnpcinfo(4)), mf_nomvploot;
	sleep2 50;
	SummonMonster;
	end;

OnMobDead:
OnNPCKillEvent:
	if (getmapxy(.@mapname$,.@x,.@y,UNITTYPE_PC) == 0) {
		if (.@mapname$ == instance_mapname(strnpcinfo(4))) {
			if( getattachedrid() ) {
				.@id = KilledRid;
				.@cid = getcharid(0);
				SummonMonster(.@id);
				if(getmonsterinfo(.@id,MOB_MVPEXP) > 0)
					UpdateStatistics(0,1,.@cid);
				else
					UpdateStatistics(1,1,.@cid);
			}
		}
	}
	end;

OnTimer60000:
	stopnpctimer;
	instance_warpall "new_1-1",114,113;
	party_destroy('partyid); //'
	end;

OnQuestFailed:
	instance_warpall "new_1-1",114,113;
	party_destroy('partyid); //'
	end;


	function SummonMonster {
		.@mobid = getarg(0,0);
		.@questid = 'questid; //'
		.@qvar$ = callfunc("GetQuestType",.@questid,0);
		.@qmobs$ = .@qvar$ + "___$";
		.@qmobs2$ = .@qvar$ + "____$";

		if(.@mobid == 0) {
			if ('sz$ == "") { //'
				if(.@questid < $@MaxAssignments) //' Monsters on Assignments have a fixed size.
					'sz = 0; //'
				else {
					switch(rand(10)) {
						case 0: 												'sz = 2; break;
						case 1:	case 2:											'sz = 1; break;
						case 3:	case 4: case 5: case 6: case 7: case 8:	case 9: 'sz = 0; break; //'
					}
				}
				'sz$ = 'sz;
			}
 
			// Summon Main Quest Monster(s);
			for (.@i=0; .@i < getarraysize(getd(.@qmobs$)); .@i++) {
				if(atoi(getd(.@qmobs$+"["+.@i+"]")) == .@questid) {
					.@i++;
					while (getmonsterinfo(atoi(getd(.@qmobs$+"["+.@i+"]")),MOB_LV) > -1) {
						.@qt = .@i+1;
						.@mobid = getd(.@qmobs$+"["+.@i+"]");
						.@mobqty = getd(.@qmobs$+"["+.@qt+"]");
						.@mobname$ = getmonsterinfo(.@mobid,MOB_NAME);
						monster instance_mapname(strnpcinfo(4)),0,0,.@mobname$,.@mobid,.@mobqty,instance_npcname(strnpcinfo(0))+"::OnMobDead",'sz; //'		
						.@i = .@i+2;
					}
					break;
				}
			}	
		} else {
			if(checkquest(.@questid,HUNTING) == 2) {
				killmonsterall instance_mapname(strnpcinfo(4));
				initnpctimer;
				callfunc "QuestCompleted",.@questid;
			} else {
				if(.@StopSharing == 0) { //After killing the first controlled mob joining shouldn't be possible anymore
					callfunc "RemoveFromJoinList", getpartyleader(getcharid(1),2);
					.@StopSharing++;
				}

				.@mobname$ = getmonsterinfo(.@mobid,MOB_NAME);
				monster instance_mapname(strnpcinfo(4)),0,0,.@mobname$,.@mobid,1,instance_npcname(strnpcinfo(0))+"::OnMobDead",'sz; //'
			}
		}
		return;
	}


	
}

que_hugel,163,15,0	script	#Camp_Entrance	45,1,1,{
	end;

	OnTouch:
		warp instance_mapname('instance_map$),169,23; //'
		end;

	OnInit:
		disablenpc(strnpcinfo(0));
		end;

	OnInstanceInit:
		enablenpc(strnpcinfo(0));
		end;

}

pay_fild07,163,17,0	script	#Camp_Exit	45,1,1,{
	end;

	OnTouch:
		warp instance_mapname("que_hugel"),163,29;
		end;

	OnInit:
		disablenpc(strnpcinfo(0));
		end;

	OnInstanceInit:
		enablenpc(strnpcinfo(0));
		end;

}

que_hugel,172,33,4	script	Handler#Camp	101,{
	mes "^0000AA[ Handler ]^000000";
	mes "Hello, partner!";
	mes "How may I help you?";
	next;
	switch(select("Change Equipment:Browse Items:Abandon Quest:^AA0000Cancel^000000")){
		case 1:
		case 2:
		case 3:
			if(select("Abandon quest and get back to HQ:Cancel") == 1) {
			//	erasequest(CURRENT_HUNT);
			//	CURRENT_HUNT = 0;
			//	party_delmember();
				callfunc "AbandonQuest";
			}
			close;
		case 4:
			close;
	}
	end;

	OnInit:
		disablenpc(strnpcinfo(0));
		end;

	OnInstanceInit:
		debugmes "Iniciou o timer. Handler";
		initnpctimer;
		end;

	OnTimer3000000:
		stopnpctimer;
		//TODO QuestFailed;
		end;
}


