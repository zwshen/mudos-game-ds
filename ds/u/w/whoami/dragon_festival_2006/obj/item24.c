inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("³¯¥Ö", ({ "orange peel", "peel" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¥÷");
        }
}
