#include <ansi.h>
inherit NPC;
void kiss_delay(object me);
void create()
{
        set_name(HIM"晴晴",({ "ching ching","ching"}));
        set("long","Basic like 的人。。\n");
        set("level", 1);
        set("gender", "女性");
        set("age",17);
        set("chat_chance", 8);
        set("chat_msg", ({
       (:command("smile"):),
"晴晴說:basic我生日快到了ㄝ!!。",
}));
        setup();
}
int accept_object(object who, object ob)
{
        object tob, a;
        tob = this_object();
        if( ob->query("id")!="necklace" || query_temp("necklace") ) return 0;
        command("blush");
        command("kiss"+who->query("id"));
        command("say 你好討厭ㄛ...謝謝你.我好高興ㄛ~basic~");
        return 1;
}
