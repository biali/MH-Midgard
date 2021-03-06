//===== eAthena Script ======================================= 
//= NPC Vars Editor
//===== By: ================================================== 
//= Zephyrus
//===== Current Version: ===================================== 
//= 1.0 10399
//===== Compatible With: ===================================== 
//= eAthena SVN Stable 
//===== Description: ========================================= 
//= Permite consultar y Modificar variables n�mericas o de
//= texto en el juego.
//===== Additional Comments: ================================= 
//= 1.0 Versi�n Inicial
//============================================================ 

//============================================================ 
//= NPC de Control de Variables Num�ricas
//============================================================ 

-	script	NPCVarsN	-1,{
	end;
	
OnWhisperGlobal:
	if (getgmlevel() < 1) end; // No acepta Players ni Cops
	set @Nombre$, @whispervar0$;
	if (getstrlen(@whispervar1$) > 0) set @Nombre$, @whispervar1$;
	if (getstrlen(@Nombre$) < 4 || getstrlen(@Nombre$) > 24) {
		dispbottom "[El nombre ingresado es incorrecto]";
		end;
	}
	set @RID, getcharid(3,@Nombre$);
	if (@RID < 1) {
		dispbottom "[El personaje no existe o no est� conectado]";
		end;
	}
	// Encontrado el Personaje

L_Consulta:
	mes "^0000FF[NPC Vars Info]^000000";
	mes "Ha solicitado informaci�n de Variables.";
	mes "Personaje: ^0000FF" + @Nombre$ + "^000000";
	mes "�Que variable deseas consultar (solamente num�ricos)?";
	next;
	input @Variable$;

L_Verificar:
	set $@GMid, playerattached(); // El ID del GM para regresar al proceso luego de la consulta
	set $@Variable$, @Variable$;
	if (attachrid(@RID) > 0) {
		set $@Valor, getd($@Variable$); // Obtiene el Valor
		if (attachrid($@GMid)) {
			set @Resultado, $@Valor;
			mes "^0000FF[NPC Vars Info]^000000";
			mes "El valor de " + @Variable$ + " es de " + @Resultado + ".";
			mes "Que deseas hacer con esto?";
			next;
			menu "Consultar otra variable",L_Consulta,"Cambiar el valor actual",L_Cambiar,"Finalizar consultas",-;
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Utiliza la herramienta cuando lo necesites";			
			close;
		} else end; // El GM se desconect�
	} else {
		// Se desconect�
		if (attachrid($@GMid)) {
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Lo lamento, el jugador se ha desconectado.";
			mes "Si quieres consultar a alguien m�s vuelve a whispearme";
			close;
		} else end; // El GM se desconect�
	}
	end;

L_Cambiar:
	if( @Variable$ == "##CASHPOINTS" || @Variable$ == "#KAFRAPOINTS" )
	{
		mes "^0000FF[NPC Vars Info]^000000";
		mes "Estas variables est�n bloqueadas por seguridad!!";
		mes "Evita problemas con la Administraci�n.";
		close;
	}

	mes "^0000FF[NPC Vars Info]^000000";
	mes "Que valor deseas ponerle a la variable ^0000FF" + @Variable$ + "^000000 para el jugador ^0000FF" + @Nombre$ + "^000000";
	mes "(Valor Actual: ^0000FF" + @Resultado + "^000000)";
	next;
	input @Valor; // Solo numerico permite
	set $@GMid, playerattached(); // El ID del GM para regresar al proceso luego de la consulta
	set $@Variable$, @Variable$;
	set $@OldValor, @Resultado;
	set $@Valor, @Valor;
	if (attachrid(@RID) > 0) {
		setd $@Variable$, $@Valor; // Actualiza el Valor
		logmes "Variable " + $@Variable$ + " de " + strcharinfo(0) + " cambio de " + $@OldValor + " a " + $@Valor + " por " + $@GMid + ".";
		if (attachrid($@GMid)) {
			mes "^0000FF[NPC Vars Info]^000000";
			mes "El Valor ha sido cambiado a " + @Valor + ".";
			mes "Que deseas hacer ahora?";
			next;
			menu "Verificar el cambio",L_Verificar,"Volver a cambiar",L_Cambiar,"Consultar otra Variable",L_Consulta,"Finalizar consultas",-;
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Utiliza la herramienta cuando lo necesites";			
			close;
		} else end; // El GM se desconect�
	} else {
		// Se desconect�
		if (attachrid($@GMid)) {
			mes "^0000FF[NPC Vars Info]^000000";
			mes "Lo lamento, el jugador se ha desconectado.";
			mes "Si quieres consultar a alguien m�s vuelve a whispearme";
			close;
		} else end; // El GM se desconect�
	}
}
