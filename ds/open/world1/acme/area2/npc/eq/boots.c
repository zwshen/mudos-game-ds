#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("飄雪靴" ,({ "snow boots","boots" }) );
        set("long","這是一雙輕飄飄的長靴，一塵不染，白如皓雪。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "linen");
        set("unit", "個" );
        set("value",1250);
		set("volume",2);
        set("armor_prop/armor", 3);
        set("limit_con",6);
        set("armor_prop/dex", 2);
        }
        setup();
}
