#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name(HIC"陰"HIR"陽"NOR"劍",({"negative positive sword","sword"})); 
set("long","這是一把由獨臂老人所打造出來的最佳傑作，劍刃的地方有著絲\n"
           "絲的寒氣，寒氣的外圍卻又包圍了一層暖氣，入手之後，令人為\n"
           "之一震。\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("limit_str",45);
set("limit_dex",20); 
set("limit_level",40);
set("value",10000);
set("material","blacksteel");
        }
set("wield_msg","$N從背後抽出一把$n，只見$N身旁圍繞著一股陰陽調和之氣。\n");
set("unwield_msg","$N放下手中的$n，將$n插入背後的劍鞘中。\n");
        set("weapon_prop/sou",-2); 
        set("weapon_prop/bar",random(2));
        set("weapon_prop/tec",random(2));
        set("weapon_prop/wit",1);
        set("weapon_prop/int",2); 
        set("weapon_prop/hit",20);
init_sword(50+random(30));
setup();
}
void attack(object me,object victim)
{
  object ob = this_object();      
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(20)) return; // 1/20 的機率特攻
                message_vision("$N"HIG"手中的$n"HIG"發出一股溫暖的氣息•••"
                      +"這股溫暖的氣息讓$N的精氣在惡鬥之中不降反升！\n"NOR,me,ob);
        me->receive_heal("hp",me->query("max_hp")*11/40);
        me->receive_heal("ap",me->query("max_ap")*11/40); 
  return;
}

