// File: /d/mist_forest/map_14_16.c
// Updated by tmr (Thu May 16 20:07:09 2002)

inherit ROOM;

void create()
{
	  set("short", "�g���˪L-�p�|");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"northeast" : __DIR__"map_13_17",
	"southwest" : __DIR__"map_15_15",
]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
