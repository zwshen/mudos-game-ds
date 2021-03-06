#include <ansi.h>
inherit NPC;
void create()
{
        set_name("扶桑浪人",({ "fu shun lan man","fu","man" }));
        set("long",
                "他是一位扶桑流浪的浪人，喜歡冒險，習慣用刀，且很有骨氣。\n"
                
        );
        set("age",41);
        set("level",20);
        set("gender", "男性");
        set("str",30);                  
        set("dex",40);                  
        set("con",40);                
        set("int",30); 
        set("exp",3117);       
        set("attitude", "peaceful");
        set("combat_exp",2000);         
                        

        set_skill("throwing",10);    
        set_skill("parry",20);          
        set_skill("dodge",50); 
 set_skill("blade",50);
        set_skill("combat",50);        
        
        set("talk_reply","戰鬥，是武士的生命，當自己技不如人時，武士都會剖腹自殺，以求尊嚴。");

        set("chat_chance",5);
        set("chat_msg", ({
  
  name()+"喃喃念道：扶桑浪人營最強的人藤田彥空，我是一輩子也追不上呀。\n",
  name()+"開始揮動武士刀練刀。\n",
  name()+"拿起武士刀平放腿中，背誦刀法。\n",
(: command("think") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "浪人激動的怒吼：看我用我的刀殺了你！！\n",
         (: command("baga") :),
    }) );
        setup();
        carry_object(__DIR__"eq/rattan_leggings");
        carry_object(__DIR__"wp/japen_blade");
}
void die()
{
        message_vision("$N承認失敗，拿起手上的刀，刺入自己的腹部中，倒在地上，一動也不動了。\n",this_object());
        ::die();
}
