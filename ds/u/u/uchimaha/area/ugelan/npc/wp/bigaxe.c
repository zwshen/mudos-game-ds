#include <weapon.h>
inherit AXE;
void create()
{
        set_name("巨斧", ({ "big axe","axe" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這把巨斧是索蘭尼亞騎士的標準配備, 但是傷害力卻也不小。\n");
                set("material", "silver");
                set("limit_str",24);
             }
    set("weapon_prop/str",2);
    init_axe(60,TWO_HANDED);
    setup();
}
