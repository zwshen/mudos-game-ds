#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIW"白葡萄酒"NOR, ({ "white-grape wine","wine" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","釀了好幾冬的白葡萄酒，對於活血，有很大的功\用。\n");
                set("unit","杯");
        }
        set("value",280);
        set("heal_hp",50);
        set("water_remaining",3);
        setup();
}
