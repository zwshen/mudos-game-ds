// Room: /u/m/mulder/area/blackshop.c

inherit ROOM;

void create()
{
	set("short", "黑店");
	set("long", @LONG
這就是新彼得城最有名氣的地方「黑店」，你發覺應該會 
有意想不到的地方，只見這裏有很多不同的人在做買賣，你好
奇地走去看看有什麼好用的物品可買.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road17.c",
  "leave" : __DIR__"road9.c",
]));
	set("no_clean_up", 0);
	set("outdoor", "shop");

	setup();
	replace_program(ROOM);
}
