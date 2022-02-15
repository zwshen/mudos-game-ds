// name.c
// #pragma save_binary
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

nosave string *my_id,inside_long,outside_long,inside_short,outside_short;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

void set_short(string outside,string inside)
{
	outside_short = outside;
	inside_short = inside;
}

void set_long(string outside,string inside)
{
//	set("long",outside);
	outside_long = outside;
	inside_long = inside;
}

string query_short(int flag)
{
	if(flag) return inside_short;
	else return outside_short;
}

string query_long(int flag)
{
	if(flag) return inside_long;
	else return outside_long;
}

int outside_vision(object me)
{
	write(outside_long);
	return 1;
}

varargs string short(int raw)
{
	string str,desc;

	str = outside_short + "(" + capitalize(query("id")) + ")";

	if(desc=this_object()->query("status_desc")) str+=" "+desc;//��ܥثe���A�Υ���

	return str;
}
int id(string str)
{
	string *applied_id;

	//if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) ) 
		if( member_array(str, applied_id)!=-1 )
			return 1;
		else
			return 0;
			
	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
		return 1;
	else
		return 0;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else
	{  
		if(query_temp("invis") && !raw)
		{
			if(this_object()->is_character()) return "�Y�H";
			else return "�Y��";
		}
		
		if(stringp(str = query("name"))) return str;
		
		return file_name(this_object());
	}
}

varargs string name_id(int raw)
{
	string str,*mask,*applied_id;
	if(raw)
	{
		str=query("name") + "(" + capitalize(query("id")) + ")";
	}
	else
	{
		if( query_temp("invis") || query_temp("hide") ) return "�Y�H(Somebody)";
		if( sizeof( mask = query_temp("apply/short")) ) str = (string)mask[sizeof(mask)-1];
			else str=query("name");
		if( sizeof( applied_id = query_temp("apply/id")) ) str +="("+capitalize((string)applied_id[sizeof(applied_id)-1])+")";
			else str+="(" + capitalize(query("id")) + ")";
	}
	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = mask[sizeof(mask)-1];
	else if( !stringp(str = query("long")) )
		str = short(raw) + "�C\n";

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}

void house_destruct()
{
	object *inv,env;
	env = environment(this_object());
	if(env)
	{
		inv = all_inventory(this_object());
		if(inv)
		{
			tell_room(this_object(),"���B�ֳQ�}�a�F�A�A�Q���k���o�Ӧa��C\n");
			inv->move(env);
			if(inv) inv->house_destruct();
		}
		destruct(this_object());
		return;
	} else return;
}