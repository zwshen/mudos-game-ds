#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name("夸父靴",({ "qua-foo-boots","boots" }) );
        set("long",
"這個靴子異常的大，也異常的重。上面以鐵皮鑲出夸父追日的傳說
。但是鐵皮已生了一層紅紅的鏽。是長年浸泡在血水中所造成的，不
過夸父追逐的太陽卻依然閃耀著金屬光澤。\n"
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "雙" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/int", -2);
        set("armor_prop/dex", 1);
        }
        setup();
}

