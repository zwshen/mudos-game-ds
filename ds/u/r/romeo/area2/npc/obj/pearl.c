inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR "火龍珠"NOR, ({ "pearl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一顆由千年火龍所煉製的夜光珠，其中好像還有什麼;
                set("unit", "顆");
                set("value",100);
        }
        set_temp("has_light",1);        //發光.
        setup();
}
