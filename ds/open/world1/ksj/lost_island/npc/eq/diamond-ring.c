#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIW"鑽石戒指"NOR ,({ "diamond ring","ring" }) );
  set("long",@LONG
一只閃耀著璀燦光芒的戒指，戒指上的鑽石有十幾克拉，價值非凡。
LONG);
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("light",1);
    set("unit", "只");
    set("value",150000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",1);
  setup();
}
