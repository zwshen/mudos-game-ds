// Modified from ES 2 drooler.c
// By Annihilator@Celestial.Empire (09/15/95)
// Last modified by Spock @ FF  97.Oct.30.
#include <ansi.h>
inherit NPC;
string *rnd_say = ({
        "HI !你好",
        "hello very body",
});
varargs void drool(string msg, string who);
void create()
{
        set_name( "性感小貓貓", ({ "SexyCat" }));
        set("level",100);
        set("title","【黑瞳秘書】");
        set("race", "人類");
        set("gender","女性");
        set("age", 20);
        set("long",
@LONG
她是黑瞳的專用秘書，一身魔鬼身材令你為之心動．
LONG
        );
        set("attitude", "friendly");
        set("welcome_msg", "性感小貓貓說道: 歡迎來到 黑瞳的睡房參觀。\n" );
        set("chat_chance", 4 );
        set("chat_msg", ({
"性感小貓貓伸手凌空一指，變出四級ＶＣＤ, 開始研究起來。\n",
"性感小貓貓跳上床上，情心款款地看著你。\n",
"性感小貓貓拿著她的性感內衣，在你的面前晃來晃去。\n",
"性感小貓貓伸手凌空一指，變出一個袋袋, 開始淫笑起來。\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }));
        setup();
}
