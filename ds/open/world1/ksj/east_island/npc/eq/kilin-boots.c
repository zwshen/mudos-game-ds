#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIC"麒麟"HIW"步雲靴"NOR, ({ "kilin boots","boots" }) );
  set("long",@long
一雙雪白的長靴，以冰蠶絲編織而成，靴上以精巧繡工繡上一對威猛
的飛天麒麟，穿著起來相當輕便靈活。
long);      
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");
    set("material","gold");
    set("value",5000);
  }
  set("armor_prop/dodge",10);
  set("armor_prop/int",1);
  set("armor_prop/con",1);
  set("armor_prop/dex",2);
  set("armor_prop/armor", 15);
  setup();
}
