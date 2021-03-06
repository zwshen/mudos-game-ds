// In room078.c 旅社
inherit NPC;

void make_mark();

void create()
{
	set_name("旅社櫃臺小姐",({"miss"}) );
	set("long","她的談吐之間散發出女性特有的韻味。\n這裡的旅客要住宿前都必須先向她登記並付費(pay)。\n");		
	set("age",32);
	set("level",10);
	set("race","人類");
	set("gender","女性");
	set("evil",-5);		// 邪惡度 -5 (正的表邪惡, 負表善良)
	set("exp_point",0);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",4);
	set("chat_msg",({
		(:command("say 嗨！您好，有需要為您服務的地方嗎？"):),
		(:command("smile"):),
		(: command,"say 要住宿嗎？" :),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);
	set("inquiry",([
  	"住宿" : "住宿一次只要 200 元喔∼！\n",
  	"付費" : "我們正在特價喔..一次只要 200 元！\n",
  	"pay" : "我們正在特價喔..一次只要 200 元！\n",
  	"登記" : "不用那麼麻煩啦∼不管是好人壞人, 只要是有錢人就可以住。\n",
	]));
	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	add_money("dollar",50);
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_pay","pay");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(random(2)) command("say 您好!歡迎光臨!!");
}
int do_pay(string arg) // rest & sleep
{
	object me,miss;
	string c;
	me = this_player();
	miss = this_object();

	if( !arg || arg!="miss")
	{
		notify_fail("付錢給誰??\n");
		return 0;
	}

	if( !me->can_afford(200) )
		return notify_fail("您身上的錢不夠喔。(200元)\n");
	if( me->query_temp("hotel_1")>0 )
		return notify_fail("您已經付過錢了，請上樓休息(sleep)吧。\n");
	me->receive_money(-200);
	me->add_temp("hotel_1",1);
	message_vision("$N付給了$n兩百元住宿費。\n",me,miss);
	command("smile "+me->query("id"));
	return 1;
}

void make_mark()
{
	object *enemy, ob;
	command("say 哇！救命阿！");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"，你是個魔鬼。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}
