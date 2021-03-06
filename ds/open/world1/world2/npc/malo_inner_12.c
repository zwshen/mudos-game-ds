#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("旅館櫃檯小姐" , ({ "hotel employee","employee" }));
	set("long",@LONG
  他是這一家店的店小二，他正忙著幫忙照顧客人。
	==========================
	訂房休息	checkin
	商品清單	list
	購買商品	buy <商品>
	==========================
LONG);
	set("race","human");
	set("gender","女性");
	set("inquiry",([
  "rest" : "休息一次只要200元∼你只要訂房(check in)就可以休息了！\n",
  "check in" : "一次200∼房間隨您挑喔！\n",
]));
	set("sell_list",([
  "/open/always/newspaper" : 10,
  "/open/always/torch" : 10,
]));
	set("level",12);
	set("no_fight",1);
	setup();
	add_money("dollar", 370);		//帶的錢(coin古代,dollar現代,未來沒有)
	carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
}

void init()
{
	object ob=this_player();
	::init();
	if( userp(ob) && this_object()->visible(ob) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list","list");
	add_action("do_buy","buy");
	add_action("do_check","checkin");
	return;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command("say 歡迎光臨!!");
			break;
		case 1:
			command("smile");
			break;
	}
	return;
}

int do_check(string arg) // rest & sleep
{
	object me,ob;
	string c;
	me = this_player();
	ob = this_object();

	if( arg )
		return 0;
	if( !me->can_afford(200) ) return notify_fail("你身上的錢不夠。(200)\n");
	if( me->query_temp("malo/inn")) return notify_fail("你已經訂過房了，請自行去房間休息。\n");
	me->set_temp("malo/inn",1);
	me->receive_money(-200);
	message_vision("$N付給了$n訂房金兩百元。\n",me,ob);
	command("say 謝謝您的惠顧，請您自行選擇房間休息吧。");
	return 1;
}
