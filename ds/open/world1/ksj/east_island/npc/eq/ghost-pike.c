#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit FORK;

void create()
{
  set_name(HIC"魂槍"NOR, ({ "ghost pike","pike" }) );
  set("long",@long
鬼魂怨氣所聚合成的長槍，看起來朦朦霧霧，虛渺不實。
long);      
  set_weight(10);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "steel");
    set("value",0);
    set("volume",0);
  }
  set("weapon_prop/sou",1);
  set("weapon_prop/hit",10);
  set("weapon_prop/dex",2);
  init_fork(30,TWO_HANDED);
  setup();
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->query("id") == "warrior ghost")
  {
    if( !random(9) )
    {
      message_vision(HIR"$N雙眼通紅，奮力對著$n一擊！\n"NOR,me,victim);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),4);
      me->start_busy(2);
    }
    else if( !random(9) )
    {
      message_vision(HIR"$N雙眼通紅，對著$n狂亂地攻擊！\n"NOR,me,victim);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      me->start_busy(2);
    }
  }
  else
  {
    call_out("dest_obj",30);
  }
  return;
}

void dest_obj()
{
  message_vision("\n$N"HIW"化為煙霧飄散在空中。\n\n"NOR,this_object());
  destruct(this_object());
}
