// File: /d/duli_port/map_1_5.c
// Updated by tmr (Thu Feb 28 01:45:21 2002)

inherit ROOM;

void create()
{
	  set("short", "§ù¥§´ä-¥_µó¹D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"north" : __DIR__"map_0_5",
	"south" : __DIR__"map_2_5",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
