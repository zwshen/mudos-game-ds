#include <weapon.h>

inherit LANCE;

void create()
{
        set_name("袈裟血槍",({"cassock-blood-pike","lance"}) );
        set("long","這是一把有兩丈長的槍，在槍上可以見到一染血的袈裟，不知道有�;
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
                    set("material", "crimsonsteel");
      set("value",1900);
        }
          init_blade(9);
        setup();
}
