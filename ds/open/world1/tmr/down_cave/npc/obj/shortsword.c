#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("短劍", ({ "short sword", "sword" }) );
        set_weight(2000);
        setup_sword(1, 14, 75, 5);

        if( !clonep() ) {
                set("wield_as", ({"sword","secondhand sword"}));
                set("unit", "把");
                set("value", 300);
                set("rigidity", 10);
                set("long", "一把鐵製的短劍，是一般旅人的基本防身武器。\n");
        }
        setup();
        /* 殊特sword */
        set("name",
                ENHANCE_D->enhance_weapon(this_object(),0,"短劍") );
}

