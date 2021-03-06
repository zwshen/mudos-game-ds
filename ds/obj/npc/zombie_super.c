// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
	set_name("殭屍", ({ "zombie" }) );
	set("long",
		"這是一具被人用符咒控制的殭屍﹐從它蒼白的臉上看不出任何喜怒哀樂。\n");
	set("str", 60);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		"殭屍口中發出荷荷的叫聲。\n",
		"殭屍的臉上開始痙攣﹐一陣抽搐﹐發狂似地大叫。\n",
		"殭屍五指箕張﹐咬牙切齒﹐露出猙獰的笑容。\n",
		(: do_bite :),
  (: command, "exert dragonfist" :),
	}) );
  set("level", 100);
  set("combat_chat_chance", 10);
  set_skill("unarmed", 100);
  set_skill("dragonfist", 100);
  set_skill("force", 100);
	set_skill("dodge", 30);

	set_temp("apply/damage", 15);

	setup();
}

int is_zombie() { return 1; }

void animate(object who, int time)
{
	set("possessed", who);
	set_leader(who);
}

void dispell()
{
	object corpse;

	if( environment() ) {
		say( name() + "緩緩地倒了下來﹐化為一灘血水。\n");
	}

	destruct(this_object());
}

int heal_up()
{
	object master;

	if( objectp(master = query("possessed")) 
	&&	(int)master->query("mp") > 10 ) {
		message("tell",
			HIR + name() + "告訴你﹕我...需...要...你...的...力...量...\n" NOR,
			master );
		master->receive_damage("mp", 10);
		::heal_up();
		return 1;		// Always acquire power from master.
	} 
}

void do_bite()
{
	object *enemy;

	say( name() + "口中噴出一股中人欲嘔的臭氣﹐使你覺得頭暈腦脹。\n" );
	enemy = query_enemy();
	for(int i=0; i<sizeof(enemy); i++) {
		if( !enemy[i] ) continue;
		enemy[i]->receive_damage("hp", 20);
		COMBAT_D->report_status(enemy[i], "hp");
	}
}
