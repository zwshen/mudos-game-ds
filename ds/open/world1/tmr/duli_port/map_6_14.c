// File: /d/duli_port/map_6_14.c
// Updated by tmr (Thu Feb 28 01:47:53 2002)

inherit ROOM;

void create()
{
	  set("short", "§ù¥§´ä-ªFµó¤j¹D");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_6_15",
	"west" : __DIR__"map_6_13",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
