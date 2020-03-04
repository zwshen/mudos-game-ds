#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("木刀", ({ "wood blade","blade" }) );
        set_weight(3000);
        setup_blade(1,8,40,4);

        if( !clonep() ) {
                set("wield_as", ({"blade","twohanded blade"}));
                set("unit", "把");
                set("value", 350);
                set("rigidity", 30);
                set("long", 
"這是一把小木刀，想拿來防身還稍嫌不足。\n"
                );
        }
        setup();
}

