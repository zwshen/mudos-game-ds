#include <armor.h>
inherit SHIELD;
#include <ansi.h>
void create()
{
  set_name(MAG"鬼"HIR"血"HIC"盾" NOR,({ "Dreamcast shield","shield" }) );
  set("long",@LONG
這是用邪鬼"道魔"的血作成的盾
LONG
);
  set_weight(3500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "面");
    set("value",2000);
  }
  setup();
}



