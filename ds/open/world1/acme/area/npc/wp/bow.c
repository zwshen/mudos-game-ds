#include <weapon.h>
inherit BOW;
void create()
{
   set_name("長弓",({"long bow","bow"}));
   set("long","這是一把獵人常使用的長弓，若身上有箭，可用(shoot)射出箭。\n");
   set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",200);
set("volume",2);
                set("material","wood");
}
               set("limit_int",6);
               set("limit_dex",6);
               set("limit_str",4);
       init_bow(10);
       setup();
}

