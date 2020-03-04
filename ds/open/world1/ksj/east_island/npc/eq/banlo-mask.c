#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name("般若鬼面"NOR,({"banlo mask","mask"}) );
  set("long",@LONG
仿般若臉型之面具，兇惡的鬼臉可以恫嚇敵人。
LONG);
  set_weight(900); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");       
    set("value",500);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",2);
  set("armor_prop/con",1);
  set("armor_prop/hit",3);
  setup();
}
