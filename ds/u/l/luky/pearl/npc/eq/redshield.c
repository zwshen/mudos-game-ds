#include <armor.h>

inherit SHIELD;

void create()
{
set_name("赤紅盾牌",({"red shield","shield"}) );
set("long","這是由熟鐵製成的紅色圓盾, 十分堅硬。\n");
set_weight(3600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","steel");
set("unit", "面");
set("value",4960);
//set("armor_prop/defense",1);
set("limit_lv",50);
//set("armor_prop/armor",72);
 }
setup();
}
