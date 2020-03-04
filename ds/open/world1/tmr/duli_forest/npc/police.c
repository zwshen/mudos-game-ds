#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("守衛警察", "duli police", "police");

    set_race("human");

    set_skill("twohanded sword", 60);
    set_skill("blunt", 100);
    set_skill("sword", 100);
    set_skill("parry", 90);
    set_skill("unarmed", 80);
    set_skill("dodge", 90);
    set_skill("blade", 70);
    set_skill("berserk", 150);
    set("title","杜尼森林");
    set("long",@long
    這是一個負責管理進入杜尼港北邊森林入口的守衛，由於近年來傳聞
森林裡有吃人的妖魔鬼怪，使得人心惶惶，所以當局警政機關特派幾孔武
有力的警察擔任保護安全的責任。
long
);
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: command, "berserk" :)
    }));
    // 不結仇
    //set("vendetta_mark", "duli_port");
    setup();
    set_level(15);
	carry_object("/d/obj/longpike")->wield("twohanded pike");
	carry_object("/d/obj/armor")->wear();
}

int accept_fight(object ob)
{
        return 1;
}


