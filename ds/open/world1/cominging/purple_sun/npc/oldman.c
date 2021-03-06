// 老人 1 : 教人進山洞 ( 江樂勝 )

#include <ansi.h>
inherit NPC;

string stone(object me);

void create()
{
	set_name( "江樂勝", ({"yuen-shan jiang", "jiang", "yuen", "shan", "yuen-shan" }) );
	set("long", @LONG
一位身形憔悴的老人，但是臉上的神色卻很紅潤。
LONG	);

	set("title", HIW"紫陽四隱 - 江"NOR);
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
  "石室" : "進不去是嗎？你可以推推看那扇門！\n",
  "開門" : "進不去是嗎？你可以推推看那扇門！\n",
]));

	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}

void take_thing_a(object me)
{
	command("say 嗯...");
	call_out("take_thing", 3, me);
	return;
}

void take_thing(object me)
{
	if( !me ) return;
	me->set_temp("open_stone_door", 1);
	message_vision("$N在$n的耳邊悄悄的講了幾句話..\n", this_object(), me);
	if( me->query("level") == 25 && me->query("class2")!="疾風門" && me->query("class1")=="疾風門" )
                   tell_object(me, HIC+this_object()->name()+"對你說: "+ RANK_D->query_respect(me) + "你進去後面的石室裡(push 石壁), 拿那顆元氣石給軒轅烈, 他就會收你了！\n"NOR);
    else tell_object(me, HIC+this_object()->name()+"對你說: "+ RANK_D->query_respect(me) + "你進去後面的石室裡(push 石壁), 拿那顆元氣石, 會有用處的！\n"NOR);
}
