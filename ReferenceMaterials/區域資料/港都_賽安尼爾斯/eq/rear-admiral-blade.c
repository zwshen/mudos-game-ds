#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit BLADE;

void create()
{
  set_name(HIY"�ֱN�����M"NOR, ({ "rear admiral blade","blade" }) );
  set("long",@long
���x�ֱN�M�Ϊ��x�M�A�M�b���ӱ��ˤO�j�A�M�`�P�M�T�h�����R��
�P�����_�ۡC
long);      
  set_weight(3500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
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
    message_vision(HIR"$N���o�ʰ_�A���$n�@�}�s��r��I\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    me->start_busy(2);
  }
  return;
}