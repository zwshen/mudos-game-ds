#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("小木斧", ({ "small wood axe", "axe" }) );
        set_weight(4000);
        setup_axe(1, 9, 120, 5);

        if( !clonep() ) {
                set("wield_as", ({"axe","secondhand axe"}));
                set("unit", "把");
                set("value", 250);
                set("rigidity", 30);
                set("long", "一把斧鋒有缺口的小木斧，握柄也有點腐壞了。\n");
        }
        setup();
}


