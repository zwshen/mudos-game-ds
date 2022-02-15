// move.c
//#pragma optimize
// #pragma save_binary
#include <dbase.h>
nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;
nosave int capacity = 0, max_capacity = 0;
nosave int light = 0, current_light = 0;
nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }
nomask int query_max_encumbrance() { return max_encumb; }
//�]�w�˸����q
nomask void set_max_encumbrance(int e)
{
	if(e<0) e=0;
	max_encumb = e;
	if(this_object()->is_item() && max_capacity == 0) max_capacity = e/2000;
}
nomask void add_encumbrance(int w)
{
	encumb += w;
	if( encumb < 0 )
	{
		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
		encumb=0;
	}
	if( encumb > max_encumb ) this_object()->over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}
int query_current_light() { return current_light; }
int query_light() { return light; }
nomask int light() { return light + current_light; }
nomask void add_light(int w)
{
	current_light += w;
	if( current_light < 0 )
	{
		log_file("move.bug", sprintf("%O current_light underflow.\n", this_object()));
		current_light=0;
	}
	if( environment() ) environment()->add_light(w);
}
nomask void start_light(int w)
{
	if(w<0) w=0;
	if( !environment() ) {
		light = w;
		return;
	}
	if( w!=light ) environment()->add_light( w - light );
	light = w;
}
void over_encumbrance()
{
	if( !interactive(this_object()) ) return;
	tell_object(this_object(), "�A���t���L���F�T\n");
}
nomask int query_capacity() { return (int)capacity; }
nomask int query_real_capacity() { return capacity; }
nomask int over_capacitied() { return capacity > max_capacity; }
nomask int query_max_capacity() { return max_capacity; }
//�]�w�˸��Ŷ�
nomask void set_max_capacity(int e)
{
	if(e<0) e=0;
	max_capacity = e; 
}
nomask void add_capacity(int v)
{
	capacity = capacity + v;
	if( capacity < 0 )
	{
		log_file("move.bug", sprintf("%O capacity underflow.\n", this_object()));
		capacity=0;
	}
	if( capacity > max_capacity ) this_object()->over_capacity();
}

void over_capacity()
{
	if( !interactive(this_object()) ) return;
	tell_object(this_object(), "�A�a���F����n�Ӥj�F�T\n");
}

nomask int query_weight() { return weight; }

nomask void set_weight(int w)
{
	if(w<0) w=0;
	if( !environment() ) {
		weight = w;
		return;
	}
	if( w!=weight ) environment()->add_encumbrance( w - weight );
	weight = w;
}

// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

nomask int can_move(mixed dest)
{
	object ob, env;
	int i;
	string *tmp;
	if( query("equipped") && !this_object()->unequip() ) return 0;
	if( objectp(dest) ) ob = dest;
	else if( stringp(dest) )
	{
		if(strsrch(dest,"..")!=-1)
		{
			tmp = explode(dest,"/");
			for (i = 0; i < sizeof(tmp); i++)
			if (tmp[i] == "..") {
				if (sizeof(tmp) > 2) {
					tmp = tmp[0..(i-2)] + tmp[(i+1)..(sizeof(tmp)-1)];
					i -= 2;
				} else {
					tmp = tmp[2 ..(sizeof(tmp)-1)];
					i = 0;
				}
			}
	 		dest = "/" + implode(tmp,"/");
		}
		call_other(dest, "???");
		ob = find_object(dest);
		if(!ob) return 0;
	} else	return 0;
	env = this_object();
	while(env = environment(env)) if( env==ob ) break;
	// ���q����
	if(!env && (int)ob->query_encumbrance() + weight() > (int)ob->query_max_encumbrance() )
	{
		if(ob->is_character())
		{
		 	if(ob == this_player() ) return notify_fail("�A�����ʳo�˪F��C\n");
		 	else return notify_fail("��讳���ʳo�˪F��C\n");
		}
		return notify_fail("��"+ob->name(1)+"�Ө��ӭ��F�C\n");
	}
	// �Ŷ�����
	if( (int)ob->query_capacity() + (int)query("volume") > (int)ob->query_max_capacity() )
	{
		if(ob->is_character())
		{
			if(ob == this_player())	return notify_fail("�A���W�w�g�S���Ŷ���o�˪F��F�C\n");
			else return notify_fail("��設�W�S���������Ŷ���o�˪F��C\n");
		}
		return notify_fail("���̨S���������Ŷ���o�ӪF��C\n");
	}
	return 1;
}
void delay_look(object env)
{
	//remove_call_out("delay_look");
	if(!env) return;
	if(environment(this_object()) != env) return;
	command("look");
	return;
}
varargs int move(mixed dest, int silently)
{
          object ob, env,ob_env;
          string *tmp;

	int i;
	// If we are equipped, unequip first.
	if( query("equipped") && !this_object()->unequip() )
		return notify_fail("�A�S����k���U�o�˪F��C\n");

	// Find the destination ob for moving.
	if( objectp(dest) )
		ob = dest;
	else if( stringp(dest) ) {
		if(strsrch(dest,"..")!=-1)
		{
			tmp = explode(dest,"/");
			for (i = 0; i < sizeof(tmp); i++)
			if (tmp[i] == "..") {
				if (sizeof(tmp) > 2) {
					tmp = tmp[0..(i-2)] + tmp[(i+1)..(sizeof(tmp)-1)];
					i -= 2;
				} else {
					tmp = tmp[2 ..(sizeof(tmp)-1)];
					i = 0;
				}
			}
	 		dest = "/" + implode(tmp,"/");
		}
		call_other(dest, "???");
		ob = find_object(dest);
		if(!ob) return notify_fail("move: ���ʥ���(�L�k���J�ت��ɮ�).\n");
	} else
		return notify_fail(sprintf("move: ���ʦܥؼЪ���ɵo�Ϳ��~: %O.\n", dest));

	// Check if the destination ob can hold this object.
	// Beforce checking it, we check if the destination is environment of
	// this_object() (or environment of its environment). If it is, then
	// this could be like get something from a bag carried by the player.
	// Since the player can carry the bag, we assume he can carry the this
	// object in the bag and encumbrance checking is unessessary.
	env = this_object();
	while(env = environment(env)) if( env==ob ) break;
	if( !env && (int)ob->query_encumbrance() + weight() > (int)ob->query_max_encumbrance() )
	{
		if( ob==this_player() ) //���a����Ĳ�o get buy
		{
			if(ob_env=environment(ob))
			{
				if(ob_env==environment(this_object())) return notify_fail( this_object()->name() + "��A�Ө��ӭ��F�C\n");
				else if(this_object()->move(ob_env,silently))
				     {
						write( this_object()->name() + "�]���ӭ��F�ӱ���a�W�C\n");
						return 1;
				     } else return notify_fail( this_object()->name() + "��A�Ө��ӭ��F�C\n");
			} else return notify_fail( this_object()->name() + "��A�Ө��ӭ��F�C\n");
		}
		else return notify_fail( this_object()->name() + "��" + ob->name() + "�Ө��ӭ��F�C\n"); //give ,go
	}
	
	if( !env && (int)ob->query_capacity() + (int)query("volume") > (int)ob->query_max_capacity())
	{
		if(!ob->is_character()) return notify_fail( "���̨S���������Ŷ��C\n");
		if( ob==this_player() ) //���a����Ĳ�o get buy
		{
		    	if(ob_env=environment(ob))
			{
				if(ob_env==environment(this_object())) return notify_fail( "�A���W���Ŷ������C\n");
				else if(this_object()->move(ob_env,silently))
				     {
						write( this_object()->name() + "�]�����W�񤣤U�ӱ���a�W�C\n");
						return 1;
				     } else return notify_fail( "�A���W���Ŷ������C\n");
			} else return notify_fail( "�A���W���Ŷ������C\n");
		} else return notify_fail( ob->name() + "���W���Ŷ������C\n");
	}
	// Move the object and update encumbrance
	if( environment() )
	{
		environment()->add_encumbrance( - weight());
		environment()->add_light( - light());
		environment()->add_capacity( - query("volume"));
		this_object()->set("last_location", file_name(environment()));
		if(living(this_object()))
		{
			//�a�ϳB�z
			if(this_object()->query_temp("map_record")) ROOM_D->moveout(environment(),this_object());
		}
	}
	move_object(ob);
	ob->add_encumbrance(weight());
	ob->add_light(light()); //�ө���
	ob->add_capacity(query("volume"));
//	IDCHECK_D->check_file(base_name(this_object()),ob);
	// If we are players, try look where we are.
	if(!this_object()) return 1;
	if(living(this_object()))
	{
		if(environment()->is_room())
			ROOM_D->movein(ob,this_object());		//�a�ϳB�z
		if(interactive(this_object()))		// are we linkdead?
		{
			if( !silently )
			{
				//
				if( query("env/brief") )
					tell_object(this_object(), "�A�Ө�F" + environment()->query("short") + "�C\n");
				else if( this_object()->query("env/delay_look")!=0 && intp(this_object()->query("env/delay_look")) )
				{
					tell_object(this_object(), "�A�Ө�F" + environment()->query("short") + "�C\n");
					remove_call_out("delay_look");
					call_out( "delay_look", query("env/delay_look"), environment());
				}
				else
				{
					command("look");
				}
			}
		}
	}
	return 1;
}

void remove(string euid)
{
	object default_ob;

	if( !previous_object()
	||	base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() �u��Q destruct() simul efun �ҩI�s.\n");
	if(query_shadowing(this_object())) remove_shadow(this_object());
	if( userp(this_object()) && euid!=ROOT_UID )
	{
		log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
			euid, this_object()->query("id"), ctime(time())));
		error("�A(" + euid + ")����R����L���ϥΪ̡C\n");
	}
	 else if( this_object()->query("equipped"))
	{
		if(	!this_object()->unequip() )
			log_file("destruct", sprintf("Move: remove()�I�sunequip()����:%s.\n",file_name(this_object())));
	}

	// We only care about our own weight here, since remove() is called once
	// on each destruct(), so our inventory (encumbrance) will be counted as
	// well.
	if( environment() )
	{
		environment()->add_encumbrance( - weight );
		environment()->add_light( - light());
		environment()->add_capacity( - query("volume") );
		if(this_object()->query_temp("map_record")) ROOM_D->moveout(environment(),this_object());
	}
	if( default_ob = this_object()->query_default_object() )
		default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
	if( userp(this_object()) ) {
		tell_object(this_object(), "�@�}�ɪŪ��ᦱ�N�A�ǰe��t�@�Ӧa��....\n");
		move(VOID_OB);
	}
}
