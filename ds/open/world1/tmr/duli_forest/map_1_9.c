// File: /d/duli_forest/map_1_9.c
// Updated by tmr (Mon Mar 11 08:26:28 2002)

inherit ROOM;

void create()
{
	  set("short", "�L���p��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"map_2_9",
	"north" : __DIR__"map_0_9",
]));
	  set("outdoors", "land");

	setup();
	  replace_program(ROOM);
}
