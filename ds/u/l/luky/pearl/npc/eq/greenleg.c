#include <armor.h>

inherit LEGGINGS;

void create()
{
set_name("綠晶護腿",({"green leggings","leggings"}));
set("long","。\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "steel");
set("unit", "對");
set("value",1800);
set("armor_prop/dodge",1);
set("limit_lv",50);
//set("amount",3); //要賣要加這行
 }
setup();
}
