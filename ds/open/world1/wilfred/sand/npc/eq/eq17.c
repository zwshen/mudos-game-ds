#include <ansi.h>
#include <armor.h>
inherit WRISTS;
void create()
{
  set_name(WHT"銀鐲"NOR ,({ "silver wrists","wrists" }) );
  set("long","這是一個銀製的手鐲，閃閃發光，令人愛不釋手。");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",1);
    set("unit", "個");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

int query_autoload() { return 1; }
