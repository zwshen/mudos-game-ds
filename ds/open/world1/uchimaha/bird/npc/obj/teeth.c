#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"九尾的牙"NOR,({ "fox teeth","teeth" }));
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","從九尾身上脫落下的牙。\n");
                set("unit","個");
                set("value",100);
        }
        setup();
}
