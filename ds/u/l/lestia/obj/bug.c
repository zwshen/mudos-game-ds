//pill.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("íL«Í¦ä", ({"mud bug","bug"}));
        set("unit", "¥ó");
        set("base_weight", 1);
        set("invis",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_dieout",1);
        set("value", 1);
        set("type", "misc");
        set_heart_beat(1);
}

void heart_beat()
{
        object ppl,opo;
        
        if( userp(ppl = environment())) {
                if(ppl->isfighting()) {
                        if(objectp(opo = ppl->query_temp("last_damage_from")) && !userp(opo)) {
                                opo->receive_heal("hp",opo->query("max_hp")/3);
                        }               
                }
        }

}


