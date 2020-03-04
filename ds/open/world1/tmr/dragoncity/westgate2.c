// Room: /open/world1/tmr/dragoncity/westgate2.c

inherit ROOM;

void create()
{
	set("short", "¥Õªê¥~ªù");
	set("long", @LONG
³o¸Ì¬O½YÀs«°ªº¦è«°ªùªº¥~«°ªù¡A¥u¨£«°ªù¤W¤è¬O¤T­Ó¤j¦r¡C

[1;36m                      ¥Õªêªù
[0m
LONG
	);
	set("current_light", 3);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"westgate1",
  "northwest" : "/open/world1/tmr/hasake/gebi1",
]));

	setup();
	replace_program(ROOM);
}
