#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李應成",({"in chen lee","lee"}) );
        set("long","他是八極門護法之一，從他臉上可看出一副武者氣息。\n");
        set("age",33);
        set("race","人類");
        set("level",30);
        set("title","〈八極門〉護法");
        set("gender", "男性" );
        set("chat_chance",5);
        set("chat_msg",({
            "李應成說道：我一定要第一個找到那個人，這是師傅老人家的吩咐！\n",
            "李應成說道：他奶奶個熊！到底那個人在哪裡！\n",
            (: random_move :),
        }) );
        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("bagi_fist",70);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
        }) );
        set("inquiry/那個人","就是很久以前消失的那個高手呀，他身上可是很神秘的\n"NOR);
        set("talk_reply", "李應成說道︰少煩老子，老子忙的很。");        
        setup();
}



