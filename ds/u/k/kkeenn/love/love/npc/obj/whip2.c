#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("精鋼鞭" , ({ "gin whip","whip" }) );
  set_weight(1750);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條以精鐵混鋼煉製成的鞭子。\n");
    set("material", "silver");
	set("value", 2300);
    set("weapon_prop/con",1);
  }
  init_whip(18);
  setup();
}

