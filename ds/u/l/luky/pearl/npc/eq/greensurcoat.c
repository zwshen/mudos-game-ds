#include <armor.h>

inherit SURCOAT;

void create()
{
set_name("綠晶外套",({"green surcoat","surcoat"}) );
set("long","這是一件綠色的外套, 手工十分精巧。\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "件");
set("value",1800);
//set("armor_prop/armor",12);
set("limit_lv",50);
        }
        setup();
}
