#include <ansi.h>
inherit NPC;

void create()
{
        set_name("人類", ({"human"}) );
        set("long", "！\n");
        set("race", "人類");
        set("gender", "女性"); 
        set("age", 20);
        set("attitude", "friendly");
        set("level", 16);
        set("evil", -999);
        set("combat_exp",2000);
        set("env/wimpy", 25);        
        set("chat_chance", 90 );           set("chat_msg", ({   
        (:command(""):),
        (:command(""):),
        (:command(""):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command(""):),
        (:command(""):),
        }) );
        setup(); 
  
}

