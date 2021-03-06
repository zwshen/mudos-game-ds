#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
  set_name("長刺刀"NOR, ({ "long bayonet","bayonet","dagget" }) );
  set("long",@long
刀身較長的刺刀，除了裝於槍上也可以做為一般肉搏用途。
long);      
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "steel");
    set("value",2500);
    set("volume",2);
    set("weapon_prop/hit",5);
  }
  set("backstab_bonus",35);
  init_dagger(37);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(random(5)) return;
  message_vision(HIR"$N被長刺刀刺中的傷口綻裂，傷口一時血流不止...！\n"NOR,victim);
  victim->apply_condition("blooding", victim->query_condition("blooding")+2);
  return;
}