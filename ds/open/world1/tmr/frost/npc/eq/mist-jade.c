#include <armor.h>

inherit WAIST;

void create()
{
        set_name("霄佑符",({"mist jade","jade"}) );
        set("long","一枚用白玉雕琢而成的玉佩，上頭還刻有雲霧深山的美景。\n");
        set_weight(200);
        set("unit","枚");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","枚");
                set("value",500);           
                set("material","jade");
                set("armor_prop/armor",4);
        }
        setup();
}

