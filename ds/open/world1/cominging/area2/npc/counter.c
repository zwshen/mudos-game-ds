#include <ansi.h>
#include <path.h>
inherit NPC;

void start_bandit_war();
void finish_bandit_war(object ob);

void create()
{
	set_name("隱形點人頭器",({ "war opener","opener"}));
	set("long","這個是 Cominging 專門用來計算點人頭開 War 的東東.\n");
	set("age",10000);
	set("level",100);
	set_temp("bandit_war_flag",0);
	set_temp("bandit_die",0);
        setup();
}

void init()
{
	if( !wizardp(this_player()) )
	{
		message_vision("$N口中喃喃自語，突然一道光射向$n亮的令人張不開眼....\n");
	}
}

void query_bandit_war(int flag)
{
	if( flag == 1 )
		add_temp("bandit_war_flag",1);
//	if( find_object(__DIR__"partol_g.c") || find_object(__DIR__"fort_g.c") || find_object(__DIR__"t_guard.c") )
//		return;
	if( query_temp("bandit_war_flag") > 5 )
		start_bandit_war();
	else return;
}

void start_bandit_war()
{
	object bandit1,bandit2,bandit_m;
	int i,b;
	bandit1 = new(__DIR__"bandit1.c");
	bandit2 = new(__DIR__"bandit2.c");
	bandit_m = new(__DIR__"bandit_m.c");

	b = 4 + random(3);
	message("world:world1:vision",
		"\n\n  "HIR"守衛塔一時殺氣沖天，一位巡邏的小兵急忙趕至官府中上報.....\n"
		"  西邊城外突然一道火光，只見塵沙飛舞，人聲滿天, 一群群的盜賊往步靈城中進攻了！！！\n"NOR
		HIY"  兵總急忙的帶領許\多兵馬到達了西邊防禦...。\n"NOR,users());
	for(i = 0 ; i < b ; i++ )
	{
		bandit1->move(COMINGING_PAST+"area2/bdoor3.c");
		bandit2->move(COMINGING_PAST+"area2/bwest5.c");
		bandit1->move(COMINGING_PAST+"area2/tower.c");
	}
	bandit_m->move(COMINGING_PAST+"area2/bdoor3.c");
	delete_temp("bandit_war_flag");
	set_temp("bandits",b);
	return;
}

void query_bandits(object ob)
{
	if( query_temp("bandit_die") >= query_temp("bandits") )
		finish_bandit_war(ob);
	else add_temp("bandit_die",1);
	return;
}

void finish_bandit_war(object ob)
{
	message_vision("world:world1:vision",
			"\n\n  只見盜賊群在最後死亡前放下一句話 ...... \n"
			"  「我∼不∼甘∼心∼，兄弟們∼∼替∼我∼報∼仇∼∼！！」\n"
			"  在這幾句之後，攻擊步靈城的盜賊們終被打退了！\n",users());
	ob->add("popularity",3);
	call_out("give",3,ob);
	return;
}

void give(object ob)
{
	message_vision("world:world1:vision",HIY"\n\n  [小道消息] 步靈城總督給予了"+ob->name(1)+"很大的獎賞。\n\n"NOR,users());
	return;
}