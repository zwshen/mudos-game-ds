#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "病人" , ({"patient"}) );
set("long", "一個幾十歲的老年病人，看起來好像很辛苦。\n");       
        set("race", "人類");
        set("age",70);        
        set("attitude", "friendly");
        set("level", 5);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
//     (: random_move :),
}) );
        setup();
        
}


