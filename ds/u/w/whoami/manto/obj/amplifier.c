inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIY"９８０２型無線擴音器"NOR, ({ "an amplifier", "amplifier" }));
set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
else
  {
   set("unit", "隻");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
}
  setup();
}

void init()
{
  add_action("do_use","use");
}
