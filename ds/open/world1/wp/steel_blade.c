#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( "鋼刀" , ({ "steel blade","blade" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把鈍鈍的鋼刀, 似乎很重的樣子....。\n");
                set("material", "steel");
                set("limit_str",10);
        }
    set("weapon_prop/dex",-1);
    init_blade(17);
    setup();
}


