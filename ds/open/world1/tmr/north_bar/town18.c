// Room: /open/world1/tmr/north_bar/town18.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－市集");
	set("long", @LONG
這裡賣著許多物品，附近有許多人在排隊買東西，這裡的東 
西都是物美價廉，且都獨具特色，滿受外地人士的喜愛。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"shop",
  "west" : __DIR__"town19",
  "east" : __DIR__"town12",
  "southwest" : __DIR__"bank",
]));
	set("outdors", "land");
	set("current_light", 2);
	set("outdoors", "land");
	set("light", 1);

	setup();
	replace_program(ROOM);
}
