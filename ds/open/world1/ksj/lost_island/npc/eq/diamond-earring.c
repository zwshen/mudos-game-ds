#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIW"鑽石耳環"NOR ,({ "diamond earring","earring" }) );
  set("long",@LONG
一對閃耀著璀燦光芒的耳環，鑲在耳環上的鑽石超過十克拉，價值
非凡。
LONG);
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("light",1);
    set("unit", "對");
    set("value",160000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",1);
  setup();
}
