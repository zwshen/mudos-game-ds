inherit NPC;

void create()
{
	set_name("老虎", ({ "tiger" }) );
	set("long", @LONG
一隻外形類似豹的動物, 但體形較為龐大, 而且眼神更之為兇猛, 不時發出怒吼。
LONG	);
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳", "尾巴" })); //受攻部位
	set("verbs", ({ "crash", "claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 5);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 3);
	set("level", 17);
	set("dex", 18);
	set("str", 21);
	set("attitude", "killer");
	setup();
}
