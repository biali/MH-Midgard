function	script	iron_daggers	{
	.@c = getarg(0,0);
	.@menu$ = "";
	setarray .@option[0], -1;
	deletearray .@options[1],127;

	switch(.@c) {
		case 19800: //Hunter Knife I
			.@menu$ = "Hunter Knife II:" + red("Cancel");
			setarray .@options[1],19801,-1;
			break;
		case 19801: //Hunter Knife II
			.@menu$ = "Hunter Knife III:Aqua Messer I:Blooming Knife I:"+red("Cancel");
			setarray .@options[1],19802,19817,19836,-1;
			break;
		case 19802: //Hunter Knife III
			.@menu$ = "Steel Knife I:"+red("Cancel");
			setarray .@options[1],19803,-1;
			break;
		case 19803: //Steel Knife I
			.@menu$ = "Steel Knife II:Flame Knife I:Heavy Bang:"+red("Cancel");
			setarray .@options[1],19804,19810,19814,-1;
			break;
		case 19804: //Steel Knife II
			.@menu$ = "Steel Knife III:"+red("Cancel");
			setarray .@options[1],19805,-1;
			break;
		case 19805: //Steel Knife III
			.@menu$ = "Chrome Slicer I:"+red("Cancel");
			setarray .@options[1],19806,-1;
			break;
		case 19806: //Chrome Slicer I
			.@menu$ = "Chrome Slicer II:Nergal Jack:"+red("Cancel");
			setarray .@options[1],19807,19808,-1;
			break;
		case 19808: //Nergal Jack
			.@menu$ = "Eradication Vanguard:"+red("Cancel");
			setarray .@options[1],19809,-1;
			break;
		case 19810: //Flame Knife I
			.@menu$ = "Flame Knife II:"+red("Cancel");
			setarray .@options[1],19811,-1;
			break;
		case 19811: //Flame Knife II
			.@menu$ = "Heat Edge:"+red("Cancel");
			setarray .@options[1],19812,-1;
			break;
		case 19812: //Heat Edge
			.@menu$ = "Corona:"+red("Cancel");
			setarray .@options[1],19813,-1;
			break;
		case 19814: //Heavy Bang
			.@menu$ = "Heavy Bang+:"+red("Cancel");
			setarray .@options[1],19815,-1;
			break;
		case 19815: //Heavy Bang+
			.@menu$ = "Master Bang:"+red("Cancel");
			setarray .@options[1],19816,-1;
			break;
		case 19817: //Aqua Messer I
			.@menu$ = "Aqua Messer II:Princess Rapier:Lomu Knife I:"+red("Cancel");
			setarray .@options[1],19818,19827,19831,-1;
			break;
		case 19818: //Aqua Messer II
			.@menu$ = "Aqua Messer III:Glacial Grace I:"+red("Cancel");
			setarray .@options[1],19819,19823,-1;
			break;
		case 19819: //Aqua Messer III
			.@menu$ = "Rogue Wave I:"+red("Cancel");
			setarray .@options[1],19820,-1;
			break;
		case 19820: //Rogue Wave I
			@menu$ = "Rogue Wave II:"+red("Cancel");
			setarray .@options[1],19821,-1;
			break;
		case 19821: //Rogue Wave II
			@menu$ = "Rogue Wave III:"+red("Cancel");
			setarray .@options[1],19822,-1;
			break;
		case 19823: //Glacial Grace I:
			@menu$ = "Glacial Grace II:"+red("Cancel");
			setarray .@options[1],19824,-1;
			break;
		case 19824: //Glacial Grace II:
			@menu$ = "Rimespire:"+red("Cancel");
			setarray .@options[1],19825,-1;
			break;
		case 19825: //Rimespire
			@menu$ = "Legia Rimespire:"+red("Cancel");
			setarray .@options[1],19826,-1;
			break;
		case 19827: //Princess Rapier
			@menu$ = "Queen Rapier:"+red("Cancel");
			setarray .@options[1],19828,-1;
			break;
		case 19828: //Queen Rapier
			@menu$ = "Queen Rose:"+red("Cancel");
			setarray .@options[1],19829,-1;
			break;
		case 19829: //Queen Rose
			@menu$ = "Royal Rose:"+red("Cancel");
			setarray .@options[1],19830,-1;
			break;
		case 19831: //Lumu Knife I
			@menu$ = "Lumu Knife II:"+red("Cancel");
			setarray .@options[1],19832,-1;
			break;
		case 19832: //Lumu Knife II
			@menu$ = "Lumu Tabar I:"+red("Cancel");
			setarray .@options[1],19833,-1;
			break;
		case 19833: //Lumu Tabar I
			@menu$ = "Lumu Tabar II:"+red("Cancel");
			setarray .@options[1],19834,-1;
			break;
		case 19834: //Lumu Tabar II
			@menu$ = "Lumu Tabar III:"+red("Cancel");
			setarray .@options[1],19835,-1;
			break;
		case 19836: //Blooming Knife I
			@menu$ = "Blooming Knife II:Girros Knife I"+red("Cancel");
			setarray .@options[1],19837,19842,-1;
			break;
		case 19837: //Blooming Knife II
			@menu$ = "Blooming Knife III:"+red("Cancel");
			setarray .@options[1],19838,-1;
			break;
		case 19838: //Blooming Knife III
			@menu$ = "Datura Blossom I:"+red("Cancel");
			setarray .@options[1],19839,-1;
			break;
		case 19839: //Datura Blossom I
			@menu$ = "Datura Blossom II:"+red("Cancel");
			setarray .@options[1],19840,-1;
			break;
		case 19840: //Datura Blossom II
			@menu$ = "Datura Blossom III:"+red("Cancel");
			setarray .@options[1],19841,-1;
			break;
		case 19842: //Girros Knife I
			@menu$ = "Girros Knife II:"+red("Cancel");
			setarray .@options[1],19843,-1;
			break;
		case 19843: //Girros Knife II
			@menu$ = "Malady's Tabar I:"+red("Cancel");
			setarray .@options[1],19844,-1;
			break;
		case 19844: //Malady's Tabar I
			@menu$ = "Malady's Tabar II:"+red("Cancel");
			setarray .@options[1],19845,-1;
			break;
		case 19845: //Malady's Tabar II
			@menu$ = "Malady's Tabar III:"+red("Cancel");
			setarray .@options[1],19846,-1;
			break;
		default:
			.@menu$ = red("Cancel");
			setarray .@options[1],-1;
			break;
	}

	.@c = select(.@menu$);

	return .@options[.@c];
}



-	script	iron_daggers_mats	-1,{
	end;
OnInit:
	//List of materials for Upgrade
	//						Zeny	BaseEquip	Materials
	setarray .cra19800[0],	200,				19655,1;								//Hunter Knife I (Craft)
	setarray .upg19801[0],	200,	19800,1,	19655,2;								//Hunter Knife II
	setarray .upg19802[0],	1000,	19801,1,	19635,2,19654,2,19655,5;				//Hunter Knife III

	setarray .upg19803[0],	2000,	19802,1,	19657,2,19654,5,19619,2;				//Steel Knife I
	setarray .upg19804[0],	4000,	19803,1,	19608,2,19657,5,19648,2,19654,10;		//Steel Knife II
	setarray .upg19805[0],	6000,	19804,1,	19656,8,19657,5,19643,2;				//Steel Knife III

	setarray .upg19806[0],	16000,	19805,1,	19640,8,19656,5,19657,10,19643,3;		//Chrome Slicer I
	setarray .upg19807[0],	32000,	19806,1,	19658,2,19640,13,19656,20,19642,1;		//Chrome Slicer II
	setarray .upg19808[0],	32000,	19807,1,	21002,3,21004,4,21006,2,21001,2;		//Nergal Jack
	setarray .upg19809[0],	56000,	19808,1,	21010,2,21003,5,21002,5,21005,1;		//Eradication Vangaurd

	setarray .upg19810[0],	4000,	19803,1,	21014,1,21017,2,21026,2,21015,1;		//Flame Knife I
	setarray .upg19811[0],	8000,	19810,1,	21014,6,21019,2,21018,2,21027,3;		//Flame Knife II
	setarray .upg19812[0],	24000,	19811,1,	21014,6,21020,4,21021,2,21022,1;		//Heat Edge
	setarray .upg19813[0],	56000,	19812,1,	21028,6,21029,4,21030,3,21032,1;		//Corona

	setarray .upg19814[0],	4000,	19803,1,	19659,1,21019,1,21034,2,21045,3;		//Heavy Bang
	setarray .upg19815[0],	16000,	19814,1,	19656,10,21045,3,21047,2,21050,1;		//Heavy Bang+
	setarray .upg19816[0],	56000,	19815,1,	19660,1,21053,3,21060,3,21042,1;		//Master Bang

	setarray .upg19817[0],	1000,	19801,1,	19635,3,21066,1,21065,3,21075,1;		//Aqua Messer I
	setarray .upg19818[0],	2000,	19817,1,	19657,5,21068,3,21067,2,21072,3;		//Aqua Messer II
	setarray .upg19819[0],	4000,	19818,1,	19608,2,21067,4,19638,3,21071,3;		//Aqua Messer III

	setarray .upg19820[0],	8000,	19819,1,	19656,1,21070,2,21065,3,21073,5;		//Rogue Wave I
	setarray .upg19821[0],	16000,	19820,1,	19640,5,21068,4,21076,3,21074,3;		//Rogue Wave II
	setarray .upg19822[0],	32000,	19821,1,	19658,3,21068,6,21067,5,21042,1;		//Rogue Wave III

	setarray .upg19823[0],	4000,	19818,1,	21079,3,21078,4,21085,2;				//Glacial Grace I
	setarray .upg19824[0],	6000,	19823,1,	21091,4,21079,4,21081,3,21082,1;		//Glacial Grace II
	setarray .upg19825[0],	16000,	19824,1,	21079,3,21078,5,21083,3,21085,2;		//Rimespire
	setarray .upg19826[0],	32000,	19825,1,	21053,2,21079,5,21077,3,21084,1;		//Lagia Rimespire

	setarray .cra19827[0],	2000,				19654,10,21111,3,21092,1,21094,5;		//Princess Rapier (Craft)
	setarray .upg19827[0],	2000,	19817,1,	21095,3,21093,5,21094,4;				//Princess Rapier
	setarray .upg19828[0],	8000,	19827,1,	21095,3,21093,5,21090,4,21092,1;		//Queen Rapier
	setarray .upg19829[0],	16000,	19828,1,	21095,4,21100,5,21099,4,21042,1;		//Queen Rose
	setarray .upg19830[0],	32000,	19829,1,	19658,3,21095,5,21100,6,21098,1;		//Royal Rose

	setarray .upg19831[0],	2000,	19817,1,	21087,1,21086,2,21088,3;				//Lumu Knife I
	setarray .upg19832[0],	4000,	19831,1,	21035,3,21087,3,21089,2,21102,5;		//Lumu Knife II
	setarray .upg19833[0],	6000,	19832,1,	21090,1,21086,5,21088,4,21102,3;		//Lumu Tabar I
	setarray .upg19834[0],	16000,	19833,1,	21040,2,21090,5,21086,7,19639,1;		//Lumu Tabar II
	setarray .upg19835[0],	32000,	19834,1,	19615,3,21090,5,21086,7,21042,1;		//Lumu Tabar III

	setarray .upg19836[0],	1000,	19801,1,	21104,2,21105,3,21111,1;				//Blooming Knife I
	setarray .upg19837[0],	2000,	19836,1,	19638,3,21107,2,21103,3,21106,1;		//Blooming Knife II
	setarray .upg19838[0],	4000,	19837,1,	19608,2,21104,4,21107,2,21111,2;		//Blooming Knife III
	setarray .upg19839[0],	6000,	19838,1,	21105,3,21109,2,21110,2,19609,3;		//Datura Blossom I
	setarray .upg19840[0],	16000,	19839,1,	19616,3,21109,3,21110,3,21108,5;		//Datura Blossom II
	setarray .upg19841[0],	32000,	19840,1,	21116,2,21107,4,21109,6,21050,1;		//Datura Blossom III

	setarray .upg19842[0],	2000,	19836,1,	21127,1,21125,3,21122,3;				//Girros Knife I
	setarray .upg19843[0],	4000,	19842,1,	21034,2,21127,3,21124,2,21129,2;		//Girros Knife II
	setarray .upg19844[0],	6000,	19843,1,	21127,3,21125,5,21126,2,21121,6;		//Malady's Tabar I
	setarray .upg19845[0],	16000,	19844,1,	21040,1,21127,4,21124,2,21128,4;		//Malady's Tabar II
	setarray .upg19846[0],	32000,	19845,1,	21115,2,21127,5,21124,3,21050,1;		//Malady's Tabar III

	end;
}