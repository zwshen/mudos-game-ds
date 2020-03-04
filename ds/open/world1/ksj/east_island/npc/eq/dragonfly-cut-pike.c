#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create()
{
  set_name(HIG"蜻蛉切"NOR, ({ "dragonfly-cut pike","pike" }) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_str",30);
    set("limit_skill",25);
    set("limit_lv",30);
    set("unit", "把");
    set("long", "據說蜻蜓一停在槍尖上就被切成兩半掉落，故得此名，是把難得的好\n"
                "槍。\n");
    set("value",10000);
    set("volume",5);
    set("material","blacksteel");
  }
  set("weapon_prop/hit",5);
  init_fork(60,TWO_HANDED);
  setup();
}
