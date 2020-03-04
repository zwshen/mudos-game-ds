#include <weapon.h>

inherit F_SWORD;

void create()
{
    set_name("哈粒剝落劍", ({ "ha lipoluo sword", "sword" }) );
    set_weight(2000);
    setup_sword(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"sword"}));
        set("unit", "把");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "一把哈哈村特製的短劍，上頭還刻畫著一個笑臉，十分有趣。\n");
    }
    setup();
}
