#include <weapon.h>
inherit BLADE;
void create()
{
  set_name( "精鋼砍刀" , ({ "steel blade","blade" }) );
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是一把厚重堅實的精鋼砍刀。\n");
    set("material", "iron");
    set("value", 1500);
    set("volume",1);
  }
  init_blade(30);
  setup();
}

