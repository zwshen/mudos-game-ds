// Room: /u/f/fanny/area/green/green1.c

inherit ROOM;

void create()
{
	set("short", "【不歸草原】入口");
	set("long", @LONG
一望無際的草原，放眼所及的景像完全是一個模子印出來的，只
能看遠遠的那頭似乎有著跨不過的高山，一直綿延到遙遠的東邊。看
到這驚人的景像，你不由自主的緊張了起來，看來這似乎就是江湖三
大險地之首的－【不歸草原】。
LONG
	);
	set("world", "undefine");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"green1",
  "north" : __DIR__"green1",
  "west" : __DIR__"green1",
  "east" : __DIR__"green2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
