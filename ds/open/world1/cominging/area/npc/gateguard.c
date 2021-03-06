#include <ansi.h>
inherit NPC;
void create()
{
	set_name("守門守衛", ({ "gate guard","guard" }) );
	set("long","一個平常在大門旁邊檢查從各地而來的人身上是否帶有危險器具的人。\n");
	set("level",30);
        set("age",40+random(3));

	set("combat_exp", 29000);
	set("chat_chance", 4);
        set("chat_msg", ({
  "守衛說：沒事的就快快走。\n",
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  HIW"守衛說：反了反了，光天化日之下竟敢群眾打架\n"NOR,
  "守衛說：兄弟們，把他捕了\n"NOR
}));
	set_skill("sword", 60);
	set_skill("parry", 70);
	set_skill("unarmed", 76);
	set_skill("dodge", 65);

        setup();
	carry_object(__DIR__"wp/longsword")->wield();
	carry_object(__DIR__"eq/boots")->wear();
}