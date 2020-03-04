// Room: /open/world1/tmr/dragoncity/southgate2.c

inherit ROOM;

void create()
{
	set("short", "¦¶³¶¥~ªù");
	set("long", @LONG
³o¸Ì¬O½YÀs«°ªº«n«°ªùªº¥~«°ªù¡A¥u¨£«°ªù¤W¤è¬O¤T­Ó¤j¦r¡C

[1;36m                      ¦¶³¶ªù
[0m
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge3",
  "north" : __DIR__"southgate1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
