// beast.c
// #pragma save_binary
#include <race.h>
inherit F_DBASE;
mapping combat_action =
([
	"hoof": ([
		"action":		"$N用後腿往$n的$l用力一蹬",
		"damage":		40,
		"attact_type":  "bar",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"瘀傷",
	]),
	"bite": ([
		"action":		"$N撲上來張嘴往$n的$l狠狠地一咬",
		"damage":		30,
		"attact_type":  "bar",
		"damage_type":	"咬傷",
	]),
	"claw": ([
		"action":		"$N用爪子往$n的$l一抓",
		"damage":		30,
		"attact_type":  "bar",
		"damage_type":	"抓傷",
	]),
	"poke": ([
		"action":		"$N用嘴往$n的$l一啄",
		"damage":		25,
		"attact_type":  "bar",
		"damage_type":	"刺傷",
	]),
	"crash": ([
		"action":		"$N用力往$n的$l一撞",
		"damage":		25,
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	"horn": ([
		"action":		"$N用頭上的角猛烈的往$n的$l一頂",
		"damage":		40,
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	"needle": ([
		"action":		"$N挺起身上的刺往$n的$l一刺",
		"damage":		30,
		"attact_type":  "bar",
		"damage_type":	"刺傷",
	]),
	"tail": ([
		"action":		"$N突然轉身用尾巴往$n的$l一掃",
		"damage":		30,
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	"wing": ([
		"action":		"$N衝上高空又呼嘯而下撲向$n的$l",
		"damage":		40,
		"attact_type":  "bar",
		"damage_type":	"刮傷",
	]),
]);

string *actions;

void create()
{
	actions = keys(combat_action);
}

void setup_attribute(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();
	if( undefinedp(my["heart_beat_rate"]) ) my["heart_beat_rate"] = 5;
	if( undefinedp(my["unit"]) ) my["unit"] = "隻";
	if( undefinedp(my["limbs"]) )
	{
		my["limbs"] = ({ "head","body","front_leg","near_leg","tail" });
		ob->set("limbs_effect",([
		"int" : ({"head"}),
		"con" : ({"body"}),
		"dex" : ({"front_leg","near_leg"}),
		"str" : ({"tail","front_leg"}),
		"skill" : ({"head"}),
		]));
	}
	if( undefinedp(my["actions"]) && undefinedp(my["default_actions"]))
	{
		if( pointerp(my["verbs"]) )
			ob->set("default_actions", (: call_other, __FILE__, "query_action" :) );
		else
			my["default_actions"] = ([
				"action": "$N攻擊$n的%l﹐",
			]);
	}
	
	if( undefinedp(my["gender"]) ) my["gender"] = "雄性";
	if( undefinedp(my["age"]) ) my["age"] = random(40) + 5;
	if( undefinedp(my["level"])) my["level"] = random(5)+1;
	if( undefinedp(my["str"]) ) my["str"] = my["level"]*7/4+random(my["level"]/5);
	if( undefinedp(my["con"]) ) my["con"] = my["level"]*2+random(my["level"]/5);
	if( undefinedp(my["int"]) ) my["int"] = 1+my["level"]*4/7+random(my["level"]/5);
	if( undefinedp(my["dex"]) ) my["dex"] = my["level"]*7/4+random(my["level"]/5);
	if( undefinedp(my["Merits"])) // 設定內在素質
	{
		my["Merits"]=([
				"bio": (my["con"]+my["dex"])/25,
				"bar": (my["con"]+my["str"])/20,
				"wit": my["int"]/30+my["dex"]/40,
				"sou": my["int"]/30+my["str"]/40,
				"tec": (my["int"]+my["dex"])/40,
				]);
	}
	else
	{
		if( undefinedp(my["Merits"]["bio"])) my["Merits"]["bio"]=(my["con"]+my["dex"])/25;
		if( undefinedp(my["Merits"]["bar"])) my["Merits"]["bar"]=(my["con"]+my["str"])/20;
		if( undefinedp(my["Merits"]["wit"])) my["Merits"]["wit"]=my["int"]/30+my["dex"]/40;
		if( undefinedp(my["Merits"]["sou"])) my["Merits"]["sou"]=my["int"]/30+my["str"]/40;
		if( undefinedp(my["Merits"]["tec"])) my["Merits"]["tec"]=(my["int"]+my["dex"])/40;
	}

	if( undefinedp(my["volume"]) ) my["volume"] = 4+my["con"]/20;
	if( undefinedp(my["evil"]) ) my["evil"] = random(my["level"]) - random(my["level"]) ;
	if( undefinedp(my["exp"]) )
	{
		if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
		my["exp"] = my["level"]*60 + my["level"]*my["level"]*(6+my["exp_point"])+random(my["level"]*60);
		if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*4;
	}
	if( undefinedp(my["max_hp"]) )
	{
		int q_con = ob->query_con();
		if(userp(ob))
		{
			my["max_hp"] =50 ;
			my["max_hp"] += ( q_con * 25);
		} else 
		{
		 my["max_hp"] = my["level"]*my["level"]*3;
		 my["max_hp"] += q_con * 28;
		}
	}
	if( undefinedp(my["max_mp"]) )
	{
		int q_int = ob->query_int();
		my["max_mp"] = 20;
		my["max_mp"] += ( q_int * 10);
	}
	if( undefinedp(my["max_ap"]) )
	{
		int q_con = ob->query_con();
		my["max_ap"] = 30;
		my["max_ap"] += ( q_con * 15 );
	}
	if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
	if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
	if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
	if(!userp(ob))
	{
//		if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = random(my["level"]*2200);
		if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*400;
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*3/2;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/4;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"];
	} else
	{
		if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=14;
		if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=8;
		if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=8;
	}
	//	NOTE: beast has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT_BEAST + (my["con"])* 500);
	ob->set_max_encumbrance( BASE_ENCUMBRANCE_BEAST + my["str"] * 1350 + my["level"] * 1000);
	ob->set_max_capacity( BASE_CAPACITY_BEAST + my["con"]*1 +my["level"]*2 );
}

mapping query_action(object me)
{
	string *act;

	act = me->query("verbs");
	return combat_action[act[random(sizeof(act))]];
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
	my["heart_beat_rate"] = 5;
	if(userp(ob))
	{
 		my["max_hp"] = ( 50 + ( q_con * 25 ) );
 		my["max_mp"] = ( 20 + ( q_int * 10 ) );
 		my["max_ap"] = ( 30 + ( q_con * 15 ) );
		// 對於mp較差, 但hp成長稍快, ap中等.

		my["Merits"]["bio"]=(q_con+q_dex)/25;
		my["Merits"]["bar"]=(q_con+q_str)/20;
		my["Merits"]["wit"]=q_int/30+q_dex/40;
		my["Merits"]["sou"]=q_int/30+q_str/40;
		my["Merits"]["tec"]=(q_int+q_dex)/40;
	}
 	ob->set_max_encumbrance( BASE_ENCUMBRANCE_BEAST + (ob->query_str()*1350) + my["level"]*1000);
 	ob->set_max_capacity( BASE_CAPACITY_BEAST + (ob->query_con()*1)+my["level"]*2 );
	return;
}
