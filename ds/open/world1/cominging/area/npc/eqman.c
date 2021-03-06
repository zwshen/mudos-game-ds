inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("丘洛靈",({ "chao lo-lin","lin","lo-lin","chao" }));
	set("long",@LONG
他是這家在步靈城中防具店的老版，他的頸部旁有一
條專門擦汗用的小毛巾，上面繡有許多漂亮的圖案。

[ 提示: 你可以用 list 向他詢問有什麼防具可賣或用 buy  向他購買裝備 ]

LONG
	);
	set("level", 5);
	set("age",10);
	set("no_fight",1);
	set("sell_list",([
		__DIR__"eq/steelshield": 6,
		__DIR__"eq/steelhead": 5,
		__DIR__"eq/surcoat":5,
		__DIR__"eq/wrists":6,
		__DIR__"eq/cloudarmor":7,
		__DIR__"eq/gloves" : 4,
	]) );
	setup();
	add_money("silver",150);
	carry_object(__DIR__"eq/e_cloth.c")->wear();
	carry_object(__DIR__"wp/dagger.c")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy","buy");
	add_action("do_list","list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "丘洛靈說：這位是需要什麼樣的裝備呢？\n");
			break;
		case 1:
			say( "丘洛靈說：歡迎光臨。\n");
			break;
	}
}