#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
  set_name( GRN"毒匕首"NOR , ({ "poison dagger","dagger" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這匕首己粹煉了劇毒，只見刃面覆著一層淡淡綠光，妖異奇詭。");
    set("material", "poison");
    set("value",3000);
    set("volume",3);
    set("limit_skill",30);
    set("limit_lv",15);
    set("class_only","thief");
  }
  init_dagger(28);
  setup();
}

void attack(object me, object victim)
{
  int i;
  for(i=0;i<4;i++)
    ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(3) == 2) return;
  message_vision(HIG"$N的傷口漸漸轉為深綠色，發出一股惡臭!!\n"NOR,victim);
  if( userp(victim) ) victim->apply_condition("poison", victim->query_condition("poison")+ (7+random(5)));
    else victim->apply_condition("poison", victim->query_condition("poison")+ (15+random(5)));
  return;
}

