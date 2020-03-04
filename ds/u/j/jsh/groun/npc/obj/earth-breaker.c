#include <weapon.h> 
#include <ansi.h>
inherit FORK; 
void create()
{
        set_name(HIB"破地之雷"NOR, ({ "earth breaker","breaker" }) );
        set_weight(3400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");  
                set("limit_str",50);
                set("long",  
 "這是一把沉重的斧槍，全部用鋼鐵鍛造而成，不論是刺擊或是揮
  砍都可以造成強大的破壞，槍上施有召雷咒文，可以喚來雷電產
  驚天動地的一擊，因此有破地之雷的別稱\n");
                set("value", 4000);
        }
        init_fork(68);
        setup();
}
void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(10) < 6 && !me->is_busy()) return;
        message_vision(HIW"$N舉起手中"+this_object()->query("name")+HIW"頓時天上烏雲聚集，霎時一道閃電隨著槍尖殛向$n！\n"NOR,me,victim);
        me->receive_heal("mp",-50);  
        victim->receive_damage("hp",100) ;
        return;
}

