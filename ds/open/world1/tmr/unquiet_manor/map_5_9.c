// File: /d/unquiet_manor/map_5_9.c
// Updated by tmr (Sat Jul 10 15:41:20 2004)

inherit ROOM;

void create()
{
	  set("short", "¯O¦D¤§¼X-¤J¤f");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("outdoors", "land");
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_5_10",
	"west" : __DIR__"map_5_8",
	"south" : __DIR__"map_6_9",
]));

	setup();
	  replace_program(ROOM);
}
