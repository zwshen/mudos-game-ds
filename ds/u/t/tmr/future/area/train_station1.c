inherit ROOM;
void create()
{
          set("short","鐵路車站");
          set("long",@LONG
唯一一條通往主城的鐵路就是建於這個車站裡面，每天都有很多貨物
和人們都經這裡往來。可能由於貨品大多以礦物為主，使得這裡有一些碎
掉的礦物在地上，而通過的人踏了下去，使得地面黏上了礦物的色彩。
LONG
           );
	set("exits", ([ /* sizeof() == 1 */
          "westdown" : __DIR__"digging_street4",
	]));
	set("objects",([
          __DIR__"npc/driver":1,
	]));
	set("no_kill",1);
        set("outdoors","desert");
            set("world", "future");
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
	if(!arg || arg != "train") return 0;
	if(!me->query_temp("do_train") ) return 0;
	me->move(__DIR__"train");
	me->delete_temp("do_train");
	tell_room(environment(me),"$N走進了鐵路。\n",me);
	return 1;
}
