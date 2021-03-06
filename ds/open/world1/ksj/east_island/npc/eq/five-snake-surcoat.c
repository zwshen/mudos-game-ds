#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(GRN"五頭蛇披風"NOR,({ "five snakes surcoat","surcoat" }) );
  set("long",@LONG
蛇皮製成的披風，披風下擺還帶著五個不同顏色的蛇頭。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1300);
    set("material", "fur");
    set("unit", "件" );
    set("value",3000);
    set("volume",2);
    set("wear_msg",
        HIG"$N披上一張帶五個蛇頭的蛇皮，渾身繚繞著邪氣。\n"NOR);
  }
  set("limit_lv",30);
  set("armor_prop/armor", 12);
  set("armor_prop/shield", 13);
  set("armor_prop/con", 2);
  set("armor_prop/wit", 1);
  set("armor_prop/bio", -1);
  setup();
}
