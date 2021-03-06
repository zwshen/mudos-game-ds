#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIM"桃"HIC"風"HIM"惑"HIC"劍"NOR, ({ "peach-wind sword","sword" }) );
  set("long",@long
劍刃呈現漂亮的水藍色，不知是何材質做成，劍柄與劍鞘則是桃木製
成，上面雕刻有精細的桃林春風圖，據說此劍是桃花神所配帶。
long);      
  set_weight(1850);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",8000);
    set("volume",4);
    set("limit_skill",30);
    set("limit_lv",35);
  }
  set("weapon_prop/str",-2);
  init_sword(52);
  set("wield_msg","$N拔出腰間的$n，炫爛的劍光使人神迷。\n"NOR);
  set("unwield_msg","$N挽個劍花，輕巧地將$n收回劍鞘中。\n");
  setup();
}

void attack(object me, object victim)
{
  int be_busy;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_sou() > 2 && !random(7))
  {
    message_vision(HIM"\n桃風惑劍的劍芒幻化成一朵朵桃花，在$n"HIM"的四周旋轉飛舞。\n"NOR,me,victim);
    be_busy=me->query_sou();
    if (be_busy > 5) be_busy=5;
    message_vision("$N"HIR"目光呆滯陷入迷夢之中！！\n"NOR,victim);
    victim->add_busy(random(be_busy));
  }
  return;
}
