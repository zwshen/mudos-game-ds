#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIC "楊威利" NOR, ({"morral" }) );
	set("long", "他看起來十分象一個傻子！\n");
	set("race", "人類");
	set("gender", "男性");
	set("age", 30);
	set("level", 20);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("thundersword", 100);
	set("chat_chance",100);
	set("chat_msg",({
	(:command("rumor 小藍"):),
	}) );
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
            (:command("exert thundersword"):),
            }) );

	set("title", "『他是Mud�堛漱@個超級傻子』");
	
	setup();
	
	carry_object("/obj/longsword.c")->wield();
}
	