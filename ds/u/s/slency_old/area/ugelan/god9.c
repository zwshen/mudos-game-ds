// Room: /u/s/slency/area/ugelan/god9.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這裡是一條挺長的走廊，由這裡一直往前走可以到達一個神父的房
間，這裡身旁的景物十分美麗，花草樹木相當整齊，很顯然必定是某人
花了很多的心思在照顧這些植物上。
LONG
	);
	

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"god10",
  "south" : __DIR__"god3",
]));
	create_door("north", "木門", "south", DOOR_CLOSED);
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
