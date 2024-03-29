// door.c
// 將門與房間分離, 以節省記憶體
// 往後要使用門時, 必須加上 inherit DOOR;
// #pragma save_binary
#include <dbase.h>
#include <door.h>
#define LOOK_CMD		"/cmds/std/look"

nosave mapping doors;
void create()//如果有問題可以拿掉.
{
        seteuid(getuid());
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir,string room_file)
{
	object target;
	string result;
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "你要看什麼﹖\n";
	if( doors[dir]["status"] == DOOR_SMASHED )
	        return "這個" + doors[dir]["name"] + "已經壞了。\n";
	if( doors[dir]["status"] == DOOR_LOCKED )
	        return "這個" + doors[dir]["name"] + "是鎖著的。\n";
	if( doors[dir]["status"] == DOOR_CLOSED )
		return "這個" + doors[dir]["name"] + "是關著的。\n";
	else
	{
		if(!target=load_object(room_file)) return "這個" + doors[dir]["name"] + "是開著的。\n";
		else
		{
			result = "你從"+ doors[dir]["name"] +"望了過去看到..\n\n";
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
		message("vision", "『..喀.啦..!!』有人從另一邊把" + doors[dir]["name"] + "的鎖打開了。\n", this_object());
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
		message("vision", "『.喀!..喀!!』有人從另一邊把" + doors[dir]["name"] + "鎖上了。\n", this_object());
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
		message("vision", "有人從另一邊將" + doors[dir]["name"] + "打開了。\n", this_object());
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
		message("vision", "有人從另一邊將" + doors[dir]["name"] + "關上了。\n", this_object());
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
	this_object()->set("no_clean_up", 1);
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

string valid_leave_door(object me, string dir)
{
	if( mapp(doors) && !undefinedp(doors[dir]) )
	{
		if( !(doors[dir]["status"] == DOOR_OPENED) && !(doors[dir]["status"] == DOOR_SMASHED) )
			return "你必須先把" + doors[dir]["name"] + "打開﹗\n";
		// if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
	}
	return 0;
}

int have_door() { return 1; }
