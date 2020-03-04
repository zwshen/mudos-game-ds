inherit NPC;

void create()
{
	set_name("母牛", ({"cow"}) );
	set("long",@LONG
一頭體型龐大的母牛，正在揮動尾巴趕蒼蠅。
LONG);
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age",5);
	set("level",10);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<7;i++)
	{
		meat=new_ob(__DIR__"../obj/beef");
		meat->move(this_object());
	}
	::die();
}