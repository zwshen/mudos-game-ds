// equip.c
#include <box.h>
inherit ITEM;

int cover_status;
int cover_durable;
int lock_status;
int lock_level;
int lock_durable;

string *keys=({});

int is_box() { return 1; }

void setup()
{
	::setup();
        if(query_max_encumbrance() < 1 ) set_max_encumbrance(999999);
        if(query_max_capacity() < 1) set_max_capacity(99);
        if(!query("cover_name")) set("cover_name","蓋\子");
        if(lock_level<1 ) lock_level=1;
        if(lock_durable<1 ) lock_durable=100;
        if(cover_durable<1 ) cover_durable=100;
}

int can_access_box()
{
	if(cover_status==COVER_CLOSED) return 0;
	else return 1;
}

int query_cover_status()
{
	return cover_status;
}

int query_lock_status()
{
	return lock_status;
}

int set_cover(int new_status)
{
	cover_status=new_status;
	return new_status;
}

int set_lock(int new_status)
{
	lock_status=new_status;
	return new_status;
}

int close_cover()
{
	if(cover_status==COVER_OPENED)
	{
		cover_status=COVER_CLOSED;
		return 1;
	}
	return cover_status;
}

int open_cover()
{
	if(cover_status==COVER_CLOSED)
	{
		if(lock_status==LOCK_CLOSED) return lock_status;
		cover_status=COVER_OPENED;
		return 1;
	}
	else return cover_status;
}

int disable_cover()
{
	if(cover_status==COVER_NONE || cover_status==COVER_SMASHED) return cover_status;
	cover_status=COVER_SMASHED;
	return 1;
}

int fix_cover()
{
	if(cover_status!=COVER_SMASHED) return cover_status;
	cover_durable=50+random(50);
	cover_status=COVER_OPENED;
	return 1;
}

varargs int open_lock(object key)
{
	if(cover_status!=COVER_CLOSED) return cover_status;
	if(lock_status!=LOCK_CLOSED) return lock_status;
	if(key && sizeof(keys))
	{
		if(member_array(base_name(key),keys)==-1)
		return 0;
	}
	lock_status=LOCK_OPENED;
	return 1;
}

varargs int close_lock(object key)
{
	if(cover_status!=COVER_CLOSED) return cover_status;
	if(lock_status!=LOCK_OPENED) return lock_status;
	if(key && sizeof(keys))
	{
		if(member_array(base_name(key),keys)==-1)
		return 0;
	}
	lock_status=LOCK_CLOSED;
	return 1;
}

int disable_lock()
{
	if(lock_status==LOCK_NONE || lock_status==LOCK_SMASHED) return lock_status;
	lock_status=LOCK_SMASHED;
	return 1;
}

int fix_lock()
{
	if( lock_status!=LOCK_SMASHED) return lock_status;
	cover_durable=50+random(50);
	lock_status=LOCK_OPENED;
	return 1;
}

nomask void set_keys(string *key_files)
{
	keys=key_files;
	return;
}

nomask void add_keys(string key_file)
{
	keys+=({key_file});
	return;
}

nomask void set_lock_level(int level)
{
	lock_level=level;
	return;
}

int query_lock_level()
{
	return lock_level;
}

varargs int damage_cover(int damage,object me)
{
	if(me) this_object()->set_temp("cover_damage_from",me);
	if(cover_status!=COVER_CLOSED) return cover_status;
	cover_durable-=damage;
	if(cover_durable < 1)
	{
		cover_status=COVER_SMASHED;
		return cover_status;
	}
	return 1;
}

varargs int damage_lock(int damage,object me)
{
	if(me) this_object()->set_temp("lock_damage_from",me);
	if(cover_status!=COVER_CLOSED) return cover_status;
	lock_durable-=damage;
	if(lock_durable < 1)
	{
		lock_status=LOCK_SMASHED;
		return lock_status;
	}
	return 1;
}

string show_cover_status()
{
	string str,name,unit,cover;
	name=this_object()->name();
	unit=this_object()->query("unit");
	cover=this_object()->query("cover_name");
	if(cover_status==COVER_NONE) return "這"+unit+name+"並沒有蓋\子。";
	if(cover_status==COVER_SMASHED) return "這"+unit+name+"的"+cover+"已經壞了。";
	if(cover_status==COVER_CLOSED)
	{
		str="這"+unit+name+"的"+cover+"是關起來的";
		if(lock_status==LOCK_OPENED) str+="，似乎並沒有被鎖上";
		else if(lock_status==LOCK_CLOSED) str+="，而且已經被上了鎖";
		else if(lock_status==LOCK_SMASHED) str+="，鎖也已經卡死了無法打開";
		str+="。\n";
	}
	
	if(cover_status==COVER_OPENED)
	{
		str="這"+unit+name+"的"+cover+"是打開的";
		str+="。\n";
	}
	return str;
}

/* int query_autoload() { return 0; } */