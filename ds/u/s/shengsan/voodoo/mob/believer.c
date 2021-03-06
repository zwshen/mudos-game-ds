#include <path.h>
inherit NPC;

void use_poison();

void create()
{
	set_name("教徒", ({"believer"}) );
	set("race", "人類");
	set("gender", "男性");
	set("level",35);
	set("age", 19);
set("evil",10+random(5));
	set("long", "他是一位巫毒教的教徒\n");

	set("combat_exp", 80000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: use_poison :)
	}) );

	set("chat_chance",50);
//	set("chat_msg",({ (:random_move:) }));
	set("chat_msg",({
	   (:command,"east":),
	   (:command,"west":),
	   (:command,"south":),
	   (:command,"north":),
	   (:command,"up":),
	   (:command,"down":)
           }));
           
	setup();

	add_money("coin",50);
	carry_object(SHENGSAN+"voodoo/eq/dagger")->wield();
}

void use_poison()
{
	object *enemy, ob;
	string msg;
	int damage;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob->query_condition("poison") ) return;

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
	{
	  ob->apply_condition("poison", 20);
	  message_vision("白色的粉末從$N手中直直襲向$n。\n",this_object(), ob);
	  tell_object(ob, "你覺得臉上似乎沾上了什麼東西，伸手一摸卻什麼也沒有。\n");
	}
}
