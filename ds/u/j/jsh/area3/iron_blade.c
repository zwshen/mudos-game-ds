#include <ansi.h>
#include <weapon.h>  
inherit BLADE; 
void create()
{
        set_name(WHT"鐵刀"NOR, ({ "iron blade" , "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", "一把用鐵鑄成的刀。\n");
                set("value", 3000);
        }
        init_blade(50);
        setup();
}

