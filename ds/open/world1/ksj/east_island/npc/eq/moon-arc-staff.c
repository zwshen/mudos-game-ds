#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() 
{
  set_name("月牙杖",({"moon-arc staff","staff"}));
  set("long",@LONG
杖頭為月牙形鐵刃的長杖。
LONG
);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",30);
    set("unit", "把");        
    set("value",2000);
    set("volume",5);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_staff(50);
  setup();
}
