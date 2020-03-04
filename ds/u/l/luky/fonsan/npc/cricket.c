
inherit NPC;

void create()
{
	set_name("蟋蟀", ({"cricket"}) );
	set("long", "一隻很可愛的小蝸牛, 正吃力的爬著。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "前腳","後腳" })); //受攻部位
	set("verbs", ({ "bite","claw","crash"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",1);
	set("dex",6);
	set("str",3);
	setup();

}
