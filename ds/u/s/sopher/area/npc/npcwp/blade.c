#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
      set_name(HIW"°f"HIR"¤b"HIW"¤M"NOR, ({ "blade" }) );
      set_weight(1000);
      if( clonep() )
      set_default_object(__FILE__);
      else {
             set("unit","§â");
             set("value",10000);
             set("material","steel");
        }
       init_blade(400);
       
       setup();
}    
