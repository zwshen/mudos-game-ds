#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("大刀", ({ "big blade", "blade" }) );
        set_weight(8000);
          setup_blade(2, 10, 120, 4);

        if( !clonep() ) {
                set("wield_as", ({"blade","twohanded blade"}));
                set("unit", "把");
                set("value", 500);
                set("rigidity", 30);
                set("long", 
"這是一把光刀鋒就長近半公尺的大刀，力量稍嫌不足的人，連拿都拿不動。\n"
                );
        }
        setup();
}

