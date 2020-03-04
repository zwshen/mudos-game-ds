#include <ansi.h>
inherit NPC;

void create()
{
        set_name("李村長",({ "mayor lee","mayor","lee" }) );
        set("long","這個村子的村長，平時喜歡做善事，所以得到許\多人的誇獎。\n");
        set("race","人類");
        set("age",60);
        set("level",10);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "李村長嘆道：這個洞穴真是奧妙玄奇，不知道裡頭都住著什麼生物...\n",
        "李村長很煩惱地走來走去...\n",
        }) );
        setup();                
}
