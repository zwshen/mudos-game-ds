// monster.c
// #pragma save_binary
#include <race.h>
mapping combat_action =
([
        "hoof": ([
                "action":               "$N用後腿往$n的$l用力一蹬",
                "damage":               40,
                "attact_type":  "bio",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "瘀傷",
        ]),
        "bite": ([
                "action":               "$N撲上來張嘴往$n的$l狠狠地一咬",
                "damage":               30,
                "attact_type":  "bio",
                "damage_type":  "咬傷",
        ]),
        "claw": ([
                "action":               "$N用爪子往$n的$l一抓",
                "damage":               30,
                "attact_type":  "bio",
                "damage_type":  "抓傷",
        ]),
        "poke": ([
                "action":               "$N用嘴往$n的$l一啄",
                "damage":               25,
                "attact_type":  "bio",
                "damage_type":  "刺傷",
        ]),
        "crash": ([
                "action":               "$N用力往$n的$l一撞",
                "damage":               25,
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
        "horn": ([
                "action":               "$N用頭上的角猛烈的往$n的$l一頂",
                "damage":               40,
                "attact_type":  "bio",
                "damage_type":  "瘀傷",
        ]),
        "needle": ([
                "action":               "$N挺起身上的刺往$n的$l一刺",
                "damage":               30,
                "attact_type":  "bio",
                "damage_type":  "刺傷",
        ]),
        "tail": ([
                "action":               "$N突然轉身用尾巴往$n的$l一掃",
                "damage":               30,
                "attact_type":  "bio",
                "damage_type":  "瘀傷",
        ]),
        "wing": ([
                "action":               "$N衝上高空又呼嘯而下撲向$n的$l",
                "damage":               40,
                "attact_type":  "bio",
                "damage_type":  "刮傷",
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
        if( undefinedp(my["heart_beat_rate"]) ) my["heart_beat_rate"] = 7;
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
                                "action": "$N攻擊$n的$l﹐",
                        ]);
        }
        if( undefinedp(my["age"]) ) my["age"] = random(40) + 5;
        if( undefinedp(my["level"])) my["level"] = random(5)+1;
        if( undefinedp(my["str"]) ) my["str"] = my["level"]*2+random(my["level"]/4);
        if( undefinedp(my["int"]) ) my["int"] = 1+my["level"]*2+random(my["level"]/4);
        if( undefinedp(my["con"]) ) my["con"] = my["level"]*7/4+random(my["level"]/4);
        if( undefinedp(my["dex"]) ) my["dex"] = my["level"]*7/4+random(my["level"]/4);
        if( undefinedp(my["volume"]) ) my["volume"] = 5+my["con"]/20;
        if( undefinedp(my["Merits"])) // 設定內在素質
        {
                my["Merits"]=([
                                "bio": (my["con"]+my["dex"])/25,
                                "bar": (my["con"]+my["str"])/30,
                                "wit": my["int"]/20+my["dex"]/40,
                                "sou": my["int"]/25+my["str"]/40,
                                "tec": (my["int"]+my["dex"])/40,
                                ]);
        }
        else
        {
                if( undefinedp(my["Merits"]["bio"])) my["Merits"]["bio"]=(my["con"]+my["dex"])/25;
                if( undefinedp(my["Merits"]["bar"])) my["Merits"]["bar"]=(my["con"]+my["str"])/30;
                if( undefinedp(my["Merits"]["wit"])) my["Merits"]["wit"]=my["int"]/20+my["dex"]/40;
                if( undefinedp(my["Merits"]["sou"])) my["Merits"]["sou"]=my["int"]/25+my["str"]/30;
                if( undefinedp(my["Merits"]["tec"])) my["Merits"]["tec"]=(my["int"]+my["dex"])/40;
        }

        if( undefinedp(my["evil"]) ) my["evil"] = random(my["level"]*2) ;
        if( undefinedp(my["exp"]) )
        {
                if( undefinedp(my["exp_point"]) ) my["exp_point"] = 0;
                my["exp"] = my["level"]*60 + my["level"]*my["level"]*(8+my["exp_point"])+random(my["level"]*80);
                if(my["level"]>25) my["exp"]+=my["level"]*my["level"]*5;
        }
        
        if( undefinedp(my["max_hp"]) )
        {
                int q_con = ob->query_con();
                if(userp(ob))
                {
                        my["max_hp"] =45;
                        my["max_hp"] += ( q_con * 20);
                } else
                {
                 my["max_hp"] = my["level"]*my["level"]*3;
                 my["max_hp"] += q_con * 32;
                }

        }
        if( undefinedp(my["max_mp"]) )
        {
                int q_int = ob->query_int();
                my["max_mp"] = 30;
                my["max_mp"] += ( q_int * 20 );
        }
        if( undefinedp(my["max_ap"]) )
        {
                int q_con = ob->query_con();
                my["max_ap"] = 25;
                my["max_ap"] += ( q_con * 10 );

        }
        if( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"] ;
        if( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"] ;
        if( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"] ;
        if(!userp(ob))
        {
                if( undefinedp(my["combat_exp"]) ) my["combat_exp"] = my["level"]*(1+my["exp_point"])*400;
                if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=my["level"]*3/2;
                if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=my["level"]/4;
                if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=my["level"];
        } else
        {
                if( undefinedp(my["addition_armor"]) ) my["addition_armor"]=6;
                if( undefinedp(my["addition_shield"]) ) my["addition_shield"]=12;
                if( undefinedp(my["addition_damage"]) ) my["addition_damage"]=12;
        }
        //      NOTE: monster has no initial limbs defined, you must define it yourself.
        //      ob->init_limbs(LIMBS);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT_MONSTER + ( my["con"] ) * 700);
        ob->set_max_encumbrance( BASE_ENCUMBRANCE_MONSTER + (ob->query_str()*1350) + my["level"]*1000);
        ob->set_max_capacity( BASE_CAPACITY_MONSTER + (ob->query_con()*1)+my["level"]*2 );
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
        my["heart_beat_rate"] = 7;
        if(userp(ob))
        {
                my["max_hp"] = ( 45 + ( q_con * 20 ) );
                my["max_mp"] = ( 30 + ( q_int * 20 ) );
                my["max_ap"] = ( 25 + ( q_con * 10 ) );
                // 對於mp方面成長快, 但ap較差

                my["Merits"]["bio"]=(q_con+q_dex)/25;
                my["Merits"]["bar"]=(q_con+q_str)/30;
                my["Merits"]["wit"]=q_int/20+q_dex/40;
                my["Merits"]["sou"]=q_int/25+q_str/40;
                my["Merits"]["tec"]=(q_int+q_dex)/40;
        }
        ob->set_max_encumbrance( BASE_ENCUMBRANCE_MONSTER + (ob->query_str()*1350) + my["level"]*1000);
        ob->set_max_capacity( BASE_CAPACITY_MONSTER + (ob->query_con()*1)+my["level"]*2 );
        return;
}

mapping query_action(object me)
{
        string *act = me->query("verbs");
        return combat_action[act[random(sizeof(act))]];
}

