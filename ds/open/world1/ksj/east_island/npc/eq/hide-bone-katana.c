#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(MAG"惡鬼刀"HIR"•"NOR""GRN"骨葬"NOR, ({ "hide-bone katana","katana" }) );
  set("long",@long
傳說惡鬼把掠奪來的名刀刀刃以人骨為刀柄及刀鞘，製成這把惡鬼刀
，由於處於邪惡污穢的環境中，刀刃漸漸帶有邪氣，成為令人畏懼的
邪刀，刀身中潛藏怨念及暴戾的力量。
long);      
  set_weight(2550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",5);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",42);
  set("weapon_prop/str",3);
  set("weapon_prop/int",-3);
  set("weapon_prop/bio",1);
  set("weapon_prop/bar",-1);
  set("replica_ob",__DIR__"peach-wind-sword");
  init_blade(67);
  set("wield_msg",HIC"$N拔出腰間的$n，渾然不覺面目變得猙獰邪惡。\n"NOR);
  set("unwield_msg","$N將手中的$n收回刀鞘，只覺得心情輕鬆不少。\n");
  setup();
}


void attack(object me, object victim)
{
  int damage,def;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_bio() > 7 && random(10)<3 )
  {
    message_vision(MAG"\n惡鬼刀•骨葬刀刃的邪氣大盛，散發出深綠的鬼氣，$N"MAG"突然被一股怨\n"
      +"恨的感覺充斥腦中，臉色猙獰地將惡鬼刀•骨葬斬向$n。\n"NOR,me,victim);
    damage += me->query_skill("blade")+me->query_str()+random(100);
    damage = damage/3;
    message_vision("$N"HIR"中刀處疼痛不堪，流出紫色血液！！("+damage+")\n"NOR,victim);
    victim->receive_damage("hp",damage, me);
    victim->apply_condition("blooding",victim->query_condition("blooding")+(random(2)+1));
    victim->apply_condition("poison",victim->query_condition("poison")+(random(2)+1));
  }
  return;
}
