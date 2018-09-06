// Daily Hunting Missions
// ==============================================================================

prontera,178,188,1	script	Busca Empleo?::MissionSign	837,{
	mes "^0000FF* Busca empleo?";
	mes "* Tiene habilidades para cazar criaturas?";
	mes "* Quiere ganar art�culos y dinero?^000000";
	mes "...";
	mes "Busque a Zeph en la sala izquierda y no pierda m�s tiempo!";
	close;
}

function	script	MissionInfo	{
	set .@Mission_Lvl, 0;
	set .@Mission_Exp, 0;
	set .@Mission_Job, 0;
	
	mes "[^FFA500Contrato - Misi�n^000000]";
	for( set .@i, 1; .@i < 6; set .@i, .@i + 1 )
	{
		set .@MobID, getd("Mission_ID" + .@i);
		mes "^0000FF" + getd("Mission_Count" + .@i) + "^000000 x ^FFA500" + strmobinfo(2,.@MobID) + "^000000 (ID : " + .@MobID + ")";

		set .@Mission_Lvl, .@Mission_Lvl + strmobinfo(3, .@MobID);
		set .@Mission_Exp, .@Mission_Exp + (strmobinfo(6, .@MobID) * 10);
		set .@Mission_Job, .@Mission_Job + (strmobinfo(7, .@MobID) * 10);
	}

	set .@Mission_Zeny, .@Mission_Lvl * 150;
	next;

	mes "[^FFA500Detalles - Misi�n^000000]";
	mes "Nivel : ^0000FF" + .@Mission_Lvl + "^000000";

	if( .@Mission_Lvl < 125 )
	{
		mes "Dificultad : ^008000Bajo^000000";
		set .@Mission_Points, 5;
	}
	else if( .@Mission_Lvl < 250 )
	{
		mes "Dificultad : ^000080Media^000000";
		set .@Mission_Points, 10;
	}
	else
	{
		mes "Dificultad : ^FF0000Alta000000";
		set .@Mission_Points, 15;
	}
	
	set .@Time_Left, Mission_Tick - gettimetick(2);
	if( .@Time_Left <= 0 )
		mes "Tiempo Restante : ^FF0000Expirado^000000";
	else if( .@Time_Left > 3600 )
		mes "Tiempo Restante : ^0000FF" + (.@Time_Left / 3600) + " hora(s)^000000.";
	else if( .@Time_Left > 60 )
		mes "Tiempo Restante : ^0000FF" + (.@Time_Left / 60) + " minuto(s)^000000.";
	else
		mes "Tiempo Restante : ^0000FF" + (.@Time_Left) + " segundo(s)^000000.";
	next;

	mes "[^FFA500Premio - Misi�n^000000]";
	mes "Base Exp : ^0000FF" + .@Mission_Exp + "^000000";
	mes "Job Exp : ^0000FF" + .@Mission_Job + "^000000";
	mes "Zeny : ^0000FF" + .@Mission_Zeny + "^000000";
	mes "Puntos : ^0000FF" + .@Mission_Points + "^000000";
	mes "Cash Points : ^0000FF75^000000";
	return;
}

prt_in,94,73,0	script	Contratos	111,{
	if( Mission_Tick <= 0 ) end;
	callfunc "MissionInfo";
	close;
}

prt_in,90,72,4	script	Zeph::HuntingSystem	732,{
	mes "[^FFA500Zeph^000000]";
	if( Mission_Tick < gettimetick(2) )
	{
		if( Mission_Tick == 0 )
		{
			mes "Hola...";
			mes "�Interesado en el puesto de trabajo?";
			next;
			mes "[^FFA500Zeph^000000]";
			mes "Para explicarte, busco personas interesadas en realizar ^0000FFMisiones de Cacer�a^000000 cada d�a.";
			mes "Las misiones constan de eliminar criaturas que te asignar�.";
			next;
			mes "[^FFA500Zeph^000000]";
			mes "A como vayas realizando misiones te ir� asignando cada vez criaturas m�s dificiles.";
			mes "Pero no te preocupes, puedes realizar el trabajo en grupos de amigos, y cualquiera del equipo puede ser quien elimine y a ti se te cuenta.";
			next;
			mes "[^FFA500Zeph^000000]";
			mes "Tendr�s exactamente 24 horas para terminar una misi�n, si la terminas antes del tiempo debes venir a mi para pagarte el trabajo.";
			
		}
		else if( Mission_Ended )
		{
			mes "Tu nueva misi�n est� lista, ya revis� los documentos.";
			mes "Est�s tu listo para recibirla?";
		}
		else
		{
			mes "Seg�n puedo ver fallaste tu �ltima misi�n, no llegaste antes de las 24 horas o no eliminaste el total de criaturas solicitadas.";
			next;
			mes "[^FFA500Zeph^000000]";
			mes "En fin, una l�stima. Supongo que vienes por tu misi�n de hoy.";
			mes "Est�s tu listo para recibirla?";
		}

		next;
		if( select("Si, cual es mi trabajo del d�a?:No gracias, por hoy no.") == 2 )
		{
			mes "[^FFA500Zeph^000000]";
			mes "Suerte entonces, vuelve cuando cuentes con tiempo y recibir�s buena paga.";
			close;
		}

		mes "[^FFA500Zeph^000000]";
		mes "Un momento, dejar leer que te puedo asignar...";
		next;
		
		// Building Mission...
		// =======================================================================================================
		mission_settime gettimetick(2) + 86400;
		// Mission Difficulty
		set .@Mission_Rank, ((Mission_Rank % 45) * 2) + 1;
		// Bonus Difficulty
		set .@Mission_Bonus, (Mission_Rank / 45) * 5;
		// Final Difficulty
		if( set(.@Mission_Rank, .@Mission_Rank + .@Mission_Bonus) > 99 ) set .@Mission_Rank, 99;
		set Mission_Ended, 0;
		for( set .@i, 1; .@i < 6; set .@i, .@i + 1 )
		{
			set .@MobID, getmobrandid(.@Mission_Rank, 14);
			// Mission Index - Mob ID - Mob Amount
			mission_sethunting .@i, .@MobID, 75 - (.@Mission_Rank / 2) + (.@Mission_Bonus / 2);
		}

		callfunc "MissionInfo";
		next;

		mes "[^FFA500Zeph^000000]";
		mes "Suerte en tu misi�n, recuerda que tienes 24 horas para completarla.";
		mes "Presentate conmigo cuando termines.";
		close;
	}
	else
	{
		mes "Hola, de vuelta por aca?";
		mes "Veamos como vas con el trabajo que te encargu�...";
		next;
		
		if( Mission_Count1 + Mission_Count2 + Mission_Count3 + Mission_Count4 + Mission_Count5 < 1 )
		{
			mes "[^FFA500Zeph^000000]";
			if( Mission_Ended == 0 )
			{
				mes "Excelente trabajo!! Terminaste tu misi�n del d�a sin problemas y antes del tiempo l�mite.";
				mes "Dejame pagarte por tus servicios.";
				next;

				set .@Mission_Lvl, 0;
				set .@Mission_Exp, 0;
				set .@Mission_Job, 0;
				for( set .@i, 1; .@i < 6; set .@i, .@i + 1 )
				{
					set .@MobID, getd("Mission_ID" + .@i);
					set .@Mission_Lvl, .@Mission_Lvl + strmobinfo(3, .@MobID);
					set .@Mission_Exp, .@Mission_Exp + (strmobinfo(6, .@MobID) * 10);
					set .@Mission_Job, .@Mission_Job + (strmobinfo(7, .@MobID) * 10);
				}
				set .@Mission_Zeny, .@Mission_Lvl * 150;
				if( .@Mission_Lvl < 125 )
					set .@Mission_Points, 5;
				else if( .@Mission_Lvl < 250 )
					set .@Mission_Points, 10;
				else
					set .@Mission_Points, 15;
				
				// Mission Rewards...
				// =====================================================================
				getexp .@Mission_Exp, .@Mission_Job, 100;
				set Zeny, Zeny + .@Mission_Zeny;
				set Mission_Points, Mission_Points + .@Mission_Points;
				if( Mission_Rank < 449 ) set Mission_Rank, Mission_Rank + 1;
				set Mission_Completed, Mission_Completed + 1;
				if( Mission_Completed > $TMission_Score )
				{
					npctalk "Felicitaciones, eres el nuevo Top Hunter del d�a!!";
					set $TMission_Score, Mission_Completed;
					set $TMission_CharID, getcharid(0);
					set $TMission_Name$, strcharinfo(0);
					set $TMission_Job$, jobname(Class);
				}

				if( $TMission_CharID == getcharid(0) )
					set ##CASHPOINTS, ##CASHPOINTS + 100;
				else
					set ##CASHPOINTS, ##CASHPOINTS + 75;

				getitem 8996,1;
				// =====================================================================
				
				// Clear Mission Data
				for( set .@i, 1; .@i < 6; set .@i, .@i + 1 )
					mission_sethunting .@i,0,0;
				set Mission_Ended, 1;
			}
			
			mes "[^FFA500Zeph^000000]";
			mes "Tu misi�n diaria ya esta terminada.";

			set .@Time_Left, Mission_Tick - gettimetick(2);
			if( .@Time_Left > 3600 )
				mes "Te asignar� una nueva misi�n en ^0000FF" + (.@Time_Left / 3600) + " horas^000000.";
			else if( .@Time_Left > 60 )
				mes "Te asignar� una nueva misi�n en ^0000FF" + (.@Time_Left / 60) + " minutos^000000.";
			else if( .@Time_Left > 0 )
				mes "Te asignar� una nueva misi�n en ^0000FF" + (.@Time_Left) + " segundos^000000.";
			else
				mes "Dejame ordenar mis documentos, vuelve a hablarme para asignarte tu nueva misi�n.";
			close;
		}

		mes "[^FFA500Zeph^000000]";
		mes "A�n no completas la misi�n, te faltan criaturas por eliminar.";
		mes "Consulta el cart�l a mi izquierda para ver el estado de tu trabajo.";
		close;
	}
}

prt_in,86,72,4	script	Top Hunter	857,{
	mes "[^FFA500El Mejor Cazador^000000]";
	if( $TMission_CharID )
	{
		mes "Nombre : ^0000FF" + $TMission_Name$ + "^000000";
		mes "Profesi�n : ^0000FF" + $TMission_Job$ + "^000000";
		mes "Misiones : ^0000FF" + $TMission_Score + "^000000";
	}
	else
	{
		mes "Nombre : ^0000FF(ninguno)^000000";
		mes "Profesi�n : ^0000FF(ninguno)^000000";
		mes "Misiones : ^0000FF0^000000";
	}

	next;
	mes "[^FFA500El Mejor Cazador^000000]";
	mes "El puesto al mejor cazador es asignado a quien tenga primero el mayor n�mero de misiones terminadas.";
	mes "Su premio es un bono de 25 Cash Points mientras mantenga el primer lugar.";
	close;
}

prt_in,85,61,6	script	Sophie::HuntingRewards	894,{
	mes "[^FFA500Sophie^000000]";
	mes "Buenas, soy Sophie la esposa y asistente de Zeph.";
	mes "Cambiar� tus puntos de misi�n y medallas por art�culos.";
	next;
	mes "[^FFA500Sophie^000000]";
	mes "Tus estad�sticas:";
	mes "- Misiones Completas: ^0000FF" + Mission_Completed + "^000000";
	mes "- Puntos de Misiones: ^0000FF" + Mission_Points + "^000000";
	mes "- Medallas de Misi�n: ^0000FF" + countitem(8996) + "^000000";
	next;
	switch( select("Invertir Puntos:Invertir Medallas") )
	{
		case 1:
			mes "[^FFA500Sophie^000000]";
			mes "Esta es la lista de Art�culos que puedes conseguir invirtiendo ^0000FF15 puntos de misi�n^000000. Por favor elije tu opci�n.";
			next;
			setarray .@Shop[0],501,300,502,250,503,200,504,150,505,75,7139,75,7138,200,7137,200,7135,50,7136,50,678,10;
			set .@Index, (select("300 Red Potion:250 Orange Potion:200 Yellow Potion:150 White Potion:75 Blue Potion:75 Glistening Coat:200 Marine Sphere Bottle:200 Plant Bottle:50 Bottle Grenade:50 Acid Bottle:10 Poison Bottle") - 1) * 2;

			set .@Item, .@Shop[.@Index];
			set .@Amount, .@Shop[.@Index + 1];

			if( Mission_Points < 15 )
			{
				mes "[^FFA500Sophie^000000]";
				mes "No tienes suficientes puntos de misi�n, lo lamento.";
				close;
			}

			if( checkweight(.@Item, .@Amount) == 0 )
			{
				mes "[^FFA500Sophie^000000]";
				mes "No soportas el peso del producto seleccionado. Libera espacio y vuelve.";
				close;
			}

			set Mission_Points, Mission_Points - 15;
			getitem .@Item, .@Amount;
			mes "[^FFA500Sophie^000000]";
			mes "Disfruta tu selecci�n, y sigue trabajando realizando m�s misiones.";
			close;

		case 2:
			mes "[^FFA500Sophie^000000]";
			mes "Estos art�culos solo se pueden conseguir con Medallas de Misiones, dime que deseas conseguir.";
			next;
			setarray .@Shop[0],7776,45,1230,90,2345,90,2347,90,2349,90,2351,90;
			set .@Index, (select("1 Gym Pass ^0000FF(45 Medals)^000000:1 Ice Pick ^0000FF(90 Medals)^000000:1 Armor of Volcano[1] ^0000FF(90 Medals)^000000:1 Armor of Ocean[1] ^0000FF(90 Medals)^000000:1 Typhoon Armor[1] ^0000FF(90 Medals)^000000:1 Earth Armor[1] ^0000FF(90 Medals)^000000") - 1) * 2;

			set .@Item, .@Shop[.@Index];
			set .@Amount, .@Shop[.@Index + 1];

			if( countitem(8996) < .@Amount )
			{
				mes "[^FFA500Sophie^000000]";
				mes "No tienes suficientes medallas de misi�n, lo lamento.";
				close;
			}

			if( checkweight(.@Item, 1) == 0 )
			{
				mes "[^FFA500Sophie^000000]";
				mes "No soportas el peso del producto seleccionado. Libera espacio y vuelve.";
				close;
			}

			delitem 8996, .@Amount;
			getitem .@Item, 1;
			mes "[^FFA500Sophie^000000]";
			mes "Disfruta tu selecci�n, y sigue trabajando realizando m�s misiones.";
			close;
	}
}
