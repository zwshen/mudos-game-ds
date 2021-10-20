// zerg.c
// #pragma save_binary
#include <race.h>

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N���ʧQ������$n��$l",
		"attact_type":  "bar",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"���",
	]),
	([	"action":		"$N��$n��$l�@��",
		"attact_type":  "bar",
		"damage_type":	"����",
	]),
	([	"action":		"$N��$n��$l�����a�r�F�@�f",
		"attact_type":  "bar",
		"damage_type":	"�r��",
	]),
	([	"action":		"$N�ΤO���N���ڥϦV$n��$l",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
	([	"action":		"$N�˷�$n��$l�Q�X�@�ǻĲG",
		"attact_type":  "bio",
		"damage_type":	"�G�k",
	]),
});

void create()
{
	seteuid(getuid());
	set("can_speak", 1);
	set("limbs", ({ "head","body","right_arm","left_arm","belly_leg","tail" }) );
	set("limbs_effect",([
	"int" : ({"head"}),
	"con" : ({"body"}),
	"dex" : ({"belly_leg","tail"}),
	"str" : ({"right_arm","left_arm","tail"}),
	"skill" : ({"head"}),
	]));

}

void setup_attribute(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	if( undefinedp(my["unit"]) ) my["unit"] = "��";
	if( undefinedp(my["gender"]) ) my["gender"] = "�k��";
	if( undefinedp(my["volume"]) ) my["volume"] = 7;
	if( undefinedp(my["attitude"]) ) my["attitude"] = "heroism";
	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	if( undefinedp(my["heart_beat_rate"]) ) my["heart_beat_rate"] = 5;
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;
	if( undefinedp(my["level"])) my["level"] = random(5)+1;
	if( undefinedp(my["guild_gifts"])) my["guild_gifts"] = ({7,5,0,8}); //str,con.int.dex
	if( undefinedp(my["str"]) ) my["str"] = (my["level"]*(10+my["guild_gifts"][0]))/10+random(my["level"]/10);
	if( undefinedp(my["con"]) ) my["con"] = (my["level"]*(10+my["guild_gifts"][1]))/10+random(my["level"]/10);
	if( undefinedp(my["int"]) ) my["int"] = (my["level"]*(10+my["guild_gifts"][2]))/10+random(my["level"]/10);
	if( undefinedp(my["dex"]) ) my["dex"] = (my["level"]*(10+my["guild_gifts"][3]))/10+random(my["level"]/10);
	if( undefinedp(my["night_vision"]) ) my["night_vision"] = 1;

	if( undefinedp(my["Merits"])) // �]�w���b����
	{
		my["Merits"]=([
				"bio": (my["con"]+my["dex"])/25,
				"bar": (my["con"]+my["str"])/25,
				"wit": my["int"]/30+my["dex"]/40,
				"sou": my["int"]/30+my["str"]/30,
				"tec": (my["int"]+my["dex"])/40,
				]);
	}
	else
	{
		if( undefinedp(my["Merits"]["bio"])) my["Merits"]["bio"]=(my["con"]+my["dex"])/25;
		if( undefinedp(my["Merits"]["bar"])) my["Merits"]["bar"]=(my["con"]+my["str"])/25;
		if( undefinedp(my["Merits"]["wit"])) my["Merits"]["wit"]=my["int"]/30+my["dex"]/40;
		if( undefinedp(my["Merits"]["sou"])) my["Merits"]["sou"]=my["int"]/30+my["str"]/30;
		if( undefinedp(my["Merits"]["tec"])) my["Merits"]["tec"]=(my["int"]+my["dex"])/40;
	}


	if( undefinedp(my["evil"]) ) my["evil"] = random(my["level"]);
	if( undefinedp(my["exp"]) )
	{
		if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
		my["exp"] = my["level"]*60 + my["level"]*my["level"]*(7+my["exp_point"])+random(my["level"]*60);
		if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*4;
	}
	if( userp(ob) || undefinedp(my["max_hp"]) )
	{
	   if(userp(ob))
	   {
		int q_con = ob->query_con(); 
		my["max_hp"] = 30 + ( q_con * 15 ) ;
	   } else
	   {
		int q_con = ob->query_con(); 
		 my["max_hp"] = my["level"]*my["level"];
		 my["max_hp"] += q_con * 24;
	   }
	}
	if( userp(ob) || undefinedp(my["max_mp"]) ) {
	   if(userp(ob))
	   {
		int q_int = ob->query_int();
		my["max_mp"] =  20 + q_int * 10;
	   } else
	   {

		int q_int = ob->query_int();
		my["max_mp"] = my["level"]*10;
		my["max_mp"] +=  q_int * 15 ;
	   }
	}
	if( userp(ob) || undefinedp(my["max_ap"]) ) {
	   if(userp(ob))
	   {
		int q_con = ob->query_con();
		my["max_ap"] =  30 + q_con * 25 ;
	   } else
	   {
		int q_con = ob->query_con();
		my["max_ap"] = my["level"]*10;
		my["max_ap"] +=  q_con * 15 ;
	   }
	}
	if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
	if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
	if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
	if(!userp(ob))
	{
		if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*500;
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*3/2+my["con"]/2;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/3;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"];
	}
	else
	{
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/3;
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=6 + my["level"] + my["con"]/2;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=8+my["level"];
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT_ZERG + ( my["con"] )* 900);
	ob->set_max_encumbrance( BASE_ENCUMBRANCE_ZERG + my["str"] * 1350 + my["level"] * 1100);
	ob->set_max_capacity( BASE_CAPACITY_ZERG + my["con"] +my["level"]*2 );
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
	if(my["level"] > 49 || my["dex"] > 60) my["heart_beat_rate"] = 3;
	else if(my["level"]>24 || my["dex"] > 30) my["heart_beat_rate"] = 4;
	else my["heart_beat_rate"] = 5;
	if(userp(ob))
	{
		my["max_hp"] = ( 30 + ( q_con * 15 ) );
		my["max_mp"] = ( 20 + ( q_int * 10 ) );
		my["max_ap"] = ( 30 + ( q_con * 25 ) );
		my["addition_armor"] = my["level"] * 3 / 2 + my["con"]/3;
		my["addition_damage"]= my["level"];
	 	// ����: 
	
		my["Merits"]["bio"]=(q_con+q_dex)/25;
		my["Merits"]["bar"]=(q_con+q_str)/20;
		my["Merits"]["wit"]=q_int/30+q_dex/40;
		my["Merits"]["sou"]=q_int/30+q_str/35;
		my["Merits"]["tec"]=(q_int+q_dex)/40;
	}	 	
 	ob->set_max_encumbrance( BASE_ENCUMBRANCE_ZERG + (ob->query_str()*1350) + my["level"]*1100);
 	ob->set_max_capacity( BASE_CAPACITY_ZERG + (ob->query_con())+my["level"]*2 );
	ob->set_weight(BASE_WEIGHT_ZERG + ( my["con"] )* 900);
	return;
}