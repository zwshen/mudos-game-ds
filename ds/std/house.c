// room.c

// #pragma save_binary

#include <dbase.h>
#include <room.h>
#define LOOK_CMD		"/cmds/std/look"
inherit F_DBASE;
//inherit F_CLEAN_UP;
inherit F_MOVE;
inherit F_BUILDING;

nosave mapping doors;
void create() //�p�G�����D�i�H����.
{
        seteuid(getuid());
}

int is_house() { return 1; }
int valid_enter(object me) { return 1; }
object make_inventory(string file)
{
	object ob;

	if( !objectp(ob = new(file)) ) return 0;

	// �䴩�ߤ@���~(�tNPC) by Luky.
	if( ob->violate_unique() ) ob = ob->create_replica();
	if( !ob ) return load_object(VOID_OB);

	ob->move(this_object());
	ob->set("startroom", base_name(this_object()));
	return ob;
}

void reset()
{
	mapping ob_list, ob;
	object *objs, monster;
	string *list, env_dir, buffer1, buffer2;
	int i,j;

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is 
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//

	set("no_clean_up", 0);
	if(query_temp("mob_count")) set_temp("mob_count",0); //�t�Xmobroom.c
	if(query_temp("long")) delete_temp("long"); //�t�Xlook.c
        if(!query("world"))
        {
        	env_dir = base_name(this_object());
        	if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)==2)
        	{
         		switch(buffer1)
        		{
        			case "world1": set("world","past"); break;
        			case "world2": set("world","now"); break;
        			case "world3": set("world","future"); break;
        			default: set("world","undefine"); break;
        		}
        	} else set("world","undefine");
	}
	objs = all_inventory(this_object());
	if(query("stroom"))
	{
		if(sizeof(objs)>130)
		{
	  		i=sizeof(objs);
	  		while(i>100)
	  		{
	    			if(!objs[i-1]->is_character() && !objs[i-1]->query("no_get")) destruct(objs[i-1]);
	    			i--;
			}
			tell_room(this_object(),"[�W�Źq��-�R��]: ���a�F��Ӧh, �Ұʦ۰ʲM���t��!!\n");
		}
		set("no_clean_up",1);
		return ;
	}
	
	if(sizeof(objs)>90) //����~�q
	{
  		i=sizeof(objs);
  		while(i>100)
  		{
    			if(!objs[i-1]->is_character() && !objs[i-1]->query("no_get")) destruct(objs[i-1]);
    			i--;
		}
		tell_room(this_object(),"[�t��]: �����M�z����!!\n");
	}
	ob_list = query("objects");
	if( !mapp(ob_list) ) return;
	
	if( !mapp(ob = query_temp("objects")) )
		ob = allocate_mapping(sizeof(ob_list));
	list = keys(ob_list);
	for(i=0; i<sizeof(list); i++)
	{
		// Allocate an array if we have multiple same object specified.
		if(	undefinedp(ob[list[i]])
		&&	intp(ob_list[list[i]])
		&&	ob_list[list[i]] > 1 )
			ob[list[i]] = allocate(ob_list[list[i]]);

		switch(ob_list[list[i]])
		{
		  case 1:
			if( !ob[list[i]] ) ob[list[i]] = make_inventory(list[i]);
			if( !ob[list[i]] ) error("/std/room.c can't load object : "+list[i]);
			else if( environment(ob[list[i]]) != this_object()
			&&	ob[list[i]]->is_character() )
			{
				if( !ob[list[i]]->return_home(this_object()) )
					add("no_clean_up", 1);
			}
			break;
		  default:
			for(j=0; j<ob_list[list[i]]; j++)
			{
				// If the object is gone, make another one.
				if( !objectp(ob[list[i]][j]) )
				{
					ob[list[i]][j] = make_inventory(list[i]);
					continue;
				}
				// Try to call the wandering npc come back here.
				if( environment(ob[list[i]][j]) != this_object()
				&&	ob[list[i]][j]->is_character() )
				{
					if( !ob[list[i]][j]->return_home(this_object()) )
						add("no_clean_up", 1);
				}
			}
		}
	}
	set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir,string room_file)
{
	object target;
	string result;
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "�A�n�ݤ���S\n";
	if( doors[dir]["status"] == DOOR_SMASHED )
	        return "�o��" + doors[dir]["name"] + "�w�g�a�F�C\n";
	if( doors[dir]["status"] == DOOR_LOCKED )
	        return "�o��" + doors[dir]["name"] + "�O��۪��C\n";
	if( doors[dir]["status"] == DOOR_CLOSED )
		return "�o��" + doors[dir]["name"] + "�O���۪��C\n";
	else
	{
		if(!target=load_object(room_file)) return "�o��" + doors[dir]["name"] + "�O�}�۪��C\n";
		else
		{
			result = "�A�q"+ doors[dir]["name"] +"��F�L�h�ݨ�..\n\n";
			result += LOOK_CMD->room_describe(this_player(),target);
			return result;
		}
	}
}

varargs int unlock_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;
	
	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to unlock a door with out an exit.\n");

	if( from_other_side )
		message("vision", "�y..��.��..!!�z���H�q�t�@���" + doors[dir]["name"] + "���ꥴ�}�F�C\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) )
	{
                if( !ob->unlock_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}
	doors[dir]["status"] = DOOR_CLOSED;
	return 1;
}

varargs int lock_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: close_door: attempt to lock a door with out an exit.\n");
	if( from_other_side )
		message("vision", "�y.��!..��!!�z���H�q�t�@���" + doors[dir]["name"] + "��W�F�C\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->lock_door(doors[dir]["other_side_dir"], 1) ) return 0;                        
	}
	doors[dir]["status"] = DOOR_LOCKED;
	return 1;
}

varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "���H�q�t�@��N" + doors[dir]["name"] + "���}�F�C\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] = DOOR_OPENED;
	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: close_door: attempt to close a door with out an exit.\n");

	if( from_other_side )
		message("vision", "���H�q�t�@��N" + doors[dir]["name"] + "���W�F�C\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] = DOOR_CLOSED;
	return 1;
}

int check_door(string dir, mapping door)
{
	// If we have no responding door, assume it is correct.
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

	door["status"] = doors[dir]["status"];
	return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status,string key)
{
	mapping d, exits, item_desc;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: create_door: attempt to create a door without exit.\n");

	// Compact mode.
	if( stringp(data) ) {
//		if(!key) d = allocate_mapping(5);
//		 else   d = allocate_mapping(6);
		if(!key) d = allocate_mapping(4);
		 else   d = allocate_mapping(5);
		d["name"] = data;
		d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
		d["status"] = status;
		if(key) d["key"] =key;
	} else if( mapp(data) )
		d = data;
	else
		error("Create_door: Invalid door data, string or mapping expected.\n");

	set("item_desc/" + dir, (: look_door, dir, exits[dir]:) );

	if( ob = find_object(exits[dir]) ) {
		if( !ob->check_door(other_side_dir, d) )
			return;
	}

	if( !mapp(doors) ) doors = ([ dir: d ]);
	else doors[dir] = d;
}

varargs void destruct_door(string dir,string other_side_dir,int from_other_side)
{
	mapping d, exits, item_desc;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: destruct_door: attempt to destruct a door without exit.\n");
	if(!mapp(doors))
	{
		error("Room: destruct_door: Here has no any door.\n");
		return;
	}
	if(undefinedp(doors[dir]))
	{
		error("Room: destruct_door: That direction has no door.\n");
		return;
	}
	
	map_delete(doors,dir);
	delete("item_desc/" + dir );
	
	if(from_other_side) return;
	
	if( ob = find_object(exits[dir]))
	{
		ob->destruct_door(other_side_dir,dir,1);
		return;
	}
	return;
}
mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
	else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
	object wall;
	if( mapp(doors) && !undefinedp(doors[dir]) )
	{
		if( !(doors[dir]["status"] == DOOR_OPENED) && !(doors[dir]["status"] == DOOR_SMASHED) )
			return notify_fail("�A��������" + doors[dir]["name"] + "���}�T\n");
		// if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
	}
	if(wall=query_temp("wall/"+dir))
	{
	 tell_room(this_object(),me->name()+"�Q��"+to_chinese(dir)+"���}�o��M�Q"+wall->name()+"�u�F�^�ӡC\n",me);
	 return notify_fail("�A�Q��"+to_chinese(dir)+"���}�o��M�Q"+wall->name()+"�u�F�^�ӡC\n");
	}
	return 1;
}

void remeber_exit(object env)
{
	int i;
	string from,*exits;
	mapping exit=([ ]);
	from = base_name(env);
	exit=this_object()->query("exits");
	exits=keys(exit);
	for(i=0;i<sizeof(exits);i++)
	{
		if(exit[exits[i]]==from)
		{
			if(env->is_room()) this_object()->set("exits/"+exits[i],from);
			if(env->is_house()) this_object()->set("exits_file/"+exits[i],env);
			break;
		}
	}
}

void setup()
{
	seteuid(getuid());
	set("no_get",1);
	set("no_sac",1);
	set_max_encumbrance(1000000000);
	set_max_capacity(1000000000);
	this_object()->reset();
}

void init()
{
	return;
}