#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "女護士" , ({"nurse"}) );
set("long", "一個在這間醫院�堣u作的女護士，她正在忙碌地工作。\n");       
        set("race", "人類");
        set("gender", "女性"); 
        set("age",20); 
        set("attitude", "friendly");
        set("level", 10);
// set_skill("medicine",100);
        set("combat_exp",300); 
    set("chat_chance", 10 );  
  set("chat_msg", ({       
     (: random_move :),
}) );
        setup();
        
}


