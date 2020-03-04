// File: /d/duli_port/map_2_15.c
// Updated by tmr (Thu Feb 28 01:48:13 2002)

inherit ROOM;

void create()
{
	  set("short", "§ù¥§´ä-¥_µó¤j¹D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_2_16",
	"north" : __DIR__"map_1_15",
	"south" : __DIR__"map_3_15",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
