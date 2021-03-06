inherit NPC;
void create()
{
        set_name("錟都武兵", ({ "city soldier","soldier" }) );
        set("long","由錟都特極營訓練出的士兵，個個身強體壯，對於空手搏擊有一定的訓\n"
                   "練，總是在事故發生時第一個趕到，給錟都城的居民向來都是不錯的映\n"
                   "像。\n");
        set("level",35);
        set("age",25+random(5));

        set("combat_exp", 20000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
    "守衛說：兄弟們，把他捕了\n"
}));
        set_skill("sword", 60);
        set_skill("parry", 70);
        set_skill("unarmed", 80);
        set_skill("dodge", 70);

        setup();
        carry_object(__DIR__"obj/fake-armor")->wear();
        carry_object(__DIR__"obj/fist")->wield();
}
