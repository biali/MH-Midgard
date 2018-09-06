// *********************************
// *                               *
// * Miner System - GaiaRo Version *
// *                               *
// *********************************

// Used to draw HP bar string
function	script	DrawHP	{
	set .@Draw$, " [";
	set .@HP, getarg(0);
	// Starting Color
	if( .@HP > 20 ) set .@Draw$, .@Draw$ + "^0EAE1B";
	else if( .@HP > 15 ) set .@Draw$, .@Draw$ + "^7CAE0E";
	else if( .@HP > 10 ) set .@Draw$, .@Draw$ + "^E3C521";
	else if( .@HP > 5 ) set .@Draw$, .@Draw$ + "^D86112";
	else set .@Draw$, .@Draw$ + "^D82412";
	// Draw HP Bar
	for( set .@x, 0; .@x < 30; set .@x, .@x + 1 )
	{
		if( .@x == .@HP ) set .@Draw$, .@Draw$ + "^E0E0E0=";
		else set .@Draw$, .@Draw$ + "=";
	}
	
	set .@Draw$, .@Draw$ + "^000000]";
	
	return .@Draw$;
}

// Main Mining Engine
// arg(0) = NPC Name
function	script	Mining_Work	{
	
	// Check Requeriments
	if( getvariableofnpc(.Mine_On, getarg(0)) == 0 ) end;
	mes "[^0000FF" + strcharinfo(0) + "^000000]";

	set @Mine_Ele, getvariableofnpc(.Mine_Ele, getarg(0));
	set @Mine_Lvl, $@Mine_Lvl[@Mine_Ele];

	// * Working Level
	if( MiningLvl < @Mine_Lvl ) {
		mes "Your level is not enough for working in mines ^0000FF" + $@Mine_Name$[@Mine_Ele] + "^000000";
		mes "Required Level: ^FF0000" + $@MiningLv$[@Mine_Lvl] + "^000000";
		mes " ";
		mes ">> ^FF0000" + $@MiningLv$[MiningLvl] + "^000000 <<";
		set @Progress, (MiningExp * 30) / $@MiningLUp[MiningLvl];
		mes "" + callfunc("DrawHP",@Progress) + "";
		close;
	}
	
	// * Old Pick
	if( countitem(7318) < 1 ) {
		mes "To work in mine you must have an Old Pick in your inventory.";
		mes " ";
		mes ">> ^FF0000Item required: " + getitemname(7318) + " ^000000 <<";
		close;
	}

	// * HeadGear
	if( getequipid(1) != 5009 && getequipid(1) != 5031 ) {
		mes "For your safety, before work you must put on ^FF0000" + getitemname(5009) + "^000000 or ^FF0000" + getitemname(5031) + " ^000000.";
		close;
	}

	set @Pike_HP, rand(4,10) + (MiningLvl - @Mine_Lvl) * 2;
	set @Mine_WPF, 0;
	delitem 7318,1;

	mes "What a luck, a ^0000FF" + $@Mine_Size$[getvariableofnpc(.Mine_SZ, getarg(0))] + "^000000 mine ^0000FF" + $@Mine_Name$[@Mine_Ele] + "^000000!!, see what we find in it.";
	mes " ";
	mes ">> ^FF0000" + $@MiningLv$[MiningLvl] + "^000000 <<";
	if( MiningLvl < 7 ) {
		set @Progress, (MiningExp * 30) / $@MiningLUp[MiningLvl];
		mes "" + callfunc("DrawHP",@Progress) + "";
	}
	next;
	
	// Working
L_BreakRock:
	if( getvariableofnpc(.Mine_On, getarg(0)) == 0 ) goto L_Close;
	mes "> Pike:";
	mes "" + callfunc("DrawHP",@Pike_HP) + "";
	mes "> Rock:";
	mes "" + callfunc("DrawHP",getvariableofnpc(.Mine_HP, getarg(0))) + "";
	mes " ";
	mes "[^0000FF" + strcharinfo(0) + "^000000]";
	if( @Mine_WPF )
		mes "Break the ^0000FF" + $@PickLocation$[getvariableofnpc(.Mine_WP, getarg(0))] + "^000000";
	else
		mes "Fnd the weak point!";
	next;
	
	if( getvariableofnpc(.Mine_On, getarg(0)) == 0 ) goto L_Close;

	// Random Menu Build
	set @i, 0;
	setarray @KPos[0],9,9,9,9,9,9,9,9,9;
	setarray @TPos[0],0,1,2,3,4,5,6,7,8;

	while( @i < 9 ) {
		set @Wrd, rand(9 - @i);

		set @KPos[@i], @TPos[@Wrd];
		deletearray @TPos[@Wrd],1;
		
		set @i, @i + 1;
	}

	set @tmpMenu$,"";
	for( set @x, 0; @x < 9; set @x, @x + 1 ) {
		set @tmpMenu$, @tmpMenu$ + $@PickLocation$[@KPos[@x]] + ":";
	}
	set @tmpMenu$, @tmpMenu$ + "Salir";
	// Menu Display
	set @Opcion, select(@tmpMenu$) - 1;
	if( @Opcion == 9 ) goto L_Exit;

	if( getvariableofnpc(.Mine_On, getarg(0)) == 0 ) goto L_Close;
	// Hit Point
	if( @KPos[@Opcion] == getvariableofnpc(.Mine_WP, getarg(0)) ) {
		set @Mine_WPF, 1;
		soundeffect "chepet_attack.wav",0;
		specialeffect 4;
		set @HPower1, rand(3,4);
		set @HPower2, rand(2);
	} else {
		soundeffect "apocalips_h_move.wav",0;
		specialeffect 5;
		set @HPower1, rand(2);
		set @HPower2, rand(1,3);
	}
	
	flooritem $@Stones[rand(2)],rand(1,2);
	
	// Update Mine and Pick HP
	set getvariableofnpc(.Mine_HP, getarg(0)), getvariableofnpc(.Mine_HP, getarg(0)) - @HPower1;
	set @Pike_HP, @Pike_HP - @HPower2;

	// Success ??
	if( getvariableofnpc(.Mine_HP, getarg(0)) < 1 ) {
		soundeffect "ice_titan_die.wav",0;
		specialeffect 135;
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "I did it! See the fruits of the hard work...";
		emotion e_what,1;

		// Exp Progress
		if( MiningLvl < 7 )
		{
			set MiningExp, MiningExp + $@Mine_Exp[@Mine_Ele];
			if( MiningExp >= $@MiningLUp[MiningLvl] ) {
				// Level Up
				set MiningLvl, MiningLvl + 1;
				set MiningExp, 0;
				specialeffect2 568;
				dispbottom "[You raised your experience level to " + $@MiningLv$[MiningLvl] + " at work in mines]";
			} else {
				set @Progress, (MiningExp * 100) / $@MiningLUp[MiningLvl];
				dispbottom "[ Current: " + $@MiningLv$[MiningLvl] + " -> " + @Progress + "% -> Next: " + $@MiningLv$[MiningLvl + 1] + " ]";
			}
		}

		// Hide NPC
		setnpcdisplay getarg(0),"Mining Spot",844,0;
		set getvariableofnpc(.Mine_Spawn, getarg(0)), rand($@Mine_SpawnMin[@Mine_Ele],$@Mine_SpawnMax[@Mine_Ele]);
		set getvariableofnpc(.Mine_On, getarg(0)), 0;
		initnpctimer getarg(0);
		disablenpc getarg(0);

		set @Mine_Size, getvariableofnpc(.Mine_SZ, getarg(0));
		close2;

		// @Mine_Lvl @Mine_Ele @Mine_Size allready set
		emotion e_cash,1;
		callfunc "Mining_Drop";
		end;
	}
	
	// Accidents
	if( !rand(10) ) {
		// Scream!!
		if( sex ) soundeffect "die_male.wav",0;
		else soundeffect "die_merchant_female.wav",0;
		
		percentheal -rand(5,20),0; // Damage
		
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "^FF0000" + $@MNAccidents$[rand(getarraysize($@MNAccidents$))] + "^000000";
		emotion e_omg,1;

		if( HP < 1 ) close; // Killed by Mine
		next;
	} else if( !rand(500) ) {
		specialeffect 666;
		atcommand "@die";
		announce "There was a landslide, can't escape alive!",3;
		end;
	}

	// Pike Status
	if( @Pike_HP < 1 ) {
		specialeffect 155;
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "Baahhhhh.... bad luck... Pike has broken!";
		close;
	}

	goto L_BreakRock;

L_Close:
	mes "[^0000FF" + strcharinfo(0) + "^000000]";
	mes "This vein has collapsed, there is nothing to do here anymore.";
	close;

L_Exit:
	mes "[^0000FF" + strcharinfo(0) + "^000000]";
	mes "Maybe come back later.";
	close;
}

// Called on Init per Mine
// arg(0) = NPC Name
// arg(1) = Mine Element
function	script	Mining_Init	{
	setnpcdisplay getarg(0),"Mining Spot",844,111;
	if( !$@MiningReady ) donpcevent "MiningEngine::OnInit";
	
	set getvariableofnpc(.Mine_Spawn,getarg(0)), rand($@Mine_SpawnMin[getarg(1)],$@Mine_SpawnMax[getarg(1)]);
	set getvariableofnpc(.Mine_On, getarg(0)), 0; // Mine Inactive
	set getvariableofnpc(.Mine_Ele, getarg(0)), getarg(1);
	
	initnpctimer getarg(0);
	disablenpc getarg(0);
	return;
}

// CountDown to Mine Spawn
// arg(0) = NPC Name
function	script	Mining_Tick	{
	stopnpctimer;
	set getvariableofnpc(.Mine_Spawn,getarg(0)), getvariableofnpc(.Mine_Spawn,getarg(0)) - 1; // Tick
	if( getvariableofnpc(.Mine_Spawn,getarg(0)) < 1 ) {
		// Mine Spawn
		enablenpc getarg(0);
		set .@size, rand(100);
		if( .@size < 5 )
			set getvariableofnpc(.Mine_SZ, getarg(0)), 2; // Big 5%
		else if( .@size < 90 )
			set getvariableofnpc(.Mine_SZ, getarg(0)), 1; // Small 85%
		else
			set getvariableofnpc(.Mine_SZ, getarg(0)), 0; // Normal 10%

		set .@Mine_Ele, getvariableofnpc(.Mine_Ele, getarg(0));
		setnpcdisplay getarg(0), "" + $@Mine_Name$[.@Mine_Ele] + " Mine", $@Mine_Sprite[.@Mine_Ele], getvariableofnpc(.Mine_SZ, getarg(0));

		specialeffect 134;
		switch( getvariableofnpc(.Mine_SZ, getarg(0)) ) {
			// Mine Total HP
			case 0: set getvariableofnpc(.Mine_HP, getarg(0)), rand(15,25); break;
			case 1: set getvariableofnpc(.Mine_HP, getarg(0)), rand(10,15); break;
			case 2: set getvariableofnpc(.Mine_HP, getarg(0)), rand(25,30); break;
		}
		
		set getvariableofnpc(.Mine_WP, getarg(0)), rand(9); // Weak Point
		set getvariableofnpc(.Mine_On, getarg(0)), 1;
		end;
	}
	initnpctimer getarg(0);
	end;
}

// Mine Drop
// Uses: @Mine_Ele @Mine_Lvl @Mine_Size
function	script	Mining_Drop	{
	// Common Minerals
	if( rand(100) < 90 + @Mine_Lvl ) getitem $@CommonMinerals[rand(getarraysize($@CommonMinerals))],1;

	// Unique Drops
	set @size, getarraysize(getd("$@Minerals_" + @Mine_Ele + "_ID"));
	switch( @Mine_Size ) {
		case 0: set @bonus, 2; break;
		case 1: set @bonus, 1; break;
		case 2: set @bonus, 3; break;
	}

	for( set @i, 0; @i < @size; set @i, @i + 1 )
	{
		set @rate, getd("$@Minerals_" + @Mine_Ele + "_RT[" + @i + "]") * @bonus;

		if( @rate >= rand(1,10000) ) getitem getd("$@Minerals_" + @Mine_Ele + "_ID[" + @i + "]"), 1;
	}
	
	// Normal Minerals
	if( rand(100) < 20 + @Mine_Lvl ) getitem $@NormalMinerals[rand(getarraysize($@NormalMinerals))],1;
	// Special Minerals
	if( rand(100) < 2 + @Mine_Lvl ) getitem $@SpecialMinerals[rand(getarraysize($@SpecialMinerals))],1;

	return;
}

-	script	MiningEngine	-1,{
	end;

OnInit:
	if( $@MiningReady ) end;

	// Player Settings
	setarray $@MiningLv$[0],	"Candidate","Rookie","Apprentice","Worker","Pitman","Expert","Craftsman","Master";
	setarray $@MiningLUp[0],	       9000,   21600,     37800,      57600,   81000,   108000,    157500,   999999;

	// Per Element - Mine Settings
	setarray $@Mine_Name$[0],	"Phracon","Emveretarcon","Iron","Steel","Star","Crystal","Oridecon","Elunium","Magic Crystal"; // * Mine Names
	setarray $@Mine_Lvl[0],		        0,             1,     2,      3,     4,        5,         6,        7,              7; // * Required Lvl to Work on It
	setarray $@Mine_Sprite[0],	     1915,          1907,  1908,   1908,  1907,     1914,      1914,     1915,           1907; // * Sprite
	setarray $@Mine_SpawnMin[0],	        3,             5,    20,     40,    90,       90,        90,       90,           1200; // * Minimum Spawn Time
	setarray $@Mine_SpawnMax[0],	        5,            20,    40,     80,   120,      180,       300,      360,           2400; // * Maximum Spawn Time
	setarray $@Mine_Exp[0],		       60,           140,   250,    360,   450,      540,       630,      720,            900; // * Experience

	// Other Stuff
	setarray $@Stones[0],		7067,7049;
	setarray $@Mine_Size$[0],	"medium","small","large";
	setarray $@PickLocation$[0],	"[O] Center","[/\\] Top","[<\\] Top Left","[<] Left","[</] Bottom Left","[\\/] Bottom","[\\>] Bottom Right","[>] Right","[/>] Top Right";
	setarray $@MNAccidents$[0],	"Ouchhh! A stone hurted my eye... snifff",
					"OMG!!!!...  I've crushed my finger!",
					"Ouchhh! A stone hit my face...",
					"Auch!!!...  I'm always hitting myself while mining... grr...",
					"Arghhh!... A rock hurted my head...",
					"Ayy!!... A rock fell on my feet... argghh...",
					"Grrr... I always forget to keep my hand out of the middle... damn mine...";

	// Common Drops
	setarray $@CommonMinerals[0],	909,910,911,912,7067,7049,7067,7049;
	setarray $@NormalMinerals[0],	1003,7053,7054,7315,7321,7096,7300,7067,7049,7067,7049,7067,7049;
	setarray $@SpecialMinerals[0],	7231,7231,7231,7232,7232,7232,7233,7233,7233,12040,714,969,7067,7049,7067,7049,7067,7049,7067,7049,7067,7049;

	// Unique Drops Phracon
	setarray $@Minerals_0_ID[0],	 1010, 1010, 1010,  756,  757;
	setarray $@Minerals_0_RT[0],	 4000, 2000,  500,  150,  150;
	// Unique Drops Emveretarcon
	setarray $@Minerals_1_ID[0],	 1011, 1011, 1011,  756,  757,  714;
	setarray $@Minerals_1_RT[0],	 5000, 4000, 3000,  200,  200,   50;
	// Unique Drops Iron
	setarray $@Minerals_2_ID[0],	 1002, 1002, 1002,  998,  756,  757,  998, 1003;
	setarray $@Minerals_2_RT[0],	 3500, 3000, 1000, 1000,  300,  300,  750,  500;
	// Unique Drops Steel
	setarray $@Minerals_3_ID[0],	  999,  999, 1003,  756,  757, 1003, 1003;
	setarray $@Minerals_3_RT[0],	 3500, 2500, 3500,  700,  700,  500,  250;
	// Unique Drops Star
	setarray $@Minerals_4_ID[0],	 1001, 1001, 1001, 1000, 1000, 1000,  714, 7096, 7096, 7096;
	setarray $@Minerals_4_RT[0],	 5000, 3500, 2500, 3000, 1500,  500,  100, 5000, 5000, 5000;
	// Unique Drops Crystal
	setarray $@Minerals_5_ID[0],	  730,  731,  732,  733, 7315, 7321, 7053, 7054, 7066, 7066, 7066;
	setarray $@Minerals_5_RT[0],	 4000, 2500, 3500, 1250, 4000, 5000, 2000, 2000, 5000, 5000, 5000;
	// Unique Drops Oridecon
	setarray $@Minerals_6_ID[0],	  756,  756,  756,  756,  984,  984,  984, 7620;
	setarray $@Minerals_6_RT[0],	 5000, 4000, 3000, 2000, 2500, 1500,  500,   50;
	// Unique Drops Elunium
	setarray $@Minerals_7_ID[0],	  757,  757,  757,  757,  985,  985,  985, 7619;
	setarray $@Minerals_7_RT[0],	 5000, 4000, 3000, 2000, 2500, 1500,  500,   50;
	// Unique Drops Magic Crystal
	setarray $@Minerals_8_ID[0],	 8906,  717,  717,  717,  717,  716,  716,  716,  716,  715,  715,  715,  715;
	setarray $@Minerals_8_RT[0],	 7000, 9500, 7500, 5500, 3500, 9500, 7500, 5500, 3500, 9500, 7500, 5500, 3500;

	// Spawn Min-Max Time
	
	set $@MiningReady, 1;
	end;
}

// *****************
// * Mining Guides *
// *****************

function	script	Mining_DropInfo	{
	set @Size, getarraysize(getd("$@Minerals_" + getarg(0) + "_ID"));
	set .@Return$, "";
	set .@Comma$, "";
	for( set @i, 0; @i < @Size; set @i, @i + 1 )
	{
		set .@Return$, .@Return$ + .@Comma$ + "^0000FF" + getitemname(getd("$@Minerals_" + getarg(0) + "_ID[" + @i + "]")) + "^000000";
		set .@Comma$, ", ";
	}
	
	return .@Return$;
}

function	script	Mining_Common	{
	set @Size, getarraysize($@CommonMinerals);
	set .@Return$, "";
	set .@Comma$, "";
	for( set @i, 0; @i < @Size; set @i, @i + 1 )
	{
		set .@Return$, .@Return$ + .@Comma$ + "^0000FF" + getitemname($@CommonMinerals[@i]) + "^000000";
		set .@Comma$, ", ";
	}
	
	return .@Return$;
}

function	script	Mining_Normal	{
	set @Size, getarraysize($@NormalMinerals);
	set .@Return$, "";
	set .@Comma$, "";
	for( set @i, 0; @i < @Size; set @i, @i + 1 )
	{
		set .@Return$, .@Return$ + .@Comma$ + "^0000FF" + getitemname($@NormalMinerals[@i]) + "^000000";
		set .@Comma$, ", ";
	}
	
	return .@Return$;
}

function	script	Mining_Special	{
	set @Size, getarraysize($@SpecialMinerals);
	set .@Return$, "";
	set .@Comma$, "";
	for( set @i, 0; @i < @Size; set @i, @i + 1 )
	{
		set .@Return$, .@Return$ + .@Comma$ + "^0000FF" + getitemname($@SpecialMinerals[@i]) + "^000000";
		set .@Comma$, ", ";
	}
	
	return .@Return$;
}

// Information NPCs
// arg(0) Mine Ele
// arg(1) Zeny per Old Pick

function	script	Mining_Info	{
	set @Mine_Ele, getarg(0);
	set @Mine_Lvl, $@Mine_Lvl[@Mine_Ele];
	
	mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
	mes "Welcome to the mines ^FF0000" + $@Mine_Name$[@Mine_Ele] + "^000000.";
	if( @Mine_Lvl < 7 )
		mes "I'll working hard to become a ^FF0000" + $@MiningLv$[@Mine_Lvl + 1] + "^000000.";
	else
		mes "I'm an expert in mining and I have the ability to work in any mine.";
	next;
	mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
	mes "Can I help you?";
	next;
	switch( select("Sell me Old Picks:Tell me about Mining:Tell me about Mines:What about Drops?:Different Sizes?:Become a Master?:No thanks.") )
	{
		case 1:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
//			mes "Of course, I always bring a lot to me because they break often.";
			mes "I can sell you some for " + getarg(1) + " zeny.";
			mes "Wanna buy? (1 to 10)";
			next;
			input @Picks;
			if( @Picks < 1 || @Picks > 10 ) {
				mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
				mes "Please input the number from 1 to 10:";
				close;
			}
			
			set @Price, getarg(1) * @Picks;
			if( Zeny < @Price ) {
				mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
				mes "Sorry but you don't have enough money.";
				close;
			}
			
			set Zeny, Zeny - @Price;
			getitem 7318, @Picks;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "Here you go, good luck in work.";
			break;
		case 2:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "Mining is a good work. Minerals from different mines in different places can make you good fortune.";
			next;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "In Midgard, there are many mines of different elements that provide a variety of different minerals.";
			mes "But to work in higher level mines are required to have experience.";
			next;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Mine^000000]";
			mes "There are 8 different levels of worker:";
			mes "- Lvl 0 : ^FF0000Candidate^000000";
			mes "- Lvl 1 : ^FF0000Rookie^000000";
			mes "- Lvl 2 : ^FF0000Apprentice^000000";
			mes "- Lvl 3 : ^FF0000Worker^000000";
			mes "- Lvl 4 : ^FF0000Pitman^000000";
			mes "- Lvl 5 : ^FF0000Expert^000000";
			mes "- Lvl 6 : ^FF0000Craftsman^000000";
			mes "- Lvl 7 : ^FF0000Master^000000";
			break;
		case 3:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Mine^000000]";
			mes "What kind of Mine you wanna know about?";
			set @Mine, 0;
			while( @Mine != 10 )
			{
				next;
				set @Mine, select("Phracon:Emveretarcon:Iron:Steel:Star:Crystal:Oridecon:Elunium:Magic Crystal:Thanks for the Info");
				switch( @Mine )
				{
					case 1:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Phracon Mines you can find in Payon Dungeon.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",0) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Candidate.";
						break;
					case 2:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Emveretarcon Mines you can find in Ant Hell.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",1) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Rookie.";
						break;
					case 3:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Iron Mines you can find in Einbech Dungeon.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",2) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Apprentice.";
						break;
					case 4:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Steel Mines you can find in Juperos.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",3) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Worker.";
						break;
					case 5:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Star Mines you can find in Magma Dungeon.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",4) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Pitman.";
						break;
					case 6:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Crystal Mines you can find in Ice Dungeon.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",5) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Expert.";
						break;
					case 7:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Oridecon Mines you can find in Abyss Lake.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",6) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Craftsman.";
						break;
					case 8:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Elunium Mines you can find in Thor Dungeon.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",7) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Master.";
						break;
					case 9:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "Crystal Magic mines are special and you'll find in the middle of a map, in a small oasis in the north desert of Rachel.";
						mes "You can get the following minerals:";
						mes "" + callfunc("Mining_DropInfo",8) + ".";
						next;
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "To work in these mines, you must be Master.";
						mes "Unlike other mines, they produce a special called Crystal ^FF0000Support Crystal Summoner^000000.";
						break;
					case 10:
						mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
						mes "A pleasure to help that you need.";
						break;
				}
			}
			break;
		case 4:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "There are certain minerals that come in different mines, and all together.";
			next;
			mes "^0000FFCommon^000000 Minerals : 90% chance";
			mes "You can get one of the following minerals:";
			mes "" + callfunc("Mining_Common") + ".";
			next;
			mes "^0000FFNormal^000000 Minerals : 20% chance";
			mes "You can get one of the following minerals:";
			mes "" + callfunc("Mining_Normal") + ".";
			next;
			mes "^0000FFSpecial^000000 Minerals : 2% chance";
			mes "You can get one of the following minerals:";
			mes "" + callfunc("Mining_Special") + ".";
			next;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "Obtain base percentage does not change the size of the mine, but if it improves the higher level required it.";
			next;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "For example, in Phracon Mines have 2% kind of common minerals, whereas Elunium Mines up to 9%";
			break;
		case 5:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "The mines are presented in different sizes, making it easier to find small, medium and difficult then mine appear larger.";
			next;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "The larger size of the mine increase the chance of getting all their drops.";
			break;
		case 6:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "Oh... being Master is the best, you can work in any kind of mine and get good luck and skill.";
			mes "But there is something special to be Master...";
			next;
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "Masters can work in rare mines that are in north of Rachel, in a small oasis in the middle of the map.";
			mes "This object can summon a ^0000FFSupport Crystal^000000 for 20 minutes, that provides various blessings.";
			break;
		case 7:
			mes "[^0000FF" + $@MiningLv$[@Mine_Lvl] + " Miner^000000]";
			mes "Then get to work!!";
			mes "Remember, you need Old Picks and Helmet to protect your head during work.";
			mes "And careful of accidents...";
			break;
	}
	close;
}

pay_dun00,149,171,1	script	Candidate::OPick1	848,{
	callfunc "Mining_Info",0,1400;
}

anthell01,85,261,3	script	Rookie::OPick2	848,{
	callfunc "Mining_Info",1,1510;
}

ein_dun02,261,210,5	script	Apprentice::OPick3	848,{
	callfunc "Mining_Info",2,1620;
}

juperos_01,146,51,5	script	Worker::OPick4	848,{
	callfunc "Mining_Info",3,1730;
}

mag_dun01,229,62,7	script	Pitman::OPick5	848,{
	callfunc "Mining_Info",4,1840;
}

ice_dun03,32,252,3	script	Expert::OPick6	848,{
	callfunc "Mining_Info",5,1950;
}

abyss_02,247,273,3	script	Craftsman::OPick7	848,{
	callfunc "Mining_Info",6,2060;
}

thor_v02,24,126,1	script	Master::OPick8	848,{
	callfunc "Mining_Info",7,2170;
}



// *****************
// * Phracon Mines *
// *****************

pay_dun00,146,173,0	script	MiningSpot::MPay00	844,{
	callfunc "Mining_Work","MPay00"; end;
OnInit:		callfunc "Mining_Init","MPay00",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay00"; end;
}

pay_dun00,146,171,0	script	MiningSpot::MPay01	844,{
	callfunc "Mining_Work","MPay01"; end;
OnInit:		callfunc "Mining_Init","MPay01",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay01"; end;
}

pay_dun00,148,175,0	script	MiningSpot::MPay02	844,{
	callfunc "Mining_Work","MPay02"; end;
OnInit:		callfunc "Mining_Init","MPay02",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay02"; end;
}

pay_dun00,152,175,0	script	MiningSpot::MPay03	844,{
	callfunc "Mining_Work","MPay03"; end;
OnInit:		callfunc "Mining_Init","MPay03",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay03"; end;
}

pay_dun00,153,175,0	script	MiningSpot::MPay04	844,{
	callfunc "Mining_Work","MPay04"; end;
OnInit:		callfunc "Mining_Init","MPay04",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay04"; end;
}

pay_dun00,155,175,0	script	MiningSpot::MPay05	844,{
	callfunc "Mining_Work","MPay05"; end;
OnInit:		callfunc "Mining_Init","MPay05",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay05"; end;
}

pay_dun00,156,174,0	script	MiningSpot::MPay06	844,{
	callfunc "Mining_Work","MPay06"; end;
OnInit:		callfunc "Mining_Init","MPay06",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay06"; end;
}

pay_dun00,157,173,0	script	MiningSpot::MPay07	844,{
	callfunc "Mining_Work","MPay07"; end;
OnInit:		callfunc "Mining_Init","MPay07",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay07"; end;
}

pay_dun00,157,172,0	script	MiningSpot::MPay08	844,{
	callfunc "Mining_Work","MPay08"; end;
OnInit:		callfunc "Mining_Init","MPay08",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay08"; end;
}

pay_dun00,145,170,0	script	MiningSpot::MPay09	844,{
	callfunc "Mining_Work","MPay09"; end;
OnInit:		callfunc "Mining_Init","MPay09",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay09"; end;
}

pay_dun00,143,168,0	script	MiningSpot::MPay10	844,{
	callfunc "Mining_Work","MPay10"; end;
OnInit:		callfunc "Mining_Init","MPay10",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay10"; end;
}

pay_dun00,149,175,0	script	MiningSpot::MPay11	844,{
	callfunc "Mining_Work","MPay11"; end;
OnInit:		callfunc "Mining_Init","MPay11",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay11"; end;
}

pay_dun00,157,169,0	script	MiningSpot::MPay12	844,{
	callfunc "Mining_Work","MPay12"; end;
OnInit:		callfunc "Mining_Init","MPay12",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay12"; end;
}

pay_dun00,157,168,0	script	MiningSpot::MPay13	844,{
	callfunc "Mining_Work","MPay13"; end;
OnInit:		callfunc "Mining_Init","MPay13",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay13"; end;
}

pay_dun00,157,167,0	script	MiningSpot::MPay14	844,{
	callfunc "Mining_Work","MPay14"; end;
OnInit:		callfunc "Mining_Init","MPay14",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay14"; end;
}

pay_dun00,144,169,0	script	MiningSpot::MPay15	844,{
	callfunc "Mining_Work","MPay15"; end;
OnInit:		callfunc "Mining_Init","MPay15",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay15"; end;
}

pay_dun00,145,172,0	script	MiningSpot::MPay16	844,{
	callfunc "Mining_Work","MPay16"; end;
OnInit:		callfunc "Mining_Init","MPay16",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay16"; end;
}

pay_dun00,150,176,0	script	MiningSpot::MPay17	844,{
	callfunc "Mining_Work","MPay17"; end;
OnInit:		callfunc "Mining_Init","MPay17",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay17"; end;
}

pay_dun00,149,176,0	script	MiningSpot::MPay18	844,{
	callfunc "Mining_Work","MPay18"; end;
OnInit:		callfunc "Mining_Init","MPay18",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay18"; end;
}

pay_dun00,154,176,0	script	MiningSpot::MPay19	844,{
	callfunc "Mining_Work","MPay19"; end;
OnInit:		callfunc "Mining_Init","MPay19",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay19"; end;
}

pay_dun00,156,175,0	script	MiningSpot::MPay20	844,{
	callfunc "Mining_Work","MPay20"; end;
OnInit:		callfunc "Mining_Init","MPay20",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay20"; end;
}

pay_dun00,158,169,0	script	MiningSpot::MPay21	844,{
	callfunc "Mining_Work","MPay21"; end;
OnInit:		callfunc "Mining_Init","MPay21",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay21"; end;
}

pay_dun00,158,172,0	script	MiningSpot::MPay22	844,{
	callfunc "Mining_Work","MPay22"; end;
OnInit:		callfunc "Mining_Init","MPay22",0; end;
OnTimer60000: 	callfunc "Mining_Tick","MPay22"; end;
}

// **********************
// * Emveretarcon Mines *
// **********************

anthell01,92,271,0	script	MiningSpot::MAnt00	844,{
	callfunc "Mining_Work","MAnt00"; end;
OnInit:		callfunc "Mining_Init","MAnt00",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt00"; end;
}

anthell01,91,270,0	script	MiningSpot::MAnt01	844,{
	callfunc "Mining_Work","MAnt01"; end;
OnInit:		callfunc "Mining_Init","MAnt01",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt01"; end;
}

anthell01,94,271,0	script	MiningSpot::MAnt02	844,{
	callfunc "Mining_Work","MAnt02"; end;
OnInit:		callfunc "Mining_Init","MAnt02",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt02"; end;
}

anthell01,97,271,0	script	MiningSpot::MAnt03	844,{
	callfunc "Mining_Work","MAnt03"; end;
OnInit:		callfunc "Mining_Init","MAnt03",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt03"; end;
}

anthell01,104,265,0	script	MiningSpot::MAnt04	844,{
	callfunc "Mining_Work","MAnt04"; end;
OnInit:		callfunc "Mining_Init","MAnt04",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt04"; end;
}

anthell01,107,264,0	script	MiningSpot::MAnt05	844,{
	callfunc "Mining_Work","MAnt05"; end;
OnInit:		callfunc "Mining_Init","MAnt05",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt05"; end;
}

anthell01,108,263,0	script	MiningSpot::MAnt06	844,{
	callfunc "Mining_Work","MAnt06"; end;
OnInit:		callfunc "Mining_Init","MAnt06",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt06"; end;
}

anthell01,108,261,0	script	MiningSpot::MAnt07	844,{
	callfunc "Mining_Work","MAnt07"; end;
OnInit:		callfunc "Mining_Init","MAnt07",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt07"; end;
}

anthell01,77,262,0	script	MiningSpot::MAnt08	844,{
	callfunc "Mining_Work","MAnt08"; end;
OnInit:		callfunc "Mining_Init","MAnt08",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt08"; end;
}

anthell01,78,263,0	script	MiningSpot::MAnt09	844,{
	callfunc "Mining_Work","MAnt09"; end;
OnInit:		callfunc "Mining_Init","MAnt09",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt09"; end;
}

anthell01,78,254,0	script	MiningSpot::MAnt10	844,{
	callfunc "Mining_Work","MAnt10"; end;
OnInit:		callfunc "Mining_Init","MAnt10",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt10"; end;
}

anthell01,86,264,0	script	MiningSpot::MAnt11	844,{
	callfunc "Mining_Work","MAnt11"; end;
OnInit:		callfunc "Mining_Init","MAnt11",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt11"; end;
}

anthell01,87,265,0	script	MiningSpot::MAnt12	844,{
	callfunc "Mining_Work","MAnt12"; end;
OnInit:		callfunc "Mining_Init","MAnt12",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt12"; end;
}

anthell01,101,252,0	script	MiningSpot::MAnt13	844,{
	callfunc "Mining_Work","MAnt13"; end;
OnInit:		callfunc "Mining_Init","MAnt13",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt13"; end;
}

anthell01,105,254,0	script	MiningSpot::MAnt14	844,{
	callfunc "Mining_Work","MAnt14"; end;
OnInit:		callfunc "Mining_Init","MAnt14",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt14"; end;
}

anthell01,94,272,0	script	MiningSpot::MAnt15	844,{
	callfunc "Mining_Work","MAnt15"; end;
OnInit:		callfunc "Mining_Init","MAnt15",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt15"; end;
}

anthell01,95,272,0	script	MiningSpot::MAnt16	844,{
	callfunc "Mining_Work","MAnt16"; end;
OnInit:		callfunc "Mining_Init","MAnt16",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt16"; end;
}

anthell01,96,272,0	script	MiningSpot::MAnt17	844,{
	callfunc "Mining_Work","MAnt17"; end;
OnInit:		callfunc "Mining_Init","MAnt17",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt17"; end;
}

anthell01,88,267,0	script	MiningSpot::MAnt18	844,{
	callfunc "Mining_Work","MAnt18"; end;
OnInit:		callfunc "Mining_Init","MAnt18",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt18"; end;
}

anthell01,76,259,0	script	MiningSpot::MAnt19	844,{
	callfunc "Mining_Work","MAnt19"; end;
OnInit:		callfunc "Mining_Init","MAnt19",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt19"; end;
}

anthell01,76,258,0	script	MiningSpot::MAnt20	844,{
	callfunc "Mining_Work","MAnt20"; end;
OnInit:		callfunc "Mining_Init","MAnt20",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt20"; end;
}

anthell01,75,257,0	script	MiningSpot::MAnt21	844,{
	callfunc "Mining_Work","MAnt21"; end;
OnInit:		callfunc "Mining_Init","MAnt21",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt21"; end;
}

anthell01,78,252,0	script	MiningSpot::MAnt22	844,{
	callfunc "Mining_Work","MAnt22"; end;
OnInit:		callfunc "Mining_Init","MAnt22",1; end;
OnTimer60000: 	callfunc "Mining_Tick","MAnt22"; end;
}

// **************
// * Iron Mines *
// **************

ein_dun02,287,183,0	script	MiningSpot::MEin00	844,{
	callfunc "Mining_Work","MEin00"; end;
OnInit:		callfunc "Mining_Init","MEin00",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin00"; end;
}

ein_dun02,286,183,0	script	MiningSpot::MEin01	844,{
	callfunc "Mining_Work","MEin01"; end;
OnInit:		callfunc "Mining_Init","MEin01",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin01"; end;
}

ein_dun02,283,184,0	script	MiningSpot::MEin02	844,{
	callfunc "Mining_Work","MEin02"; end;
OnInit:		callfunc "Mining_Init","MEin02",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin02"; end;
}

ein_dun02,281,187,0	script	MiningSpot::MEin03	844,{
	callfunc "Mining_Work","MEin03"; end;
OnInit:		callfunc "Mining_Init","MEin03",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin03"; end;
}

ein_dun02,276,192,0	script	MiningSpot::MEin04	844,{
	callfunc "Mining_Work","MEin04"; end;
OnInit:		callfunc "Mining_Init","MEin04",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin04"; end;
}

ein_dun02,275,193,0	script	MiningSpot::MEin05	844,{
	callfunc "Mining_Work","MEin05"; end;
OnInit:		callfunc "Mining_Init","MEin05",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin05"; end;
}

ein_dun02,269,199,0	script	MiningSpot::MEin06	844,{
	callfunc "Mining_Work","MEin06"; end;
OnInit:		callfunc "Mining_Init","MEin06",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin06"; end;
}

ein_dun02,270,200,0	script	MiningSpot::MEin07	844,{
	callfunc "Mining_Work","MEin07"; end;
OnInit:		callfunc "Mining_Init","MEin07",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin07"; end;
}

ein_dun02,267,207,0	script	MiningSpot::MEin08	844,{
	callfunc "Mining_Work","MEin08"; end;
OnInit:		callfunc "Mining_Init","MEin08",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin08"; end;
}

ein_dun02,267,211,0	script	MiningSpot::MEin09	844,{
	callfunc "Mining_Work","MEin09"; end;
OnInit:		callfunc "Mining_Init","MEin09",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin09"; end;
}

ein_dun02,266,216,0	script	MiningSpot::MEin10	844,{
	callfunc "Mining_Work","MEin10"; end;
OnInit:		callfunc "Mining_Init","MEin10",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin10"; end;
}

ein_dun02,276,222,0	script	MiningSpot::MEin11	844,{
	callfunc "Mining_Work","MEin11"; end;
OnInit:		callfunc "Mining_Init","MEin11",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin11"; end;
}

ein_dun02,277,222,0	script	MiningSpot::MEin12	844,{
	callfunc "Mining_Work","MEin12"; end;
OnInit:		callfunc "Mining_Init","MEin12",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin12"; end;
}

ein_dun02,278,222,0	script	MiningSpot::MEin13	844,{
	callfunc "Mining_Work","MEin13"; end;
OnInit:		callfunc "Mining_Init","MEin13",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin13"; end;
}

ein_dun02,281,223,0	script	MiningSpot::MEin14	844,{
	callfunc "Mining_Work","MEin14"; end;
OnInit:		callfunc "Mining_Init","MEin14",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin14"; end;
}

ein_dun02,266,209,0	script	MiningSpot::MEin15	844,{
	callfunc "Mining_Work","MEin15"; end;
OnInit:		callfunc "Mining_Init","MEin15",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin15"; end;
}

ein_dun02,266,210,0	script	MiningSpot::MEin16	844,{
	callfunc "Mining_Work","MEin16"; end;
OnInit:		callfunc "Mining_Init","MEin16",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin16"; end;
}

ein_dun02,266,211,0	script	MiningSpot::MEin17	844,{
	callfunc "Mining_Work","MEin17"; end;
OnInit:		callfunc "Mining_Init","MEin17",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin17"; end;
}

ein_dun02,266,203,0	script	MiningSpot::MEin18	844,{
	callfunc "Mining_Work","MEin18"; end;
OnInit:		callfunc "Mining_Init","MEin18",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin18"; end;
}

ein_dun02,267,203,0	script	MiningSpot::MEin19	844,{
	callfunc "Mining_Work","MEin19"; end;
OnInit:		callfunc "Mining_Init","MEin19",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin19"; end;
}

ein_dun02,283,223,0	script	MiningSpot::MEin20	844,{
	callfunc "Mining_Work","MEin20"; end;
OnInit:		callfunc "Mining_Init","MEin20",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin20"; end;
}

ein_dun02,284,223,0	script	MiningSpot::MEin21	844,{
	callfunc "Mining_Work","MEin21"; end;
OnInit:		callfunc "Mining_Init","MEin21",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin21"; end;
}

ein_dun02,285,223,0	script	MiningSpot::MEin22	844,{
	callfunc "Mining_Work","MEin22"; end;
OnInit:		callfunc "Mining_Init","MEin22",2; end;
OnTimer60000: 	callfunc "Mining_Tick","MEin22"; end;
}

// ***************
// * Steel Mines *
// ***************

mjo_dun03,144,37,0	script	MiningSpot::MJup00	844,{
	callfunc "Mining_Work","MJup00"; end;
OnInit:		callfunc "Mining_Init","MJup00",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup00"; end;
}

mjo_dun03,137,48,0	script	MiningSpot::MJup01	844,{
	callfunc "Mining_Work","MJup01"; end;
OnInit:		callfunc "Mining_Init","MJup01",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup01"; end;
}

mjo_dun03,136,87,0	script	MiningSpot::MJup02	844,{
	callfunc "Mining_Work","MJup02"; end;
OnInit:		callfunc "Mining_Init","MJup02",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup02"; end;
}

mjo_dun03,88,77,0	script	MiningSpot::MJup03	844,{
	callfunc "Mining_Work","MJup03"; end;
OnInit:		callfunc "Mining_Init","MJup03",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup03"; end;
}

mjo_dun03,84,99,0	script	MiningSpot::MJup04	844,{
	callfunc "Mining_Work","MJup04"; end;
OnInit:		callfunc "Mining_Init","MJup04",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup04"; end;
}

mjo_dun03,49,83,0	script	MiningSpot::MJup05	844,{
	callfunc "Mining_Work","MJup05"; end;
OnInit:		callfunc "Mining_Init","MJup05",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup05"; end;
}

mjo_dun03,71,36,0	script	MiningSpot::MJup06	844,{
	callfunc "Mining_Work","MJup06"; end;
OnInit:		callfunc "Mining_Init","MJup06",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup06"; end;
}

mjo_dun03,39,199,0	script	MiningSpot::MJup07	844,{
	callfunc "Mining_Work","MJup07"; end;
OnInit:		callfunc "Mining_Init","MJup07",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup07"; end;
}

mjo_dun03,38,180,0	script	MiningSpot::MJup08	844,{
	callfunc "Mining_Work","MJup08"; end;
OnInit:		callfunc "Mining_Init","MJup08",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup08"; end;
}

mjo_dun03,29,151,0	script	MiningSpot::MJup09	844,{
	callfunc "Mining_Work","MJup09"; end;
OnInit:		callfunc "Mining_Init","MJup09",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup09"; end;
}

mjo_dun03,117,158,0	script	MiningSpot::MJup10	844,{
	callfunc "Mining_Work","MJup10"; end;
OnInit:		callfunc "Mining_Init","MJup10",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup10"; end;
}

mjo_dun03,183,249,0	script	MiningSpot::MJup11	844,{
	callfunc "Mining_Work","MJup11"; end;
OnInit:		callfunc "Mining_Init","MJup11",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup11"; end;
}

mjo_dun03,176,245,0	script	MiningSpot::MJup12	844,{
	callfunc "Mining_Work","MJup12"; end;
OnInit:		callfunc "Mining_Init","MJup12",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup12"; end;
}

mjo_dun03,197,219,0	script	MiningSpot::MJup13	844,{
	callfunc "Mining_Work","MJup13"; end;
OnInit:		callfunc "Mining_Init","MJup13",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup13"; end;
}

mjo_dun03,254,201,0	script	MiningSpot::MJup14	844,{
	callfunc "Mining_Work","MJup14"; end;
OnInit:		callfunc "Mining_Init","MJup14",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup14"; end;
}

mjo_dun03,281,195,0	script	MiningSpot::MJup15	844,{
	callfunc "Mining_Work","MJup15"; end;
OnInit:		callfunc "Mining_Init","MJup15",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup15"; end;
}

mjo_dun03,291,183,0	script	MiningSpot::MJup16	844,{
	callfunc "Mining_Work","MJup16"; end;
OnInit:		callfunc "Mining_Init","MJup16",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup16"; end;
}

mjo_dun03,311,162,0	script	MiningSpot::MJup17	844,{
	callfunc "Mining_Work","MJup17"; end;
OnInit:		callfunc "Mining_Init","MJup17",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup17"; end;
}

mjo_dun03,290,152,0	script	MiningSpot::MJup18	844,{
	callfunc "Mining_Work","MJup18"; end;
OnInit:		callfunc "Mining_Init","MJup18",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup18"; end;
}

mjo_dun03,257,134,0	script	MiningSpot::MJup19	844,{
	callfunc "Mining_Work","MJup19"; end;
OnInit:		callfunc "Mining_Init","MJup19",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup19"; end;
}

mjo_dun03,222,141,0	script	MiningSpot::MJup20	844,{
	callfunc "Mining_Work","MJup20"; end;
OnInit:		callfunc "Mining_Init","MJup20",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup20"; end;
}

mjo_dun03,126,220,0	script	MiningSpot::MJup21	844,{
	callfunc "Mining_Work","MJup21"; end;
OnInit:		callfunc "Mining_Init","MJup21",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup21"; end;
}

mjo_dun03,149,197,0	script	MiningSpot::MJup22	844,{
	callfunc "Mining_Work","MJup22"; end;
OnInit:		callfunc "Mining_Init","MJup22",3; end;
OnTimer60000: 	callfunc "Mining_Tick","MJup22"; end;
}

// **************
// * Star Mines *
// **************

mag_dun01,227,85,0	script	MiningSpot::MMag00	844,{
	callfunc "Mining_Work","MMag00"; end;
OnInit:		callfunc "Mining_Init","MMag00",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag00"; end;
}

mag_dun01,229,83,0	script	MiningSpot::MMag01	844,{
	callfunc "Mining_Work","MMag01"; end;
OnInit:		callfunc "Mining_Init","MMag01",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag01"; end;
}

mag_dun01,229,80,0	script	MiningSpot::MMag02	844,{
	callfunc "Mining_Work","MMag02"; end;
OnInit:		callfunc "Mining_Init","MMag02",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag02"; end;
}

mag_dun01,229,82,0	script	MiningSpot::MMag03	844,{
	callfunc "Mining_Work","MMag03"; end;
OnInit:		callfunc "Mining_Init","MMag03",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag03"; end;
}

mag_dun01,215,68,0	script	MiningSpot::MMag04	844,{
	callfunc "Mining_Work","MMag04"; end;
OnInit:		callfunc "Mining_Init","MMag04",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag04"; end;
}

mag_dun01,212,75,0	script	MiningSpot::MMag05	844,{
	callfunc "Mining_Work","MMag05"; end;
OnInit:		callfunc "Mining_Init","MMag05",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag05"; end;
}

mag_dun01,232,67,0	script	MiningSpot::MMag06	844,{
	callfunc "Mining_Work","MMag06"; end;
OnInit:		callfunc "Mining_Init","MMag06",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag06"; end;
}

mag_dun01,242,58,0	script	MiningSpot::MMag07	844,{
	callfunc "Mining_Work","MMag07"; end;
OnInit:		callfunc "Mining_Init","MMag07",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag07"; end;
}

mag_dun01,243,57,0	script	MiningSpot::MMag08	844,{
	callfunc "Mining_Work","MMag08"; end;
OnInit:		callfunc "Mining_Init","MMag08",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag08"; end;
}

mag_dun01,219,62,0	script	MiningSpot::MMag09	844,{
	callfunc "Mining_Work","MMag09"; end;
OnInit:		callfunc "Mining_Init","MMag09",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag09"; end;
}

mag_dun01,219,67,0	script	MiningSpot::MMag10	844,{
	callfunc "Mining_Work","MMag10"; end;
OnInit:		callfunc "Mining_Init","MMag10",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag10"; end;
}

mag_dun01,235,51,0	script	MiningSpot::MMag11	844,{
	callfunc "Mining_Work","MMag11"; end;
OnInit:		callfunc "Mining_Init","MMag11",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag11"; end;
}

mag_dun01,213,74,0	script	MiningSpot::MMag12	844,{
	callfunc "Mining_Work","MMag12"; end;
OnInit:		callfunc "Mining_Init","MMag12",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag12"; end;
}

mag_dun01,211,76,0	script	MiningSpot::MMag13	844,{
	callfunc "Mining_Work","MMag13"; end;
OnInit:		callfunc "Mining_Init","MMag13",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag13"; end;
}

mag_dun01,229,79,0	script	MiningSpot::MMag14	844,{
	callfunc "Mining_Work","MMag14"; end;
OnInit:		callfunc "Mining_Init","MMag14",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag14"; end;
}

mag_dun01,216,67,0	script	MiningSpot::MMag15	844,{
	callfunc "Mining_Work","MMag15"; end;
OnInit:		callfunc "Mining_Init","MMag15",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag15"; end;
}

mag_dun01,217,67,0	script	MiningSpot::MMag16	844,{
	callfunc "Mining_Work","MMag16"; end;
OnInit:		callfunc "Mining_Init","MMag16",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag16"; end;
}

mag_dun01,218,67,0	script	MiningSpot::MMag17	844,{
	callfunc "Mining_Work","MMag17"; end;
OnInit:		callfunc "Mining_Init","MMag17",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag17"; end;
}

mag_dun01,215,67,0	script	MiningSpot::MMag18	844,{
	callfunc "Mining_Work","MMag18"; end;
OnInit:		callfunc "Mining_Init","MMag18",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag18"; end;
}

mag_dun01,235,62,0	script	MiningSpot::MMag19	844,{
	callfunc "Mining_Work","MMag19"; end;
OnInit:		callfunc "Mining_Init","MMag19",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag19"; end;
}

mag_dun01,236,61,0	script	MiningSpot::MMag20	844,{
	callfunc "Mining_Work","MMag20"; end;
OnInit:		callfunc "Mining_Init","MMag20",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag20"; end;
}

mag_dun01,236,51,0	script	MiningSpot::MMag21	844,{
	callfunc "Mining_Work","MMag21"; end;
OnInit:		callfunc "Mining_Init","MMag21",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag21"; end;
}

mag_dun01,231,52,0	script	MiningSpot::MMag22	844,{
	callfunc "Mining_Work","MMag22"; end;
OnInit:		callfunc "Mining_Init","MMag22",4; end;
OnTimer60000: 	callfunc "Mining_Tick","MMag22"; end;
}

// *****************
// * Crystal Mines *
// *****************

ice_dun03,27,250,0	script	MiningSpot::MIce00	844,{
	callfunc "Mining_Work","MIce00"; end;
OnInit:		callfunc "Mining_Init","MIce00",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce00"; end;
}

ice_dun03,28,249,0	script	MiningSpot::MIce01	844,{
	callfunc "Mining_Work","MIce01"; end;
OnInit:		callfunc "Mining_Init","MIce01",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce01"; end;
}

ice_dun03,27,257,0	script	MiningSpot::MIce02	844,{
	callfunc "Mining_Work","MIce02"; end;
OnInit:		callfunc "Mining_Init","MIce02",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce02"; end;
}

ice_dun03,28,258,0	script	MiningSpot::MIce03	844,{
	callfunc "Mining_Work","MIce03"; end;
OnInit:		callfunc "Mining_Init","MIce03",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce03"; end;
}

ice_dun03,30,258,0	script	MiningSpot::MIce04	844,{
	callfunc "Mining_Work","MIce04"; end;
OnInit:		callfunc "Mining_Init","MIce04",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce04"; end;
}

ice_dun03,31,258,0	script	MiningSpot::MIce05	844,{
	callfunc "Mining_Work","MIce05"; end;
OnInit:		callfunc "Mining_Init","MIce05",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce05"; end;
}

ice_dun03,35,265,0	script	MiningSpot::MIce06	844,{
	callfunc "Mining_Work","MIce06"; end;
OnInit:		callfunc "Mining_Init","MIce06",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce06"; end;
}

ice_dun03,36,266,0	script	MiningSpot::MIce07	844,{
	callfunc "Mining_Work","MIce07"; end;
OnInit:		callfunc "Mining_Init","MIce07",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce07"; end;
}

ice_dun03,37,267,0	script	MiningSpot::MIce08	844,{
	callfunc "Mining_Work","MIce08"; end;
OnInit:		callfunc "Mining_Init","MIce08",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce08"; end;
}

ice_dun03,43,266,0	script	MiningSpot::MIce09	844,{
	callfunc "Mining_Work","MIce09"; end;
OnInit:		callfunc "Mining_Init","MIce09",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce09"; end;
}

ice_dun03,42,266,0	script	MiningSpot::MIce10	844,{
	callfunc "Mining_Work","MIce10"; end;
OnInit:		callfunc "Mining_Init","MIce10",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce10"; end;
}

ice_dun03,44,265,0	script	MiningSpot::MIce11	844,{
	callfunc "Mining_Work","MIce11"; end;
OnInit:		callfunc "Mining_Init","MIce11",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce11"; end;
}

ice_dun03,46,261,0	script	MiningSpot::MIce12	844,{
	callfunc "Mining_Work","MIce12"; end;
OnInit:		callfunc "Mining_Init","MIce12",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce12"; end;
}

ice_dun03,46,262,0	script	MiningSpot::MIce13	844,{
	callfunc "Mining_Work","MIce13"; end;
OnInit:		callfunc "Mining_Init","MIce13",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce13"; end;
}

ice_dun03,35,262,0	script	MiningSpot::MIce14	844,{
	callfunc "Mining_Work","MIce14"; end;
OnInit:		callfunc "Mining_Init","MIce14",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce14"; end;
}

ice_dun03,51,258,0	script	MiningSpot::MIce15	844,{
	callfunc "Mining_Work","MIce15"; end;
OnInit:		callfunc "Mining_Init","MIce15",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce15"; end;
}

ice_dun03,52,258,0	script	MiningSpot::MIce16	844,{
	callfunc "Mining_Work","MIce16"; end;
OnInit:		callfunc "Mining_Init","MIce16",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce16"; end;
}

ice_dun03,52,257,0	script	MiningSpot::MIce17	844,{
	callfunc "Mining_Work","MIce17"; end;
OnInit:		callfunc "Mining_Init","MIce17",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce17"; end;
}

ice_dun03,26,254,0	script	MiningSpot::MIce18	844,{
	callfunc "Mining_Work","MIce18"; end;
OnInit:		callfunc "Mining_Init","MIce18",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce18"; end;
}

ice_dun03,26,255,0	script	MiningSpot::MIce19	844,{
	callfunc "Mining_Work","MIce19"; end;
OnInit:		callfunc "Mining_Init","MIce19",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce19"; end;
}

ice_dun03,26,253,0	script	MiningSpot::MIce20	844,{
	callfunc "Mining_Work","MIce20"; end;
OnInit:		callfunc "Mining_Init","MIce20",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce20"; end;
}

ice_dun03,37,266,0	script	MiningSpot::MIce21	844,{
	callfunc "Mining_Work","MIce21"; end;
OnInit:		callfunc "Mining_Init","MIce21",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce21"; end;
}

ice_dun03,38,266,0	script	MiningSpot::MIce22	844,{
	callfunc "Mining_Work","MIce22"; end;
OnInit:		callfunc "Mining_Init","MIce22",5; end;
OnTimer60000: 	callfunc "Mining_Tick","MIce22"; end;
}

// ******************
// * Oridecon Mines *
// ******************

abyss_02,251,284,0	script	MiningSpot::MAby00	844,{
	callfunc "Mining_Work","MAby00"; end;
OnInit:		callfunc "Mining_Init","MAby00",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby00"; end;
}

abyss_02,250,285,0	script	MiningSpot::MAby01	844,{
	callfunc "Mining_Work","MAby01"; end;
OnInit:		callfunc "Mining_Init","MAby01",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby01"; end;
}

abyss_02,245,287,0	script	MiningSpot::MAby02	844,{
	callfunc "Mining_Work","MAby02"; end;
OnInit:		callfunc "Mining_Init","MAby02",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby02"; end;
}

abyss_02,246,286,0	script	MiningSpot::MAby03	844,{
	callfunc "Mining_Work","MAby03"; end;
OnInit:		callfunc "Mining_Init","MAby03",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby03"; end;
}

abyss_02,241,288,0	script	MiningSpot::MAby04	844,{
	callfunc "Mining_Work","MAby04"; end;
OnInit:		callfunc "Mining_Init","MAby04",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby04"; end;
}

abyss_02,241,289,0	script	MiningSpot::MAby05	844,{
	callfunc "Mining_Work","MAby05"; end;
OnInit:		callfunc "Mining_Init","MAby05",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby05"; end;
}

abyss_02,241,290,0	script	MiningSpot::MAby06	844,{
	callfunc "Mining_Work","MAby06"; end;
OnInit:		callfunc "Mining_Init","MAby06",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby06"; end;
}

abyss_02,235,274,0	script	MiningSpot::MAby07	844,{
	callfunc "Mining_Work","MAby07"; end;
OnInit:		callfunc "Mining_Init","MAby07",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby07"; end;
}

abyss_02,236,274,0	script	MiningSpot::MAby08	844,{
	callfunc "Mining_Work","MAby08"; end;
OnInit:		callfunc "Mining_Init","MAby08",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby08"; end;
}

abyss_02,237,274,0	script	MiningSpot::MAby09	844,{
	callfunc "Mining_Work","MAby09"; end;
OnInit:		callfunc "Mining_Init","MAby09",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby09"; end;
}

abyss_02,241,271,0	script	MiningSpot::MAby10	844,{
	callfunc "Mining_Work","MAby10"; end;
OnInit:		callfunc "Mining_Init","MAby10",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby10"; end;
}

abyss_02,260,266,0	script	MiningSpot::MAby11	844,{
	callfunc "Mining_Work","MAby11"; end;
OnInit:		callfunc "Mining_Init","MAby11",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby11"; end;
}

abyss_02,261,266,0	script	MiningSpot::MAby12	844,{
	callfunc "Mining_Work","MAby12"; end;
OnInit:		callfunc "Mining_Init","MAby12",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby12"; end;
}

abyss_02,264,265,0	script	MiningSpot::MAby13	844,{
	callfunc "Mining_Work","MAby13"; end;
OnInit:		callfunc "Mining_Init","MAby13",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby13"; end;
}

abyss_02,265,265,0	script	MiningSpot::MAby14	844,{
	callfunc "Mining_Work","MAby14"; end;
OnInit:		callfunc "Mining_Init","MAby14",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby14"; end;
}

abyss_02,241,280,0	script	MiningSpot::MAby15	844,{
	callfunc "Mining_Work","MAby15"; end;
OnInit:		callfunc "Mining_Init","MAby15",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby15"; end;
}

abyss_02,241,279,0	script	MiningSpot::MAby16	844,{
	callfunc "Mining_Work","MAby16"; end;
OnInit:		callfunc "Mining_Init","MAby16",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby16"; end;
}

abyss_02,240,279,0	script	MiningSpot::MAby17	844,{
	callfunc "Mining_Work","MAby17"; end;
OnInit:		callfunc "Mining_Init","MAby17",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby17"; end;
}

abyss_02,257,265,0	script	MiningSpot::MAby18	844,{
	callfunc "Mining_Work","MAby18"; end;
OnInit:		callfunc "Mining_Init","MAby18",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby18"; end;
}

abyss_02,257,264,0	script	MiningSpot::MAby19	844,{
	callfunc "Mining_Work","MAby19"; end;
OnInit:		callfunc "Mining_Init","MAby19",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby19"; end;
}

abyss_02,257,266,0	script	MiningSpot::MAby20	844,{
	callfunc "Mining_Work","MAby20"; end;
OnInit:		callfunc "Mining_Init","MAby20",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby20"; end;
}

abyss_02,259,278,0	script	MiningSpot::MAby21	844,{
	callfunc "Mining_Work","MAby21"; end;
OnInit:		callfunc "Mining_Init","MAby21",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby21"; end;
}

abyss_02,260,277,0	script	MiningSpot::MAby22	844,{
	callfunc "Mining_Work","MAby22"; end;
OnInit:		callfunc "Mining_Init","MAby22",6; end;
OnTimer60000: 	callfunc "Mining_Tick","MAby22"; end;
}

// *****************
// * Elunium Mines *
// *****************

thor_v02,23,136,0	script	MiningSpot::MTho00	844,{
	callfunc "Mining_Work","MTho00"; end;
OnInit:		callfunc "Mining_Init","MTho00",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho00"; end;
}

thor_v02,24,137,0	script	MiningSpot::MTho01	844,{
	callfunc "Mining_Work","MTho01"; end;
OnInit:		callfunc "Mining_Init","MTho01",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho01"; end;
}

thor_v02,27,137,0	script	MiningSpot::MTho02	844,{
	callfunc "Mining_Work","MTho02"; end;
OnInit:		callfunc "Mining_Init","MTho02",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho02"; end;
}

thor_v02,28,136,0	script	MiningSpot::MTho03	844,{
	callfunc "Mining_Work","MTho03"; end;
OnInit:		callfunc "Mining_Init","MTho03",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho03"; end;
}

thor_v02,33,136,0	script	MiningSpot::MTho04	844,{
	callfunc "Mining_Work","MTho04"; end;
OnInit:		callfunc "Mining_Init","MTho04",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho04"; end;
}

thor_v02,34,137,0	script	MiningSpot::MTho05	844,{
	callfunc "Mining_Work","MTho05"; end;
OnInit:		callfunc "Mining_Init","MTho05",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho05"; end;
}

thor_v02,40,137,0	script	MiningSpot::MTho06	844,{
	callfunc "Mining_Work","MTho06"; end;
OnInit:		callfunc "Mining_Init","MTho06",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho06"; end;
}

thor_v02,41,137,0	script	MiningSpot::MTho07	844,{
	callfunc "Mining_Work","MTho07"; end;
OnInit:		callfunc "Mining_Init","MTho07",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho07"; end;
}

thor_v02,42,138,0	script	MiningSpot::MTho08	844,{
	callfunc "Mining_Work","MTho08"; end;
OnInit:		callfunc "Mining_Init","MTho08",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho08"; end;
}

thor_v02,56,145,0	script	MiningSpot::MTho09	844,{
	callfunc "Mining_Work","MTho09"; end;
OnInit:		callfunc "Mining_Init","MTho09",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho09"; end;
}

thor_v02,57,145,0	script	MiningSpot::MTho10	844,{
	callfunc "Mining_Work","MTho10"; end;
OnInit:		callfunc "Mining_Init","MTho10",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho10"; end;
}

thor_v02,59,139,0	script	MiningSpot::MTho11	844,{
	callfunc "Mining_Work","MTho11"; end;
OnInit:		callfunc "Mining_Init","MTho11",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho11"; end;
}

thor_v02,60,138,0	script	MiningSpot::MTho12	844,{
	callfunc "Mining_Work","MTho12"; end;
OnInit:		callfunc "Mining_Init","MTho12",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho12"; end;
}

thor_v02,64,137,0	script	MiningSpot::MTho13	844,{
	callfunc "Mining_Work","MTho13"; end;
OnInit:		callfunc "Mining_Init","MTho13",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho13"; end;
}

thor_v02,65,137,0	script	MiningSpot::MTho14	844,{
	callfunc "Mining_Work","MTho14"; end;
OnInit:		callfunc "Mining_Init","MTho14",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho14"; end;
}

thor_v02,15,128,0	script	MiningSpot::MTho15	844,{
	callfunc "Mining_Work","MTho15"; end;
OnInit:		callfunc "Mining_Init","MTho15",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho15"; end;
}

thor_v02,15,129,0	script	MiningSpot::MTho16	844,{
	callfunc "Mining_Work","MTho16"; end;
OnInit:		callfunc "Mining_Init","MTho16",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho16"; end;
}

thor_v02,16,129,0	script	MiningSpot::MTho17	844,{
	callfunc "Mining_Work","MTho17"; end;
OnInit:		callfunc "Mining_Init","MTho17",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho17"; end;
}

thor_v02,21,132,0	script	MiningSpot::MTho18	844,{
	callfunc "Mining_Work","MTho18"; end;
OnInit:		callfunc "Mining_Init","MTho18",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho18"; end;
}

thor_v02,20,128,0	script	MiningSpot::MTho19	844,{
	callfunc "Mining_Work","MTho19"; end;
OnInit:		callfunc "Mining_Init","MTho19",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho19"; end;
}

thor_v02,45,143,0	script	MiningSpot::MTho20	844,{
	callfunc "Mining_Work","MTho20"; end;
OnInit:		callfunc "Mining_Init","MTho20",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho20"; end;
}

thor_v02,45,144,0	script	MiningSpot::MTho21	844,{
	callfunc "Mining_Work","MTho21"; end;
OnInit:		callfunc "Mining_Init","MTho21",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho21"; end;
}

thor_v02,46,144,0	script	MiningSpot::MTho22	844,{
	callfunc "Mining_Work","MTho22"; end;
OnInit:		callfunc "Mining_Init","MTho22",7; end;
OnTimer60000: 	callfunc "Mining_Tick","MTho22"; end;
}

// *****************
// * Magic Crystal *
// *****************

ra_fild03,220,267,0	script	MiningSpot::MRac00	844,{
	callfunc "Mining_Work","MRac00"; end;
OnInit:		callfunc "Mining_Init","MRac00",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac00"; end;
}

ra_fild03,212,272,0	script	MiningSpot::MRac01	844,{
	callfunc "Mining_Work","MRac01"; end;
OnInit:		callfunc "Mining_Init","MRac01",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac01"; end;
}

ra_fild03,208,262,0	script	MiningSpot::MRac02	844,{
	callfunc "Mining_Work","MRac02"; end;
OnInit:		callfunc "Mining_Init","MRac02",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac02"; end;
}

ra_fild03,217,261,0	script	MiningSpot::MRac03	844,{
	callfunc "Mining_Work","MRac03"; end;
OnInit:		callfunc "Mining_Init","MRac03",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac03"; end;
}

ra_fild03,213,265,0	script	MiningSpot::MRac04	844,{
	callfunc "Mining_Work","MRac04"; end;
OnInit:		callfunc "Mining_Init","MRac04",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac04"; end;
}

ra_fild03,218,268,0	script	MiningSpot::MRac05	844,{
	callfunc "Mining_Work","MRac05"; end;
OnInit:		callfunc "Mining_Init","MRac05",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac05"; end;
}

ra_fild03,211,268,0	script	MiningSpot::MRac06	844,{
	callfunc "Mining_Work","MRac06"; end;
OnInit:		callfunc "Mining_Init","MRac06",8; end;
OnTimer60000: 	callfunc "Mining_Tick","MRac06"; end;
}

