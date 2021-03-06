// Room: /u/m/mulder/area/naboo/jungle/junglecenter.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIM"森林中心");
	set("long", 
HIG"這裡的環境和剛才的森林十分不同，這裡風境如畫和遠處的水池給人\n"NOR
HIG"一種清新的感覺。而這兒有一棵神秘的大樹(tree)看來有一些古怪。四周\n"NOR
HIG"的生物看到這棵大樹都不敢接近這裡。從地上的火種，可以看出剛剛有人\n"NOR
HIG"離開這裡。\n"NOR

	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle13",
  "west" : __DIR__"jungle15",
  "south" : __DIR__"jungle20",
  "east" : __DIR__"jungle1",
]));
	set("item_desc",([
	"tree":"這棵大樹看來可以爬(climb)的\n",
	]));
	set("world", "undefine");
	set("outdoors","forest");
	set("no_map",1);
	set("no_clean_up", 0);
	


	setup();
}
void init()
{
	add_action("do_climb","climb");
}	
	int do_climb(string arg)
{
	object me;
	me=this_player();
	if (arg != "大樹" && arg !="tree" )
	return 0;

	else
	{
	message_vision(HIG"$N辛辛苦苦由地面爬上樹頂。\n"NOR,me);
	me->add("ap",-10);
	me->move(__DIR__"tree");
	tell_room(environment(me),me->query("name")+"開始由地面爬上樹頂。\n",me);
	return 1;
	}
}

int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
