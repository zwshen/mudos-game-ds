#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIW"聖誕藥丸"NOR, ({ "X'mas pill","pill" }));
        set("long",@long
一顆看來十分雪白的藥丸，握在手裡隱隱帶有暖意。
long
        );
        set("weight", 200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "顆");
        set("value", 1);
        set("heal_hp",1000);      
        set("heal_mp",1000);
        set("heal_ap",1000);
        set("eat_msg",HIW "$N吃下一顆雪白的藥丸，嘴裡輕輕地發出一聲「咕」。" NOR );
        }
        setup();
}
