#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("感謝信", ({"letter" }) );
        set("long", 
"是雷恩太太為了感謝你，而幫你寫的一封信。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "封");
        }
        setup(); 
}