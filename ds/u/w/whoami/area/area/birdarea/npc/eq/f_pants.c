#include <ansi.h>
#include <armor.h>
inherit PANTS; 
void create()
{
  set_name(YEL"狐皮"NOR"褲",({"fox pants","pants"}));
  set("long", @LONG 
一條用狐狸的皮毛做出來的褲子，摸起來十分柔軟•防禦力會因
製作人的不同而有所改變•
LONG);
  set_weight(1100);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",4500);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",7+random(6)); 
  set("armor_prop/shield",8+random(4));
  set("armor_prop/dex",1);
  set("armor_prop/int",-2);
  set("armor_prop/str",2);
  setup();
}

