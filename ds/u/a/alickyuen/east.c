// Room: /tmr/ship/1.c

inherit ROOM;

void create()
{
	set("short", "東渡口");
	set("long", @LONG
這是一個位於Ｘ縣的東渡口。
LONG
	);
	set("objects",([
		__DIR__"shipman":1,
	]) );

	set("no_kill",1);
	set("no_magic",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	
	if(!arg || arg != "ship") return 0;
	if(!me->query_temp("do_ship") ) return 0;
	me->move(__DIR__"ship");
	me->delete_temp("do_ship");
	tell_room(environment(me),"$N走上了渡船。\n",me);
	return 1;
}

