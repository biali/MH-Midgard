-	script	enchanter	-1,{
OnInit:
	bindatcmd "enchant",strnpcinfo(3)+"::OnAtcommand";
	end;
OnAtcommand:
	callfunc "Enchanting_Info";
	end;
}


// Hidding Slot Enchant NPC
// Important Note : Item ID 677 Platinum Coin is a special item that allow user to select the Enchant.

-	script	EnchantingEngine	-1,{
	end;

OnInit:
	if( $@EnchantingReady ) end;

	// Player Settings
	setarray $@EnchantTitle$[0],	    "Apprentice","Journeyman","Skilled","Expert","Artisan","Master","Grand Master","Illustrious";
//	setarray $@EnchantingDyeID[0],              975,         976,      978,     979,      970,     981,           982,          983;
	setarray $@EnchantingLUp[0],	            6000,       18000,    30000,   55000,    80000,  100000,        157500,       999999;
	setarray $@Enchanting_Lvl[0],	               0,           1,        2,       3,        4,       5,             6,            7; // * Required Lvl to Work on It
	setarray $@Enchanting_Exp[0],                200,         250,      300,     360,      450,     540,           630,          900; // * Experience
	setarray $@Enchantings$[0], "Enchant Scrolls","Enchant Armors","Enchant Weapons","Remove Cards (Armor)","Remove Cards (Weapon)","Add Slot to Armor","Add Slot to Weapon";

	set $@EnchantingReady, 1;
	end;
}


function	script	Enchanting_Info	{
// What can enchanters do:
// lv 1 : Produce scrolls (firebolt, etc)
// lv 2 : Enchant armors 
// lv 3 : Enchant weapons
// lv 4 : Remove cards from Armor
// lv 5 : Remove cards from Weapon
// lv 6 : Slot Armor
// lv 7 : Slot Weapon

	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes " ";
	mes "Enchanting Powder: ^AA00AA" + EnchantingPowder + "^000000"; 
	set .@menu$,"~ Cancel:~ Desinchant Equipmanet:";
	for(set .@i,0; .@i <= EnchantingLvl; .@i++)
		set .@menu$, .@menu$+"~ " + $@Enchantings$[.@i] + ":";
	next;

	switch(select(.@menu$)) {
		case 1:
			close;
			break;
		
		case 2:
			while (1) {
				callfunc "F_EnchantingPowder";
			}
			if(select("Desinchant other equipments:Close") == 2)
				close;
			break;

		case 3: // Scrolls Creation
			while (1) {
				mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
				mes "Enchanting Scrolls cost 1000x ^AA00AAEnchanting Powder^000000 per transmutation.";
				mes " ";
				mes "Enchanting Powder: ^AA00AA" + EnchantingPowder + "^000000"; 
				.@i = select("~ Cancel:~ Earth Spike:~ Cold Bolt:~ Fire Bolt:~ Lightening Bolt:~ Soul Strike:~ Fire Ball:~ Fire Wall:~ Frost Diver");
				callfunc "F_EncScrolls",.@i;
			}
			if(select("Enchant More Scrolls:Close") == 2)
				close;
			break;

		case 4: // Enchant Armors
			while (1) {
				mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
				mes "Enchantment of Armor, Garments, Footgear or Shilds";
				mes "will take " + 4000 * EnchantingLvl +"x ^AA00AAEnchanting Powder^000000 per piece.";
				mes " ";
				mes "Enchanting Powder: ^AA00AA" + EnchantingPowder + "^000000";
				.@i = select( "~ Cancel:^99AAE1~ Enchant Armor:^FFA500~ Enchant Garment/Footgear^000000:^AAAA00~ Enchant Shield^000000" );

				callfunc "F_EncEArmor",.@i;
			}
			if(select("Continue Enchanting:Close") == 2)
				close;
			break;

		case 5: // Enchant Weapons
			mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
			mes "Enchanting Weapons will take";
			mes 6500 * EnchantingLvl + "x ^AA00AAEnchanting Powder^000000 per Weapon.";
			mes " ";
			mes "Enchanting Powder: ^AA00AA" + EnchantingPowder + "^000000";
			callfunc "F_EncEWeapon";
			break;
			
		case 6: // Card Remover Armor
			mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
			mes "Removing Cards from Equipments will take";
			mes "80000x ^AA00AAEnchanting Powder^000000 per piece.";
			mes " ";
			mes "Enchanting Powder: ^AA00AA" + EnchantingPowder + "^000000";
			callfunc "F_EncCRemover",1;
			break;
		
		case 7: // Card Remover Weapon
			mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
			mes "Removing Cards from Equipments will take";
			mes "80000x ^AA00AAEnchanting Powder^000000 per piece.";
			mes " ";
			mes "Enchanting Powder: ^AA00AA" + EnchantingPowder + "^000000";
			callfunc "F_EncCRemover",2;
			break;
		
		case 8: // Slot Armor
			mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
			callfunc "F_EncSlots",1;
			break;
			
		case 9: // Slot Equips
			mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
			callfunc "F_EncSlots",2;
			break;
	}
	close;
}

function	script	F_EncScrolls	{
	switch(getarg(0)) {
		case 1:	close; break;
		case 2:	.@s = 687; break;
		case 3:	.@s = 689; break;
		case 4:	.@s = 691; break;
		case 5:	.@s = 693; break;
		case 6:	.@s = 695; break;
		case 7:	.@s = 697; break;
		case 8:	.@s = 699; break;
		case 9: .@s = 700; break; }
	.@q = 10 + EnchantingLvl;
	if( countitem(7433) < 1 || EnchantingPowder < 1000 ) {
		next;
		mes "[^0000FF" + strcharinfo(0) + "^000000]";
		mes "Oh, crap! Something is missing.";
		mes "Do I have enough ^AA00AAEnchanting Powder^000000 and ^AA00AA" + getitemname(7433) + "^000000?";
		close; }
	delitem 7433,1;
	set EnchantingPowder, EnchantingPowder - 1000;
	set @casting, (EnchantingLvl + 1) * 5;
	progressbar "0x0000FF",@casting;
	soundeffect "the_paper_die.wav",0;
	specialeffect 135;
	emotion e_grat,1;
	getitem .@s,.@q;	
	// Exp Progress
	if( EnchantingLvl < 7 )
	{
		set EnchantingExp, EnchantingExp + ($@Enchanting_Exp[EnchantingLvl] / (EnchantingLvl+1));
		if( EnchantingExp >= $@EnchantingLUp[EnchantingLvl] ) {
			// Level Up
			EnchantingLvl++;
			set EnchantingExp, 0;
			specialeffect2 409;
			dispbottom "[You've become a " + $@EnchantTitle$[EnchantingLvl] + " Enchanter.]";
		} else {
			set @Progress, (EnchantingExp * 100) / $@EnchantingLUp[EnchantingLvl];
			dispbottom "[ Current: " + $@EnchantTitle$[EnchantingLvl] + " Enchanter [" + @Progress + "%] -> Next: " + $@EnchantTitle$[EnchantingLvl + 1] + " Enchanter ]";
		}
	}
	next;
	return;
}

function	script	F_EncEArmor	{
	switch(getarg(0)) {
		case 1:	close;	break;
			
		case 2: // Enchanting Armors
			if( !getequipisequiped(2) )	{
				mes "There is no Armor equiped.";
				close;
			}
			
			deletearray .@Armor[0],127;
			setarray .@Armor[0],2358,2307,2309,2314,2316,2321,2325,2327,2330,2332,2334,2335,2341,2344,2346,2348,2350,2337,2386,2311,2318,2319,2320,2308,2310,2315,2317,2322,2324,2326,2331,2333,2336,2342,2345,2347,2349,2351,2364,2365,2374,2375,2387,2389,2391,2390,2376,2377,2378,2379,2380,2381,2382,2394,2395,2396;
			set .@Item, getequipid(2);
			
			for( .@i=0; .@i < getarraysize(.@Armor); .@i++ )
			{
				if( .@Armor[.@i] == .@Item )
					break;
			}

			if( .@i >= getarraysize(.@Armor) ) {
				mes "Cannot work on this piece of Armor.";
				close;
			}

			mes "Enchanting: " + getitemname(.@Item);
			mes " ";
			mes "^FF0000Armor will lose any Refine and Cards^000000.";
			mes " ";
			mes "Proceed anyway?";
			next;
			if ( select("Cancel:Go Ahead") == 1 )
				close;

			if( getequipisequiped(2) == 0 || getequipid(2) != .@Item ) {
				mes "Something is missing. There is nothing I can do.";
				close;
			}

			set .@Enchant, 0;

			if( EnchantingLvl < 4 ) 		set .@indice, 4700;
			else if( EnchantingLvl < 6 ) 	set .@indice, 4701;
			else							set .@indice, 4702;
			
			set .@Menu$,"";
			for( .@i=0; .@i < 6; .@i++ )
				set .@Menu$, .@Menu$ + getitemname(.@indice + (.@i * 10)) + ":";

			set .@Enchant, .@indice + ((select(.@Menu$) - 1) * 10);
			set .@Equip, 2;
			break;
		case 3: // Enchanting Garments and Footgear
			set @menu, select("Cancel:Enchant Garment:Enchant Footgear");
			if ( @menu == 1 ) close;
							
			set .@Equip, 3 + @menu; // Selected option
			if( !getequipisequiped(.@Equip) ) {
				mes "There is nothing equiped";
				mes "that can be enchanted.";
				close;
			}

			set .@Slot0, getequipcardid(.@Equip,0);
			if( .@Slot0 == 255 || .@Slot0 == 254 || .@Slot0 < 0 ) {
				mes "Signed items cannot be enchanted.";
				close;
			}

			mes "Enchanting: " + getitemname(getequipid(.@Equip));
			mes " ";
			mes "^FF0000It will lose any Refine and Cards^000000.";
			mes " ";
			mes "Proceed anyway?";
			next;
			if ( select("Cancel:^FFA500Enchant it with HP^000000:^0000FFEnchant it with SP^000000") == 1 )
				close;

			set .@Type, @menu - 1; // 1 : HP | 2 : SP

			set .@Slot0, getequipcardid(.@Equip,0);
			if( !getequipisequiped(.@Equip) || .@Slot0 == 255 || .@Slot0 == 254 || .@Slot0 < 0 ) {
				mes "This is not the equip we were talking about...";
				close;
			}

			if( EnchantingLvl < 4 )
				set .@Enchant, 4761 + (.@Type * 100);
			else if( EnchantingLvl < 6 )
				set .@Enchant, 4762 + (.@Type * 100);
			else
				set .@Enchant, 4767 + (.@Type * 100);

			break;
		case 4: // Enchanting Shields
			if( !getequipisequiped(3) ) {
				mes "There is nothing equiped";
				mes "that can be enchanted.";
				close;
			}
			
			if( getequipweaponlv(3) ) {
				mes "This Enchant is for Shield, not weapons...";
				close;
			}

			set .@Slot0, getequipcardid(3,0);
			if( .@Slot0 == 255 || .@Slot0 == 254 || .@Slot0 < 0 ) {
				mes "Signed items cannot be enchanted.";
				close;
			}

			mes "Enchanting: " + getitemname(getequipid(3));
			mes " ";
			mes "^FF0000It will lose any Refine and Cards^000000.";
			mes " ";
			mes "Proceed anyway?";
			next;
			if ( select("Cancel:Go Ahead") == 1 )
				close;

			set .@Slot0, getequipcardid(3,0);
			if( !getequipisequiped(3) || getequipweaponlv(3) || .@Slot0 == 255 || .@Slot0 == 254 || .@Slot0 < 0 ) {
				mes "This is not the equip we were talking about...";
				close;
			}

			if(EnchantingLvL < 6)
				.@max = 4983; // Somente por Elementos;
			else
				.@max = 4993; // Elementos e Racas;
				
			set .@Menu$,"";
			for( .@i=4979; .@i <= .@max; .@i++ )
				set .@Menu$, .@Menu$ + getitemname(.@i) + ":";

			set .@Enchant, 4978 + select(.@Menu$);

			set .@Equip, 3;
			break;
	}
	
	if( EnchantingPowder < (4000 * EnchantingLvl) ) {
		mes "Not enough ^AA00AAEnchanting Powder^000000.";
		close;
	}
	
	set @casting, (EnchantingLvl + 1) * 5;
	progressbar "0x0000FF",@casting;
	soundeffect "the_paper_die.wav",0;
	specialeffect 135;
	emotion e_grat,1;

	EnchantingPowder = EnchantingPowder - (4000 * EnchantingLvl);
	successenchant .@Equip,.@Enchant;
	
	// Exp Progress
	if( EnchantingLvl < 7 )	{
		set EnchantingExp, EnchantingExp + ($@Enchanting_Exp[EnchantingLvl] / (EnchantingLvl+1));
		if( EnchantingExp >= $@EnchantingLUp[EnchantingLvl] ) {
			// Level Up
			EnchantingLvl++;
			set EnchantingExp, 0;
			specialeffect2 409;
			dispbottom "[You've become a " + $@EnchantTitle$[EnchantingLvl] + " Enchanter.]";
		} else {
			set @Progress, (EnchantingExp * 100) / $@EnchantingLUp[EnchantingLvl];
			dispbottom "[ Current: " + $@EnchantTitle$[EnchantingLvl] + " Enchanter [" + @Progress + "%] -> Next: " + $@EnchantTitle$[EnchantingLvl + 1] + " Enchanter ]";
		}
	}
	
	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes "Your ^0000FF"+getitemname(getequipid(.@Equip))+"^000000 received ^0000FF" + getitemname(.@Enchant) + "^000000 enchant.";
	next;
	return;
}

function	script	F_EncEWeapon	{
	setarray .@Position$[3], "Left hand","Right hand";
	set .@Menu$,"";
	for( set .@i, 3; .@i <= 4; set .@i, .@i + 1 )
	{
		if( getequipisequiped(.@i) )
			set .@Menu$, .@Menu$ + .@Position$[.@i] + "-" + "[" + getequipname(.@i) + "]";
		set .@Menu$, .@Menu$ + ":";
	}

	set .@Part,select(.@Menu$ + "Cancel") + 2;
	if( .@Part >= 5 )
		close;

	if( !getequipisequiped(.@Part) ) {
		mes "There is nothing equiped there.";
		close;
	}
	
	if( getequipweaponlv(.@Part) == 0 ) {
		mes "This enchant is for Weapons only.";
		close;
	}
	
	set .@Slot0, getequipcardid(.@Part,0);
	if( .@Slot0 == 255 || .@Slot0 == 254 || .@Slot0 < 0 ) {
		mes "Signed items cannot be enchanted.";
		close;
	}
	
	set .@Item, getequipid(.@Part);
	if( getitemslots(.@Item) >= 4 ) {
		mes "Weapons with 4 slots can't be enchanted.";
		close;
	}

	mes "Enchanting: " + getitemname(.@Item);
	mes " ";
	mes "^FF0000It will lose any Refine and Cards^000000.";
	mes " ";
	mes "Proceed anyway?";
	next;
	if ( select("Cancel:Go Ahead") == 1 )
		close;

	set .@Slot0, getequipcardid(.@Part,0);
	if( !getequipisequiped(.@Part) || !getequipweaponlv(.@Part) || .@Slot0 == 255 || .@Slot0 == 254 || .@Slot0 < 0 || .@Item != getequipid(.@Part) ) {
		mes "This is not the equip we were talking about...";
		close;
	}

	if(EnchantingLvL < 6)
		.@max = 4968;
	else
		.@max = 4978;
		
	set .@Menu$,"";
	for( .@i=4964; .@i <= .@max; .@i++ )
		set .@Menu$, .@Menu$ + getitemname(.@i) + ":";

	set .@Enchant, 4963 + select(.@Menu$);
	
	if( EnchantingPowder < (6500 * EnchantingLvl) ) {
		mes "Not enough ^AA00AAEnchanting Powder^000000.";
		close;
	}

	set @casting, (EnchantingLvl + 1) * 5;
	progressbar "0x0000FF",@casting;
	soundeffect "the_paper_die.wav",0;
	specialeffect 135;
	emotion e_grat,1;

	EnchantingPowder = EnchantingPowder - (6500 * EnchantingLvl);
	successenchant .@Part,.@Enchant;

	// Exp Progress
	if( EnchantingLvl < 7 )
	{
		set EnchantingExp, EnchantingExp + ($@Enchanting_Exp[EnchantingLvl] / (EnchantingLvl+1));
		if( EnchantingExp >= $@EnchantingLUp[EnchantingLvl] ) {
			// Level Up
			EnchantingLvl++;
			set EnchantingExp, 0;
			specialeffect2 409;
			dispbottom "[You've become a " + $@EnchantTitle$[EnchantingLvl] + " Enchanter.]";
		} else {
			set @Progress, (EnchantingExp * 100) / $@EnchantingLUp[EnchantingLvl];
			dispbottom "[ Current: " + $@EnchantTitle$[EnchantingLvl] + " Enchanter [" + @Progress + "%] -> Next: " + $@EnchantTitle$[EnchantingLvl + 1] + " Enchanter ]";
		}
	}
	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes "Your weapon received ^0000FF" + getitemname(.@Enchant) + "^000000 enchant.";
	next;
	return;
}

function	script	F_EncCRemover	{
	setarray .@pos$[1],"Upper Headgear","Armor","Left hand","Right hand","Garment","Footgear","Left Accessory","Right Accessory","Mid Headgear","Lower Headgear";
	set .@menu$,"";
	set @i, 0;
	switch(getarg(0)){
	case 1:
		for (.@i=1; .@i <= 10; .@i++) {
			if (getequipisequiped(.@i) && (.@i < 3 || .@i > 4)) 
				set .@menu$, .@menu$+.@pos$[.@i]+" [^0055FF"+getequipname(.@i)+"^000000]" + ":";
	//		set .@menu$, .@menu$+":";
		}
		break;
	
	case 2:
		for (.@i=3; .@i <= 4; .@i++) {
			if (getequipisequiped(.@i))
				set .@menu$, .@menu$+.@pos$[.@i]+" [^0055FF"+getequipname(.@i)+"^000000]" + ":";
		}
		set @i, 2;
		break;
	}
	
	set @i, @i + select(.@menu$);

	if (!getequipisequiped(@i)) {
		mes "Nothing is equipped there.";
		close;
	}

	set .@j,getequipcardcnt(@i);
	if (!.@j) {
		mes "There are no cards compounded to "+getequipname(@i)+".";
		close;
	}
	
	if (!checkweight(4001,(.@j+1))) {
		mes "You're carrying too many items!";
		close;
	}
	
	mes "Item: "+getequipname(@i);
	for(set .@i,0; .@i<.@j; set .@i,.@i+1)
		mes "Card "+(.@i+1)+": "+getitemname(getequipcardid(@i,.@i));
	next;
	if (select("~ Remove "+.@j+" card(s):~ ^777777Cancel^000000") == 2)
		close;

	if (EnchantingPowder < 80000) {
		mes "Not enough ^AA00AAEnchanting Powder^000000.";
		close;
	}
	
	set @casting, (EnchantingLvl + 1) * 5;
	progressbar "0x0000FF",@casting;
	soundeffect "the_paper_die.wav",0;
	specialeffect 135;
	emotion e_grat,1;
	
	EnchantingPowder = EnchantingPowder - 80000;
	successremovecards @i;

	// Exp Progress
	if( EnchantingLvl < 7 )
	{
		set EnchantingExp, EnchantingExp + ($@Enchanting_Exp[EnchantingLvl] / (EnchantingLvl+1));
		if( EnchantingExp >= $@EnchantingLUp[EnchantingLvl] ) {
			// Level Up
			EnchantingLvl++;
			set EnchantingExp, 0;
			specialeffect2 409;
			dispbottom "[You've become a " + $@EnchantTitle$[EnchantingLvl] + " Enchanter.]";
		} else {
			set @Progress, (EnchantingExp * 100) / $@EnchantingLUp[EnchantingLvl];
			dispbottom "[ Current: " + $@EnchantTitle$[EnchantingLvl] + " Enchanter [" + @Progress + "%] -> Next: " + $@EnchantTitle$[EnchantingLvl + 1] + " Enchanter ]";
		}
	}

	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes "Cards successfully removed!";
	next;
	return;
}

function	script	F_EncSlots	{
	if (checkweight(1201,1) == 0) {
		mes "Too many items. Too heavy.";
		close;
	}
	switch(getarg(0)) {
		case 1:
			mes "Armor is divided into";
			mes "4 different classes.";
			mes "^B2C2F0C Class is the easiest one,";
			mes "^1947D1and S Class he hardest one.^000000";
			mes "Which armor would you like to try adding a Slot?";
			next;
			switch(select("^B2C2F0Mantle:^B2C2F0Coat:^B2C2F0Circlet:^B2C2F0Biretta:^8099E6Mirror Shield:^8099E6Chain Mail:^8099E6Saint Robe:^8099E6Silk Robe:^8099E6Boots:^8099E6Shoes:^8099E6Muffler:^8099E6Guard:^8099E6Buckler:^8099E6Shield:^8099E6Bongun Hat:^4D70DBGemmed Sallet^4D70DB:Bucket Hat:^4D70DBMemory Book:^4D70DBTights:^4D70DBLegion Plate Armor:^4D70DBFull Plate:^4D70DBThief Clothes:^4D70DBGreaves:^4D70DBCoif:^4D70DBManteau:^4D70DBHelm:^4D70DBNinja Suit:^4D70DBOrc Helm:^4D70DBAncient Cape:^4D70DBMonk Hat:^4D70DBGolden Gear:^4D70DBBrooch:^4D70DBMunak Hat:^1947D1Majestic Goat:^1947D1Spiky Band:^1947D1Bone Helm:^1947D1Corsair:^1947D1Crown:^1947D1Tiara:^1947D1Sphinx Hat:^1947D1Robe of Cast:^1947D1Earring:^1947D1Ring:^1947D1Bow Thimble^000000"))	{
				case 1: callfunc "Func_Socket",2307,2308,40,66,200,999,10;
				case 2: callfunc "Func_Socket",2309,2310,40,66,200,999,10;
				case 3: callfunc "Func_Socket",2232,2233,40,66,200,999,10;
				case 4: callfunc "Func_Socket",2216,2217,40,66,200,999,10;
				
				case 5:  callfunc "Func_Socket",2107,2108,40,61,250,999,10;
				case 6:  callfunc "Func_Socket",2314,2315,40,61,250,999,10;
				case 7:  callfunc "Func_Socket",2325,2326,40,61,300,999,10;
				case 8:  callfunc "Func_Socket",2321,2322,40,61,300,999,10;
				case 9:  callfunc "Func_Socket",2405,2406,40,61,300,999,10;
				case 10:  callfunc "Func_Socket",2403,2404,40,61,300,999,10;
				case 11:  callfunc "Func_Socket",2503,2504,40,61,300,999,10;
				case 12:  callfunc "Func_Socket",2101,2102,40,61,300,999,10;
				case 13:  callfunc "Func_Socket",2103,2104,40,61,300,999,10;
				case 14: callfunc "Func_Socket",2105,2106,40,61,250,999,10;
				case 15: callfunc "Func_Socket",5046,5168,40,61,250,999,10;
				
				case 16:  callfunc "Func_Socket",2230,2231,40,61,400,985,10;
				case 17:  callfunc "Func_Socket",5114,5120,40,61,400,985,10;
				case 18:  callfunc "Func_Socket",2109,2121,40,61,400,985,10;
				case 19:  callfunc "Func_Socket",2330,2331,40,61,400,985,10;
				case 20:  callfunc "Func_Socket",2341,2342,40,61,400,985,10;
				case 21:  callfunc "Func_Socket",2316,2317,40,61,400,985,10;
				case 22:  callfunc "Func_Socket",2335,2336,40,61,400,985,10;
				case 23:  callfunc "Func_Socket",2411,2412,40,61,400,985,10;
				case 24:  callfunc "Func_Socket",5092,5093,40,61,400,985,10;
				case 25: callfunc "Func_Socket",2505,2506,40,61,400,985,10;
				case 26: callfunc "Func_Socket",2228,2229,40,61,400,985,10;
				case 27: callfunc "Func_Socket",2337,2359,40,61,400,985,10;
				case 28: callfunc "Func_Socket",2299,5157,40,61,400,985,10;
				case 29: callfunc "Func_Socket",2507,2525,40,61,400,985,10;
				case 30: callfunc "Func_Socket",2251,5158,40,61,400,985,10;
				case 31: callfunc "Func_Socket",2246,5159,40,61,400,985,10;
				case 32: callfunc "Func_Socket",2605,2625,40,61,400,985,10;
				case 33: callfunc "Func_Socket",2264,5167,40,61,300,985,10;
				
				case 34:  callfunc "Func_Socket",2256,5160,40,51,2000,985,10;
				case 35:  callfunc "Func_Socket",2258,5161,40,51,2000,985,10;
				case 36:  callfunc "Func_Socket",5017,5162,40,51,2000,985,10;
				case 37:  callfunc "Func_Socket",5019,5163,40,51,2000,985,10;
				case 38:  callfunc "Func_Socket",2235,5165,40,51,2000,985,10;
				case 39:  callfunc "Func_Socket",2234,5164,40,51,2000,985,10;
				case 40:  callfunc "Func_Socket",5053,5166,40,51,1000,985,10;
				case 41:  callfunc "Func_Socket",2343,2360,40,51,1000,985,10;
				case 42:  callfunc "Func_Socket",2602,2622,40,51,1000,985,10;
				case 43: callfunc "Func_Socket",2601,2621,40,51,1000,985,10;
				case 44: callfunc "Func_Socket",2619,2671,40,51,1000,985,10;
			}

		case 2:
			mes "Weapons are divided into";
			mes "4 different classes.";
			mes "^FFD1B2C Class is the easiest one,";
			mes "^FF7519and S Class he hardest one.^000000";
			mes "Which weapon would you like to try adding a Slot?";
			next;
			switch(select("^FFD1B2Trident:Rope:Violin:^FFB280Chain:Gladius:Gakkung Bow:Pike:Haedonggum:Lute:Wire:Waghnakh:Arbalest Bow:^FF944DHunter Bow:Survivor's Rod(INT):Zweihander:Flamberge:Infiltrator:Ballista:Stunner:Berserk:Claymore:^FF7519Gungnir:Poison Knife:Ice Pick:Sucsamad:Ginnungagap:Cutlas:Crescent Scythe:Survivor's Rod(DEX)")) {
				case 1: callfunc "Func_Socket",1460,1461,40,66,200,1010,10;
				case 2: callfunc "Func_Socket",1950,1951,40,66,200,1010,10;
				case 3: callfunc "Func_Socket",1901,1902,40,66,200,1010,10;
				
				case 4: callfunc "Func_Socket",1519,1520,40,61,300,1010,10;
				case 5: callfunc "Func_Socket",1219,1220,40,61,300, 984, 10,999,5;
				case 6: callfunc "Func_Socket",1714,1716,40,61,300, 984, 20,999,5;
				case 7: callfunc "Func_Socket",1407,1408,40,61,200,1010,10;
				case 8: callfunc "Func_Socket",1123,1128,40,61,300, 984, 20,999,5;
				case 9: callfunc "Func_Socket",1905,1906,40,61,300,1011,10;
				case 10: callfunc "Func_Socket",1954,1955,40,61,300,1011,10;
				case 11: callfunc "Func_Socket",1801,1802,40,61,300,1010,10;
				case 12: callfunc "Func_Socket",1713,1715,40,61,300, 984, 20,999,5;
				
				case 13: callfunc "Func_Socket",1718,1726,40,61,500,984,20,999,10;
				case 14: callfunc "Func_Socket",1619,1620,40,61,500,984,50,999,10;
				case 15: callfunc "Func_Socket",1168,1171,40,61,800,984,50,999,10;
				case 16: callfunc "Func_Socket",1129,1149,40,61,500,984,20,999,10;
				case 17: callfunc "Func_Socket",1261,1266,40,61,700,984,50,999,10;
				case 18: callfunc "Func_Socket",1722,1727,40,61,500,984,50,999,10;
				case 19: callfunc "Func_Socket",1522,1532,40,61,500,984,20,999,10;
				case 20: callfunc "Func_Socket",1814,1816,40,61,500,984,50,999,10;
				case 21: callfunc "Func_Socket",1163,1172,40,61,500,984,20,999,10;
				
				case 22: callfunc "Func_Socket", 1413, 1418,40,51,1000,984,50,999,10;
				case 23: callfunc "Func_Socket", 1239,13016,40,51,1000,984,50,999,10;
				case 24: callfunc "Func_Socket", 1230,13017,40,51,2000,984,50,999,10;
				case 25: callfunc "Func_Socket", 1236,13018,40,51,1000,984,50,999,10;
				case 26: callfunc "Func_Socket",13002,13019,40,51,1000,984,50,999,10;
				case 27: callfunc "Func_Socket", 1135,13400,40,51,1000,984,50,999,10;
				case 28: callfunc "Func_Socket", 1466, 1476,40,51,1000,984,50,999,10;
				case 29: callfunc "Func_Socket", 1617, 1618,40,51,2000,984,50,999,10;
			}
	}
}

function	script	Func_Socket	{
	disable_items;
	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes " ";
	mes "Slotting: " + getitemname(getarg(0));
	mes "[ Materials ]";
	mes "^FF0000" + getarg(6) + " " + getitemname(getarg(5)) + (getarg(6) > 1 && getarg(5) != 999 ? "s":"") + "^000000, " + (getarg(7,0) != 0 && getarg(8,0) != 0 ? ("^FF0000" + getarg(8,0) + " " + getitemname(getarg(7,0)) + (getarg(8,0) > 1 && getarg(7,0) != 999 ? "s":"") + "^000000 ") : "") + "and ^AA00AA" + (getarg(4) * EnchantingLvl) + "Enchanting Powder^000000.";
	next;
	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes "If this process fails, the ^FF0000Equipment^000000, ^FF0000it's upgrades^000000 and any ^FF0000Cards^000000 compounded to it will be destroyed.";
	mes " ";
	mes "Proceed anyway?";
	next;
	switch(select("Go ahead:Cancel")) {
		case 1:
			if ( (countitem(getarg(5)) >= getarg(6)) && (countitem(getarg(7,512)) >= getarg(8,0)) && (countitem(getarg(0)) > 0) && EnchantingPowder >= (getarg(4) * EnchantingLvl) ) {
				set @casting, (EnchantingLvl + 1) * 5;
				progressbar "0x0000FF",@casting;

				set .@a, rand(1,100);
				if ((.@a > getarg(2)) && (.@a < getarg(3)))	{
					specialeffect getarg(3) == 51 ? EF_LORD : EF_SANCTUARY; // only S Class items have Lord of Vermillion effect
					getitem getarg(1),1;
				} else {
					specialeffect EF_SUI_EXPLOSION;
				}
				
				EchantingPowder = EnchantingPowder - (getarg(4) * EnchantingLvl);
				delitem getarg(0),1;
				delitem getarg(5),getarg(6);
				if (getarg(7,0) != 0 && getarg(8,0) != 0)
					delitem getarg(7),getarg(8);
				
				// Exp Progress
				if( EnchantingLvl < 7 ) {
					set EnchantingExp, EnchantingExp + $@Enchanting_Exp[EnchantingLvl];
					if( EnchantingExp >= $@EnchantingLUp[EnchantingLvl] ) {
						// Level Up
						EnchantingLvl++;
						set EnchantingExp, 0;
						specialeffect2 409;
						dispbottom "[You've become a " + $@EnchantTitle$[EnchantingLvl] + " Enchanter.]";
					} else {
						set @Progress, (EnchantingExp * 100) / $@EnchantingLUp[EnchantingLvl];
						dispbottom "[ Current: " + $@EnchantTitle$[EnchantingLvl] + " Enchanter [" + @Progress + "%] -> Next: " + $@EnchantTitle$[EnchantingLvl + 1] + " Enchanter ]";
					}
				}
				close;
			} else {
				mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
				mes "Something is missing";
				mes "Please double-check.";
				close;
			}
			break;
		case 2:
			close;
	}
}

function	script	F_EnchantingPowder	{
	getinventorylist;
	.@p = 1;
	for (.@i=0; .@i < @inventorylist_count; .@i++) {
		if( @inventorylist_equip[.@i] == 0 && (getiteminfo(@inventorylist_id[.@i],2) == 4 || getiteminfo(@inventorylist_id[.@i],2) == 5) ) {
			set .@Menu$, .@Menu$ + "1x " + getitemname(@inventorylist_id[.@i]) + " +" + @inventorylist_refine[.@i] + ":";
			set .@equiplist[.@p], @inventorylist_id[.@i];
			.@p++;
//		set .@Menu$, .@Menu$ + ":";
		}
	}
	set .@equip, .@equiplist[select(.@Menu$)];
	set .@powder, ((getiteminfo(.@equip,3))<1?0:getiteminfo(.@equip,3)) + (getiteminfo(.@equip,1) / 2);
	if(.@powder > 10000) set .@powder, 10000;

	mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
	mes "Desinchanting ^0000AA" + getitemname(.@equip) +"^000000";
	mes "will generate ^AA00AA" + .@powder + "^000000 Enchanting Powder.";
	mes " ";
	mes "Do you want to proceed?";
	mes "^FF0000The equipment will be destroyed.^000000";
	next;
	if(select("Go ahead:Cancel") == 2)
		close;
	
	if(countitem(.@equip) == 1) {
		set @casting, (EnchantingLvl + 1) * 5;
		progressbar "0x0000FF",@casting;
		soundeffect "the_paper_die.wav",0;
		specialeffect 135;
		emotion e_grat,1;

		// Exp Progress
		if( EnchantingLvl < 7 ) {
			set EnchantingExp, EnchantingExp + ($@Enchanting_Exp[EnchantingLvl] / (EnchantingLvl+1));
			if( EnchantingExp >= $@EnchantingLUp[EnchantingLvl] ) {
				// Level Up
				EnchantingLvl++;
				set EnchantingExp, 0;
				specialeffect2 409;
				dispbottom "[You've become a " + $@EnchantTitle$[EnchantingLvl] + " Enchanter.]";
			} else {
				set @Progress, (EnchantingExp * 100) / $@EnchantingLUp[EnchantingLvl];
				dispbottom "[ Current: " + $@EnchantTitle$[EnchantingLvl] + " Enchanter [" + @Progress + "%] -> Next: " + $@EnchantTitle$[EnchantingLvl + 1] + " Enchanter ]";
			}
		}
		
		delitem .@equip,1;
		EnchantingPowder = EnchantingPowder + .@powder;

		mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
		mes "Successfull transmutation";
		mes "of the ^0000FF" + getitemname(.@equip) + "^000000 into ";
		mes .@powder + "x ^AA00AAEnchanting Powder^000000.";
		next;
	} else {
		mes "[^0000FF" + $@EnchantTitle$[EnchantingLvl] + " Enchanter^000000]";
		mes "Something is wrong.";
		mes "Is the equioment still in the inventory?";
		mes "Is it unique or perhaps you have others of the same kind in your inventory?";
		close;
	}
	
	return;
}