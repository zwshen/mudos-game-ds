// Room: /open/world1/tmr/north_bar/town23.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－庭院");
	set("long", @LONG
這裡是村長家門前的庭院，裡面種著許多花，看來村長
園藝上的造詣頗高，庭中的花花草草井然有序，遠看落落大
方，近看卻是玲瓏巧致，平凡中見神奇。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town22",
  "north" : __DIR__"town25",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
