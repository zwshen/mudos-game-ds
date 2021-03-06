// master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("駱雲舟", ({ "master scholar", "master", "scholar" }) );

	set("gender", "男性");
	set("age", 32);
	set("long",
		"駱雲舟生於京城有名的武林世家﹐他的本名是駱建炎﹐但是因為生性喜愛\n"
		"四處遊蕩﹐遂自號「雲舟」﹐四處遊山玩水﹐結交豪傑異人。數年前繼承\n"
		"其父駱易而成為步玄派的新任掌門﹐但是喜愛飄泊的個性仍然不改﹐令門\n"
		"中耆宿頭痛不已。\n" );

	set("attitude", "peaceful");
	create_family("步玄派", 7, "掌門人");

	set("str", 26);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);

	set("force", 3000);
	set("max_force", 1600);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 60);
	set_skill("sword", 90);
	set_skill("force", 80);
	set_skill("parry", 90);
	set_skill("dodge", 100);
	set_skill("literate", 150);
	set_skill("perception", 80);

	setup();
}

/*
void init()
{
	add_action("do_swear", "swear");
}

void attempt_apprentice(object me)
{
	if( me->query_temp("pending/celestial_swear") ) {
		command("say 多說無益﹐若不發誓恪守門規﹐便是跪著求我也沒用。");
		return;
	} else {
		command("say 我天邪派門規甚嚴﹐" + RANK_D->query_respect(me)
			+ "如果真的有心﹐且發個誓(swear)來。");
		me->set_temp("pending/celestial_swear", 1);
	}
}

int do_swear(string arg)
{
	if( !this_player()->query_temp("pending/celestial_swear") )
		return 0;
	if( !arg ) return notify_fail("你要發什麼誓﹖\n");
	this_player()->set_temp("pending/celestial_swear", 0);
	message_vision("$N發誓道﹕" + arg + "\n", this_player());
	if( strsrch(arg, "守") >=0 && strsrch(arg, "門規") >=0 ) {
		command("smile");
		command("say 這就是了。\n");
		command("recruit " + this_player()->query("id"));
	} else {
		command("say 你發的是什麼鬼誓﹐別以為我沒聽到﹗");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_availavble", -1);
}
*/
void consider()
{
	int i, flag = 0;
	object *enemy;

	enemy = query_enemy() - ({ 0 });
	for(i=0; i<sizeof(enemy); i++) {
		if( !living(enemy[i]) ) continue;
		if( enemy[i]->query_temp("weapon") ) {
			flag++;
			if(	!query_temp("weapon") ) {
				command("say " + RANK_D->query_respect(enemy[i]) + "既然使兵刃﹐在下空手接招未免不敬。");
				command("wield sword");
				command("say 進招吧﹗");
				break;
			}
		}
	}
	if( !flag && query_temp("weapon") ) {
		if( sizeof(enemy) > 1 )
			command("say 嗯... 既然" + chinese_number(sizeof(enemy)) + "位都是空手﹐在下理當奉陪﹗");
		else
			command("say 既然" + RANK_D->query_respect(enemy[0]) + "不使兵刃﹐在下自然奉陪﹗\n");
		command("unwield sword");
	}
}
