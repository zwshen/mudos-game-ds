#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIR"¯ó²ù³J¿|"NOR, ({ "berry cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"¤@­Ó¦³¿@­§¯ó²ù­»¨ýªº¯ó²ù³J¿|\n"NOR);
                set("unit", "­Ó");
                set("value", 10);
                set("food_remaining",6);
                set("heal_hp",30);
        }
}
