#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIR"血不沾"NOR, ({ "blood-no-touch boots","boots" }) );
  set("long",@long
血不沾是一雙以朱紅蠶絲所編的長靴，外皮由於塗上層特殊的
防水藥物，可達到滴血不沾，另外穿著起來相當輕便靈活。
long);      
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");
    set("material","gold");
    set("value",2500);
  }
  set("armor_prop/dodge",10);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/armor", 5);
  setup();
}

