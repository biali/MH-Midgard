function	script	GetQuestType	{
	//arg0 = Quest Id
	//arg1 = 	flag 0 retorna a o tipo da quest em forma de variavel. 
	//			flag 1 retorna a descricao do tipo.
	.@qid = getarg(0,0);
	.@flag = getarg(1,0);
	if(.@qid > $@MaxAssignments)
		if(.@qid > $@MaxOptionals)
			setd (".@quest$","$@Events");
		else
			setd (".@quest$","$@Optionals");
	else
		setd (".@quest$","$@Assignments");

	if(.@flag == 1)
		.@quest$ = substr(.@quest$,2,getstrlen(.@quest$));
	return .@quest$;
}


function	script	UpdateStatistics	{
	//arg0 = Posicao na array $@Stats$ contendo a variavel desejada
	//arg1 = Valor a incrementar na variavel
	//arg2 = char_id;
	.@p 	= getarg(0);
	.@v 	= getarg(1);
	.@cid 	= getarg(2);

	if(.@cid == 0) {
		debugmes "UpdateStatistics: Error. No charid attached.";
		return;
	}
	
	.@var$ = getd("$@Stats$["+.@p+"]");
	.@newv = getvar(getd(.@var$),.@cid);
	.@newv = .@newv + .@v;

	set getd(.@var$), .@newv, .@cid;

	return;
}




function	script	CalculateXP	{
	//bonus is a real number not a percentage and is applied to the individual not divided among party members.
	debugmes ".....Calculating XP.....";
	.@bonus = getarg(0,0);
	getpartymember 'partyid,1;
	getpartymember 'partyid,2;
	.@count = $@partymembercount;
	copyarray .@chars[0], $@partymembercid[0], .@count;
	copyarray .@names$[0], $@partymembername$[0], .@count;
	copyarray .@acc[0], $@partymemberaid[0], .@count;
	for (.@i=0; .@i < .@count; .@i++) {
		if ( isloggedin( .@acc[.@i],.@chars[.@i] ) ) {
//			attachrid(.@acc[.@i]);
			if (getmapxy(.@mapname$,.@x,.@y,UNITTYPE_PC,.@names$[.@i]) == 0) {
				if (.@mapname$ == instance_mapname(strnpcinfo(4)) || .@mapname$ == instance_mapname("que_hugel")) {
					.@base = .@base + getvar(BaseEXP,.@chars[.@i]);
					set BaseEXP, 0, .@chars[.@i];
				}
			}
		} 
	}
//	detachrid;
	.@exp = (((.@base / .@count)/'MaxFaints) * ('MaxFaints - 'cart)) + .@bonus; //'

	return .@exp;
}



function	script	CollectXP	{
	//arg0 = individual XP
	.@xp = getarg(0);
	.@charid = getarg(1);
	debugmes ".....Collecting XP [ "+strcharinfo(0,.@charid)+" ].....";

	.@hr = getvar(HR,.@charid);

	if (.@hr >= $@MaxRank)
		return;

	.@newxp = getvar(HRXP,.@charid);
	.@newxp = .@newxp + .@xp;
	set HRXP,.@newxp,.@charid;

	if(.@newxp >= $@NeededExp[.@hr]) {
		
		.@newhr = getvar(HR,.@charid);
		.@newhr = .@newhr + 1;
		set HR,.@newhr,.@charid;

		dispbottom "Hero Rank has increased to " + .@newhr + ".",.@charid;
		
		.@hrxp = getvar(HRXP,.@charid);
		.@nexp = $@NeededExp[.@hr];
		
		if((.@hrxp - .@nexp) >= $@NeededExp[(.@hr+1)]){
			.@newhrxp = ($@NeededExp[(.@hr+1)] - 100);
			set HRXP,.@newhrxp, .@charid;
		} else {
			.@newhrxp = (.@hrxp - $@NeededExp[(.@hr-1)]);
			set HRXP,.@newhrxp,.@charid;
		}
	}
	return;
}


function	script	CalculateLoot	{
	debugmes ".....Calculating Loot.....";
	.@q=getarg(0,0); // quest id
	.@psize=getarg(1,1); // size of party
	.@qvar$ = callfunc("GetQuestType",.@q);
	.@qloot$ = .@qvar$ + "__$";

	if (.@q == 0) return;

	for (.@i=0; .@i < getarraysize(getd(.@qloot$)); .@i++){
		if(atoi(getd(.@qloot$+"["+.@i+"]")) == .@q) {
			.@zeny = atoi(getd(.@qloot$+"["+(.@i+1)+"]")); //Zeny da quest
			.@zeny = ((.@zeny / 'MaxFaints) * ('MaxFaints - 'cart)) / .@psize; //'
			.@j = .@i+2;
			.@loot$ = .@zeny + "|";
			while (atoi(getd(.@qloot$+"["+.@j+"]")) < .@q) {
				.@loot$ = .@loot$ + getd(.@qloot$+"["+.@j+"]") + "|";
				.@j++;		
			}
		}
	}
	return .@loot$;
}




function	script	CollectLoot	{
	debugmes ".....Collecting Loot.....";
	//arg0 = string com zeny e itens para o loot.
	explode(.@loot$, getarg(0),"|");
	.@acc = getarg(1,0);
	.@charid = getarg(2,0);

	debugmes "CollectLoot: Acc:" + .@acc + " charid:" + .@charid;

	if(.@acc == 0 || .@charid == 0 ) {
		debugmes "CollectLoot: Error. No acc or charid attached.";
		return;
	}

	.@normal 	=	3; //qtde de loot normalmente
	.@bonus 	=	1;	//qtde bonus de itens
	.@zeny 		= 	atoi(.@loot$[0]); //Grava os Zenys numa variavel a parte;
	
	deletearray .@loot$[0],1; //Remove Zenys da Array;
	.@c = getarraysize(.@loot$);
	for (.@i=0; .@i < (.@normal+.@bonus); .@i++) {
		.@item = atoi(.@loot$[rand(.@c)]);
		if(.@item > 0) {
			getitem(.@item,1,.@acc);
			dispbottom "1x " + getitemname(.@item),.@charid;
		}
	}
	dispbottom "Zeny Rewarded: " + .@zeny + "z",.@charid;
	.@newzeny = getvar(Zeny,.@charid);
	.@newzeny = .@newzeny + .@zeny;
	debugmes "New Zeny : " + .@newzeny;
	set Zeny,.@newzeny,.@charid;
	UpdateStatistics(7,.@zeny, .@charid);

	return;
}



// Remove Quest from the Join List
// ----------------------------------------------
//arg0 = char_id
function	script	RemoveFromJoinList	{
	.@charid = getarg(0,getcharid(0));

	if(!getcharid(1))
		return;

	if(getpartyleader(getcharid(1),2) != .@charid)
		return;

	// Remove quests from join quest section
	for (.@i = 0; .@i < getarraysize($@quests); .@i++) {
		debugmes "RemoveFromJoinList: $@quests possui: " + $@quests[.@i];
		if(getelementofarray($@quests,.@i) == .@charid) {
			debugmes "RemoveFromJoinList: Removendo charid: " + .@charid;
			deletearray $@quests[.@i],1;
		}
	}

	return;
}





// Leave Party safely transfering leadership if necessary
// ----------------------------------------------
function	script	LeaveParty	{
	.@p = getarg(0,getcharid(1));

	if(.@p == 0)
		return;

	getpartymember .@p,1;
	getpartymember .@p,2;
	.@count = $@partymembercount;
	copyarray .@chars[0], 	$@partymembercid[0], .@count;
	copyarray .@acc[0], 	$@partymemberaid[0], .@count;

	if(.@count == 1 || getcharid(0) != getpartyleader(.@p,2)) {
		party_delmember;
	} else {
		for ( .@i = 0; .@i < .@count; .@i++ ) {
			if ( isloggedin( .@acc[.@i],.@chars[.@i] ) && .@chars[.@i] != getcharid(0) ) {
				party_changeleader .@p,.@chars[.@i];
				party_delmember;
				return;
			}
		}
	}
	return;
}

// Remove Quest from Chars and Clean CURRENT_HUNT
// ----------------------------------------------
//arg0 = char_id

function	script	RemoveQuest	{
	.@charid = getarg(0,getcharid(0));
	.@f_quest = getvar(CURRENT_HUNT,.@charid);
	
	if(.@f_quest == 0)
		return;

	if(getcharid(1))
		RemoveFromJoinList(@charid);

	switch(isbegin_quest(.@f_quest,.@charid)) {
	case 1:
		erasequest CURRENT_HUNT,.@charid;
	case 0:
	case 2:
		set CURRENT_HUNT,0,.@charid;
		break;
	}
	return;
}




// Abandon Quest, Remove from Party and Clean Up Vars
// --------------------------------------------------
function	script	AbandonQuest	{
	.@id = getarg(0,getcharid(0));
	.@p  = getarg(1,getcharid(1));
	set BaseEXP,0,.@id; // Just to be on the safe side	

	RemoveFromJoinList(.@id);
	LeaveParty(.@p);
	RemoveQuest(.@id);

	
	return;

}



// Mark the quest as completed for all party members
// -------------------------------------------------
function	script	QuestCompleted	{
	debugmes ".....Completing Quest.....";
	.@questid = getarg(0);
	instance_announce 0, "QUEST COMPLETED",0,0x00DD00,FW_BOLD,64;
	getpartymember 'partyid,1;
	getpartymember 'partyid,2;
	.@count = $@partymembercount;
	copyarray .@chars[0], $@partymembercid[0], .@count;
	copyarray .@names$[0], $@partymembername$[0], .@count;
	copyarray .@acc[0], $@partymemberaid[0], .@count;
	.@loot$ = CalculateLoot(.@questid, .@count);
	.@exp = CalculateXP();

	for ( .@i = 0; .@i < .@count; .@i++ ) {
		if ( isloggedin( .@acc[.@i],.@chars[.@i] ) ) {
			if (getmapxy(.@mapname$,.@x,.@y,UNITTYPE_PC,.@names$[.@i]) == 0) {
				if (.@mapname$ == instance_mapname(strnpcinfo(4)) || .@mapname$ == instance_mapname("que_hugel")) {
					
					CollectLoot(.@loot$, .@acc[.@i], .@chars[.@i]);
					CollectXP(.@exp, .@chars[.@i]);

					debugmes ".....Adjusting Statistics.....";
					.@type$ = GetQuestType(.@questid,1);
					if (.@type$ == "Assignments")
							UpdateStatistics(2,1,.@chars[.@i]);
						else if(.@type$ == "Optionals")
							UpdateStatistics(3,1,.@chars[.@i]);
						else if(.@type$ == "Events")
							UpdateStatistics(5,1,.@chars[.@i]);
					
					completequest .@questid,.@chars[.@i];
					set CURRENT_HUNT, 0, .@chars[.@i];

					attachrid(.@acc[.@i]);
					showdigit 60,3;
					detachrid;
				}
			} else {
				debugmes "QuestCompleted: Player not found: " + .@names$[.@i]; 
			}
		}  
	}
	return;
}



// Mark the quest as failled for all party members
// -------------------------------------------------
function	script	QuestFailed	{
	.@map$ = getarg(0,"-1");

	if(.@map$ == "-1") {
		debugmes "QuestFailed: No Map found. System Halted";
		return;
	}

	debugmes ".....Quest Failed.....";
	killmonsterall instance_mapname(.@map$);
	sleep2 1000;
	instance_announce 0, "QUEST FAILED",0,0xDD0000,FW_BOLD,64;

	getpartymember 'partyid,1;
	getpartymember 'partyid,2;
	.@count = $@partymembercount;
	copyarray .@chars[0], $@partymembercid[0], .@count;
	copyarray .@names$[0], $@partymembername$[0], .@count;
	copyarray .@acc[0], $@partymemberaid[0], .@count;

	for ( .@i = 0; .@i < .@count; .@i++ ) {
		if ( isloggedin( .@acc[.@i],.@chars[.@i] ) ) {
			attachrid(.@acc[.@i]);
			if (getmapxy(.@mapname$,.@x,.@y,UNITTYPE_PC) == 0) {
				if (.@mapname$ == instance_mapname(.@map$) || .@mapname$ == instance_mapname("que_hugel")) {
					showdigit 10,3;
					addtimer 10000, instance_npcname("#QuestPayon")+"::OnQuestFailed";
					RemoveQuest();
				}
			}
		} 
	}	
	return;
}

function	script	blue	{
	return "^0000AA" + getarg(0) + "^000000";
}
function	script	green	{
	return "^00AA00" + getarg(0) + "^000000";
}
function	script	red	{
	return "^AA0000" + getarg(0) + "^000000";
}
function	script	grey	{
	return "^AAAAAA" + getarg(0) + "^000000";
}