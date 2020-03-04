inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("清心靈動丹", ({ "hand_pill"}));
        set("long",@LONG
這是一顆只有在清心藥鋪才買得到的丹，你嗅了一嗅，辛辣刺鼻，令人作噁。
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "顆");
	        set("eat_msg","$N吃下一顆清心靈動丹。");
	        set("eff_msg","你感到腹內有如萬蟲鑽動，巨痛難當，但是手上的傷卻恢復了不少。");
	}
        set("value",150);
        set("cure",([
         "right_arm" : 10,
         "left_arm" : 10,
         ]));
        setup();
}
