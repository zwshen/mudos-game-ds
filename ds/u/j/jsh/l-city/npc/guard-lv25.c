#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("開羅門衛",({"kailo guard","guard"}));
       set("gender","人類");
       set("level",25);
       set("age",30);      
       set("attitude","friendly");  
       set("evil",20);
       set("chat_chance", 7);
       set("chat_msg", ({
                        "開羅門衛說：閒雜人等！！不得進入！！你想跟我們戰爭嘛！\n"}));
       set("long",@LONG      
鎮守著開羅長城的正門，雙眼迥迥有神。
LONG
); 
        setup();  
        carry_object(__DIR__"obj/axe")->wield();
} 

