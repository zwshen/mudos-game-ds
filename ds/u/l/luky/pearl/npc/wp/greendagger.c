#include <weapon.h>

inherit DAGGER;
void create()
{
set_name("綠晶匕首",({"green dagger","dagger"}));
set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","這是一把墨綠色的匕首﹐握在手上感覺十分輕巧。\n");
//set("limit_sk",12);
set("dagger",30);
set("value",3500);
set("material","gem");
init_dagger(240);
}
setup();
}
