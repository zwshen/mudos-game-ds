inherit NPC;
inherit SELLMAN;

string gflower(object me);

void create()
{
	set_name("草藥醫生",({ "herbalist" }));
	set("long",
		"他是清香藥舖第某代的醫生，這個藥舖已流傳多年，他似乎有些煩惱！\n"
		"你可以向他詢問尚無存貨(list)或購買(buy)。\n"
	);
	set("age",50+random(10));
	set("no_fight",1);
	set("chat_chance", 3);
	set("chat_msg", ({
  "草藥醫生正在清點櫃子中的藥草。\n",
  (: command,"say 最近來客可真多！！" :),
  (: command(":)") :),
}) );
	set("sell_list",([
		__DIR__"obj/pdragon-herb.c": 12,
		__DIR__"obj/big-pill.c": 15,
        __DIR__"obj/tp_candy.c": 20,
		__DIR__"obj/appill.c": 20,
]));
	set("inquiry",([
  "help" : "可否小兄弟幫我去西邊森林尋找一種紫蘇玉蘭花，這種花生長在森林空地附近。",
  "紫蘇玉蘭花" : "這是一種花，可以用來做草藥，通常長在陽光充足但乾燥之地。",
  "煩惱": (: gflower :),
]));
	setup();
	add_money("silver", 10);
}

void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}

string gflower(object me)
{
	return "能否請"+RANK_D->query_respect(me)+"幫我一個忙(help)呢？\n";
}

int talk_action(object me)
{
	object ob;
	ob = this_object();
	if( !query_temp("herbalist") )
		message_vision(ob->name()+"對$N說：能否請"+RANK_D->query_respect(me)+"幫我一個忙(help)呢？\n",me);
	return 1;
}

int accept_object(object who, object ob)	//可接受東西
{
	object tob, herb,a;
	tob = this_object();
	herb = new(__DIR__"obj/pdragon-herb.c");
	if( ob->query("id")!="gei-su flower" ) return 0;
	if( !query_temp("herbalist") )
	{
		command("thank "+who->query("id"));
		command("say 謝謝你了"+RANK_D->query_respect(who)+"，那我就送你一個我親手製成的藥草吧！\n");
		// destruct(a);
		who->delete("quest"); //ccc
		herb->move(who);
		set_temp("herbalist",1);
		message_vision("$N給$n一株藥草。\n",tob,who);
		set("long",
			"他是清香藥舖第某代的醫生，這個藥舖已流傳多年.\n"
			"你可以向他詢問尚無存貨(list)或購買(buy)。\n");
		delete("inquiry/help");
		delete("inquiry/煩惱");
		call_out("delay",600,this_object());
	}
	else return 0;
	return 1;
}

void delay(object tob)
{
	delete_temp("herbalist");
	set("inquiry/help","可否小兄弟幫我去南邊森林尋找一種紫蘇玉蘭花，這種花生長在森林空地附近。");
	set("inquiry/煩惱",(: gflower :));
	set("long",
		"他是清香藥舖第某代的醫生，這個藥舖已流傳多年，他似乎有些煩惱！\n"
		"你可以向他詢問尚無存貨(list)或購買(buy)。\n"
	);
	return;
}
