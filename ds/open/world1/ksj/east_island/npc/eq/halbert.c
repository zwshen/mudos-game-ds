#include <weapon.h>
inherit FORK;

void create()
{
  set_name("片鐮", ({"halbert" }) );
  set_weight(3500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "有著大小兩隻槍刃的長槍。\n");
    set("value",1200);
    set("volume",4);
    set("material","steel");
  }
  init_fork(30,TWO_HANDED);
  setup();
}
