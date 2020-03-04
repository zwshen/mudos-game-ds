#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name(HIY"金蔘補"NOR, ({ "ginseng pill","pill" }));
  set("long",
      "以千年人蔘熬製的藥丹，可以補充血氣，回復精神。\n"
     );
  set_weight(600);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
  }
  set("value", 5000);
  set("heal",([
      "hp": 2000,
      "ap": 1500,
      "mp": 1500,
     ]));
  setup();
}
