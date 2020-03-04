
inherit NPC;
void create()
{
        set_name("文人騷客",({ "scholar"}));
        set("long","頭戴綸巾，身著青衫，手搖折扇，搖頭晃腦吟詩中的文人。\n");
        set("level", 5);
        set("age",23);
        set("chat_chance", 8);
        set("chat_msg", ({
        (: command,"think 下一句該怎麼接呢" :),
        (: command,"say 好一個古樸清幽之所..." :),
        }) );
        setup();
        add_money("coin",100);
}
