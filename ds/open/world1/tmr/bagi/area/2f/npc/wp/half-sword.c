#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("半截長劍",({"half long sword","sword"}));
        set("long",@long
    這是一把已經斷了半截的長劍，但是劍身散發著陰森的綠光，似乎塗
有劇毒。劍柄上刻著的字樣早已模糊不清，看樣子此劍鑄成的歷史已久。
long
        );
          set_weight(5000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",4000);
                set("volume",3);
                set("material","iron");
        }
        init_sword(35);
        set("waepon_prop/str",1);
        set("waepon_prop/dex",1);
        set("limit_str",20);
        set("limit_dex",20);
        setup();
}

void attack(object me,object victim)
{
        int damage,def;

        ::attack();
        if(!me ||!victim ) return;
        if( random(100)<30 && victim->query_skill("dodge") < random(200) ) {
                message_vision(HIG"$n一個不小心被$N手上的半截長劍輕輕劃過一個小口...\n"NOR,me,victim);
                victim->apply_condition("poison", 5);
        }
        return ;
}



