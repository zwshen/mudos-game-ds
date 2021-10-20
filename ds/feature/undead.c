// damage.c
// #pragma save_binary
#include <ansi.h>

varargs int receive_damage(string type, int damage, object who, string elem)
{
	return 1;
}

varargs int receive_wound(string type, int damage, object who)
{
	return 1;
}

void die()
{
	object corpse, killer;
	
	killer = this_object()->query_temp("last_damage_from");
	this_object()->remove_all_enemy();
	this_object()->remove_all_killer();
	if( objectp(killer) ) killer->remove_killer(this_object());
	message_vision("$N�j�ۤ@�n: ����..�ڬO��������!!!!\n",this_object());
	return;	
}

int apply_undead(object ob)
{
	if(!ob) return 0;
	if(this_object()==shadow(ob,0)) return 0;
	if(query_shadowing(this_object())) return 0;
	shadow(ob,1);
	return 1;
}

int have_undead() { return 1; }

int destruct_undead()
{
	destruct(this_object());
	return 1;
}