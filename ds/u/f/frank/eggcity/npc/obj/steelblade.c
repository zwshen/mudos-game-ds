#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("鋼刀", ({ "steel blade","blade" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "  一把用鋼注造的刀子，十分的笨重，不過用來卻得心應手。\n");
                set("material", "steel");
                set("value",7000);
         }
    init_blade(20);
    setup();
}


