#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "老人" , ({"oldman"}) );
set("long", "一個高齡的老人，他正在輪候醫生為他看病。\n");       
        set("race", "人類");
        set("age",80);  
        set("attitude", "friendly");
        set("level",10);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
//   (: random_move :),
}) );
        setup();
        
}


