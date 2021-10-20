// meda.c	���F�H	by Shengsan@DS
// #pragma save_binary
#include <race.h>

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N�|�_�k��V$n��$l���h",
		"attact_type":  "sou",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"���F����",
	]),
	([	"action":		"$N���W���F�@�V�A�H��N�V$n��$l���X�@��",
		"attact_type":  "sou",
		"damage_type":	"���F����",
	]),
	([	"action":		"$N���X�@��o����Ĳ����$n��$l�g�X�ť�",
		"attact_type":  "sou",
		"damage_type":	"���F����",
	]),
	([	"action":		"$N���_���Y��$n��$l���h",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
});

void create()
{
	seteuid(getuid());
//	set("unit","��");
//	set("gender", "�k��");
	set("can_speak", 1);
//	set("attitude", "peaceful");
	set("limbs", ({"head","body","right_arm","left_arm","right_leg","left_leg" }) );
	set("limbs_effect",([
	"int" : ({"head"}),
	"con" : ({"body"}),
	"dex" : ({"right_leg","left_leg"}),
	"str" : ({"right_arm","left_arm"}),
	"skill" : ({"head"}),
	]));
}

void setup_attribute(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();
	if( undefinedp(my["heart_beat_rate"]) ) my["heart_beat_rate"] = 6;
	if( undefinedp(my["unit"]) ) my["unit"] = "��";
	if( undefinedp(my["gender"]) ) my["gender"] = "�k��";
	if( undefinedp(my["volume"]) ) my["volume"] = 10;
	if( undefinedp(my["attitude"]) ) my["attitude"] = "peaceful";
	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;
	if( undefinedp(my["level"])) my["level"] = random(5)+1;
	if( undefinedp(my["guild_gifts"])) my["guild_gifts"] = ({4,4,8,4});

	if( undefinedp(my["str"]) ) my["str"] = (my["level"]*(10+my["guild_gifts"][0]))/10+random(my["level"]/10);
	if( undefinedp(my["con"]) ) my["con"] = (my["level"]*(10+my["guild_gifts"][1]))/10+random(my["level"]/10);
	if( undefinedp(my["int"]) ) my["int"] = (my["level"]*(10+my["guild_gifts"][2]))/10+random(my["level"]/10);
	if( undefinedp(my["dex"]) ) my["dex"] = (my["level"]*(10+my["guild_gifts"][3]))/10+random(my["level"]/10);

	if( undefinedp(my["Merits"])) // �]�w���b����
	{
		my["Merits"]=([
				"bio": (my["con"]+my["dex"])/35,
				"bar": (my["con"]+my["str"])/35,
				"wit": my["int"]/20+my["dex"]/40,
				"sou": my["int"]/20+my["str"]/40,
				"tec": (my["int"]+my["dex"])/30,
				]);
	}
	else
	{
		if( undefinedp(my["Merits"]["bio"])) my["Merits"]["bio"]=(my["con"]+my["dex"])/35;
		if( undefinedp(my["Merits"]["bar"])) my["Merits"]["bar"]=(my["con"]+my["str"])/35;
		if( undefinedp(my["Merits"]["wit"])) my["Merits"]["wit"]=my["int"]/20+my["dex"]/40;
		if( undefinedp(my["Merits"]["sou"])) my["Merits"]["sou"]=my["int"]/20+my["str"]/40;
		if( undefinedp(my["Merits"]["tec"])) my["Merits"]["tec"]=(my["int"]+my["dex"])/30;
	}


	if( undefinedp(my["evil"]) ) my["evil"] = -random(my["level"])-1;
	if( undefinedp(my["exp"]) )
	{
		if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
		my["exp"] = my["level"]*my["level"]*(7+my["exp_point"])+random(my["level"]*60);
		if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*5;
	}
	if( userp(ob) || undefinedp(my["max_hp"]) )
	{
		int q_con = ob->query_con();
	   if(userp(ob))
	   {
		my["max_hp"] = ( 30 + ( q_con * q_con ) );
	   } else
	   {
		 my["max_hp"] = my["level"]*my["level"];
		 my["max_hp"] += q_con * 31;
	   }
	}
	if( userp(ob) || undefinedp(my["max_mp"]) ) {
	   if(userp(ob))
	   {
		int q_int = ob->query_int();
//	     	my["max_mp"] = ( 30 + my["int"] * 12 );
		my["max_mp"] = ( 30 + q_int * my["level"] );
	   } else
	   {
		int q_int = ob->query_int();
		if( my["level"] <= 5 ) my["max_mp"] = 10;
		else if( my["level"] <= 15 ) my["max_mp"] = 100 + my["level"]*2;
		else if( my["level"] <= 30 ) my["max_mp"] = 300 + my["level"]*3;
		else my["max_mp"] = 500 + my["level"]*4;
		my["max_mp"] += ( q_int * my["level"] );
	   }
	}
	if( userp(ob) || undefinedp(my["max_ap"]) ) {
	   if(userp(ob))
	   {
		int q_con = ob->query_con();
		my["max_ap"] = ( 30 + q_con * my["level"] );
	   } else
	   {
		int q_con = ob->query_con();
		if( my["level"] <= 5 ) my["max_ap"] = 0;
		else if( my["level"] <= 15 ) my["max_ap"] = my["level"]*2;
		else if( my["level"] <= 30 ) my["max_ap"] = my["level"]*3;
		else my["max_ap"] = my["level"]*4;
		my["max_ap"] += ( q_con * my["level"] );
	   }
	}
	if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
	if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
	if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
	if(!userp(ob))
	{
//		if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = random(my["level"]*2300);
		if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*500;
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*3/2;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/3;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"];
	} else
	{
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=10;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=10;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=10;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT_MEDA + ( my["con"] )* 1000);
	ob->set_max_encumbrance( BASE_ENCUMBRANCE_MEDA + (ob->query_str()*1350) + my["level"]*1000);
	ob->set_max_capacity( BASE_CAPACITY_MEDA + (ob->query_con()*1)+my["level"]*2 );
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void reset_attribute(object ob)
{
	mapping my;
	int q_con,q_int,q_dex,q_str;
	my = ob->query_entire_dbase();
	q_con = ob->query_con();
	q_int = ob->query_int();
	q_str = ob->query_str();
	q_dex = ob->query_dex();
	my["heart_beat_rate"] = 6;
	if(userp(ob))
	{
		my["max_hp"] = ( 40 + ( q_con * 20 ) );
		my["max_mp"] = ( 30 + ( q_int * 15 ) );
		my["max_ap"] = ( 30 + ( q_con * 15 ) );
	 		// �H������: ������������.

		my["Merits"]["bio"]=(q_con+q_dex)/35;
		my["Merits"]["bar"]=(q_con+q_str)/35;
		my["Merits"]["wit"]=q_int/20+q_dex/40;
		my["Merits"]["sou"]=q_int/20+q_str/40;
		my["Merits"]["tec"]=(q_int+q_dex)/30;
	}
	ob->set_max_encumbrance( BASE_ENCUMBRANCE_MEDA + (ob->query_str()*1350) + my["level"]*1000);
	ob->set_max_capacity( BASE_CAPACITY_MEDA + (ob->query_con()*1)+my["level"]*2 );
	return;
}
