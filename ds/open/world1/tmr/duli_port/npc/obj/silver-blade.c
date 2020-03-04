#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("白銀短刀", ({ "silver blade", "blade" }) );
        set_weight(3500);
        setup_blade(2, 10, 60, 3);

        if( !clonep() ) {
                set("wield_as", ({"blade","secondhand blade"}));
                set("unit", "把");
                set("value", 1000);
                set("rigidity", 25);
                set("apply_weapon/blade", ([
                        "attack":5,
                ]));
                set("apply_weapon/secondhand blade", ([
                        "attack":5,
                ]));
                set("long", 
        "這是一把純銀打造的短刀，摸起來非常堅固，刀鋒也是非常銳利。\n"
                );
        }
        setup();
}

