#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "美女" , ({"beauty"}) );
set("long", "一個十分美麗的少女，她好像在等一個人\n");       
        set("race", "人類");
        set("gender", "女性"); 
        set("age",18); 
        set("env/wimpy", 50);        
        set("attitude", "friendly");
        set("level",10);
        set("combat_exp",500);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10); 
    set("chat_chance", 2 );  
  set("chat_msg", ({       
(:command("sigh"):),  
"看來美女的心情十分焦急了\n",
}) );
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
        (:command("say Don't kill me"):),
        }) );
        setup();
        
}

