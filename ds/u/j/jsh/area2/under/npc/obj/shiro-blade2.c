#include <weapon.h> 
#include <ansi.h>
inherit BLADE; 
void create()
{
        set_name("鐵紙刀", ({ "iron_paper blade" , "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", "一把塊鐵，敲成像紙一樣的薄，看起來蠻鋒利的。\n");
                set("value", 1000);
        }
        init_blade(35);
        setup();
}

