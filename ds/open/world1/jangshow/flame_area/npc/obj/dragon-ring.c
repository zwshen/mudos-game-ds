#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIR"聖炎"HIY"轉龍戒"NOR,({"flame turn-dragon ring","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("long","一只散發著"HIR"火紅"NOR"光輝的戒指，為聖炎殿的寶物之一。\n"NOR);
    set("value",10000); 
    set_weight(1000); 
    set("material","diamond");
    set("unit","只");
  } 
    set("armor_prop/int",3);   
    set("armor_prop/dex",2);
    set("armor_prop/str",-2);
  set("armor_prop/armor",3);
  setup();
}

