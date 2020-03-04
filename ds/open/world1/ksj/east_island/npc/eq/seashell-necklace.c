#include <armor.h>
inherit NECK;

void create()
{
  set_name("扇貝頸飾",({"seashell necklace","necklace"}) );
  set("long",@LONG
用幾個紅色貝殼串成的項鏈，手工並不精巧。
LONG);
  set_weight(30); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "串");
    set("light",0);       
    set("value",100);          
    set("volume", 1);                       
    set("material", "blacksteel");
  }
  set("armor_prop/armor",1);       
  setup();
} 
