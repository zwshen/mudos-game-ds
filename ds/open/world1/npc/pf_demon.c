#include <ansi.h>

inherit NPC;

void create()
{
        set_name("豬面魔", ({ "pigface demon","demon" }) );
        set("race","human");
        set("level",35);
        set("age",90);
        set("evil",6);
        set("long",@LONG
渾身惡臭的怪物，整個頭跟豬一模一樣，也是屬於低等妖魔
，力大無比，愛好女色。
LONG
);
        set_skill("sword",90);
        setup(); 
        carry_object(__DIR__"../eq/bs_boots")->wear();
        carry_object(__DIR__"../wp/ghost_sword")->wield();
}



