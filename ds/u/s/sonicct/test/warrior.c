#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIR"戰士導師"NOR, ({"master warrior","warrior","master"}) );
	set("long", 
    "他是戰士指導教師，提供基本的技巧訓練。你可以使\n"
    "用"HIR"list"NOR"來看看有什麼技巧可以提供學習(train)\n"
    "。也可以用advance <level或屬性> 來升級, 升級前建議\n"
    "先使用level 指令來查閱\所需要的經驗值。\n"
    );

	set("race", "人類");
	set("no_join", 1);
	set("age", 37);
set("level",50);
        set("attitude", "heroism");
        set_skill("parry",100);
set_skill("fogseven",100);
set_skill("fork",100);
        set_skill("dodge",100);
        set("guild_skills", ([
        "dodge":({50,5,35}),
        "parry":({30,5,40}),
        "unarmed":({40,5,40}),
        ]) );
set("chat_chance_combat", 80);
set("chat_msg_combat", ({
(:command,"exert fogseven":),
}) );

	setup();
carry_object("/u/s/sonicct/test/finallance.c")->wield();
}
void init()
{
        object ob;

        ::init();
                if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("d_advance","advance");
        add_action("d_list","list");
        add_action("d_train","train");
}
int d_advance(string arg)
{
 return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int d_list(string arg)
{
 return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int d_train(string arg)
{
 return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "戰士導師道:"HIC"歡迎各位戰士在此學習技巧。"NOR"\n");
                        break;
                }
}
