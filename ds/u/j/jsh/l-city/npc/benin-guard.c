#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("兵營士兵",({"benin soldier","soldier"}));
       set("gender","人類");
       set("level",25);
       set("age",30);      
       set("attitude","friendly");  
       set("evil",20);
       set("chat_chance", 7);
       set("chat_msg", ({
                        "昨天看見一個美女！嗚∼∼看了就酥麻麻的！\n"}));
       set("long",@LONG      
開羅長城裡，兵營裡面的士兵。
LONG
); 
        setup();  
        carry_object(__DIR__"obj/fork")->wield();
} 

