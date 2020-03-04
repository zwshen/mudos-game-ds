#include <armor.h>
inherit HEAD;
void create()
{
        set_name("炫光之盔", ({ "light helmet","helmet" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一個純電子製成的頭盔。\n");
                set("unit", "件");
                set("material", "silver");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1000);          
                set("wear_msg", "$N把四周的電子凝聚於脖子上, 好像有東西在保護$N的大頭\n");
                set("unequip_msg", "$N的電力不足, $n突然消失了。\n");
           }
        set("armor_prop/dodge",1);
        set("armor_prop/armor",7);
        setup();
}

