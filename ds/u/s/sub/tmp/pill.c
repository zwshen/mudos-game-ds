#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("清心鍑合丹", ({ "body_pill"}));
        set("long",
        "這是一顆只有在清心藥鋪才買得到的丹，此丹遍體通紅。\n"
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "顆");
	        set("eat_msg","$N吃下一顆清心鍑合丹。");
	        set("eff_msg",HIG "你直覺得有股冷流在丹田繞轉不停，身上的傷口似乎也漸漸癒合了。" NOR );
	}
        set("value", 150);
        set("cure",([ "body" : 10,]));
        setup();
}
