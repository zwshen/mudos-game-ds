#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("單刀", ({ "blade" }) );
        set_weight(3500);
        setup_blade(1, 14, 60, 2);

        if( !clonep() ) {
                set("wield_as", ({"blade"}));
                set("unit", "把");
                set("value", 500);
                set("rigidity", 25);
                set("long", 
"這是一把鐵製的單刀，由於價格便宜，一般人都能買的到。\n"
                );
        }
        setup();
        /* 殊特blade */
        set("name",
                ENHANCE_D->enhance_weapon(this_object(),0,"刀") );
}

