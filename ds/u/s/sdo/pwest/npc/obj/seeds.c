#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("从贺", ({"seeds" }) );
        set("long", 
"采采从贺\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "采");
        }
        setup(); 
}