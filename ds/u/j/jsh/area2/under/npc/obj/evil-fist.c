#include <weapon.h> 
#include <ansi.h>
inherit FIST; 
void create()
{
        set_name(MAG"紫山鳶"NOR, ({ "perple fist" , "fist" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把");
                set("long", MAG"天魔在紫山時所造之爪，故以山名為其命名。\n"NOR);
                set("value", 10000);
        }
        init_fist(40);
        setup();
}

