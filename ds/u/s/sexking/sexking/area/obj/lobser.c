#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"龍蝦"NOR,({ "lobser","lobser" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一隻活跳跳的龍蝦..看起來很好吃的樣子。\n");
                set("unit","隻");
                set("value",100);
        }
        setup();
}

