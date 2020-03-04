inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("Âû³J", ({ "hen's egg", "egg" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Áû");
        }
}
