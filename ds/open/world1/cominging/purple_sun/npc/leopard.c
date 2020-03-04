inherit NPC;

void create()
{
	set_name("野豹\", ({ "wild leopard", "leopard" }) );
	set("long", @long
一隻看起來動作很靈敏的動物, 由它的行動上, 看的出它的力大, 它的迅速。
long	);
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳"})); //受攻部位
	set("verbs", ({ "crash","bite", "claw", "hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 13);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 6);
	set("level", 18);
	set("str", 27);
	set("dex", 25);
	setup();
}