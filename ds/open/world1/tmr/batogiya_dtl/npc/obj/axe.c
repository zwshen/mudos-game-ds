#include <weapon.h>

inherit F_AXE;

void create()
{
    set_name("哈粒剝落斧", ({ "ha lipoluo axe", "axe" }) );
    set_weight(2000);
    setup_axe(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"axe"}));
        set("unit", "把");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "一把哈哈村特製的短斧，上頭還刻畫著一個笑臉，十分有趣。\n");
    }
    setup();
}
