inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name("長毛獸", ({"wendigo monster", "monster","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
巨大而敏捷的生物，通常出在荒野之中，但有也會盤踞在洞窟或是地
下城內，人類應該避免和牠們接觸，牠們有可能會瞬間暴怒，並以牠們巨
大、沉重的爪子進行攻擊。
long
);
        set("title","血腥荒野");
		set("race","evil");
		set("level", 50+random(10));
        set("age", 320);
        set("chat_chance", 8);
        set("chat_msg", ({
                (: random_move :),
        }) );
		/* 戰鬥動作 */
	   	 set("chat_chance_combat", 50);
	   	 set("chat_msg_combat", ({
	      (: do_fight_issue :),        
	   	 }) );
	   	  
        set("attitude", "aggressive");
        set("addition/bar", 5);
        set("addition/bio", 3);
        set("addition/wit", 5);
        set("addition_armor", 150);
        set("addition_damage", 200);
        set("addition_shield", 250);
        setup();
        set_living_name("_BLOOD_FIELD_NPC_");
        set_temp("apply/hit", 200);

	 	switch(random(4)) {        
        case 0:
                carry_object(__DIR__"obj/boots")->wear();
                carry_object(__DIR__"obj/armor")->wear();
        break;
        case 1:
                carry_object(__DIR__"obj/armor")->wear();
                carry_object(__DIR__"obj/belt")->wear();
        break;
        case 2:
                carry_object(__DIR__"obj/belt")->wear();
                carry_object(__DIR__"obj/ring")->wear();
        break;
        case 3:
                carry_object(__DIR__"obj/ring")->wear();
                carry_object(__DIR__"obj/boots")->wear();
        break;
        }     
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
}



