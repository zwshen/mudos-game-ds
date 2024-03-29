// room.c

// #pragma save_binary

#include <dbase.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create()//如果有問題可以拿掉.
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
void empty_check()
{
	object *inv;
	int i;

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
	{
		if(inv[i]->is_character()) return;
	}
	destruct(this_object());
	return;
}

int valid_leave(object me, string dir)
{
	object wall;
	string stop;
	if(wall=query_temp("wall/"+dir))
	{
	 tell_room(this_object(),me->name()+"想往"+to_chinese(dir)+"離開卻突然被"+wall->name()+"彈了回來。\n",me);
	 return notify_fail("你想往"+to_chinese(dir)+"離開卻突然被"+wall->name()+"彈了回來。\n");
	}
	if(stop=this_object()->valid_leave_door(me,dir)) return notify_fail(stop);

	call_out("empty_check",10);
	return 1;
}

void init()
{
	remove_call_out("empty_check");
	return;
}

// extra functions
string query_long(int raw)
{
	string out="";
	if(!out=this_object()->query_temp("long"))
	 if(!out=this_object()->query("long"))
	  out=@DEFAULT_LONG

  你正位於地面下方五公尺處的地層中。

DEFAULT_LONG
;
	return out;
}

void set_exit(string dir,string roomfile)
{
	set("exits/"+dir,roomfile);
	return;
}
