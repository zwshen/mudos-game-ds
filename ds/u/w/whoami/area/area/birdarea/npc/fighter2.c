#include <ansi.h>
inherit NPC;
void create()
{
        set_name("大徒弟" , ({ "fighter" }) );
        set("level",25);
        set("race","人類");
        set("gender","男性");
        set("age",28+random(3));
        set_skill("dagger",35);
        set_skill("parry", 35);
        set_skill("dodge", 80);
        set_skill("sky-dagger", 30);
        set_skill("bird-eight", 80);
        map_skill("dagger","sky-dagger");
        map_skill("dodge","bird-eight");
        set("long",@LONG
他是天梟教的大徒弟, 看起來輕功絕佳, 而且武功也有一定的造詣了。
LONG);
        set("chat_chance", 8);
        set("chat_chance_combat", 80);
        set("chat_msg_combat",({
            "大徒弟對你喝道：我要讓你見識見識天梟教的厲害!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger4.c")->wield();
        carry_object(__DIR__"eq/surcoat2.c")->wear();
        carry_object(__DIR__"eq/wrists.c")->wear();
}

