#include <ansi.h> 
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIY"��s"NOR, ({ "beer" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�j�M��s�A�i�H���H�P��M�D�C\n");
                set("unit","�M");
        }
        set("value",100);
        this_player()->add("talk_point",10); 
        set("water_remaining",1);
        setup();
}
