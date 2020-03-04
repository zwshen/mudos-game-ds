// vehicle.c
// ��ĥ;�B���u��;����;���澹;�ӪŤ��b

#include <dbase.h>
#include <move.h>
#include <name.h>
#include <command.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;
/*
varargs string short(int raw)
{
	string str;
	str=::short(raw);
	//if(this_object() != environment(this_player()) && stringp(str) ) str = replace_string( str,this_object()->query("short"),sprintf("%s(%s)",this_object()->query("name"),this_object()->query("id")));
	if(this_object() == environment(this_player()) && stringp(str) ) str = replace_string( str,this_object()->query("name"),this_object()->query("v_short"));
	return str;
}
*/

int outside_vision(object me)
{
	string str,name;
	name=this_object()->name();
	name+="("+capitalize(this_object()->query("id"))+")\n";
	if(!stringp(str=this_object()->query("vlong"))) str=this_object()->long();
	str=name+str;
	me->start_more(str);
	return 1;
}

void setup()
{
	seteuid(getuid());
	if(!stringp(this_object()->query("unit")))
		this_object()->set("unit","�x");
	if(!this_object()->query("unit"))
		this_object()->set("v_level",1);	// �w�]���Ĥ@�h��ĥ
}

int enter_vehicle(object me)
{
	object obj;
	obj = this_object();
	
	if( me->query("in_vehicle") > this_object()->query("v_level") )	// �ˬd�O�_�w�g�i�J��ĥ�F
	{
		write("���H�A�n�i�J���̡H�C\n");
		return 0;
	}
	if(!me->can_move(obj))	// �ˬd�O�_�i����
	{
		write("�A�S����k�i�J "+obj->query("name")+" �̡C\n");
		return 0;
	}
	else if( me->move(obj) )	// ���沾��
	{
		me->add("in_vehicle",1);	// �W�[�ۤv�b��ĥ�����h��
		message_vision( sprintf("$N�i�J %s �F�C\n",obj->query("name")), me );
	}
	else
	{
		write("�A�N�O�S����k�i�J "+obj->query("name")+" �̡C\n");
		return 0;
	}
		
	return 1;
}

int leave_vehicle(object me)
{
	object env,obj,me_env;
	obj = this_object();
	env = environment(obj);
	me_env = environment(me);
	if(!me_env->is_vehicle())
	{
		return 0;
	}
	if(!me->can_move(env))
	{
		return notify_fail("�A�S����k���} "+obj->query("name")+" �C�C\n");
	}
	else if( me->move(env) )
		message_vision( sprintf("$N���} %s �F�C\n",obj->query("name")), me );
	else
		return notify_fail("�A�N�O�S����k���} "+obj->query("name")+" �C�C\n");
		
	me->add("in_vehicle",-1);
	return 1;
}

string look_out(string arg)	// �d�ݲ�ĥ�~������
{
	string outline;
	object env, obj;
	
	obj = this_object();
	env = environment(obj);
	LOOK_CMD->main(this_object(),arg);
	
	return outline;
}

mapping default_dirs = ([
	"north":		"�_",
	"south":		"�n",
	"east":			"�F",
	"west":			"��",
	"northup":		"�_��",
	"southup":		"�n��",
	"eastup":		"�F��",
	"westup":		"����",
	"northdown":		"�_��",
	"southdown":		"�n��",
	"eastdown":		"�F��",
	"westdown":		"����",
	"northeast":		"�F�_",
	"northwest":		"��_",
	"southeast":		"�F�n",
	"southwest":		"��n",
	"up":			"�W",
	"down":			"�U",
	"enter":		"��",
	"out":			"�~",
]);

int v_go(string arg)	// ��ĥ����
{
	object thisob,obj,env,me;
	mapping exit=([ ]),h_exit=([ ]);
	string dest,dir;
	
	thisob = this_object();
	me = this_player();
	
	env = environment(thisob);
	exit = env->query("exits");
	h_exit = env->query("hide_exits");
	
	if( mapp(exit) && !undefinedp(exit[arg]) );
        else
        if( !mapp(h_exit) || undefinedp(h_exit[arg]) )
        {
        	if( query_verb()=="go")
        	{
	    		write("�o�Ӥ�V�S���X���C\n");
	    		return 0;
	    	}
                else
                        { write("lalalal\n");return 0; }
        }
        if(!mapp(exit)) dest = h_exit[arg];
        else
        if( !exit[arg]) dest = h_exit[arg];
        else dest = exit[arg];
        if( !(obj = find_object(dest)) ) call_other(dest, "???");
        if( !(obj = find_object(dest)) ) {write("�L�k���ʡC\n");return 0;}
        if( !env->valid_leave(me, arg) ) {write(".........\n");return 0;}
        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;
                
        if( !this_object()->move(obj) )
        {
        	write("���ʥ���...\n");
        	return 0;
        }
        
        write("���Q���ʨ� "+obj->query("short")+" �F...\n");
	return 1;
}

int v_search()
{
	return 1;
}


int is_vehicle() { return 1; }