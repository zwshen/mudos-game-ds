// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit PANTS;

void create()
{
        set_name("哈薩克襖裙", ({ "hasake skirt", "skirt"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "這是一件織著紅花綠草的襖裙, 哈薩克女孩常穿的衣著。\n");
                set("armor_prop/armor", 3);
                set("value", 500);
        }
        setup();
}

