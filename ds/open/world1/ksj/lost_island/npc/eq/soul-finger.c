#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIC"清靈之戒"NOR,({"soul finger","finger"}));
  set("long", @LONG
純白水晶鑲在純銀戒座，當光線反射時可以看到水晶中央浮現閃亮的
十字架，這是古代某位聖者的遺物。
LONG
);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "只");
    set("volume",1);
    set("value",5000);
    set("material","stone");
  }
  set("armor_prop/armor",1);
  set("armor_prop/shield",10);
  set("armor_prop/sou",1);
  set("armor_prop/bar",-1);
  setup();
}
