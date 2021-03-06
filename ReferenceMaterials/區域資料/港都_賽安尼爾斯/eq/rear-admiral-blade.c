#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit BLADE;

void create()
{
  set_name(HIY"少將指揮刀"NOR, ({ "rear admiral blade","blade" }) );
  set("long",@long
海軍少將專用的軍刀，刀刃堅韌而殺傷力強，刀柄與刀鞘則有華麗的
墬飾及寶石。
long);      
  set_weight(3500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",15000);
    set("volume",3);
    set("rigidity",700);
  }
  set("limit_skill",50);
  set("limit_level",30);
  set("weapon_prop/str",3);
  set("weapon_prop/hit",3);
  init_blade(55);
  setup();
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->query("id") != "rear admiral") return;
  if( !random(7) )
  {
    message_vision(HIR"$N殺得性起，對著$n一陣連續猛攻！\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    me->start_busy(2);
  }
  return;
}