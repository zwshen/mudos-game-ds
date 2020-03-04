inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("«C±ö", ({ "green plum", "plum" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¥÷");
        }
}
