// Room: /tmr/garea/forest16.c

#include <ansi.h>
#include <path.h>

inherit ROOM;

void create()
{
	set("short", "分岐小路");
	set("long", @LONG
你正在一處林中的一條分岐路上，在東南方向有條爛泥巴路，往西南
方向在林木中隱隱約約能發現有條小路。往北方走能出森林到達天城東城
處，就怕忽然起霧，那可就難找到得路去天城了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southwest" : __DIR__"forest14",
	  "southeast" : __DIR__"forest15",
	  "north":__DIR__"road2",
 	]));
	set("outdoors", "forest");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	object ob;
	ob=this_player();
	if ( !ob->query_temp("kneel_ghost") )
	{
		tell_object(ob,HIW"往北的方向忽然起了一陣白霧.......\n" NOR);
		set("exits", ([ /* sizeof() == 2 */
		  "southwest" : __DIR__"forest14",
		  "southeast" : __DIR__"forest15",
		  "north":__DIR__"road2",
	 	]));

	}
	else
	{
          set("exits", ([ /* sizeof() == 2 */
		  "southwest" : __DIR__"forest14",
		  "southeast" : __DIR__"forest15",
	          "north":ACME_PAST"area/forest1",
          ]));
	ob->delete_temp("kneel_ghost");

	}
}



