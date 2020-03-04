
inherit NPC;

void create()
{
	set_name("蟑螂", ({"roach"}) );
	set("long", "一隻黑色的蟑螂, 有著油亮的翅膀和毛毛的腳刺, 並且不斷的舞動牠的觸鬚。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "翅膀", "後腳","腹部"})); //受攻部位
	set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",2);
	set("str",3);
	set("dex",6);
	setup();

}
