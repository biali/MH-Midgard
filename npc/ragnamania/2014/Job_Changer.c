prontera,149,192,4	script	Helper	831,{
function Job_Menu;

	mes "[Job Master]";
	if (Class > Job_Soul_Linker) {
		mes "No more jobs are available.";
		close;
	}
	if (checkfalcon() || checkcart() || checkriding() || ismounting()) {
		mes "Please remove your " +
			((checkfalcon()) ? "falcon" : "") +
			((checkcart()) ? "cart" : "") +
			((checkriding()) ? "Peco" : "") +
			((ismounting()) ? "mount" : "") +
			" before proceeding.";
		close;
	}
	if (.SkillPointCheck && SkillPoint) {
		mes "Please use all your skill points before proceeding.";
		close;
	}

	.@eac = eaclass();
	.@i = ((.ThirdClass) ? roclass(.@eac&EAJ_UPPERMASK) : Class);
	if (.@i >= Job_Knight && .@i <= Job_Crusader2) {
		if (BaseLevel < .Rebirth[0] || JobLevel < .Rebirth[1]) {
			.@blvl = .Rebirth[0] - BaseLevel;
			.@jlvl = .Rebirth[1] - JobLevel;
			mes "You need " +
				((.@blvl > 0) ? .@blvl + " more base levels " + ((.@jlvl > 0) ? " and " : "") : "") +
				((.@jlvl > 0) ? .@jlvl + " more job levels " : "") + "to continue.";
			close;
		}
		if (Class > Job_Crusader2) {
			mes "Switch to third class?";
			next;
			Job_Menu(roclass(.@eac|EAJL_THIRD));
			close;
		}
		while(1) {
			mes "Select an option.";
			next;
			.@i = select(" ~ ^0055FFRebirth^000000:" + ((.ThirdClass) ? " ~ ^FF0000Third Class^000000" : "") + ": ~ ^777777Cancel^000000");
			if (.@i == 3)
				close;
			mes "[Job Master]";
			mes "Are you sure?";
			next;
			Job_Menu(((.@i == 1) ? Job_Novice_High : roclass(.@eac|EAJL_THIRD)));
			mes "[Job Master]";
		}
	}
	.@j1 = roclass(.@eac|EAJL_2_1);
	.@j2 = roclass(.@eac|EAJL_2_2);
	if ((.@eac&EAJ_UPPERMASK) == EAJ_SUPER_NOVICE)
		setarray .@exp[0], roclass(.@eac|EAJL_THIRD), 99;
	if (Class == Job_Ninja || Class == Job_Gunslinger)
		setarray .@exp[0], .@j1, 70;
	if (.@exp[0] && .SecondExpanded) {
		if (BaseLevel < .Rebirth[0] || JobLevel < .@exp[1]) {
			.@blvl = .Rebirth[0] - BaseLevel;
			.@jlvl = .@exp[1] - JobLevel;
			mes "You need " +
				((.@blvl > 0) ? .@blvl + " more base levels " + ((.@jlvl > 0) ? " and " : "") : "") +
				((.@jlvl > 0) ? .@jlvl + " more job levels " : "") + "to continue.";
			close;
		}
		mes "Switch to " + jobname(.@exp[0]) + "?";
		next;
		Job_Menu(.@exp[0]);
		close;
	}
	if (.@eac&EAJL_2)
		if (.@eac&(EAJL_UPPER|EAJL_BABY) || roclass(.@eac|EAJL_UPPER) == -1) {
			mes "No more jobs are available.";
			close;
		}
	if ((.@eac&EAJ_BASEMASK) == EAJ_NOVICE) {
		if (JobLevel < .JobReq[0])
			mes "A job level of " + .JobReq[0] + " is required to change into the 1st Class.";
		else if (Class == Job_Novice_High && .LastJob && lastJob) {
			mes "Switch classes now?";
			next;
			Job_Menu(roclass((eaclass(lastJob)&EAJ_BASEMASK)|EAJL_UPPER));
		} else {
			switch(Class) {
			case Job_Novice:
				Job_Menu(
					Job_Swordman,
					Job_Mage,
					Job_Archer,
					Job_Acolyte,
					Job_Merchant,
					Job_Thief,
					Job_SuperNovice,
					Job_Taekwon,
					Job_Gunslinger,
					Job_Ninja,
					Job_Baby
				);
				break;
			case Job_Novice_High:
				Job_Menu(
					Job_Swordman_High,
					Job_Mage_High,
					Job_Archer_High,
					Job_Acolyte_High,
					Job_Merchant_High,
					Job_Thief_High
				);
				break;
			case Job_Baby:
				Job_Menu(
					Job_Baby_Swordman,
					Job_Baby_Mage,
					Job_Baby_Archer,
					Job_Baby_Acolyte,
					Job_Baby_Merchant,
					Job_Baby_Thief,
					Job_Super_Baby
				);
				break;
			default:
				mes "An error has occurred.";
				break;
			}
		}
		close;
	}
	if (roclass(.@eac|EAJL_2_1) == -1 || roclass(.@eac|EAJL_2_2) == -1)
		mes "No more jobs are available.";
	else if (!(.@eac&EAJL_2) && JobLevel < .JobReq[1])
		mes "A job level of " + .JobReq[1] + " is required to change into the 2nd Class.";
	else if (.LastJob && lastJob && (.@eac&EAJL_UPPER)) {
		mes "Switch classes now?";
		next;
		Job_Menu(lastJob + Job_Novice_High);
	} else
		Job_Menu(.@j1, .@j2);
	close;

function Job_Menu {
	while(1) {
		if (getargcount() > 1) {
			mes "Select a job.";
			.@menu$ = "";
			for (.@i = 0; .@i < getargcount(); .@i++)
				.@menu$ = .@menu$ + " ~ " + jobname(getarg(.@i)) + ":";
			.@menu$ = .@menu$+" ~ ^777777Cancel^000000";
			next;
			.@i = getarg(select(.@menu$) - 1, 0);
			if (!.@i)
				close;
			if ((.@i == Job_SuperNovice || .@i == Job_Super_Baby) && BaseLevel < .SNovice) {
				mes "[Job Master]";
				mes "A base level of " + .SNovice + " is required to turn into a " + jobname(.@i) + ".";
				close;
			}
			mes "[Job Master]";
			mes "Are you sure?";
			next;
		} else
			.@i = getarg(0);
		if (select(" ~ Change into ^0055FF" + jobname(.@i) + "^000000 class: ~ ^777777" + ((getargcount() > 1) ? "Go back" : "Cancel") + "^000000") == 1) {
			mes "[Job Master]";
			mes "You are now " + callfunc("F_InsertArticle", jobname(.@i)) + "!";
			if (.@i == Job_Novice_High && .LastJob)
				lastJob = Class;
			jobchange .@i;
			if (.@i == Job_Novice_High)
				resetlvl(1);
			else if (.@i == Job_Baby)
				resetstatus;
			specialeffect2 EF_ANGEL2;
			specialeffect2 EF_ELECTRIC;
			if (.Platinum)
				callsub Get_Platinum;
			close;
		}
		if (getargcount() == 1)
			return;
		mes "[Job Master]";
	}
	end;
}

Get_Platinum:
	skill "NV_FIRSTAID",1,0;
	switch (BaseClass) {
	case Job_Novice:
		if (Class != Job_SuperNovice)
			skill "NV_TRICKDEAD",1,0;
		break;
	case Job_Swordman:
		skill "SM_MOVINGRECOVERY",1,0;
		skill "SM_FATALBLOW",1,0;
		skill "SM_AUTOBERSERK",1,0;
		break;
	case Job_Mage:
		skill "MG_ENERGYCOAT",1,0;
		break;
	case Job_Archer:
		skill "AC_MAKINGARROW",1,0;
		skill "AC_CHARGEARROW",1,0;
		break;
	case Job_Acolyte:
		skill "AL_HOLYLIGHT",1,0;
		break;
	case Job_Merchant:
		skill "MC_CARTREVOLUTION",1,0;
		skill "MC_CHANGECART",1,0;
		skill "MC_LOUD",1,0;
		break;
	case Job_Thief:
		skill "TF_SPRINKLESAND",1,0;
		skill "TF_BACKSLIDING",1,0;
		skill "TF_PICKSTONE",1,0;
		skill "TF_THROWSTONE",1,0;
		break;
	default:
		break;
	}
	switch (BaseJob) {
	case Job_Knight:
		skill "KN_CHARGEATK",1,0;
		break;
	case Job_Priest:
		skill "PR_REDEMPTIO",1,0;
		break;
	case Job_Wizard:
		skill "WZ_SIGHTBLASTER",1,0;
		break;
	case Job_Blacksmith:
		skill "BS_UNFAIRLYTRICK",1,0;
		skill "BS_GREED",1,0;
		break;
	case Job_Hunter:
		skill "HT_PHANTASMIC",1,0;
		break;
	case Job_Assassin:
		skill "AS_SONICACCEL",1,0;
		skill "AS_VENOMKNIFE",1,0;
		break;
	case Job_Crusader:
		skill "CR_SHRINK",1,0;
		break;
	case Job_Monk:
		skill "MO_KITRANSLATION",1,0;
		skill "MO_BALKYOUNG",1,0;
		break;
	case Job_Sage:
		skill "SA_CREATECON",1,0;
		skill "SA_ELEMENTWATER",1,0;
		skill "SA_ELEMENTGROUND",1,0;
		skill "SA_ELEMENTFIRE",1,0;
		skill "SA_ELEMENTWIND",1,0;
		break;
	case Job_Rogue:
		skill "RG_CLOSECONFINE",1,0;
		break;
	case Job_Alchemist:
		skill "AM_BIOETHICS",1,0;
		break;
	case Job_Bard:
		skill "BA_PANGVOICE",1,0;
		break;
	case Job_Dancer:
		skill "DC_WINKCHARM",1,0;
		break;
	default:
		break;
	}
	return;

OnInit:
	setarray .Rebirth[0],99,50;	// Minimum base level, job level to rebirth OR change to third class
	setarray .JobReq[0],10,50;	// Minimum job level to turn into 1st class, 2nd class
	.ThirdClass = 0;			// Enable third classes? (1: yes / 0: no)
	.SecondExpanded = 0;		// Enable new expanded second classes: Ex. Super Novice, Kagerou/Oboro, Rebellion? (1: yes / 0: no)
	.SNovice = 45;				// Minimum base level to turn into Super Novice
	.LastJob = 1;				// Enforce linear class changes? (1: yes / 0: no)
	.SkillPointCheck = 1;		// Force player to use up all skill points? (1: yes / 0: no)
	.Platinum = 1;				// Get platinum skills automatically? (1: yes / 0: no)
	end;
}