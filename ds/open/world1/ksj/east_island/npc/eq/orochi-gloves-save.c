#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
   set_name(HIR"真"HIW"•"NOR"八歧"HIR"鱗手"NOR,({"orochi gloves","gloves"}));
  set("long", @LONG
八歧大蛇的鱗皮製成的手套，手套上銳利的逆鱗增加些許的傷害力。
LONG);
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "對");
    set("volume",2);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",35);
  set("armor_prop/armor",13);
  set("armor_prop/shield",13);
  setup();
}

int query_autoload() { return 1; }
