#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(HIC"海神護面"NOR,({"leviathan mask","mask"}) );
  set("long",@LONG
大海蛇  利貝亞森額上的鱗皮製成的面具，整副面具呈現湛藍色，光
滑的表面藍光流轉，就像海浪般閃爍波光。
LONG);
  set_weight(500); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_level",25);
    set("unit", "個");       
    set("value",20000);          
    set("volume", 2);                       
    set("material", "gold");   
  }
// 2003.3.30 新增 lv限制 by ksj
  set("limit_lv",40);
  set("armor_prop/armor",4);
  set("armor_prop/shield",10);
  set("armor_prop/hit",5);
  set("armor_prop/dodge",5);       
  set("armor_prop/int",2);
  set("armor_prop/dex",2);
  set("armor_prop/tec",1);
  set("armor_prop/bar",-1);
  setup();
}
