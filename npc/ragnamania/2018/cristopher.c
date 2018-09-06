// Skill Master
// by Cristopher
// v1.0

new_1-1, 139,137,1	script	Skill Master	837,{
	function Check_Riding; function Check_SkillPoints; function GetSkill; function BuildSkillMenu;

	mes .n$;

	Check_Riding();
	Check_SkillPoints();

//	if (MASTER_SKILL) {
//		mes "Voce ja pegou sua Habilidade Especial. Lamento mas nao ha nada mais que eu possa fazer por voce";
//		close;
//	}

	mes "xxx";
	if(select("Sim, quero minha nova habilidade extra:Nao, muito obrigado") == 2)
		close;
	else {
		if(BuildSkillMenu() == 0) {
			mes "Hum... Lamento mas vc precisa ser segunda classe para q eu possa lhe ajudar.";
			close;
		}
		else {
			mes "Voce esta agora mais poderoso. Boa sorte em suas aventuras!";
			close;
		}
	}

	function	Check_Riding	{
	// Note: Why we should always check for Riding:
	// Mounts are considered as another class, which
	// would make this NPC bigger just to handle with
	// those special cases.
		if (checkfalcon() || checkcart() || checkriding() || ismounting()) {
			mes "Por favor, remova  " +
				((checkfalcon()) ? "o seu falcao" : "") +
				((checkcart()) ? "o seu carrinho" : "") +
				((checkriding()) ? "o seu Peco" : "") +
				((ismounting()) ? "a sua montaria" : "") +
				" antes que possamos continuar.";
			close;
		}
		return;
	}
	function	Check_SkillPoints	{
		if (.SkillPointCheck && SkillPoint) {
			mes "Por favor use todos seus pontos de habilidades antes de podermos continuar.";
			close;
		}
		return;
	}

	function	GetSkill	{
		.@skillid = getarg(0,0);
		if (.@skillid == 0)
			return;

		mes "Sua escolha eh:";
		mes "^00AA00 " + getskillname(.@skillid) + "[" + (.@lv = getskillmaxlv(.@skillid)) + "]^000000";
		mes "Deseja mesmo continuar? Este processo nao pode ser revertido.";
		if(select("Nao, eu mudei de ideia:Sim, estou certo da minha escolha") == 1)
			close;
		else {
			skill .@skillid,.@lv,SKILL_PERM_GRANT;
			
			if (.@iskillid == 387)
				skill 485,XX,SKILL_PERM_GRANT;

			skilleffect(.@skillid,9999);
			MASTER_SKILL = 1;
		}

		return;
	}

	function	BuildSkillMenu	{
		if (Class == Job_Super_Novice) {
			.@j=0;
			for (.@i=355; .@i<408; .@i++){
				if(.@i != 377 && .@i != 391) { //Essas skills estao comentadas no banco de dados
					setarray .@S_SuperNovice[(.@j)],.@i;
					.@menu$ = .@menu$ + getskillname(.@i) + ":";
					.@j++;
				}
			}
			.@menu$ = .@menu$ + "^AA0000Cancelar^000000";
			.@c = (select(.@menu$)) -1; // Menu comeca de 1 e array comeca de 0
			GetSkill(.@S_SuperNovice[.@c]);
			return 1;
		} else {
			if(BaseJob < 7 || BaseJob > 20)
				return 0;
			set .@var$, ".S_" + BaseJob;
			for (.@i=0; .@i<getarraysize(getd(.@var$)); .@i++) 
				.@menu$ = .@menu$ + getskillname(getd(.@var$+"["+.@i+"]")) + ":";
			.@menu$ = .@menu$ + "^AA0000Cancelar^000000";
			.@c = (select(.@menu$)) -1; // Menu comeca de 1 e array comeca de 0
			if(.@c >= getarraysize(getd(.@var$)))
				close;
			else
				GetSkill(getd(.@var$+"["+.@c+"]"));
			return 1;
		}
	}

OnInit:
	.n$ = "^0000AA[ Mestre das Habilidades ]^000000";
	setarray .S_7[0],355,397,359,356,358,357,398,399;	//Knight
	setarray .S_8[0],361,362,363,481;					//Priest
	setarray .S_9[0],364,365,366;						//Wizard
	setarray .S_10[0],384,385,386,387,388;				//Blacksmith
	setarray .S_11[0],380,381,382,383;					//Hunter
	setarray .S_12[0],376,378,379,406,407;				//Assassin
	setarray .S_14[0],367,268,369;						//Crusader
	setarray .S_15[0],370,371,372;						//Monk
	setarray .S_16[0],402,403,404,405;					//Sage
	setarray .S_17[0],389,390;							//Rogue
	setarray .S_18[0],392,393;							//Alchemist
	setarray .S_19[0],394,395,396;						//Bard
	setarray .S_20[0],394,395,396; 						//Dancer
	end;
}






// Diff do source pra incluir o script command getskillname
//--- src/map/script.c (revision 100644)
//+++ src/map/script.c (working copy)
//@@ -21217,6 +21219,34 @@ BUILDIN_FUNC(preg_match) {
// #endif
// }
 
//+
//+/** 
//+* Jezznar
//+* getskillname (skillid);
//+**/
//+BUILDIN_FUNC(getskillname)
//+{
//+	int skill_id;
//+	char *skill_name;
//+	//get input skill_id
//+	if (!script_hasdata(st, 2)){
//+		script_pushconststr(st, "null");
//+		return SCRIPT_CMD_SUCCESS;
//+	}
//+	skill_id = script_getnum(st, 2);
//+
//+	if (!skill_get_index(skill_id)){
//+		ShowError("script:conv_str: Unknown skill_id supplied.\"\n");
//+		script_pushconststr(st, "null");
//+		return SCRIPT_CMD_SUCCESS;
//+	}
//+	skill_name = (char *)aMalloc(SKILL_NAME_LENGTH*sizeof(char));
//+	memcpy(skill_name, skill_db[skill_get_index(skill_id)]->desc, SKILL_DESC_LENGTH);
//+	script_pushstr(st, skill_name);
//+
//+	return SCRIPT_CMD_SUCCESS;
//+}
//+
/** 
* Biali
* getskillmaxlv (skillid);
**/
//+BUILDIN_FUNC(getskillmaxlv)
//+{
//+	int skill_id;
//+	unsigned short *skill_max_lv;
//+	//get input skill_id
//+	if (!script_hasdata(st, 2)){
//+		script_pushconststr(st, "null");
//+		return SCRIPT_CMD_SUCCESS;
//+	}
//+	skill_id = script_getnum(st, 2);
//+
//+	if (!skill_get_index(skill_id)){
//+		ShowError("script:conv_str: Unknown skill_id supplied.\"\n");
//+		script_pushconststr(st, "null");
//+		return SCRIPT_CMD_SUCCESS;
//+	}
//+	skill_max_lv = skill_get_max(skill_id);
//+	script_pushint(st,skill_max_lv);
//+
//+	return SCRIPT_CMD_SUCCESS;
//+}
// /// script command definitions
// /// for an explanation on args, see add_buildin_func
// struct script_function buildin_func[] = {
//@@ -21737,6 +21767,7 @@ struct script_function buildin_func[] = {
// 	BUILDIN_DEF(opendressroom,"i?"),
// 	BUILDIN_DEF(navigateto,"s???????"),
// 	BUILDIN_DEF(adopt,"vv"),
//+	BUILDIN_DEF(getskillname, "v"), //Biali
//+ BUILDIN_DEF(getskillmaxlv, "v"), //Biali
// 
// #include "../custom/script_def.inc"