#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"神風"HIR"袋"NOR, ({ "godwind bag","bag" }) );
        set_weight(600);
        set_max_capacity(400);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "這是一口大袋子，紅白相間，似乎有奇妙的魔力。\n");
                set("value",5000);
               }
        setup();
}

