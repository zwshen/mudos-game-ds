#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"鐵球"NOR,({ "iron ball","ball" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一顆圓滾滾的"+this_object()->name()+"，源於紫陽山腳下的溪流。\n");
                set("unit","顆");
                set("value",360);
        }
        setup();
}

