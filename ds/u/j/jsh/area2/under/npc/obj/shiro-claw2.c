#include <weapon.h> 
#include <ansi.h>
inherit FIST; 
void create()
{
        set_name("短爪", ({ "short claw" , "claw" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", "普通的爪子，只是比平長的爪子還短了一點。\n");
                set("value", 1000);
        }
        init_fist(35);
        setup();
}

