#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(YEL"狐皮"NOR"鎖鏈甲",({"fox armor","armor"}));
  set("long", @LONG  
一件用許多狐狸皮所製成的戰甲，外頭又加上了鎖鏈以彌補本身
狐皮所不足的防禦力•防禦力會因製作人的不同而有所改變•
LONG);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",10000);
    set("material","fur");
  }
  set("limit_lv",15);
  set("armor_prop/armor",38+random(4));
  set("armor_prop/shield",10); 
  set("armor_prop/dex",-1);
  set("armor_prop/str",3);
  setup();
}

