prontera,150,175,0	script	testparty	521,{
npctalk "You're required to enter the waitingroom.";
end;

OnInit:
waitingroom "test",11,"testparty::OnFull",0;
end;

OnFull:
	getmapxy .@map$, .@x, .@y,1;
	warpwaitingpc .@map$,.@x,.@y;
	for ( .@i = 0; .@i < $@warpwaitingpcnum; .@i++ ) {
		.@name$ = rid2name($@warpwaitingpc[.@i]);
		.@char_id = getcharid( 0,.@name$ );
		if ( getcharid( 1,.@name$ ) > 0 )
			party_delmember( .@char_id );
		if ( .@create == 0 ) {
			while( party_create( "party_"+ rand(10000), .@char_id ) == -3 );
			.@create = 1;
		}
		else if ( $@party_create_id && party_addmember( $@party_create_id,.@char_id ) < 1 ) {
			npctalk "An error occur.";
			end;
		}
	}
	end;
OnPCStatCalcEvent:
OnPCLogoutEvent:
	if ( strcharinfo(3) != "alberta" || getcharid(1) == 0 ) end;
	.@party_id = getcharid(1);
	if ( getcharid(0) != getpartyleader( .@party_id,2) )
		party_delmember();
	else {
		if ( instance_check_party(.@party_id,2) == 0 )
			party_destroy(.@party_id);
		else {
			getpartymember .@party_id,1;
			getpartymember .@party_id,2;
			for ( .@i = 0; .@i < $@partymembercount; .@i++ ) {
				if ( isloggedin( $@partymemberaid[.@i],$@partymembercid[.@i] ) && $@partymembercid[.@i] != getcharid(0) ) {
					party_changeleader .@party_id,$@partymembercid[.@i];
					party_delmember $@partymembercid[.@i],.@party_id;
					break;
				}
			}
		}
	}
	end;
}