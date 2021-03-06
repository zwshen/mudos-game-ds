#include <ansi.h>
inherit NPC;

string book(object me);
string *msg = ({
  "游機子說﹕那本小冊子, 我放在四大舍的龍風小舍去了, 你去找找看吧！\n",
});

void create()
{
	set_name(WHT"游機子"NOR,({ "left-escort you","you","left-escort","left","escort" }));
	set("long" ,@LONG
    他是疾風門的光明左使，在疾風門之中等級共分五級，分別是
門主，舵主，護使，堂主，弟子等階位，疾風門之中光明右使乃是
專門收人子弟，而疾風門的光明左使則是傳授武功之用，游機子從
小就入了疾風門，他小時候父母雙亡，在一次的偶然巧遇中，遇上
了疾風門祖師爺軒轅烈，因而拜其為乾爹，軒轅烈在後來投戎從軍
時委派他為光明左使，他為人厚道，所以常為同儕玩笑，但他都一
笑置之。
LONG
	);
	set("nickname","如雲幻境");
	set("attitude","friendly");
	set("age", 20+random(10));
	set_temp("sorgitimes",12);
	set("level", 42);

	set("gender","男性");
	set("max_ap",3500);
	set("race","人類");

	set("combat_exp", 49000+random(4500));

	set("title",HIY"疾風門"HIM"光明左使"NOR);

	set("class1","疾風門");
	set("flurrydodge",1);
	create_family("疾風門",10,"光明左使");

	set_skill("sword", 90);
	set_skill("dodge", 95);
	set_skill("force", 100);
	set_skill("parry", 80);
	set_skill("sorgi_sword",85);
	set_skill("fogseven",100);
	set_skill("moon_force",100);

	map_skill("sword","sorgi_sword");
	map_skill("dodge","fogseven");

	set("chat_chance",8);
	set("chat_msg", ({
  (: command("sigh") :),
  (: command(":)") : ),
  (: command("exert moon_force recover"):),
}));
    set_temp("class_wind/power",250);
    set("chat_chance_combat",100);
	set("chat_msg_combat",({
  (: command,"exert sorgi_sword" :),
  (: command,"exert moon_force moon_arc" :),
  (: command,"wield sword" :),
  (: command,"exert moon_force recover" :),
}));

	set("inquiry",([
  "name" : "我姓游，名機子。\n",
  "moon_force" : "殘月心法是我疾風門各長老所共同創造出來之品，
小兄弟若有心學習，可以向我詢問(enquire)。\n",
  "小冊子" : (: book :),
  "冊子" : (: book :),
]));
	setup();
	carry_object(__DIR__"wp/oldsword")->wield();
	carry_object(__DIR__"eq/flurryneck")->wear();
	carry_object(__DIR__"eq/flyboots")->wear();
}

void init()
{
	object me, ob;
	ob = this_object();
	me = this_player();
	if( me->query_temp("meet_lieh" ) && me->query("level") > 9 )
	{
		me->delete_temp("meet_lieh");
		message_vision(HIY"$N一字一字的慢慢告訴$n疾風門門主的下落。\n"NOR,me,ob);
		message_vision("$N聽完$n的告知後，對$n說道：\n",ob,me);
		message_vision("  "+RANK_D->query_respect(me)+"我現在將疾風門的殘月內功\口訣教授與你，要仔細聽好了！\n"NOR,me);
		message("sound", HIG""+ob->name()+"將疾風門殘月心法的要訣告訴了"+me->name()+"。\n\n"NOR,environment(me), me);
		write("※ "+ob->name()+"將疾風門的殘月心法口訣傳授與你。 ※\n");
		me->improve_skill("moon_force", 10);
	}
	else if( me->query_temp("meet_lieh" ) && me->query("level") < 10 )
	{
		me->delete_temp("meet_lieh");
		message_vision(HIY"$N一字一字的慢慢告訴$n疾風門門主的下落。\n"NOR,me,ob);
		command("thank "+me->query("id"));
		tell_object(me,this_object()->name()+"告訴你: 你現在基礎等級還不夠, 還不能領悟到殘月心法的真義。\n");
	}
	add_action("do_enquire","enquire");
}

int do_enquire(string arg)
{
	object ob,me;
	ob = this_object();
	me = this_player();
	if( !me )return 0;
	if( me->query("class1")!="疾風門" )return notify_fail("你不是疾風門的子弟。\n");
	if( arg!="you" && arg!="left-escort" && arg!="left-escort you" )
		return notify_fail("你要詢問誰什麼東西？\n");
	if( me->query_skill("moon_force") > 0 )
		return notify_fail("你已經學過殘月心法。\n");
	else
	{
		message_vision("$N說：若"+RANK_D->query_respect(me)+"能報知本門門主軒轅烈大哥目前狀況，定當傾囊相授所學。\n",ob);
		command("bow "+me->query("id"));
		me->set_temp("find_lieh",1);
		return 1;
	}
}

string book(object me)
{
	me = this_player();
	if( !me->query_temp("get_book") )
		return "什麼小冊子？我不知道ㄝ... \n";
	if( me->query_temp("get_book") )
	{
		call_out("delay", 2, me, 0);
		return "是軒轅大哥叫你來跟我要的嗎？\n";
	}
}

void delay(object me, int flag)
{
	message_vision(msg[flag], this_object());
	if( ++flag < sizeof(msg) )
	{
		call_out("delay", 1, me, flag );
		return;
	} 
	tell_object(me, HIC" 說到這, 你知道你可以去那找冊子了！ \n"NOR);
	return;
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
CYN"\n  武林傳出了一則消息:\n\n\t一「如雲幻境」游機子敗給了"+ob->name(1)+"。\n\n"+NOR
        ,users());
        ob->add("popularity", 2); 
        ::die();
        return;
}
