// Room: /u/s/superbug/train/a-1.c

inherit ROOM;

void create()
{
	set("short", "貧民區[北街]");
	set("long", @LONG
這裡是貧民區的北街，這裡仍充滿著令你感到嘔心的氣味，在你的東
方是一間破舊的旅館，牆上寫著大大的「廉價」兩個字，你粉難想像竟會
有人將招牌取這樣的名字，往南可以前往市中心。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a-2.c",
  "south" : __DIR__"8.c",
  "east" : __DIR__"a-17.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
