// Room: /u/b/bennyng/area/room5.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "教皇大廳前園");
	set("long", @LONG
再走前一點就是十二宮的最後一宮了，你感到了最後的敵人就在前面
的大殿內。當你回想起之前的決戰，終於見到最終的敵人－－教皇，令你
不自主地露出勝利的微笑。
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room6",
  "north" : __DIR__"room4",
]));
        create_door("north","大殿之門","south",DOOR_CLOSED);
        set("objects", ([
  __DIR__"npc/guard.c":2,
]));
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
