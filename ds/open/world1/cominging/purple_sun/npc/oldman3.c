// 老人 3 : 敘事的主題 ( 廣自成 )

#include <ansi.h>
inherit NPC;

string lieh(object me);

void create()
{
	set_name( "廣自成", ({"chan-tzyh goang", "goang", "tzyh", "chan-tzyh", "chan" }) );
	set("long",@LONG
一位身形憔悴的老人，但是臉上的神色卻很紅潤。
LONG	);

	set("title", HIB"紫陽四隱 - 廣"NOR);
	set("gender", "男姓");
	set("race", "人類");
	set("age", 80+random(30));
	set("level",40);
	set("evil",20+random(20));
	set("attitude", "heroism" );

	set_skill("dodge", 70+random(10));
	set_skill("parry", 50+random(20));
	set_skill("unarmed", 65+random(30));
	set_skill("sword", 78);
	set_skill("force", 100);
	set_skill("sorgi_sword", 75);
	set_skill("moon_force", 70);

	map_skill("force","moon_force");
	map_skill("sword","sorgi_sword");

	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sigh" :),
}));
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  (: command,"exert moon_force recover" :),
  (: command,"angry" :),
  (: command,"say 真他奶奶的, 連老人都趕欺負..":),
}));
	set("inquiry", ([
  "小夥子" : (: lieh :),
]));

	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}

void init()
{
	call_out("greeting", 0, this_player());
}

void greeting(object me)
{
	if( interactive(me) ) command("say " + RANK_D->query_respect(me) + ", 你可有瞧見我那 小夥子 ？");
}

string lieh(object me)
{
	object hon = present("yuann-hwan horng", environment(this_object()) );
	me = this_player();
	if( !me->query_temp("book") )
	{
		call_out("call_hon", 2, hon, me);
		me->set_temp("book", 1);
		return "小夥子嗎？他就是前幾年來到山上的那個小子呀！\n他就是那個叫什麼∼什麼∼咺元列吧 ,洪老頭？\n";
	}
	else return "你已經問過我了還問？\n";
}

void call_hon(object hon, object me)
{
	hon->lieh(me, 0);
	return;
}
