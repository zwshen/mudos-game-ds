inherit NPC;

void create()
{
	set_name("野豬", ({"wild pig","pig"}) );
	set("long", "這隻野豬有著長長的兩顆獠牙，看起來不太好惹。\n");
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 3);
	set("level",7);
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
		"野豬很兇的衝向你，你很快的往旁邊閃過了。\n",
	}));
	setup();
}


void die()
{
	object pork;
	int i;
	for(i=0;i<4;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}