#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED "魅妖" NOR ,({"mai evil","evil"}) );
        set("long",@LONG
四絕妖之一，白鬼四幽中的魎湟幽鬼的手下。
LONG
);
        set("age",100);
        set("race","人類");
        set("title",HIC"四絕妖"NOR);
        set("level",30);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance_combat",10);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("sword",100);
setup();
     carry_object(__DIR__"wp/sword")->wield();
       
}


