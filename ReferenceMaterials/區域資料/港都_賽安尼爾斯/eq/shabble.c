#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit BLADE;

void create()
{
  set_name("�x�M"NOR, ({ "shabble","blade" }) );
  set("long",@long
�M���Ӫ��s���A�M�`ô�����⪺�M�J�A�O�x�x�H���Z���C
long);      
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "steel");
    set("value",3000);
    set("volume",2);
    set("weapon_prop/str",1);
  }
  init_blade(40);
  setup();
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->query("id") != "marine guard") return;
  if( !random(7) )
  {
    message_vision(HIR"$N����򴤭x�M�A�W�O�ǳƤ@���I\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),4);
    me->start_busy(2);
  }
  return;
}