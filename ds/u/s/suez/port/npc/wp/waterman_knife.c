#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("水手小刀",({"waterman knife","knife"}) );
        set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
         set("long","水手在船上常用的工具，也可以拿來防身。\n");
         set("material","iron");
         set("unit","把");
         set("value",300);
        }
        set("wield_msg","$N手上一晃，拿起了一把$n當武器。\n");
        init_dagger(5);
        setup();        
}

