#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit GUN;
void create()
{       set_name(HIB"終結之槍"NOR,({"final gun","gun"}) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",HIG"這是一把終結武器。\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("bullet_type","enegry");
        set("max_load",1000);
        init_gun(10000);
        set("material", "blacksteel");
        set("wield_msg","$N拿出一把$n, 並將$n的保險裝置解開。\n");
        set("unwield_msg", "$N將手中的$n保險裝置關閉。\n");
        setup();
        }
}
void attack(object me,object victim)
{
	int damage,hp,maxhp,mp;

  me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
  mp=me->query("mp");
 if ( hp > maxhp )
 { 
   damage=1000000+random(100) *(hp+mp);
  message_vision(HIR" 終結之槍吸收了所有力量，射出超級一擊！！！
   造成$N"+damage+"點的傷害！！！！\n"NOR,victim); 
  victim->receive_damage("hp", damage, me );
 return;    
 }
}