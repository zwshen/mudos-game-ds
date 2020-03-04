#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("斧頭", ({ "axe" }) );
        set_weight(5500);
        setup_axe(3, 8, 80, 0);

        if( !clonep() ) {
                set("wield_as", ({"axe","twohanded axe"}));
                set("unit", "把");
                set("value", 800);
                set("rigidity", 80);
                set("long", 
"這是一把斧面頗大的斧頭，堅實的握柄更增添幾份穩重。\n"
                );
        }
        setup();
}

