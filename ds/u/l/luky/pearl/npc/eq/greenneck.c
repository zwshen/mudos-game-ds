#include <armor.h>

inherit NECK;

void create()
{
set_name("綠晶項鍊",({"green necklace","necklace"}));
set_weight(1800);
set("long","這是一串美麗的項鍊。/n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit", "串");
set("value",1800);
//set("armor_prop/armor",1);          
set("limit_lv",45);
}
setup();
}
