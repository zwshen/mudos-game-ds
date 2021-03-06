#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit F_UNIQUE;
inherit DAGGER;

void create()
{
          set_name(HIC"八方雲集"NOR,({"cloud-together dagger","dagger"}) );
          set("long", @LONG
八方雲集是一把較短的兵器，輕巧靈活，有利於防守時的反應速度，
能有效撥開對方的刺擊，或卡著對方的劍刃，同時亦能在肉搏距離發揮
攻擊效用。
LONG
);
        set_weight(1800);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
              set("value", 40000);
              set("limit_level", 25);
              set("material", "blacksteel");
        }
        init_dagger(45);
        set("replica_ob", __DIR__"tian-que_dagger.c");
         set("class_only", "thief");
        set("weapon_prop/bio", 1);
        set("weapon_prop/wit", -1);
        set("weapon_prop/dex", 2);
          set("weapon_prop/str", -2);
        set("backstab_bonus", 30); //百分比
        setup();        
}
 
void attack(object me,object victim)
{ 
        ::attack(); 
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;

        if(random(5)) return; // 1/5 的機率特攻
        message_vision( HIC "$N"HIC"手中的八方雲集忽然噴出陣陣雲霧，將$n"HIC"團團圍住，$n"HIC"一時之間手足無措！！ \n"NOR,me,victim);
        victim->start_busy(2);
        return; 
} 

