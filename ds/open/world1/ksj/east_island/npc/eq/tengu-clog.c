#include <armor.h>
inherit BOOTS;

void create()
{
  set_name("天狗木屐", ({ "tengu clog","clog" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一雙跟部特高的木屐，穿起來使人高人一等。\n");
    set("unit", "雙");
    set("material","wood");
    set("value",500);
  }
  set("armor_prop/con",1);
  set("armor_prop/armor", 3);
  setup();
}
