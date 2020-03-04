// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
	set_name("�L��", ({ "zombie" }) );
	set("long",
		"�o�O�@��Q�H�βũG����L�͡M�q���a�ժ��y�W�ݤ��X����߫�s�֡C\n");
	set("str", 60);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		"�L�ͤf���o�X�������s�n�C\n",
		"�L�ͪ��y�W�}�l�j�ˡM�@�}���z�M�o�g���a�j�s�C\n",
		"�L�ͤ����߱i�M�r�������M�S�X�u�񪺯��e�C\n",
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
		say( name() + "�w�w�a�ˤF�U�ӡM�Ƭ��@�y����C\n");
	}

	destruct(this_object());
}

int heal_up()
{
	object master;

	if( objectp(master = query("possessed")) 
	&&	(int)master->query("mp") > 10 ) {
		message("tell",
			HIR + name() + "�i�D�A�R��...��...�n...�A...��...�O...�q...\n" NOR,
			master );
		master->receive_damage("mp", 10);
		::heal_up();
		return 1;		// Always acquire power from master.
	} 
}

void do_bite()
{
	object *enemy;

	say( name() + "�f���Q�X�@�Ѥ��H���ê����M�ϧAı�o�Y�w���ȡC\n" );
	enemy = query_enemy();
	for(int i=0; i<sizeof(enemy); i++) {
		if( !enemy[i] ) continue;
		enemy[i]->receive_damage("hp", 20);
		COMBAT_D->report_status(enemy[i], "hp");
	}
}