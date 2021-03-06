
inherit NPC;

void create()
{
	set_name("李書文", ({ "master lee shu wen", "master", "lee" }) );
	set("nickname", "神槍李");
	set("gender", "男性");
	set("class","fighter");
	set("age", 34);
	set("adv_class",1);
	set("class1","八極門");
	set("long",
"李書文看來短小，卻給人相當精悍的感覺，一臉肅穆，令人望之生畏。\n"
"他更是現今「八極門」的第六代掌門，不僅精通八極拳，其大槍訣更是已達\n"
"登峰造極的境界，在江湖上是位極有名的一代宗師。\n"

	);
	set("attitude", "peaceful");
	set("level",40);
	set("guild_skills",([
		"fork":({150,2,40}),
		"dodge" : ({140,2,50}),
		"parry" : ({140,2,50}),
		"unarmed":({150,2,50}),
		"bagi_fist":({160,2,50}),
		"horse-steps":({100,2,10}),
	])  );
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("bagi_fist",100);
	set_skill("horse-steps",100);
	set_temp("apply/armor",30);
            set("chat_chance_combat", 90);
            set("chat_msg_combat", ({
            	 (:command("exert bagi_fist"):),
       	 }) );
	
	create_family("八極門", 6, "掌門人");
	setup();
     carry_object(__DIR__"eq/cloth")->wear();
     carry_object(__DIR__"wp/dragon-fist")->wield();
}

void init()
{
::init();
            add_action("do_skill_list","list");
            add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_speak","speak");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_list(ob,me,arg);	
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
	int i;
	object ob, me;

	ob = this_object();
	me = this_player();

	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	message_vision("$N想加入「"+ arg+ "」。\n",me);	

	switch(i)
	{

	case -1: return notify_fail("你已有門派了耶。....^_^\n");
	case -2: return notify_fail("你已是八極門的弟子了。\n");
	case -8: return notify_fail("沒有這種門派耶....:P\n");
	}
	if(me->query_temp("eight_speak") )
		command("say 這位"+ RANK_D->query_respect(me) +"如不知那句話，就是在此跪了三天三夜，我也是不會收的。\n");
	else	
	{
		command("say 不敢當，如你能說出(speak)本門被江湖所盛傳的一句話，我就收了你吧");
		me->set_temp("eight_speak",1);			
	}

	return 1;
}

int do_speak(string arg)
{
	object me;
	me=this_player();

	if(!me->query_temp("eight_speak") )return 0;

	if(arg != "劈掛參八極，英雄歎莫及")
	{
		message_vision("$N大聲說出：「"+ arg +"。」\n",me);
		command("shake");
		command("say 不是不是，再想想吧。");
	}
	else
	{
		message_vision("$N大聲說出：「"+ arg +"。」\n",me);
		command("smirk");
		command("say 好，就是這句話，我就收你入「八極門」門下吧！。");
		me->set("adv_class",1);
		me->set("class1","八極門");
 		me->create_family("八極門",7,"俠客");
 		me->delete_temp("eight_speak");
	}	

	return 1;
}

int do_advance(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	if(me->query("class1")=="八極門" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是八極門的弟子。\n");
}
