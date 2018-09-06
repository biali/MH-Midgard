// ------------------
// Hunting Quests
// ------------------
// Biali
// v1.0
// ------------------
new_1-1, 148,132,1	script	Hunting Quests::QuestBoard	837,{
function GetQuestData; function GetQuest_; function GetQuest; function DepartToQuest; function CreateInstance; 
function Wipe; function JoinQuest;

	Wipe(); //Cleans any possible thrash left behind

	mes .n$;
	mes "Hunter Rank:" + HR;
	mes " ";
	mes "Hunter Experience:";
	.@ratio = ((HRXP * 100)/$@NeededExp[HR])/10;
	for (.@i=0; .@i<10; .@i++){
		if(.@i < .@ratio)
			.@b1$ = .@b1$ + "||";
		else
			.@b2$ = .@b2$ +  "||";
	}
	mes green(.@b1$) + grey(.@b2$);
//	mes "EXP : " + HRXP + " / " + $@NeededExp[HR];
	next;

	switch(CURRENT_HUNT){
	case 0:
		switch(prompt("POST A QUEST:JOIN A QUEST:"+red("QUIT"))){
			case 1: //POST A QUEST
				.@menu$ = "ASSIGNMENT:OPTIONAL:INVESTIGATION:EVENT:^AA0000BACK^000000";
				switch(.@op = (prompt(.@menu$))){
				case 1:
					@var$ = "$@Assignments$";
					break;
				case 2:
					@var$ = "$@Optionals$";
					break;
				case 3:
				case 4:
				case 5:
					close;
				}
				close2;
				callsub L_Main,.@op,.@var$;

				if(getarraysize($@quests) < 127)
					setarray $@quests[getarraysize($@quests)], getcharid(0);
				else 
					dispbottom "Others won't be able to join your quest. Quest queue is full";

				end;

			case 2: //JOIN A QUEST
				next;
				deletearray @op[0],127;
				mes blue("Available Quests");
				for (.@i=0; .@i < getarraysize($@quests); .@i++) {
					.@qid 		= getvar(CURRENT_HUNT,getelementofarray($@quests,.@i));
					.@hr 		= getvar(HR,getelementofarray($@quests,.@i));
					.@cname$ 	= strcharinfo(0,getelementofarray($@quests,.@i));
					.@qname$ 	= getquestname(.@qid);
					.@pid 		= getcharid(1,.@cname$);
					//debugmes sprintf(".@qid:%d, .@cname$:%s, .@hr:%d, .@qname$:%s, .@pid:%d",.@qid,.@cname$,.@hr,.@qname$,.@pid);
					if(.@qid > 0) {
						if(.@hr <= HR) {
							.@menu$ = .@menu$ + .@qname$ + " [" + .@cname$ +"] (hr"+.@hr+"):";
							if(getarraysize(@op) == 0) 
								setarray @op[0],-1,getelementofarray($@quests,.@i);
							else 
								setarray @op[getarraysize(@op)],getelementofarray($@quests,.@i);
						}
					}
				}
				.@c = getelementofarray(@op,select(.@menu$));
				JoinQuest(.@c);
				end;

			case 3:
				close;
		}
		break;
	default:
		switch(prompt("^00AA00DEPART TO QUEST^000000:^AA0000HAND OVER THE QUEST^000000:^0000AAWAIT FOR PARTY^000000")) {
			case 1:
				DepartToQuest(CURRENT_HUNT);
				end;
			case 2:
				mes .n$;
				mes "Do you want to hand over the quest?";
				close2;
				if (select("NO:YES") == 2)
					callfunc "AbandonQuest";
				end;
			case 3:
				close;
		}
	}
	end;

L_Main:
	.@op = getarg(0);
	set .@menu$,"";
	for (.@i=1; .@i < getarraysize(getd(@var$)); .@i=.@i+6) {
		.@c = getelementofarray(getd(@var$),(.@i-1));
		.@hrreq = getelementofarray(getd(@var$),(.@i+1));
		if(.@hrreq <= HR){
			if(.@op == 1 && isbegin_quest(.@c) == 2)
				.@menu$ = .@menu$ + "^00AA00[DONE] ^000000" + getelementofarray(getd(@var$),.@i);
			else if(.@op == 1)
				.@menu$ = .@menu$ + getelementofarray(getd(@var$),.@i);
			else
				.@menu$ = .@menu$ + getelementofarray(getd(@var$),.@i);
			.@menu$ = .@menu$ + ":";
		}
	}

	if(.@op == 1)
		.@choice = select(.@menu$)+99999; //Assignments start from questid 100000
	else if(.@op == 2)
		.@choice = select(.@menu$)+100029; //Optionals start from questid 100030

	switch(isbegin_quest(.@choice)) {
		case 2:
			if(.@op == 1) {
				mes .n$;
				mes "Assignment Quests can only be done once.";
				mes "You can still join someone else's assignments, though.";
				close2;
				break;
			}
		case 1:
			erasequest(.@choice);
		case 0:
			//explode(.@QuestData$, GetQuestData(.@choice),"|");
			// QuestID, Name, HR Req, Max Party, Time Limit (mins), Max Faints, Map Name, Map, Zeny, Loot1, Loot2 ...
			//GetQuest_(@QuestData$[0],.@QuestData$[1],.@QuestData$[2],.@QuestData$[3],.@QuestData$[4],.@QuestData$[5],.@QuestData$[6],.@QuestData$[7],.@QuestData$[8]);
			GetQuest(.@choice);
			break;

		case 255:
			end;
		default:
			mes "Something went wrong ERROR 1001.";
			close;
	}
	return;



	function GetQuest {
		.@q	= getarg(0,0);
		if(.@q == 0) {
			debugmes "GetQuest: No Quest ID. Proccess Halted.";
			return -1;
		}
		//explode(@QuestData$, GetQuestData(.@choice),"|");
		GetQuestData(.@q);
		// QuestID, Name, HR Req, Max Party, Time Limit (mins), Max Faints, Map Name, Map, Zeny, Loot1, Loot2 ...
		GetQuest_(@QuestData$[0],@QuestData$[1],@QuestData$[2],@QuestData$[3],@QuestData$[4],@QuestData$[5],@QuestData$[6],@QuestData$[7],@QuestData$[8]);

		return;
	}

	// Joining a Quest already posted
	// ----------------------------
	// arg0 = CharID of the quest holder
	function JoinQuest {
		.@cid = getarg(0);
		.@pid = getcharid(1,strcharinfo(0,.@cid));
		//debugmes "Party ID " + .@pid;
		if(getcharid(1) >0) {
			party_delmember(getcharid(0));
			sleep2 50;
		}

		if(party_addmember(.@pid,getcharid(0)) == 1) {
		//	debugmes "Entrou na party " + .@pid;
			sleep2 50;
			//explode(.@QuestData$, GetQuestData(getvar(CURRENT_HUNT,.@cid)),"|");
			// QuestID, Name, HR Req, Max Party, Time Limit (mins), Max Faints, Map Name, Map, Zeny, Loot1, Loot2 ...
			//GetQuest_(@QuestData$[0],.@QuestData$[1],.@QuestData$[2],.@QuestData$[3],.@QuestData$[4],.@QuestData$[5],.@QuestData$[6],.@QuestData$[7],.@QuestData$[8]);
			GetQuest(getvar(CURRENT_HUNT,.@cid));
			//debugmes "CURRENT_HUNT:" + CURRENT_HUNT;	
		} else {
			debugmes "JoinQuest: Error joining Party. ";
			end;
		}

		return;

	}



	// Building Quest Array of Data
	// ----------------------------
	// arg0 = QuestID
	function GetQuestData {
		.@q = getarg(0,0);

		if(.@q == 0) {
			debugmes "GetQuestData: No Quest ID. Proccess Halted.";
			return -1;
		}
		.@qvar$ = callfunc("GetQuestType",.@q);
		.@qmain$ = .@qvar$ + "$";
		.@qmeta$ = .@qvar$ + "_$";
		.@qloot$ = .@qvar$ + "__$";
		.@qmobs$ = .@qvar$ + "___$";
		.@qmobs2$ = .@qvar$ + "____$";

		deletearray @QuestData$[0],127;

		for (.@i=0; .@i < getarraysize(getd(.@qmain$)); .@i++) {
			if(atoi(getd(.@qmain$+"["+.@i+"]")) == .@q){
				//		0,	  1,	 2,		   3,				4,		   5,		6,	 7,	   8,		9,		10,
				//QuestID, Name, HRReq, MaxParty, TimeLimit(mins), MaxFaints, MapName, Map, Zeny, 1stLoot, 2ndLoot, etc
				.@var$ = .@qmain$+"["+.@i+"]";
				copyarray @QuestData$[0],(getd(.@var$)),6;
				break;
			}
		}

		for (.@i=0; .@i < getarraysize(getd(.@qmeta$)); .@i++) {
			if(atoi(getd(.@qmeta$+"["+.@i+"]")) == .@q){
				//MapName, Map
				.@var$ = .@qmeta$+"["+(.@i+1)+"]";
				copyarray @QuestData$[6],(getd(.@var$)),2;
				break;
			}
		}
		for (.@i=0; .@i < getarraysize(getd(.@qloot$)); .@i++) {
			// .@i = QuestID
			// .@i+1 = Zeny
			// .@i+2 = First Loot ID, etc
			if(atoi(getd(.@qloot$+"["+.@i+"]")) == .@q){
				//Zeny, Loot1, Loot2...
				setarray @QuestData$[8],
					getd(.@qloot$+"["+(.@i+1)+"]"); // Zeny
				.@k=9; //Proxima posicao na array @QuestData$
				for (.@j=.@i+2; .@j < getarraysize(getd(.@qloot$)); .@j++ ) {
					if (atoi(getd(.@qloot$+"["+.@j+"]")) < .@q ) {
						setarray @QuestData$[.@k],
							getd(.@qloot$+"["+.@j+"]");
						.@k++;
					} else
						break;
				}
				break;
			}
		}
		//.@quest$ = implode(@QuestData$[0],"|");

		return;
	}

	// Getting a Quest
	// ---------------
	function GetQuest_ {
		//		0,	  1,	 2,		   3,				4,		   5,		6,	 7,	   8,		9,		10,
		//QuestID, Name, HRReq, MaxParty, TimeLimit(mins), MaxFaints, MapName, Map, Zeny, 1stLoot, 2ndLoot, etc
		//----------------------
		//TODO: Aplicar Voucher?
		//----------------------
		.@questid = getarg(0,0);
		if(.@questid == 0) {
			debugmes "GetQuest_: No questID. Proccess Halted.";
			return -1;
		}
		if (getcharid(1) == 0){
			party_create(MD5(getcharid(0)+gettimetick(2))), getcharid(0);
		}

		if(getpartyleader(getcharid(1),2) == getcharid(0))
			mapannounce "new_1-1",strcharinfo(0)+" posted a quest.",bc_map,0x00AAAA,0,28;
		.@m1$ = "Quest Accepted: %s";
		.@m2$ = "Map: %s";
		.@m3$ = "Time Limit: %s mins";
		.@m4$ = "Maximum Party Size: %s Members";
		.@m5$ = "Failure: Faint %s Times or Time Expires";
		.@m6$ = "Reward: %s Zeny";
		dispbottom(sprintf(.@m1$, getquestname(atoi(getarg(0)))));
		dispbottom(sprintf(.@m2$, getarg(6)));
		dispbottom(sprintf(.@m3$, getarg(4)));
		dispbottom(sprintf(.@m4$, getarg(3)));
		dispbottom(sprintf(.@m5$, getarg(5)));
		dispbottom(sprintf(.@m6$, getarg(8)));
		sleep2 50;
		setquest .@questid;
		CURRENT_HUNT = .@questid;
		// Zera a XP pq serao usadas depois para calcular a XP do Hunter Rank
		BaseExp = 0;
		JobExp = 0;

		return;
	}


	// Depart to Quest
	// ---------------
	function DepartToQuest {
	//arg(0) = Quest ID
		.@q = getarg(0,0);

		if(.@q == 0) {
			debugmes "DepartToQuest: No questID. Proccess Halted.";
			return -1;
		}

		BaseExp = 0;
		//explode(.@q$, GetQuestData(.@q),"|");
		//GetQuestData Structure:
		//		0,	  1,	 2,		   3,				4,		   5,		6,	 7,	   8,		9,		10,
		//QuestID, Name, HRReq, MaxParty, TimeLimit(mins), MaxFaints, MapName, Map, Zeny, 1stLoot, 2ndLoot, etc
		if(getpartyleader(getcharid(1),2) == getcharid(0)) {
			// if it is the party leader, create the instance
			CreateInstance(@QuestData$[0],@QuestData$[1],@QuestData$[2],@QuestData$[3],@QuestData$[4],@QuestData$[5],@QuestData$[6],@QuestData$[7]);	
		} else {
			// Is the quest still available?
			for (.@i = 0; .@i < getarraysize($@quests); .@i++) {
				if(getelementofarray($@quests,.@i) == getpartyleader(getcharid(1),2))
					continue;
				else {
					dispbottom "This quest is no longer available.";
					AbandonQuest();
					end;
				}
			}
		}

		//otherwise just join the instance already created by the party leader
		switch(instance_enter(getquestname(.@q))) {
		case 3:
		case 2:
			dispbottom "We are waiting for the party leader to start the quest.";
			end;
		case 1:
			dispbottom "Only a member of the party can enter the instance.";
			end;
		case 0:
			//warp all party members into the instance:
			if(getpartyleader(getcharid(1),2) == getcharid(0)) {
				if (@count > 1) 
					for ( .@i = 0; .@i < @count; .@i++ ) 
						if ( isloggedin( @acc[.@i],@chars[.@i] ) && @chars[.@i] != getcharid(0) ) {
							attachrid(@acc[.@i]);
							instance_enter(getquestname(.@q));
						}
			}
		}

		return;
	}


	// Create the Instance for the Hunt
	// --------------------------------

	function CreateInstance {
	// Arguments
	// arg0 = Instance's name as per instance_db
	// arg1 = maximum number of party members to enter
	// arg2 = minimum HR to enter
	// arg3 = time limit of the quest
	// arg4 = map name for the instance
	// arg5 = max faints
	// arg6 = Quest ID
	// arg6 = MaxFaints

	set @partyid,		getcharid(1);
	set @questid,		getarg(0);
	set @md_name$, 		getquestname(@questid);
	set @HRreq,			getarg(2);
	set @maxplayers, 	getarg(3);
	set @MaxFaints,		getarg(5);
	set @map$, 			getarg(7);
	set @staytime,		checkquest(@questid,PLAYTIME);
	
	switch(@partyid) { 
	case 0:
		callsub S_Wipe;
		end;
	default:			
		getpartymember @partyid,1;
		getpartymember @partyid,2;
		@count = $@partymembercount;
		copyarray @chars[0], $@partymembercid[0], @count;
		copyarray @acc[0], $@partymemberaid[0], @count;
		if (checkquest(@questid,PLAYTIME) == 0 && instance_check_party(getcharid(1)) && @count <= @maxplayers) {
			if (@count > @maxplayers) {
				dispbottom "This quest has reached its limit of hunters.";
				end;
			}
			if (@staytime == 0) { //Quest nao inicializada ainda. Nao tem a quest.
				if (getcharid(0) == getpartyleader(@partyid,2)) { //se eh o lider da party.... booka e entra
					if (instance_create(@md_name$) < 0) {
						if (instance_create(@md_name$) == -3) { 
							//callsub S_Enter;
							return;
						}
						else {
							debugmes @md_name$ + " - Reservation Failed.";
							callsub S_Wipe;
						}
					} else {
						//Instance has been created, so lets set some of our vars:
						set 'partyid, 		@partyid;
						set 'questid, 		@questid;
						set 'HRReq, 		@HRreq; 
						set 'instance_map$, @map$; 
						set 'MaxFaints, 	@MaxFaints;//'
					}
				}
				//callsub S_Enter;
				return;

			} else if (@staytime == 0 || @staytime == 1) { //Ainda tem tempo de estadia na instancia (quest ativa)
				//callsub S_Enter;
				return;

			} else if (@staytime == 2) { //O tempo de estadia esgotou. Quest Completa
				callsub S_Wipe;
			}
			dispbottom "Impossible to create instance.";
			end;
		}

		S_Wipe:
			AbandonQuest();
			end;
		}

		return;
	}


	function wipe {
		if(getcharid(1) == 0) {
			CURRENT_HUNT = 0;
		}
		if(CURRENT_HUNT) {
			if(isbegin_quest(CURRENT_HUNT) == 1)
				if(checkquest(CURRENT_HUNT) == 0) {
					erasequest(CURRENT_HUNT);
					CURRENT_HUNT = 0;
				}
		}
		return;
	}

	end;
}