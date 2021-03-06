inherit NPC;
void create()
{
        set_name("錟都守衛", ({ "city guard","guard" }) );
        set("long","一個身穿戰甲，手拿長槍的士兵。負責在城門過濾往來的行人，並
對可疑的人進行盤查。\n");
        set("level",35);
        set("age",38+random(5));

        set("combat_exp", 20000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
    "守衛說：兄弟們，把他捕了\n"
}));
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 76);
        set_skill("dodge", 80);

        setup();
        carry_object(__DIR__"obj/fake-armor")->wear();
        carry_object(__DIR__"obj/pike")->wield();
}

