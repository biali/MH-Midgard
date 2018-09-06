//===== rAthena Script ======================================= 
//= Global Functions
//===== By: ================================================== 
//= Lupus, kobra_k88
//===== Current Version: ===================================== 
//= 2.24
//===== Compatible With: ===================================== 
//= rAthena Project
//===== Description: ========================================= 
//= General script functions.
//===== Additional Comments: ================================= 
//= Added F_ClearJobVar - on getting a new job it clears all Job Quest variables
//= Removed individual job check functions as they were redundant [kobra_k88]
//= 1.3 Added Job Change Function for Baby/Normal Classes
//= 1.3b a fix, due to const.txt change [Lupus]
//= 1.4 Added Is_Taekwon_Class: Taekwondo, Star Knight(Gladiator),Soul Linker [Lupus]
//= 1.5 Added clear of Bard Quest variables. 1.5a updated [Lupus]
//= 1.6 Added F_RandMes, F_SexMes, F_Hi, F_Bye functions [Lupus]
//=     Moved here useful function 'getJobName'
//= 1.7 Added "F_ItemName" function, added a great sample for "F_ItemName"
//= 1.8 Added Job Vars clear for Extended classes: TK,SL,SG [Lupus]
//= 1.9 Added "F_ClearGarbage" func that clears outdated, wasted variables [Lupus]
//= 1.91 Added "F_SaveQuestSkills","F_Load?Skills" functions [Lupus]
//= 2.0 Fixed F_Save/LoadQuestSkills functions. Had to split in into 2 vars [Lupus]
//= 2.01 Added $talk to F_ClearGarbage [Evera]
//= 2.02 Added $dtsglobalelig and $dts|(1<<6) to F_ClearGarbage [Evera]
//= 2.03 Added Gunslinger vars to F_ClearJobVar [Lupus]
//= 2.04 Added dtseligible 2 (becomes MISC_QUEST|128) to F_ClearGarbage [Evera]
//= 2.05 Book of Devil -> MISC_QUEST|256, clear other Niflheim garbage vars [Lupus]
//=     +more garbage clean
//= 2.06 Pass to Bio-Lab -> MISC_QUEST|512 [Lupus]
//= 2.07 Added TK_Q variable clear. 2.08 Added NINJ_Q variable clear [Lupus]
//= 2.09 Cleared F_ClearGarbage [Lupus]
//= 2.10 Added F_CheckMaxCount to check count of carrid items. [L0ne_w0lf]
//= 2.10a Removed function F_CheckMaxCount. Not needed. [L0ne_W0lf]
//= 2.11 Updated function Job_Change to jobchange based on Upper value. [Paradox924X]
//= 2.12 Added more unused vars to F_ClearGarbage [Lupus]
//= 2.13 Added more unused vars to F_ClearGarbage [Lupus]
//= 2.14 Added old novice variables to F_ClearGarbage. [L0ne_W0lf]
//= 2.15 Added no unused DTS variables to F_ClearGarbage. [L0ne_W0lf]
//= 2.16 Added F_GetWeaponType, and F_GetArmorType. [L0ne_W0lf]
//= 2.17 Renamed 'F_RandMes' to 'F_Rand'. [Euphy]
//= 2.18 Removed useless 'getJobName' function. [Euphy]
//= 2.2 Added "F_GetPlural", "F_InsertPlural", "F_InsertArticle", "F_InsertComma", "F_GetNumSuffix". [Euphy]
//=     Standardized descriptions, updated 'F_GetArmorType'.
//= 2.21 Added format string to "F_InsertPlural" and more checks to "F_GetPlural". [Euphy]
//= 2.22 Further improvements to "F_GetPlural". [Euphy]
//= 2.23 Completed article function and added "F_GetArticle". [Euphy]
//= 2.24 Added functions to check for equipment swap hacks. [Euphy]
//============================================================ 

//////////////////////////////////////////////////////////////////////////////////
// eAmod Base Scripts and Functions
//////////////////////////////////////////////////////////////////////////////////

-	script	Graveyard::Graveyard_Base	-1,{

	mes "[ ^FF0000" + graveyard_info(0) + "^000000 ]";
	mes "Has met its demise";
	mes "Time of death : ^0000FF" + graveyard_info(2) + "^000000";
	mes "Defeated by...";
	mes "[ ^FF0000" + graveyard_info(1) + "^000000 ]";
	close;
}

//////////////////////////////////////////////////////////////////////////////////
// Clears job quest variables.
// -- callfunc "F_ClearJobVar"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_ClearJobVar	{
	// Misc ---------------------------------
	set JBLVL,0;
	set FIRSTAID,0;
	set PLAYDEAD,0;
	set got_bandage,0;
	set got_novnametag,0;
	// First Class Jobs ---------------------
	set job_acolyte_q,0; set job_acolyte_q2,0;
	set job_archer_q,0;
	set job_magician_q,0;
	set job_merchant_q,0; set job_merchant_q2,0; set job_merchant_q3,0;
	set job_sword_q,0; set SWTEST, 0;
	set job_thief_q,0;
	// Super Novice
	set SUPNOV_Q,0;
	// 2-1 Jobs ------------------------------
	set ASSIN_Q,0; set ASSIN_Q2,0; set ASSIN_Q3,0;
	set BSMITH_Q,0; set BSMITH_Q2,0;
	set HNTR_Q,0; set HNTR_Q2,0;
	set KNIGHT_Q,0; set KNIGHT_Q2,0;
	set PRIEST_Q,0; set PRIEST_Q2,0; set PRIEST_Q3,0;
	set WIZ_Q,0; set WIZ_Q2,0;
	// 2-2 Jobs ------------------------------
	set ROGUE_Q,0; set ROGUE_Q2,0;
	set ALCH_Q,0; set ALCH_Q2,0;
	set CRUS_Q,0;
	set MONK_Q,0; set JOB_MONK_C,0;
	set SAGE_Q,0; set SAGE_Q2,0;
	set DANC_Q,0;
	set BARD_Q,0;
	// Extended Classes
	set TAEK_Q,0; set TK_Q,0;
	set STGL_Q,0;
	set SOUL_Q,0;
	set GUNS_Q,0;
	set NINJ_Q,0;
	return;
}


//////////////////////////////////////////////////////////////////////////////////
// Clears other unused variables.
// -- callfunc "F_ClearGarbage"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_ClearGarbage	{
	// Clear outdated global VARS
	//Clear TURTLE var if the Turtle Islans Quest is already done
		if(TURTLE==20) set MISC_QUEST,MISC_QUEST | 65536;
		if(MISC_QUEST & 65536) set TURTLE,0; //now clear the var if the quest is over
	//Clear previously saved Quest Skills (now it isn't used)
		set ADV_QSK,0;
		set ADV_QSK2,0;
	//Old Reset Skill Event used to use RES_SKILL var
		set RES_SKILL,0;
	//Here you put outdated variables from your outdated EVENTS
	//e.g. Is XMAS done? Add the EVENT var clearing code here.
	
	//due to bugs in BS quest:
	set wizard_m2,0;
	
	// Old Novice Ground Variables.
	set NEW_MES_FLAG0,0;
	set NEW_MES_FLAG1,0;
	set NEW_MES_FLAG2,0;
	set NEW_MES_FLAG3,0;
	set NEW_MES_FLAG4,0;
	set NEW_MES_FLAG5,0;
	set NEW_LVUP0,0;
	set NEW_LVUP1,0;
	set NEW_JOBLVUP,0;
	
	// Old DTS variables that are no longer used.
	set dtseligible,0;
	set MISC_QUEST,MISC_QUEST & ~128;
	
	return;
}


//////////////////////////////////////////////////////////////////////////////////
// Job change based on Upper value (normal, advanced, baby).
// -- callfunc "Job_Change",<Class value>;
// See Job_* constants in 'db/const.txt' for Class values.
//////////////////////////////////////////////////////////////////////////////////
function	script	Job_Change	{
	jobchange getarg(0),Upper;
//	logmes "CLASS CHANGE: " +strcharinfo(0)+ " become a "+jobname(Class);
	return;
}


//////////////////////////////////////////////////////////////////////////////////
// Functions used to spiff up dialoges [Lupus]
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Returns a random argument.
// -- callfunc "F_Rand",arg0,arg1,...
// Example:
//    // You can use it to pick a random number from a list:
//    set @itemIDfromList, callfunc("F_Rand",1129,1222,1163,1357,1360,1522,1811,1410);
//////////////////////////////////////////////////////////////////////////////////
function	script	F_Rand	{
	return getarg(rand(getargcount()));
}


//////////////////////////////////////////////////////////////////////////////////
// Returns 1st argument if female, 2nd argument if male.
// -- callfunc "F_Sex",argFemale,argMale
// Example:
//     mes callfunc("F_Sex","What a beautiful lady!","What a handsome man!");
//////////////////////////////////////////////////////////////////////////////////
function	script	F_SexMes	{
	return getarg(Sex);
}


//////////////////////////////////////////////////////////////////////////////////
// Returns random "hello" and "goodbye" messages.
// -- callfunc "F_Hi"
// -- callfunc "F_Bye"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_Hi	{
	return callfunc("F_Rand","Hi!","Hello!","Good day!","How are you?","Hello there.");
}
function	script	F_Bye	{
	return callfunc("F_Rand","Bye. See you again.","Later.","Goodbye.","Good luck!","Have a nice day!","Byebye!!!");
}


//////////////////////////////////////////////////////////////////////////////////
// Returns expanded item name string.
// -- callfunc "F_ItemName",<item ID>,{<element>{,<VVS meter 0..3>{,<refine rate>}}}
//    Elements: 0=none, 1=Ice, 2=Earth, 3=Fire, 4=Wind
// Example:
//    // Displays "Show me your ^000090+5 VVS Fire Knife^000000..."
//    mes "Show me your "+callfunc("F_ItemName",1201,1,2,5)+"...";
//////////////////////////////////////////////////////////////////////////////////
function	script	F_ItemName	{
	if (getarg(3,0))
		set .@t$,"+"+getarg(3)+" ";
	switch (getarg(2,0)) {
		case 0: break;
		case 1: set .@t$,.@t$+"VS "; break;
		case 2: set .@t$,.@t$+"VVS "; break;
		case 3: set .@t$,.@t$+"VVVS "; break;
		default: set .@t$,.@t$+getarg(2)+"xVS "; break;
	}
	switch (getarg(1,0)) {
		case 0: break;
		case 1: set .@t$,.@t$+"Ice "; break;
		case 2: set .@t$,.@t$+"Earth "; break;
		case 3: set .@t$,.@t$+"Fire "; break;
		case 4: set .@t$,.@t$+"Wind "; break;
		default: set .@t$,.@t$+"Strange "; break;
	}
	return "^000090"+.@t$+getitemname(getarg(0))+"^000000";
}


//////////////////////////////////////////////////////////////////////////////////
// Stores learnt quest skills as variables ADV_QSK and ADV_QSK2.
// -- callfunc "F_SaveQuestSkills"
//
// Restores learnt 1st class quest skills.
// -- callfunc "F_Load1Skills"
//
// Restores learnt 2nd class quest skills.
// -- callfunc "F_Load2Skills"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_SaveQuestSkills	{
	set ADV_QSK,0; set ADV_QSK2,0;
	//1st classes quest skills
	for(set .@i, 0; .@i < 14; set .@i, .@i + 1){
		if(getskilllv(144+.@i)) set ADV_QSK,ADV_QSK|pow(2,.@i);
	}
	//2nd classes quest skills
	for(set .@i, 0; .@i < 19; set .@i, .@i + 1){
		if(getskilllv(1001+.@i)) set ADV_QSK2,ADV_QSK2|pow(2,.@i);
	}
	return;
}
function	script	F_Load1Skills	{
	for(set .@i, 0; .@i < 14; set .@i, .@i + 1){
		if(ADV_QSK|pow(2,.@i) == ADV_QSK) skill 144+.@i,1,0;
	}
	set ADV_QSK,0; //Clear var
	return;
}
function	script	F_Load2Skills	{
	for(set .@i, 0; .@i < 19; set .@i, .@i + 1){
		if(ADV_QSK2|pow(2,.@i) == ADV_QSK2) skill 1001+.@i,1,0;
	}
	set ADV_QSK2,0; //Clear var
	return;
}


//////////////////////////////////////////////////////////////////////////////////
// Returns weapon type, based on view.
// -- callfunc "F_GetWeaponType",<weapon ID>
//
// Returns equipment type, based on equip location.
// -- callfunc "F_GetArmorType",<item ID>
//////////////////////////////////////////////////////////////////////////////////
function	script	F_GetWeaponType	{
	switch(getiteminfo(getarg(0),11)) {
		case 1: return "Dagger"; break;
		case 2: return "One-handed Sword"; break;
		case 3: return "Two-handed Sword"; break;
		case 4: return "One-handed Spear"; break;
		case 5: return "Two-handed Spear"; break;
		case 6: return "One-handed Axe"; break;
		case 7: return "Two-handed Axe"; break;
		case 8: return "Mace"; break;
		//case 9: return "Unused"; break;
		case 10: return "Staff"; break;
		case 11: return "Bow"; break;
		case 12: return "Knuckle"; break;
		case 13: return "Instrument"; break;
		case 14: return "Whip"; break;
		case 15: return "Book"; break;
		case 16: return "Katar"; break;
		case 17: return "Revolver"; break;
		case 18: return "Rifle"; break;
		case 19: return "Gatling gun"; break;
		case 20: return "Shotgun"; break;
		case 21: return "Grenade Launcher"; break;
		case 22: return "Shuriken"; break;
		default: return "Unknown Weapon"; break;
	}
	end;
}
function	script	F_GetArmorType	{
	switch(getiteminfo(getarg(0),5)) {
		case 001: return "Lower Headgear"; break;
		case 2: return callfunc("F_GetWeaponType",getarg(0)); break;
		case 4: return "Garment"; break;
		case 8: return "Accessory"; break;
		case 16: return "Armor"; break;
		case 32: return "Shield"; break;
		case 64: return "Shoes"; break;
		case 128: return "Accessory"; break;
		case 136: return "Accessory"; break; //8+128
		case 256: return "Upper Headgear"; break;
		case 512: return "Middle Headgear"; break;
		case 1024: return "Costume Upper Headgear"; break;
		case 2048: return "Costume Midle Headgear"; break;
		case 4096: return "Costume Lower Headgear"; break;
		case 8192: return "Costume Garment"; break;
		case 32768: return "Ammo"; break;
		case 65536: return "Shadow Armor"; break;
		case 131072: return "Shadow Weapon"; break;
		case 262144: return "Shadow Shield"; break;
		case 524288: return "Shadow Shoes"; break;
		case 1048576: return "Shadow Accessory"; break;
		case 2097152: return "Shadow Accessory"; break;
		case 3145728: return "Shadow Accessory"; break; //1048576+2097152
		default: return "Unknown Equip"; break;
	}
	end;
}


//////////////////////////////////////////////////////////////////////////////////
// Returns time remaining in a readable format.
// The argument is subtracted from UNIX epoch time, or 'gettimetick(2)'.
// -- callfunc "Time2Str",<tick in UNIX epoch time>
// Example:
//    // Displays "Time left: 1 day, 1 hour, 8 minutes, 20 seconds"
//    set .@Timer, gettimetick(2) + 90500;
//    mes "Time left: " + callfunc("Time2Str",.@Timer);
//////////////////////////////////////////////////////////////////////////////////
function	script	Time2Str	{
	set .@Time_Left, getarg(0) - gettimetick(2);
	
	set .@Days, .@Time_Left / 86400;
	set .@Time_Left, .@Time_Left - (.@Days * 86400);
	set .@Hours, .@Time_Left / 3600;
	set .@Time_Left, .@Time_Left - (.@Hours * 3600);
	set .@Minutes, .@Time_Left / 60;
	set .@Time_Left, .@Time_Left - (.@Minutes * 60);
	
	set .@Time$, "";
	if( .@Days > 1 )
		set .@Time$, .@Time$ + .@Days + " days, ";
	else if( .@Days > 0 )
		set .@Time$, .@Time$ + .@Days + " day, ";

	if( .@Hours > 1 )
		set .@Time$, .@Time$ + .@Hours + " hours, ";
	else if( .@Hours > 0 )
		set .@Time$, .@Time$ + .@Hours + " hour, ";

	if( .@Minutes > 1 )
		set .@Time$, .@Time$ + .@Minutes + " minutes, ";
	else if( .@Minutes > 0 )
		set .@Time$, .@Time$ + .@Minutes + " minute, ";

	if( .@Time_Left > 1 || .@Time_Left == 0 )
		set .@Time$, .@Time$ + .@Time_Left + " seconds";
	else if( .@Time_Left == 1 )
		set .@Time$, .@Time$ + .@Time_Left + " second";
	
	return .@Time$;
}


//////////////////////////////////////////////////////////////////////////////////
// Checks if equipment has been swapped (i.e. via hacks).
// The function checks the current equipment at a position against the supplied
// values, and logs any mismatches.
// Returns 0 if match, 1 if mismatch.
// -- callfunc "F_IsEquipIDHack",<equip position>,<equip ID>
// -- callfunc "F_IsEquipRefineHack",<equip position>,<refine>
// -- callfunc "F_IsEquipCardHack",<equip position>,<card 0>,<card 1>,<card 2>,<card 3>
//////////////////////////////////////////////////////////////////////////////////
function	script	F_IsEquipIDHack	{
	set .@id_chk, getequipid(getarg(0));
	set .@id, getarg(1);
	if (.@id != .@id_chk) {
		logmes "Hack: Tried to swap equip " + getitemname(.@id) + " for " + getitemname(.@id_chk) + ".";
		return 1;
	}
	return 0;
}
function	script	F_IsEquipRefineHack	{
	set .@refine_chk, getequiprefinerycnt(getarg(0));
	set .@refine, getarg(1);
	if (.@refine != .@refine_chk) {
		logmes "Hack: Tried to swap equip with refine +" + .@refine + " for +" + .@refine_chk + ".";
		return 1;
	}
	return 0;
}
function	script	F_IsEquipCardHack	{
	set .@pos, getarg(0);
	for (set .@i,0; .@i < 4; set .@i, .@i+1) {
		set .@card, getarg(.@i + 1);
		set .@card_chk, getequipcardid(.@pos, .@i);
		if (.@card != .@card_chk) {
			logmes "Hack: Tried to swap card " + getitemname(.@card) + " for " + getitemname(.@card_chk) + ".";
			return 1;
		}
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////
// Functions for text manipulation [Euphy]
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Returns the plural of a noun - works in most cases, but not for everything!
// -- callfunc "F_GetPlural","<noun>"{,<0:normal/1:uppercase>}
// Examples:
//    callfunc("F_GetPlural","dog")            // returns "dogs"
//    callfunc("F_GetPlural","fox",1)          // returns "FOXES"
//    callfunc("F_GetPlural","knife")          // returns "knives"
//    callfunc("F_GetPlural","Piece of Cake")  // returns "Pieces of Cake"
//
// Returns the plural of a noun if the given number is not 1.
// -- callfunc "F_InsertPlural",<number>,"<noun>"{,<0:normal/1:uppercase>{,"<format string>"}}
// Format string uses sprintf(), and MUST contain %d (arg0) and %s (arg1), in that order.
// Examples:
//    callfunc("F_InsertPlural",1,"dog")    // returns "1 dog"
//    callfunc("F_InsertPlural",3,"fox",1)  // returns "3 FOXES"
//    // returns "^FF00005^000000 knives"
//    callfunc("F_InsertPlural",5,"knife",0,"^FF0000%d^000000 %s")
//////////////////////////////////////////////////////////////////////////////////
function	script	F_GetPlural	{
	set .@str$, getarg(0);

	if (countstr(.@str$," ")) {  // multiple words
		explode(.@tmp$,.@str$," ");
		set .@size, getarraysize(.@tmp$);

		// if format is "... of|in|on ...", pluralize preceding word; else pluralize last word
		if (compare(.@str$," of ") || compare(.@str$," in ") || compare(.@str$," on ")) {
			for (set .@i,1; .@i<.@size; set .@i,.@i+1) {
				if (getstrlen(.@tmp$[.@i]) == 2 && compare("of|in|on",.@tmp$[.@i]))
					break;
				set .@index, .@index + 1;
			}
		} else
			set .@index, .@size - 1;

		set .@str$, .@tmp$[.@index];
		set .@tmp$[.@index],"%s";
		set .@format$, implode(.@tmp$," ");
	} else
		set .@format$, "%s";

	set .@strlen, getstrlen(.@str$);
	if (.@strlen < 3)  // prevent errors
		return ((getarg(1,0)) ? strtoupper(sprintf(.@format$,.@str$)) : sprintf(.@format$,.@str$));

	setarray .@suffix$[0], charat(.@str$,.@strlen - 1), substr(.@str$,.@strlen - 2,.@strlen - 1);
	if (!compare("abcdefghijklmnopqrstuvwxyz",.@suffix$[0])) {  // last character is not a letter
		set .@result$, .@str$;
	}

	// common exceptions --> singular form == plural form
	else if (compare("fish|glasses|sunglasses|clothes|boots|shoes|greaves|sandals|wings|ears",.@str$)) {
		set .@result$, .@str$;
	}

	// ends in -s, -x, -z, -ch, -sh --> add -es
	else if (.@suffix$[0] == "s" || .@suffix$[0] == "x" || .@suffix$[0] == "z" ||
	    .@suffix$[1] == "ch" || .@suffix$[1] == "sh") {
		set .@result$, .@str$ + "es";
	}

	// ends in -f, -fe --> remove -f, -fe --> add -ves
	else if ((.@suffix$[0] == "f" || .@suffix$[1] == "fe") && .@suffix$[1] != "ff") {
		if (compare("belief|cliff|chief|dwarf|grief|gulf|proof|roof",.@str$))
			set .@result$, .@str$ + "s";  // exceptions --> add -s
		else
			set .@result$, substr(.@str$,0,.@strlen - 2 - (.@suffix$[1] == "fe")) + "ves";
	}
	
	// ends in consonant + -y --> remove -y --> add -ies
	else if (.@suffix$[0] == "y" && !compare("aeiou",charat(.@suffix$[1],0))) {
		set .@result$, delchar(.@str$,.@strlen - 1) + "ies";
	}

	// ends in -o --> exceptions --> add -es
	else if (.@suffix$[0] == "o" &&
	         compare("buffalo|domino|echo|grotto|halo|hero|mango|mosquito|potato|tomato|tornado|torpedo|veto|volcano",.@str$)) {
		set .@result$, .@str$ + "es";
	}

	// default --> add -s
	else {
		set .@result$, .@str$ + "s";
	}

	return ((getarg(1,0)) ? strtoupper(sprintf(.@format$,.@result$)) : sprintf(.@format$,.@result$));
}
function	script	F_InsertPlural	{
	return sprintf(getarg(3,"%d %s"), getarg(0), ((getarg(0) == 1) ? getarg(1) : callfunc("F_GetPlural",getarg(1),getarg(2,0))));
}


//////////////////////////////////////////////////////////////////////////////////
// Returns 'a' or 'an' based on a word.
// -- callfunc "F_GetArticle","<noun>";
// Examples:
//    callfunc("F_GetArticle","Apple")  // returns "an"
//    callfunc("F_GetArticle","dog")    // returns "a"
//
// Returns 'a' or 'an' based on a word, followed by the word.
// -- callfunc "F_InsertArticle","<word>"{,<0:lowercase a/1:uppercase A>}
// Examples:
//    callfunc("F_InsertArticle","Apple")  // returns "an Apple"
//    callfunc("F_InsertArticle","dog",1)  // returns "A dog"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_GetArticle	{
	set .@str$, strtolower(getarg(0));

	// not a word
	if (!charisalpha(.@str$,0))
		return "a";

	// 1-letter words
	if (getstrlen(.@str$) == 1) {
		if (strpos("aefhilmnorsx",.@str$) > -1)
			return "an";
		else
			return "a";
	}

	// special cases
	if (preg_match("(euler|hour(?!i)|heir|honest|hono)",.@str$))
		return "an";

	// consonants
	if (preg_match("^[^aeiouy]",.@str$))
		return "a";

	// special vowel forms
	if (preg_match("^e[uw]",.@str$) || preg_match("^onc?e\b",.@str$) || preg_match("^uni([^nmd]|mo)",.@str$) || preg_match("^u[bcfhjkqrst][aeiou]",.@str$))
		return "a";
	if (preg_match("^ut[th]",.@str$))
		return "an";

	// special capitals (rare)
	//if (preg_match("^U[NK][AIEO]?",getarg(0)))
	//	return "a";

	// vowels
	if (preg_match("^[aeiou]",.@str$))
		return "an";

	// y... (rare)
	//if (preg_match("^(y(b[lor]|cl[ea]|fere|gg|p[ios]|rou|tt))",.@str$))
	//	return "an";

	return "a";
}
function	script	F_InsertArticle	{
	set .@article$, callfunc("F_GetArticle",getarg(0));
	return sprintf("%s %s", ((getarg(1,0)) ? replacestr(.@article$,"a","A") : .@article$), getarg(0));
}


//////////////////////////////////////////////////////////////////////////////////
// Returns a number with commas between every three digits.
// -- callfunc "F_InsertComma",<number>
// Examples:
//    callfunc("F_InsertComma",7777777)  // returns "7,777,777"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_InsertComma	{
	set .@str$, getarg(0);
	for (set .@i,getstrlen(.@str$)-3; .@i>0; set .@i,.@i-3)
		set .@str$, insertchar(.@str$,",",.@i);
	return .@str$;
}


//////////////////////////////////////////////////////////////////////////////////
// Returns a number with a '-st', '-nd', '-rd', or '-th' suffix.
// -- callfunc "F_GetNumSuffix",<number>
// Examples:
//    callfunc("F_GetNumSuffix",1)   // returns "1st"
//    callfunc("F_GetNumSuffix",11)  // returns "11th"
//    callfunc("F_GetNumSuffix",32)  // returns "32nd"
//////////////////////////////////////////////////////////////////////////////////
function	script	F_GetNumSuffix	{
	set .@n, getarg(0);
	set .@mod, .@n % 10;
	if      (.@mod == 1 && .@n != 11) return .@n+"st";
	else if (.@mod == 2 && .@n != 12) return .@n+"nd";
	else if (.@mod == 3 && .@n != 13) return .@n+"rd";
	else return .@n+"th";
}
