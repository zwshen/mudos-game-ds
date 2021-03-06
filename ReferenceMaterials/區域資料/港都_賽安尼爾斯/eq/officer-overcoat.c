#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(HIY"高階"CYN"軍官大衣"NOR,({ "officer overcoat","overcoat" }) );
  set("long","海軍將級軍官配備的大衣，華麗而英挺。\n");
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(2500);
    set("material", "leather");
    set("unit", "件" );
    set("value",12000);
    set("volume",2);
    set("wear_msg",
        "$N將一件英挺的$n披在肩上，顯得氣勢不凡。\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 5);
  set("armor_prop/tec", -1);
  set("armor_prop/bar", 1);
  setup();
}