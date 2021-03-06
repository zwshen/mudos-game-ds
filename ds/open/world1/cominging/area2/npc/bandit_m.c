#include <ansi.h>
inherit NPC;

void create()
{
	set_name("強盜小頭頭", ({ "bandit leader","leader","bandit","golden dragon" }));
	set("long","這是金龍寨的一個小頭頭，他身上裝備著許多的裝備，手上拿著一把銳利的刀，發出耀人的閃光. \n");

	set("level",32+random(2));
        set("age",36+random(3));
        set("title",HIY"金"HIR"龍"HIM"寨"NOR);

	set("combat_exp", 43000);
	set("chat_chance", 10);
        set("chat_msg", ({
  (: command,"snort" :),
  (: command,"hmm" :),
  name(1)+"臉上一時殺氣斗現，一副想要殺人的樣子。\n",
  (: random_move :),
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
}));
	set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。

	set_skill("blade", 65);
	set_skill("parry", 30);
	set_skill("combat", 100);
	set_skill("dodge", 75);

        setup();
	carry_object(__DIR__"wp/s_m_blade")->wield();
	carry_object(__DIR__"eq/s_boots")->wear();
	carry_object(__DIR__"eq/cloth")->wear();
	carry_object(__DIR__"eq/rain_belt")->wear();
}

void init()
{
	::init();
	remove_call_out("snort");
	call_out("snort", 1);
}

void snort()
{
	command("snort");
}

void die()
{
	object ob, counter;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}

	counter = find_object(__DIR__"counter.c");

	counter->query_bandits(ob);

	::die();
        //destruct(this_object());
        return;
}