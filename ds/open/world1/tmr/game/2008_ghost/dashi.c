#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
	set_name(HIY"大士爺"NOR,({"dashi buddha", "dashi", "buddha"}) );
	set("long",@LONG
面燃大士是觀音大士的化身，也叫面燃鬼王、焦面大士、焰口鬼王，
俗稱大士爺、大士王，在道教又尊稱為「普渡公」。不少地方中元節
祭拜亡靈之前，會先祭拜「大士爺」，信眾認為，舊曆七月，所有在
陽世的亡靈，都歸「大士爺」管理。
LONG
);
	set("age",5000);
	set("race","celestial");
	set("level", 1);
    set("attitude", "peaceful");
    set("title","普渡孤魂揚善道");
    set("gender", "男性" );
    set("no_kill",1);
	setup();
	set("sell_list", ([     
             "/open/world1/tmr/game/2008_ghost/boat"    : 1, 
         ]) );

}


void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}

// 獲得獎勵
void bouns(object me, string type, int amount)
{
	int points = 0;
	string ctype;
	if(type=="art") {
		points = amount/50;
		ctype = "戰鬥藝術";
	}
	if(type=="pop") {
		points = amount/5;
		ctype = "聲望";
	}
	if(type=="exp") {
		points = amount*100;
		ctype = "經驗值";
	}
	if(type=="money") {
		points = amount*10;
		ctype = "銅板";
	}
	if(points<1) {
		type = "money";
		points = amount*10;
		ctype = "銅板";
	}

	tell_object(me, sprintf("你獲得 %4d %s。\n", points, ctype ) );
	if(type=="art")
		me->add("war_art", points);
	else if(type=="pop")
		me->add("popularity", points);
	else if(type=="exp")
		me->add("exp", points);
	else if(type=="money")
		me->add("bank/past", points);
}

int accept_object(object who,object ob)
{
	if(!ob->id("_DEAD_PAPER_"))
		return 0;
    message_vision("$N給了大士爺一張$n。\n",who,ob);
	command("say 好好好！小子您行這善道，必有後福啊。");
	bouns(who, ob->query("type"), ob->query("amount") );
	destruct(ob);
	return 1;
}
