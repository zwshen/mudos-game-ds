#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
  set_name(YEL"狐皮"NOR"衣",({"fox cloth","cloth"}));
  set("long", @LONG 
一件用部份狐狸皮所作成的服飾，摸起來十分的柔軟，防禦力會
因製作人的不同而有所改變•
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",4000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",14+random(4));
  set("armor_prop/shield",7); 
  set("armor_prop/dex",2);
  setup();
}

