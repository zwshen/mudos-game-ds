#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "小女孩" , ({"child"}) );
set("long", "一個十幾歲的小女孩。\n");       
        set("race", "人類");
        set("gender", "女性"); 
        set("age",11); 
        set("env/wimpy", 80);        
        set("attitude", "friendly");
        set("level", 5);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
(:command("jump"):),  
(:command("flip"):),  
(:command("cac"):),
     (: random_move :),
}) );
        setup();
        
}


