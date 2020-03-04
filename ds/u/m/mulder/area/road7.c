// Room: /u/m/mulder/area/road7.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 廣場大街");
	set("long", @LONG
你感覺這個城市和其他的是沒有什麼分別，但你細心看一下
你就會一樣發覺是沒有太大的分別，只是．．．．．．．．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road4",
  "east" : __DIR__"road8",
]));
	set("新彼得城", "- 新彼得大道");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
