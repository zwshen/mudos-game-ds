#include <weapon.h>
inherit FORK;
void create()
{
        set_name("長槍",({"long pike","pike"}) );
        set("long","一把隨處可見的長槍，是軍人的配件之一。\n");
          set_weight(7000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","桿");
        set("value",1000);
        set("volume",4);
        set("material","iron");
        init_fork(25);
   	}
        setup();
}

