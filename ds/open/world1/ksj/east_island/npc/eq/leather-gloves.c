#include <armor.h>
inherit HANDS;

void create()
{
  set_name("荒革手袋",({"leather gloves","gloves"}) );
  set("long",@LONG
皮革製成的手套，柔軟而且有不錯的防護力。
LONG);
  set_weight(600); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");       
    set("value",500);          
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("armor_prop/armor",4);       
  setup();
}
