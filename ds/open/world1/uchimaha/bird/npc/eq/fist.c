#include <weapon.h>
inherit FIST;

void create()
{
    set_name("鷹爪",({"eagle claw","claw"}) );
   set("long","一個老鷹的爪子。\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","個");
        set("material", "leather");
      init_fist(20);
   }
setup();
}
