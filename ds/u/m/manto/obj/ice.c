inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(YEL"©@°Ø¦B"NOR, ({ "coffee ice" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸J");
                set("value", 10);  
                set("food_remaining",2);
        }
}
