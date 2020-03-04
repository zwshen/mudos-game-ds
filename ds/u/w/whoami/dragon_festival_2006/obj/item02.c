inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("บ๊รท", ({ "zong string", "string" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ฎฺ");
                set("value", 10);  
        }
}
