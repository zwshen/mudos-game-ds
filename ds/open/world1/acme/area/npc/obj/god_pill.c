#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("清心續命丸", ({ "god_pill"}));
        set("long",@LONG
這是一顆具有神奇療效的丹藥。
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
		set("unit", "顆");
		set("eat_msg","$N吃下一顆清心續命丸。");
		set("eff_msg",HIG "你感到從腹中傳來一股溫暖的熱流，慢慢的擴散到全身。" NOR );
	}
        set("value",750);
        set("cure",([
         "head" : 10,
         "body" : 10,
         "right_arm" : 10,
         "left_arm" : 10,
         "right_leg" : 10,
         "left_leg" : 10,
         ]));
        setup();
}
