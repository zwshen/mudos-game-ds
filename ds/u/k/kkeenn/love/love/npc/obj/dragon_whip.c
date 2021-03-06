#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;
void create()
{
  set_name(HIC"龍王鞭"NOR , ({ "dragon king whip","whip" }) );
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條通體不由自主散發出一股霸氣的鞭子，傳說是\n蓮池仙尊大戰青眼白龍時，以青龍之眼加持的鞭子。\n");
    set("material", "gold");
    set("value",9500);
    set("weapon_prop/str",2);
    set("weapon_prop/con",1);
    set("weapon_prop/dex",1);
  }
        set("replica_ob", __DIR__"whip5.c");
        set("wield_msg","$N一拍纏繞在腰間的$n，煞那間一股強烈的霸氣從$N的身上狂湧出來！\n");
        set("unwield_msg", "$N隨手一抖，將手中的$n纏回腰間。\n");
  init_whip(70);
  setup();
}
void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("whip") > 50 && me->query_dex() > 20 && random(10)<3 )
    {
      message_vision(HIG "\n忽然$N手中龍王鞭大放異彩, 一道強烈的青光從龍眼爆射而出, 擊向敵人！！\n" NOR,me,victim);
      damage += me->query_skill("whip")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N不知如何反應, 被青光射著正中！\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N回身一避, 恰好避開了那致命的青光。\n"NOR,victim);
    }
    return;
}

