#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
    set_name(HIR"九狐爪"NOR,({"nine-fox claw","claw"}) );
    set("long","九尾的爪子，殺傷力非常大，傳說只要配上這雙爪子，
連不會武功\的平常人也可以變成英雄。\n");
        set_weight(10000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","對");
        set("value",50000); 
        set("material","gold"); 
        set("replica_ob",__DIR__"fist3");
        }
        set("wield_msg",
         HIW "$N雙手套上$n"HIW+"，登時$N眼中射出血紅色的殺氣，令人不由得退了二步。\n"
         NOR);
        set("limit_level",45);
        set("limit_str",70);
        set("weapon_prop/dex", 4);
        set("weapon_prop/int", -2);
        set("weapon_prop/str", 3);
        set("weapon_prop/bar", 2);
        set("weapon_prop/wit", -1);
        set("weapon_prop/sou", -1);
        init_fist(53+random(7));  //這麼高幹麻
        setup();
}
void init()
{ 
   add_action("check","wield"); 
   add_action("check","wi");
} 

int check(string arg)
{ 
   object me;
   me = this_player();
    if( me->query("MKS") < 30000)        { 
       message_vision("你的殺氣不夠沒辦法裝備這個東西•\n",me);
       }
    else return ::wield(me,arg);
}

void attack(object me,object victim)
{
  object ob = this_object();      
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/10 的機率特攻
message_vision(HIR"\n九尾的力量片段從$n"HIR"中釋放了出來！！\n"+
                  "\n$N吸收了九尾的力量，狂暴了起來！！\n"NOR,me,ob); 
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);   
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);  
        return; 
}

