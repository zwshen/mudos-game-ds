#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIY"刺蝟皮"NOR,({"hedgehog skin","skin"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","刺蝟的外皮，是用來製成上等皮甲的好材料。");
    set("value",500);
  }
  setup();
}