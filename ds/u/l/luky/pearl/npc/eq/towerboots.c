#include <armor.h>

inherit BOOTS;

void create()
{
set_name( "塔之長靴",({"tower boots","boots"}) );
set("long","一雙沉重的銅製長靴。\n");
set_weight(5800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "雙");
set("value",5800);
set("limit_lv",58);
//set("armor_prop/armor",49);
}
setup();
}
