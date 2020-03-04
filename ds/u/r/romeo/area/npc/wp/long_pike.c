#include <weapon.h>

inherit LANCE;

void create()
{
        set_name("³P¸Æ¦åºj",({"cassock-blood-pike","lance"}) );
        set("long","³o¬O¤@§â¦³¨â¤Vªøªººj¡A¦bºj¤W¥i¥H¨£¨ì¤@¬V¦åªº³P¸Æ¡A¤£ª¾¹D¦³¦;
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","§â");
                    set("material", "crimsonsteel");
      set("value",1900);
        }
          init_blade(9);
        setup();
}
