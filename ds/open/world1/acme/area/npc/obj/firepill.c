
#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "火紅內丹" NOR, ({ "fire-red pill","pill"}));
        set("long",@LONG
這是一顆火紅色的丹藥，不斷發出熾熱的高溫。
LONG
        );
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eat_msg","$N吃下一顆火紅內丹。\n");
                set("eff_msg", HIR "你感到從腹中激發一股赤流，擴散到全身。\n" NOR );
        }
        set("value",2000);
        set("heal",([
         "ap" : 500,
         "mp" : 500,
         "hp" : 2500,
         ]));
        setup();
}

