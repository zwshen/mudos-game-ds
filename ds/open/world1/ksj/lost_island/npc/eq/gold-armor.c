#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIY"黃金鎧甲"NOR,({"gold armor","armor"}));
  set("long", @LONG
純金製成的鎧甲，相當沉重，通常是當作貴重的擺飾品。
LONG
);
  set_weight(25000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "副");
    set("volume",5);
    set("value",120000);
    set("material","gold");
  }
  set("armor_prop/armor",15);
  setup();
}
