
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name( "白金" ,({"platinum"}));
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","就是白色的黃金，硬度較黃金高，成份以鉑為主，是種昂貴的金屬。");
    set("value",10000);
  }
  setup();
}

