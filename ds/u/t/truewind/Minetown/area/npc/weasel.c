#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"變種巨鼬"NOR,({"mutated weasel", "weasel" }) );
        set("long",@LONG
接受了實驗污染而變種的大型生物，已經看不出牠原本是什麼生
物，只知道他現在看起來就是一隻肥大的鼬鼠而已！

LONG
);
        set("title","地底生物");
        set("race", "野獸");
        set("limbs", ({
                "頭部", "頸部", "胸口", "後心", "腰間", "腹部", "尖牙","尾巴",
        }) );
        set("age",50+random(19));
        set("level",10);
        set("int",8);
        set("gender","雌性");
        set("attitude","killer");
        set("verbs", ({ "bite","claw" }) );
        set("chat_chance", 9);
        set("chat_msg",({
                (:random_move :),
                (:random_move():),
        })      );
        setup();
}



