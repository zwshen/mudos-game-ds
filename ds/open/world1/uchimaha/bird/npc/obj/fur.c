#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"八歧大蛇的皮"NOR,({ "snake fur","fur" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","從八歧大蛇身上所撕下來的皮。\n");
                set("unit","張");
        }
        setup();
}
