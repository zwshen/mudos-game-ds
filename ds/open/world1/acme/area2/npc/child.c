#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小孩", ({ "child" }) );
        set("gender", "男性" );
        set("long",
            "一個玩得渾身髒兮兮的小孩子。\n"
           );
        set("age",5);
        set("level",3);
        set("chat_chance", 2);
        set("chat_msg", ({
                "小孩說道：嘻嘻∼來呀！來抓我呀！\n",
                "小孩說道：可惡！又被你逃了！\n",
        }));

        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                "小孩大叫：救命啊！救命啊！有人要殺死我啊！\n",
         }) );
        setup();
}
