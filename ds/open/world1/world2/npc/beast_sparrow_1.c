inherit NPC;
void create()
{
	set_name("麻雀", ({"sparrow"}) );
	set("long",@LONG
一隻小麻雀，正在這裡找蟲吃。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "雙足", "翅膀" })); //受攻部位
	set("verbs", ({ "bite","poke" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 2);
	set("level",1);
	set("dex",1);
	set("str",1);
	set("con",1);
	set("max_hp",20);
	set("evil",-10);
	set("chat_chance",5);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));
	set_temp("fly",1);
	set_temp("apply/hit",-20);      //弱化命中率
	set_temp("apply/dodge",-20);    //弱化閃躲率
	setup();

}
