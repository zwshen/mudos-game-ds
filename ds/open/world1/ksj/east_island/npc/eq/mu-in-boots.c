#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(WHT"霧隱"CYN"足具"NOR, ({ "mu-in boots","boots" }) );
  set("long",@LONG
一雙設計特殊的皮革短靴，靴子內部裝有精密的機關，能將吸收到的
水份蒸發為水蒸氣，一方面增加彈力，一方面可以稍微隱蔽身形。
LONG);
  set_weight(1300);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");
    set("material","leather");
    set("value",2500);
    set("armor_prop/dex",1);
    set("armor_prop/dodge",5);
    set("armor_prop/armor", 6);
  }
  setup();
}
