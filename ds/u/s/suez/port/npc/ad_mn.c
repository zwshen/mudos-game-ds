inherit NPC;

void create()
{
       set_name("冒險者",({"adventurer","man"}));
       set("long","為了各種不同理由而向未知挑戰的男人。\n");
       set("gender","男性");
       set("age", random(20)+15);
       set("level", random(10)+5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say 下次的目標...這裡嗎？"):),
            (:command("say 嘿！上次的冒險可真不是蓋\的！"):),
            (:command("say 真想喝一杯啊∼∼"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("grin"):)
        }) );
    
        setup();

	carry_object( __DIR__"wp/sword")->wield();
         carry_object( __DIR__"eq/l_armor")->wear();  
        carry_object( __DIR__"eq/cloth")->wear();
}

