// In room058.c	中心廣場東北邊
// 更新日期: 1999.10.15
// 更新者: Luky
// QCer: Luky
#include <ansi.h>
inherit NPC;
inherit SSERVER;
void make_mark();
void cast_mind();

void create()
{
	set_name("銀辯",({"yin-bian","bian"}) );
	set("long","他是奧凡迪斯裡有名的修行者，聽說他擁有超能力。\n");
	set("age",30);
	set("level",40);
	set("race","人類");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say 這是座美麗的城市，請不要做出違法的事情喔！"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我身為巡官，一定要將作亂者就地正法！！"):),
		(: make_mark :),
		(: cast_mind :),
//		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
//	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();
	carry_object(__DIR__"wp/staff0")->wield();
	add_money("dollar",200);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 2 + random(3) )
	{
		command("say 你這個作亂者，居然為非作歹，今天被我遇到算你倒楣。");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}


void make_mark()
{
	object *enemy, ob;
//	command("say 哇！救命阿！");
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say 哼!無法無天的"+ob->query("name")+", 我發誓要將你逐出奧凡迪斯。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}

void cast_mind()
{
	object ob,me;
	int damage,c;

	me = this_object();

	ob = offensive_target(me);
	if(!ob) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",20);
	command("say "+ob->query("name")+"，讓你看看我超能力的利害。");


	tell_room(environment(me),"\n"+me->query("name")+"突然身子往後退了一步\n");
	tell_room(environment(me),"\n你看到他的雙手自然的垂下，雙目變得異常的有神。\n");

	if( ob->query_int() < random(150) )
	{
	    ob->add_busy(2);
	    message_vision(HIR"\n$N突然對周遭的環境充滿著恐懼，$N的行動好像被限制住了。\n",ob);
	    damage = random(100)+query_int()*3;
	    damage = damage/3+random(damage/2);
	    c=ob->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,ob,damage,"sou");
	    ob->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n$N突然被莫名的力量所打中，口吐鮮血，整個人被打在牆壁上動彈不得。\n"NOR,ob);
	    else
		message_vision(HIW"\n由於$N的靈力勝過 "+me->query("name")+" 一籌，活生生地接下了這股莫名之力。\n"NOR,ob);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(ob->query_temp("apply/show_damage") || ob->query_temp("show_damage") )
	        tell_object(ob,HIR"("+damage+")"NOR+" ("+ob->query("hp")+"/"+ob->query("max_hp")+")");
	    message_vision("\n",ob);
	    if(wizardp(ob) && ob->query("env/debug"))
	        tell_object(ob,"  造成"+damage+"點傷害!!\n"); 
	    COMBAT_D->report_status(ob);	

	}
	else message_vision("\n莫名之力直直攻向$N，結果被$N機靈的化解了。\n",ob);

 	me->start_busy(1);

}