#include <ansi.h>
inherit NPC;
void create()
{
        set_name(CYN "荊 眾" NOR ,({"gin servant","servant"}) );
        set("long",@LONG
四人眾之一，白鬼四幽中的魎湟幽鬼的手下。
LONG
);
        set("age",100);
        set("race","人類");
        set("title",HIR"四人眾"NOR);
        set("level",35);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance_combat",10);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("sword",100);
setup();
     carry_object(__DIR__"wp/whip")->wield();
       
}


