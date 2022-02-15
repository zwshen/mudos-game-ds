// room.c

// #pragma save_binary

#include <dbase.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create()//�p�G�����D�i�H����.
{
        seteuid(getuid());
}

int query_max_encumbrance() { return 1215752192; }
int query_max_capacity() { return 1215752192; }
int is_room() { return 1; }
nomask int light() { return this_object()->query("light") + this_object()->query("current_light"); }
nomask void add_light(int w)
{
	int current_light;
	current_light = this_object()->query("current_light");
	current_light += w;
	if( current_light < 0 )
	{
		this_object()->set("current_light",0);
	} else this_object()->set("current_light",current_light);
}

void reset()
{
	ROOM_D->reset_room(this_object());
}

int valid_leave(object me, string dir)
{
	return ROOM_D->valid_leave_room(this_object(),me,dir);

}

void setup()
{
	seteuid(getuid());
	this_object()->reset();
}

void init()
{
	return;
}

// extra functions
string query_long(int raw)
{
	string out="";
	if(!out=this_object()->query_temp("long")) out=this_object()->query("long");
	if(this_object()->query("map_long"))
	{
		out=ROOM_D->showmap(this_object())+out;
	}
	return out;
}