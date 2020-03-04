#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIY"黃金盾牌"NOR,({"gold shield","shield"}));
  set("long", @LONG
純金製成的盾牌，金光閃閃，相當沉重。
LONG
);
  set_weight(12000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "個");
    set("volume",4);
    set("value",57600);
    set("material","gold");
  }
  set("armor_prop/armor",10);
  setup();
}
