#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小徒弟" , ({ "second fighter","fighter" }) );
        set("level",8);
        set("race","人類");
        set("gender","男性");
        set("age",28);
        set_skill("dagger",20);
        set_skill("parry", 20);
        set_skill("dodge", 50);
        set_skill("bird-eight", 40);
        map_skill("dodge","bird-eight");
        set("long",@LONG
他是天梟教的小徒弟, 看起來輕功不錯, 但是武功卻不怎麼樣。
LONG
           );
        set("chat_chance", 8);
        set("chat_chance_combat", 80);
        set("chat_msg", ({"小徒弟左翻右衝的，正在練習剛學的輕功\n",
        })); 
        set("chat_msg_combat",({
            "小徒弟對你喝道：我要讓你知到我不是那麼好欺負的！\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger2.c")->wield();
}

