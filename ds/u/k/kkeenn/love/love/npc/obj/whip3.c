#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("軟鞭" , ({ "soft whip","whip" }) );
  set_weight(1550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "一條十分柔軟的鞭子。\n");
    set("material", "silver");
	set("value", 2700);
    set("weapon_prop/dex",1);
  }
  init_whip(22);
  setup();
}

