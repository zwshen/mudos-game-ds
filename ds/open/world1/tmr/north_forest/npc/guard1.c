#include <ansi.h>
inherit NPC;
void create()
{
        set_name("教徒", ({ "guard"}) );
     set("nickname", HIC"靈幻教守衛"NOR);
        set("long","一個平常在大門旁邊檢查從各地而來的人身上是否帶有危險器具的人。\n");
        set("level",30);
        set("age",40+random(3));
        set("combat_exp", 29000);
        set("chat_chance", 4);
        set("chat_msg", ({
        (: command,"peer" :),
        "教徒說: 你有檢查過了嗎？\n",
}));
        set("inquiry",([
"進入" : "你要進入？那裡可不是他人能隨便進入的喔。\n",
]));

        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
        HIW"教徒向裡面大喊:「有人要闖進來了！」\n"NOR
}));
        set_skill("sword", 60);
        set_skill("parry", 70);
        set_skill("unarmed", 76);
        set_skill("dodge", 65);
        setup();
//        carry_object(__DIR__"wp/longsword")->wield();
//        carry_object(__DIR__"eq/boots")->wear();
}

