#include <armor.h>
inherit HANDS;
void create()
{
  set_name("熊掌" ,({ "bear gloves","gloves" }) );
  set("long","巨熊的手掌，光看這熊掌的大小，就知道被它打到可是會死人的。");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("volume",2);
    set("unit", "雙");
    set("value",2000);
  }
  set("armor_prop/armor",7);
  set("beast_armor_prop/armor",7);
  set("limit_con",12);
  setup();
}
