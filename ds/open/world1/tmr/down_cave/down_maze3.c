// File: /d/down_cave/down_maze3.c
// Updated by tmr (Mon Aug 18 02:28:10 2003)

inherit ROOM;

void create()
{
	  set("short", "空洞穴");
	  set("long", @LONG
你正在一個空空如也的洞穴中，四周黑漆漆的，看的不是很清楚。
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"down_maze1.c",
	"north" : __DIR__"down_maze2.c",
]));

	setup();
	  replace_program(ROOM);
}
