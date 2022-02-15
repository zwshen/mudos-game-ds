// robot.c
// #pragma save_binary
#include <race.h>

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N��������$n��$l",
		"attact_type":  "bar",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"���",
	]),
	([	"action":		"$N��$n��$l�����a��F�@�}",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
	([	"action":		"$N�����u�p�g�j���$n��$l�g�F�L�h",
		"attact_type":  "tec",
		"damage_type":	"�p�g����",
	]),
	([	"action":		"$N���$n��$l�o�g�X�X�����í��u",
		"attact_type":  "tec",
		"damage_type":	"���u����",
	]),
});

void create()
{
	seteuid(getuid());
	set("can_speak", 1);

}

void setup_attribute(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();
	if( undefinedp(my["heart_beat_rate"]) ) my["heart_beat_rate"] = 8;
	if( undefinedp(my["unit"]) ) my["unit"] = "��";
	if( undefinedp(my["gender"]) ) my["gender"] = "�k��";
	if( undefinedp(my["attitude"]) ) my["attitude"] = "peaceful";
	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;
	if( undefinedp(my["level"])) my["level"] = random(5)+1;
	if( undefinedp(my["guild_gifts"])) my["guild_gifts"] = ({5,5,5,5});
	if( undefinedp(my["limbs"]))
	{
		my["limbs"] = ({"head","body","right_arm","left_arm","right_leg","left_leg"});
		ob->set("limbs_effect",([
		"int" : ({"head"}),
		"con" : ({"body"}),
		"dex" : ({"right_leg","left_leg"}),
		"str" : ({"right_arm","left_arm"}),
		"skill" : ({"head"}),
		]));
	}
	if( undefinedp(my["str"]) ) my["str"] = (my["level"]*(10+my["guild_gifts"][0]))/10+random(my["level"]/10);
	if( undefinedp(my["con"]) ) my["con"] = (my["level"]*(10+my["guild_gifts"][1]))/10+random(my["level"]/10);
	if( undefinedp(my["int"]) ) my["int"] = (my["level"]*(10+my["guild_gifts"][2]))/10+random(my["level"]/10);
	if( undefinedp(my["dex"]) ) my["dex"] = (my["level"]*(10+my["guild_gifts"][3]))/10+random(my["level"]/10);
	if( undefinedp(my["volume"]) ) my["volume"] = 4+my["con"]/10;
	if( undefinedp(my["Merits"])) // �]�w���b����
	{
		my["Merits"]=([
				"bio": (my["con"]+my["dex"])/30,
				"bar": (my["con"]+my["str"])/30,
				"wit": my["int"]/30+my["dex"]/40,
				"sou": my["int"]/30+my["str"]/40,
				"tec": (my["int"]+my["dex"])/20,
				]);
	}
	else
	{
		if( undefinedp(my["Merits"]["bio"])) my["Merits"]["bio"]=(my["con"]+my["dex"])/30;
		if( undefinedp(my["Merits"]["bar"])) my["Merits"]["bar"]=(my["con"]+my["str"])/30;
		if( undefinedp(my["Merits"]["wit"])) my["Merits"]["wit"]=my["int"]/25+my["dex"]/40;
		if( undefinedp(my["Merits"]["sou"])) my["Merits"]["sou"]=my["int"]/25+my["str"]/40;
		if( undefinedp(my["Merits"]["tec"])) my["Merits"]["tec"]=(my["int"]+my["dex"])/30;
	}


	if( undefinedp(my["evil"]) ) my["evil"] = -random(my["level"])-1;
	if( undefinedp(my["exp"]) )
	{
		if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
		my["exp"] = my["level"]*my["level"]*(7+my["exp_point"])+random(my["level"]*60);
		if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*3;
	}
	if( userp(ob) || undefinedp(my["max_hp"]) )
	{
	   int q_con = ob->query_con();
	   if(userp(ob))
	   {
		my["max_hp"] = ( 50 + ( q_con * 30 ) );
	   } else
	   {
		 my["max_hp"] = my["level"]*my["level"];
		 my["max_hp"] += q_con * 36;
	   }
	}
	if( userp(ob) || undefinedp(my["max_mp"]) )
	{
	   if(userp(ob))
	   {
		int q_int = ob->query_int();
		my["max_mp"] = ( 25 + q_int * 10 );
	   } else
	   {
		int q_int = ob->query_int();
		my["max_mp"] = my["level"]*10;
		my["max_mp"] += ( q_int * 10 );
	   }
	}
	if( userp(ob) || undefinedp(my["max_ap"]) ) {
	   if(userp(ob))
	   {
		int q_con = ob->query_con();
		my["max_ap"] = ( 25 + q_con * 10 );
	   } else
	   {
		int q_con = ob->query_con();
		my["max_hp"] = my["level"]*10;
		my["max_ap"] += ( q_con * 12 );
	   }
	}
	if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
	if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
	if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
	if(!userp(ob))
	{
		if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*500;
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*2;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/3;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"]*3/2;
	} else
	{
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=13;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=5;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=12;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT_ROBOT + ( my["con"] )* 1000);
	ob->set_max_encumbrance( BASE_ENCUMBRANCE_ROBOT + (ob->query_str()*1350) + my["level"]*1000);
	ob->set_max_capacity( BASE_CAPACITY_ROBOT + (ob->query_con()*2)+my["level"]*2 );
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
	my["heart_beat_rate"] = 8;
	if(userp(ob))
	{
		my["max_hp"] = ( 50 + ( q_con * 30 ) );
 		my["max_mp"] = ( 25 + ( q_int * 10 ) );
 		my["max_ap"] = ( 25 + ( q_con * 10 ) );
		//hp�����ֳt�G���@��, ����j, �������C

		my["Merits"]["bio"]=(q_con+q_dex)/30;
		my["Merits"]["bar"]=(q_con+q_str)/30;
		my["Merits"]["wit"]=q_int/30+q_dex/40;
		my["Merits"]["sou"]=q_int/30+q_str/40;
		my["Merits"]["tec"]=(q_int+q_dex)/20;
	}
	ob->set_max_encumbrance( BASE_ENCUMBRANCE_ROBOT + (ob->query_str()*1350) + my["level"]*1000);
	ob->set_max_capacity( BASE_CAPACITY_ROBOT + (ob->query_con()*2)+my["level"]*2 );
	return;
}
