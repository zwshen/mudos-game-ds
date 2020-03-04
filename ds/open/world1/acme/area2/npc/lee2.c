#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李文恫",({"wen don lee","lee"}) );
        set("long","他是八極門護法之一，他濃眉大眼，身材魁武，看起來威風凜凜。\n");
        set("age",33);
        set("race","人類");
        set("level",25);
        set("title","〈八極門〉護法");
        set("gender", "男性" );
        set("chat_chance",5);
        set("chat_msg",({
            "李文恫喃喃自語地說道：這個施迅不知把邪教一干人藏到哪去了。\n",
            "李文恫喃喃自語地說道：他會不會把邪教一幫人藏到水裡去了。\n",
        }) );
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",40);
        set_skill("bagi_fist",60);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
                  (: random_move :),
        }) );
        setup();
}
