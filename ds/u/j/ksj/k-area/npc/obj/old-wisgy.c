#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIB"朝б"NOR, ({ "old-wisgy","wisgy" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","甤禥壁┮都都珇基ぃぷㄤ琌朝基蔼\n");
                set("unit","狹");
        }
        set("value",350);
        set("heal_ap",60);
        set("water_remaining",3);
        setup();
}

