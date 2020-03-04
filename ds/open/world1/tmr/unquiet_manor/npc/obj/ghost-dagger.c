#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name(HIW"冰霜流星錘"NOR,({"frost hammer","hammer"}) );
  set("long","一枝巨大的冰霜流星錘，由白金打造而成，上面佈滿尖銳的鐵刺，沾著不少血跡跟碎肉。\n");
  set_weight(35000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","枝");
    set("volume", 4);
    set("value", 12000);
  }
  init_hammer(65);
    set("material","gold");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 4);
  set("weapon_prop/attack", 5);
  setup();        
}
