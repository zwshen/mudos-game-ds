#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
     set_name( HIR"魔劍"HIW"-"NOR"提爾鋒"NOR,({"tyrfing sword","sword"}) );
     set("long", "北歐神話中的魔劍，也翻譯做「斬裂劍」。是一把出鞘就得吸血，雖然會帶給持\n"
                 "有者大量榮光，但也會使持有劍者陷入毀滅的一柄魔劍。\n");
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("unit", "把");             
            set("value", 6000);
            set("material","gold"); 
          }         
     set("limit_str",70);
     set("limit_level",40);
     set("weapon_prop/con", 1);
     set("weapon_prop/dex", 3);
     init_sword(70);
     setup();
}
void attack(object me,object victim)
{
     object ob = this_object();
     ::attack();
     if(!me || !victim || me->is_busy()) return;
     
     if( userp(me) ) me->receive_damage("hp", 20);
     tell_object(me, "你身上流動的血液正在慢慢地被"+ob->query("name")+"吸取之中。\n");
     COMBAT_D->do_attack(me, victim, this_object(), random(5));
     COMBAT_D->report_statue(victim);  
     return;
}

