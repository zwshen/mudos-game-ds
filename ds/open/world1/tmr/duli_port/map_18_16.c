// File: /d/duli_port/map_18_16.c
// Updated by tmr (Thu Feb 28 08:39:22 2002)

inherit ROOM;

void create()
{
	  set("short", "ÃÄ¯ó©±ªù¤f");
	  set("long", @LONG

LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"duli_herb",
	"west" : __DIR__"map_18_15",
]));
	  set("map_long", 1);
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
