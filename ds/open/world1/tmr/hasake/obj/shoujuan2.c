// bandage.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT"白手絹"NOR, ({ "white piece", "piece"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "方");
                set("material", "cloth");
                set("long", "這是一方雪白的手絹，上面有些字：
     跟著手絹上的圖案走，你就可以走出大戈壁。。。\n");               
        }
}
