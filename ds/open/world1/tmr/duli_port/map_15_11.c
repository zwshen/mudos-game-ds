// File: /d/duli_port/map_15_11.c
// Updated by tmr (Thu Feb 28 01:49:09 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�s���n�j��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_15_12",
	"west" : __DIR__"map_15_10",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
