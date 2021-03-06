// In room120.c 雅莉的酒店
inherit NPC;
inherit SELLMAN;
void make_mark();
string askboss();

void create()
{
	set_name("酒店店員",({"clerk"}) );
	set("long",@LONG
	這位店員調酒的功\力可是一等一的。
	==========================
	飲品清單	list
	購買飲品	buy <飲品>
	==========================
LONG);		
	set("age",32);
	set("level",10);
	set("race","human");
	set("gender","男性");
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say 嗯∼就是這個滋味∼"):),
		(:command("say ∼我所調的酒是最好喝的∼要不要嚐嚐阿∼"):),
		(:command("say 這家店的老闆娘雅莉，也不知道跑到哪去了，已經有好些日子沒看到她了。"):),
	})	);

	set("inquiry/老闆娘","喔。老闆娘啊，她叫「雅莉」，很好聽吧。" );
	set("inquiry/雅莉",(: askboss :) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);
	set("sell_list",([
  "/open/world2/obj/bloodmarry_wine" : 10,
"/open/world2/obj/bluegimi_wine" : 15,
"/open/world2/obj/beer" : 5,
]));
	set("talk_reply","喔，要跟我聊天？晚上到我家吧。");
	setup();

	add_money("dollar",200);
}

string askboss()
{
	return "唉，已經快一個月沒看到她了，真不知道她在忙什麼？";
}

void make_mark()
{
	object *enemy, ob;
	command("say 救命阿！救命阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"你是個魔鬼。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}
