inherit NPC;
#include <ansi.h>
#include <guild_mark.h>
void create()
{
	set_name(HIC"Obi-Wan"NOR, ({ "Obi-Wan Kenobi", "obi","wan" }) );
	set("title", HIW"『Jedi Knight』"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long",@LONG
他是『Jedi Knight』的武士，提供基本的技巧訓練。你可
以使用 list來看看有什麼技巧可以提供學習(train)。也可以用
advance <level或屬性> 來升級, 升級前建議先使用 level指令
來查閱所需要的經驗值。

[ 若想加入Jedi Knight公會, 請輸入 join jedi ]
[ 查閱Jedi Knight會技能, 請輸入 list       ]

LONG
	);
	set("attitude", "peaceful");
	set("level",40);
	set("evil",-100);
	
	set_skill("sword", 95);
	set_skill("block", 90);
	set_skill("dodge", 100);
	set_skill("dagger",92);
	set_temp("apply/armor",38);

	
	//公會設定
	
	set("class","jedi");
	set("adv_class",1);
	set("class1",HIW"『Jedi Knight』"NOR);
	set("no_check_class",1);
	set("guild_gifts",({2,6,8,4}));
	set("guild_skills",([
		"block":	({180,2,50}),
//		"heal":   ({100,2,50}),
		"sword":	({180,2,50}),
		"dodge": 	({180,3,65}),
		"parry": 	({180,2,50}),
//		"lightsaber knowlege":	({180,2,50}),
//		"force_push":	({180,2,50}),
		"perception": 	({180,2,50}),
		"organization":	({180,2,50}),
//		"free_action":	({180,2,50}),
	])  );

	setup();
//	carry_object(__DIR__"eq/cloth")->wear();
//      carry_object(__DIR__"wp/masterfork")->wield();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);	
}

int do_skill_train(string arg)
{
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}

int do_join(string arg)
{
	int i;
	string guild_rank;
	object ob, me;

	ob = this_object();
	me = this_player();
	

	if(me->query("evil")>100) return notify_fail("你太邪惡了不適合加入本公會。\n");
	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	switch(i)
	{
	case 0:  return notify_fail("人物設定錯誤，請通知巫師幫忙解決。\n");
	case -1: return notify_fail("你已經加入其他公會了。\n");
	case -2: return notify_fail("你已經加入其他公會了。\n");
	case -3: return notify_fail("你不適合加入本公會。\n");
	case -4: return notify_fail("你目前的等級不適合加入本公會。\n");
	case -5:
	case -6:
	case -7: return notify_fail("你的條件不適合加入本公會。\n");
	case -8: return notify_fail("沒有這種職業。\n");
	}
	if(!guild_rank = this_object()->guild_rank(me) || guild_rank=="")
			guild_rank = "新加入的新手武士";
	me->set("guild_rank",guild_rank);

            message_vision("$N加入了Jedi Knight公會。\n",me);
 	return 1;
}

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
	if(me->query("class1")=="jedi" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是Jedi Knight公會的武士。\n");
}
string guild_rank(object me)
{
	string rank;
	if( me->query("gender") == "女性" )
	{
		switch( me->query("level")/5 )
		{
			case 0: rank = "笨手笨腳的小女賊"; break;
			case 1: rank = "四處流竄的小女賊"; break;
			case 2:	rank = "技術純熟的女飛賊"; break;
			case 3:	rank = "難以捉摸的女盜賊"; break;
			case 4:	rank = "橫行霸道的女大盜"; break;
			case 5:	rank = "神出鬼沒的女神偷"; break;
			default: rank = "神出鬼沒的女神偷";
		}
	}
	else
	{
		switch( me->query("level")/5 )
		{
			case 0: rank = "笨手笨腳的笨小偷"; break;
			case 1: rank = "動作靈活的小盜  "; break;
			case 2:	rank = "技巧熟練的小賊  "; break;
			case 3:	rank = "前科累累的慣竊  "; break;
			case 4:	rank = "橫行霸道的大盜  "; break;
			case 5:	rank = "神出鬼沒的神偷  "; break;
			default: rank = "神出鬼沒的神偷  ";
		}
	}
	return rank;
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
	message("world:world2:vision",
HIC"\n  [本日頭條]:"HIW"\n\n\t"+ob->name(1)+"涉嫌殺害號稱「神手」，目前警方已經組成專案小組進行調查中。\n\n"+NOR
	,users());
	ob->add("popularity",2); //聲望
	::die();
	//destruct(this_object());
	return;
}
