#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name("手甲鉤", ({ "climb claw","claw" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",20);
    set("unit", "對");
    set("long", "用四根鐵鉤連在鐵環上，手握於鐵環可以攻擊敵人，也可以用來攀牆。\n");
    set("value",1000);
    set("volume",3);
    set("material","steel");
  }
  init_fist(15,TWO_HANDED);
  setup();
}
