#include <armor.h>
inherit PANTS;
void create()
{
  set_name("強盜超嗆短褲" ,({ "bandits pants","pants" }) );
  set("long","一件短褲上面鏽滿了虎啊獅啊的花樣，看來十分的台客，不過深受強盜的喜愛。");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("volume",2);
    set("material", "leather");
    set("unit", "條");
    set("value",1200);
  }
  set("armor_prop/armor",15);
  setup();
}

