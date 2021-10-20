#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
  set_name("����M"NOR, ({ "long bayonet","bayonet","dagget" }) );
  set("long",@long
�M����������M�A���F�˩�j�W�]�i�H�����@��׷i�γ~�C
long);      
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
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
  message_vision(HIR"$N�Q����M�뤤���ˤf����A�ˤf�@�ɦ�y����...�I\n"NOR,victim);
  victim->apply_condition("blooding", victim->query_condition("blooding")+2);
  return;
}