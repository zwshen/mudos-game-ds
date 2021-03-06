// Room: /u/l/lestia/area/map_7_6.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-石板道路");
	set("long", @LONG

經過魔力屏障之後你已經進入靈幻教的區域了，路上的行人不時的用狐
疑的眼光看你，讓你覺得有一種頗怪異的感覺，你想可能是因為前方就是通
往靈幻教的總壇了，所以才會有許多人盯著你吧。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_7",
  "north" : __DIR__"map_6_6",
  "west" : __DIR__"map_7_5",
  "south" : __DIR__"map_8_6",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
