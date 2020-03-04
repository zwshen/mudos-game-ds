#include <armor.h>

inherit BOOTS;

void create()
{
set_name( "ºñ´¹¹u",({"green boots","boots"}) );
set("long","¤@Âù°{°{µo«Gªººñ¦âÅK¹u¡C\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "Âù");
set("value",3600);
set("limit_lv",56);
//set("armor_prop/armor",49);
}
setup();
}
