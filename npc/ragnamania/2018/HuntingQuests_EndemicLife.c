-	script	#EndemicLife	-1,{
	end;

OnInstanceInit:
	sleep2 50;
	.@mobid = getelementofarray($@pets,rand(getarraysize($@pets)));
	.@mobname$ = getmonsterinfo(.@mobid,MOB_NAME);

//	if(rand(3) == 1) 
		monster instance_mapname(strnpcinfo(4)),0,0,.@mobname$,.@mobid,1;
		debugmes "----- Endemic Life Created -----";
//	end;

OnInit:
	disablenpc(strnpcinfo(0));
	end;
}
pay_fild07,0,0,0	duplicate(#EndemicLife)	#el_forest	111,0,0