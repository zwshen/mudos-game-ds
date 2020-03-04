
inherit ITEM;
inherit F_PILL;
#include <ansi.h>

void create()
{

        set_name(HIW"¶W°·±d¯Àºê"NOR, ({ "wit zong zi", "zong", "zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Áû");
                set("value", 10);  
        }
}
