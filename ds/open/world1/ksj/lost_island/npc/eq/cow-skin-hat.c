#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name("刺牛皮盔",({"cow-skin hat","hat"}) );
  set("long",@LONG
用一種上面長有尖刺的牛皮製成的頭盔，防護力還不錯。
LONG
);
  set_weight(1000); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",10);
    set("unit", "頂");       
    set("value",5000);          
    set("volume", 3);                       
    set("material", "leather");   
  }
  set("armor_prop/armor", 8);
  set("armor_prop/damage",3);
  setup();
}
