function	script	iron_bows	{
	.@c = getarg(0,0);
	.@menu$ = "";
	setarray .@option[0], -1;
	deletearray .@options[1],127;

	switch(.@c) {
		case 19860: //Iron Bow I
			.@menu$ = "Iron Bow II:" + red("Cancel");
			setarray .@options[1],19861,-1;
			break;
		case 19861: //Iron Bow II
			.@menu$ = "Iron Bow III:Kulu Arrow I:Aqua Arrow I:"+red("Cancel");
			setarray .@options[1],19862,19870,19884,-1;
			break;
		case 19862: //Iron Bow III
			.@menu$ = "Steel Bow I:"+red("Cancel");
			setarray .@options[1],19863,-1;
			break;
		case 19863: //Steel Bow I
			.@menu$ = "Steel Bow II:"+red("Cancel");
			setarray .@options[1],19864,-1;
			break;
		case 19864: //Steel Bow II
			.@menu$ = "Steel Bow III:"+red("Cancel");
			setarray .@options[1],19865,-1;
			break;
		case 19865: //Steel Bow III
			.@menu$ = "Alloy Bow I:"+red("Cancel");
			setarray .@options[1],19866,-1;
			break;
		case 19866: //Alloy Bow I
			.@menu$ = "Alloy Bow II:Nergal Whisper:"+red("Cancel");
			setarray .@options[1],19867,19868,-1;
			break;
		case 19868: //Nergal Whisper
			.@menu$ = "Doom's Shaft:"+red("Cancel");
			setarray .@options[1],19869,-1;
			break;
		case 19870: //Kulu Arrow I
			.@menu$ = "Kulu Arrow II:Princess Arrow I:"+red("Cancel");
			setarray .@options[1],19871,19878,-1;
			break;
		case 19871: //Kulu Arrow II
			.@menu$ = "Kulu Arrow III:"+red("Cancel");
			setarray .@options[1],19872,-1;
			break;
		case 19872: //Kulu Arrow III
			.@menu$ = "Archer's Dance I:"+red("Cancel");
			setarray .@options[1],19873,-1;
			break;
		case 19873: //Archer's Dance I
			.@menu$ = "Archer's Dance II:Brazencord:"+red("Cancel");
			setarray .@options[1],19874,19876,-1;
			break;
		case 19874: //Archer's Dance II
			.@menu$ = "Archer's Dance III:"+red("Cancel");
			setarray .@options[1],19875,-1;
			break;
		case 19876: //Brazencord
			@menu$ = "Gigacles:"+red("Cancel");
			setarray .@options[1],19877,-1;
			break;
		case 19878: //Princess Arrow I:
			@menu$ = "Princess Arrow II:Rathslinger I:"+red("Cancel");
			setarray .@options[1],19879,19881,-1;
			break;
		case 19879: //Princess Arrow II:
			@menu$ = "Princess Arrow III:"+red("Cancel");
			setarray .@options[1],19880,-1;
			break;
		case 19881: //Rathslinger I
			@menu$ = "Rathslinger II:"+red("Cancel");
			setarray .@options[1],19882,-1;
			break;
		case 19882: //Rathslinger II
			@menu$ = "Rathslinger III:"+red("Cancel");
			setarray .@options[1],19883,-1;
			break;
		case 19884: //Aqua Arrow I
			@menu$ = "Aqua Arrow II:"+red("Cancel");
			setarray .@options[1],19885,-1;
			break;
		case 19885: //Aqua Arrow II
			@menu$ = "Aqua Arrow III:Glacial Arrow I:"+red("Cancel");
			setarray .@options[1],19886,19890,-1;
			break;
		case 19886: //Aqua Arrow III
			@menu$ = "Water Shot I:"+red("Cancel");
			setarray .@options[1],19887,-1;
			break;
		case 19887: //Water Shot I
			@menu$ = "Water Shot II:"+red("Cancel");
			setarray .@options[1],19888,-1;
			break;
		case 19888: //Water Shot II
			@menu$ = "Water Shot III:"+red("Cancel");
			setarray .@options[1],19889,-1;
			break;
		case 19890: //Glacial Arrow I
			@menu$ = "Glacial Arrow II:"+red("Cancel");
			setarray .@options[1],19891,-1;
			break;
		case 19891: //Glacial Arrow II
			@menu$ = "Snowfletcher:"+red("Cancel");
			setarray .@options[1],19892,-1;
			break;
		case 19892: //Snowfletcher
			@menu$ = "Legia Snowfletcher:"+red("Cancel");
			setarray .@options[1],19893,-1;
			break;
		default:
			.@menu$ = red("Cancel");
			setarray .@options[1],-1;
			break;
	}

	.@c = select(.@menu$);

	return .@options[.@c];
}



-	script	iron_bows_mats	-1,{
	end;
OnInit:
	//List of materials for Upgrade
	//
	setarray .upg19860[0],	200,				19655,1;								//Iron Bow II (Craft)						Zeny	BaseEquip	Materials
	setarray .upg19861[0],	200,	19860,1,	19655,2;								//Iron Bow II
	setarray .upg19862[0],	1000,	19861,1,	19635,2,19654,2,19655,5;				//Iron Bow III

	setarray .upg19863[0],	2000,	19862,1,	19657,2,19654,5,19619,2;				//Steel Bow I
	setarray .upg19864[0],	4000,	19863,1,	19608,2,19657,5,19648,2,19654,10;		//Steel Bow II
	setarray .upg19865[0],	6000,	19864,1,	19656,8,19657,5,19643,2;				//Steel Bow III

	setarray .upg19866[0],	16000,	19865,1,	19640,8,19656,5,19657,10,19643,3;		//Alloy Bow I
	setarray .upg19867[0],	32000,	19866,1,	19658,2,19640,13,19656,20,19642,1;		//Alloy Bow II

	setarray .upg19868[0],	32000,	19867,1,	21002,3,21004,4,21006,2,21001,2;		//Nergal Whisper
	setarray .upg19869[0],	56000,	19868,1,	21010,2,21003,5,21002,5,21005,1;		//Doom's Shaft

	setarray .upg19870[0],	1000,	19861,1,	21130,1,21133,2,21132,3;				//Kulu Arrow I
	setarray .upg19871[0],	2000,	19870,1,	19611,3,21130,2,21131,2,21132,3;		//Kulu Arrow II
	setarray .upg19872[0],	4000,	19871,1,	21130,2,21131,4,21045,2,19623,3;		//Kulu Arrow III

	setarray .cra19873[0],	6000,				19656,10,21130,3,21133,6,21132,6;		//Archer's Dance I (Craft)
	setarray .upg19873[0],	6000,	19871,1,	21130,3,21132,6,21133,4;				//Archer's Dance I
	setarray .upg19874[0],	16000,	19873,1,	19612,3,21130,4,21131,3,21045,2;		//Archer's Dance II
	setarray .upg19875[0],	32000,	19874,1,	21050,1,21130,5,21131,4,21002,2;		//Archer's Dance III
	setarray .upg19876[0],	24000,	19875,1,	21140,4,21138,1,21136,1,21134,6;		//Brazencord
	setarray .upg19877[0],	32000,	19876,1,	21149,4,21138,2,21137,1,21135,4;		//Gigacles

	setarray .upg19878[0],	2000,	19870,1,	21093,5,21094,4,21095,3;				//Princess Arrow I
	setarray .upg19879[0],	8000,	19878,1,	21097,4,21092,1,21093,5,21095,3;		//Princess Arrow II
	setarray .upg19880[0],	32000,	19879,1,	19658,3,21100,6,21098,1,21095,5;		//Princess Arrow III
	setarray .upg19881[0],	4000,	19880,1,	21026,2,21150,3,21015,1,21016,2;		//Rathslinger I
	setarray .upg19882[0],	24000,	19881,1,	21020,4,21022,1,21014,6,21021,2;		//Rathslinger II
	setarray .upg19883[0],	32000,	19818,1,	21029,4,21028,6,21021,3,21032,1;		//Rathslinger III

	setarray .upg19884[0],	1000,	19861,1,	21085,1,19635,3,21065,3,21066,1;		//Aqua Arrow I
	setarray .upg19885[0],	2000,	19884,1,	19657,5,21072,3,21067,2,21068,3;		//Aqua Arrow II
	setarray .upg19886[0],	4000,	19885,1,	19638,3,21071,3,21067,4,19608,2;		//Aqua Arrow III
	setarray .upg19887[0],	6000,	19886,1,	19656,5,21073,5,21070,2,21065,3;		//Water Shot I
	setarray .upg19888[0],	16000,	19887,1,	19640,5,21074,3,21068,4,21076,3;		//Water Shot II
	setarray .upg19889[0],	32000,	19888,1,	19658,3,21067,5,21068,6,21042,1;		//Water Shot III

	setarray .upg19890[0],	4000,	19885,1,	21151,2,21079,3,21078,4;				//Glacial Arrow I
	setarray .upg19891[0],	6000,	19890,1,	21079,4,21082,1,21081,3,21091,4;		//Glacial Arrow II
	setarray .upg19892[0],	16000,	19891,1,	21085,2,21079,3,21078,5,21083,3;		//Snowfletcher
	setarray .upg19893[0],	32000,	19892,1,	21053,2,21079,5,21084,1,21077,3;		//Legia Snowfletcher
	end;
}