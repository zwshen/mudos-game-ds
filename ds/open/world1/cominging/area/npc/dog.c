#include <ansi.h>
inherit NPC;
void create()
{
	set_name("小狗", ({ "dog","mob" }));
	set("long","一隻小小的小狗。\n");

	set("race","野獸");
	set("age",3);
	set("level",1);
	set("max_hp",50+random(6));
	set("limbs", ({ "狗頭","尾巴","耳朵","前腳","後腳" }) );
	set("verbs", ({ "bite", "claw","crash" }));

	set("chat_chance", 10);
	set("chat_msg",({
  (: command("dog"):),
}));
	setup();
}