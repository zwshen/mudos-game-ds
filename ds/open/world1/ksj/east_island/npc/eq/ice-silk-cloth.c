#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
  set_name(HIW"冰雪絲衣"NOR ,({ "ice-silk cloth","cloth" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",@LONG
一件雪白的衣服，摸起來冰冰涼涼的，不知道是什麼材質製成的。
LONG);
    set("female_only",1);
    set("unit", "件");
    set("value",3500);
    set("material", "silk");
  }
      set("armor_prop/shield",20);
      set("armor_prop/int",3);
     set("armor_prop/armor", 5);
  setup();
}
