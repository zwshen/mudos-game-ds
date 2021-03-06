#include <ansi2.h>
#define LIEH "do l off,s,s,sd,s,s,su,s,s,sd,s,s,su,s,s,se,s,s,e,se,s,e,e,se,e,e,e,e,enter,e,e,e,e,e,e,e,l on,l"
#define BACK "do look off,w,w,w,w,w,w,w,out,w,w,w,nw,w,w,n,nw,w,n,n,nw,n,n,nd,n,n,nu,n,n,nd,n,n,nu,n,n,look on,l"

inherit NPC;

void fly();

void create()
{
	set_name("萬鮮靈", ({ "wan xian ling", "ling" }));
	set("long", @long
在你眼前這一位是疾風門的門下大弟子，在門中地位僅次於左右使之
下，但她聰敏過人，憑著門主軒轅烈所傳之昂星劍法為基礎而自創出
一套全新的劍法，使用其強大之內力一套全新的劍法，使用其強大之
內力控制劍任意攻擊對手，是當今世上後輩中比較出眾的一位。
long);
	set("level", 50);
	set("title", HIY"疾風門大弟子"NOR);
	set("gender", "女性");
        set("chat_chance", 60);
	set("chat_msg", ({
//                (: command("defend lieh") :),
		(: fly :),
		(: command("exert moon_force recover") :),
	}));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
                (: command("do wield ling yan sword,exert sevenstar") :),
                (: command("do wield ling yan sword,exert sevenstar") :),
                (: command("do wield ling yan sword,exert sevenstar") :),
                (: command("do wield ling yan sword,exert sevenstar") :),
//                (: command("defend lieh") :),
		(: command("exert moon_force long-arc") :),
	}));
	set_temp("class_wind/power", 300);
	set("nickname", HIW"劍氣神童"NOR);
	set("age", 25);
	set("flurrydodge", 1);
//        set("Merits/tec", 8);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("combat", 100);
	set_skill("sorgi_sword", 100);
	set_skill("star-sword", 100);
	set_skill("sevenstar-sword", 100);
	set_skill("sevenstar", 100);
	set_skill("force", 100);
	set_skill("moon_force", 100);
	set_skill("fogseven", 100);
	set_skill("stealing", 100);

	map_skill("dodge", "fogseven");

	setup();
        carry_object(__DIR__"sword2");
        carry_object(__DIR__"sword2");
        carry_object(__DIR__"sword2");
        carry_object(__DIR__"sword2");
        carry_object(__DIR__"sword2");
	carry_object(__DIR__"sword2");
	carry_object(__DIR__"sword2");
        carry_object(__DIR__"wrists")->wear();
        carry_object(__DIR__"only");
	set_living_name("ling");
}

void die()
{
	object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
	{
                ::die();
		return;
	}
        message("world:world1:vision",
CYN"\n  武林傳出了一則消息:\n\n\t疾風門大弟子「劍氣神童」萬鮮靈被"+ob->name(1)+"殺死了。\n\n"+NOR
        ,users());
          ob->add("popularity", 5); 
        tell_object(ob, HIC"你得到 5 點聲望。\n"NOR);
        ::die();
        return;
}

void help()
{
	return;
	remove_call_out("help");
	if( file_name(environment(this_object())) == "/open/world1/cominging/area/flurry50" )
	{
		command(LIEH);
		command("defend lieh");
		command("wield ling yan sword");
		map_skill("sword", "sevenstar-sword");
	if( file_name(environment(this_object())) == "/open/world1/cominging/area/flurry50" ) call_out("help", 0);
	}
	else {
        if( file_name(environment(this_object())) == "/open/world1/cominging/area/boo-lin" )
	{
		command(BACK);
	}
	}
	if( query("flee") )
	{
		delete("flee");
		call_out("help", 60);
	}
}

varargs int receive_damage(string type, int damage, object who)
{
	object me = this_object();
	object sword;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
        if( !random(3) ) 
	{
		foreach(object one in filter_array( children("/daemon/skill/npc/sword"), (: clonep :) ) )
		{
			if( one->query_leader() == me ) sword = one;
		}
		if( sword ) {
		message_vision(HIM"$n突然在$N前檔下此次攻擊！\n", me, sword);
		sword->receive_damage(type,damage,who);
		damage = 0;
		}
	}
	else {
		::receive_damage(type,damage,who);
		if( !random(5) )
		{
			me->set("flee", 1);
			me->help();
		}
	}

	return damage;
}

void fly()
{
        int num = SKILL_D("sevenstar")->check(this_object(), 0);
        if( num >= 7 ) return;

        command("do wield testing,exert sevenstar,exert sevenstar");
	return;
}

//void start_busy() { return; }  -by js
//void add_busy() { return; } -by js
void add_block() { return; }
void set_block() { return; }

int be_stolen(object me, object what)
{
	if( !me || !what )
		return notify_fail("[錯誤]:請用 report 指令回報。\n");

	tell_object(me, this_object()->name() + "不經意地一轉頭﹐你急忙將手縮了回去﹗\n"
		"還好﹐沒有被發現。\n");
	me->start_busy(2);
	return 1;
}
