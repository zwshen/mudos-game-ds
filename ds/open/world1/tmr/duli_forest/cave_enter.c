// File: /d/duli_forest/cave_enter.c
// Updated by tmr (Sat Aug 16 20:39:33 2003)

inherit ROOM;

void create()
{
	  set("short", "沙穴");
	  set("long", @LONG
你正處在一個不大的沙穴中，頭頂上有個出去的洞口，往東是條深不
見頂的小道，烏漆抹黑的，不知內處有什麼。
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"cave_path1",
	"up" : __DIR__"map_6_9",
]));

	setup();
	  replace_program(ROOM);
}
