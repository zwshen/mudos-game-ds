#include <weapon.h>
inherit AXE;

void create()
{
        set_name("鋼斧",({"steel axe","axe"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long",@LONG
這一把伐木用的斧頭，為了兼顧耐用性，所以斧柄的地方也用鋼製成的，相當的沉重。
LONG);
                set("limit_str",20);
        }
        init_axe(25);
        setup();
        set("value",2500);
        set("volume", 8);
}

