#include <ansi.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"秋雲長矛"NOR,({"hero pike","pike"}) );
        set("long",@LONG
這是一把矛
LONG
        );
        set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit","桿");
        set("value",17000);
        set("volume",5);
        set("material","steel");
//init_fork(62);
        set("replica_ob",__DIR__"long_pike");
        }
        set("weapon_prop/bar",1);
init_fork(62);
        setup();
}
void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/5 的機率特攻
        message_vision(HIW"$N發出一道佛氣..正中你心窩。\n;
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);
        victim->add_busy(2);
        return;
}
