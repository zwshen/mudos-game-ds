#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;
void create()
{
  set_name( HIR"血魔鞭"NOR , ({ "blood dream whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條通體不由自主散發出一股殺氣的鞭子，傳說是\n妙法仙尊大戰血魔時，以血魔之血煉過的鞭子。\n");
    set("material", "gold");
    set("value",8500);
    set("weapon_prop/str",2);
    set("weapon_prop/dex",2);
  }
        set("replica_ob", __DIR__"whip5.c");
        set("wield_msg","$N一拍纏繞在腰間的$n，煞那間一股強烈的殺氣從$N的身上爆發出來！\n");
        set("unwield_msg", "$N隨手一抖，將手中的$n纏回腰間。\n");
  init_whip(65);
  setup();
}

void attack(object me,object victim)
{
  int i;
  object *enemy;

  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(3)) return;
  if(me->query("ap") < 40) return;
message_vision(HIG"\n$N似乎是感應到了手中$n"HIG"的邪氣，一股殺意直湧心頭《分化攻擊》！\n\n"NOR,me,this_object());

  enemy = me->query_enemy();
  for(i=0;i<sizeof(enemy);i++)
  {
    if(userp(enemy[i])) COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"),4);
      else COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"),random(3)+2);
  }
  message_vision("\n",me);
  me->receive_damage("ap", 30, me);
  return;
}
