inherit NPC;

void create()
{
	set_name("李書文", ({ "master lee shu wen", "master", "lee" }) );
	set("nickname", "神槍李");
	set("gender", "男性");
	set("class","fighter");
	set("age", 60);
	set("adv_class",1);
	set("class1","八極門");

	set("guild_gifts",({10,7,0,3}));
	set("long",
"李書文看來短小，卻給人相當精悍的感覺，一臉肅穆，令人望之生畏。\n"
"他更是現今「八極門」的第六代掌門，不僅精通八極拳，其大槍訣更是已達\n"
"登峰造極的境界，在江湖上是位極有名的一代宗師。\n"

	);
	set("attitude", "peaceful");
set("level",50);
	set("guild_skills",([
		"bagi_fist":({160,2,50}),
		"horse-steps":({120,2,10}),
		"dodge" : ({130,2,50}),
		"parry" : ({130,2,50}),
		"unarmed":({150,2,50}),
		"fork":({130,2,40}),
        "da-fork":({160,2,5}),
	])  );
	set_skill("unarmed", 90);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("fork",120);
	set_skill("bagi_fist",100);
	set_skill("da-fork",100);
	set_skill("horse-steps",100);

	set_temp("apply/armor",30);
            set("chat_chance_combat", 90);
            set("chat_msg_combat", ({
	           	 (:command("exert bagi_fist"):),
		(:command("snort"):),
		(:command("exert da-fork"):),
       	 }) );
	
	create_family("八極門", 6, "掌門人");
	setup();
carry_object("/open/world1/tmr/area/npc/wp/masterfork")->wield();
}

void init()
{
::init();
            add_action("do_skill_list","list");
            add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_speak","speak");
	add_action("do_join","join");
         add_action("do_force1","force1");
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
  int do_force1(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕force <人物> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}
