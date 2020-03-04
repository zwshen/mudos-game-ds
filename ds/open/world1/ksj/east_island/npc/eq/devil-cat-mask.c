#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
   set_name(HIG"妖貓面"NOR,({"devil cat mask","mask"}) );
  set("long",@LONG
貓妖的臉皮製成的面具，具有強大的妖力。
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("limit_lv",40);
    set("unit", "張");       
    set("value",50000);          
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("armor_prop/armor",3);
  set("armor_prop/int",3);
// save eq 不適合加merits -tmr 2007/04/10
//   set("armor_prop/wit",1);
//    set("armor_prop/bar",-1);

  setup();
}

int query_autoload() { return 1; }
