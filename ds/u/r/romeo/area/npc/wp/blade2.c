#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("大般若",({"bo-yeah-blade","blade"}) );
        set("long","這是一把精剛打造的刀，只見刀柄上以金絲繡著『般若』兩個古字。。\n");
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
