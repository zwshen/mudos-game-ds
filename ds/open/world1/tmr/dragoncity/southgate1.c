// Room: /open/world1/dragoncity/southgate1.c

inherit ROOM;

void create()
{
	set("short", "¦¶³¶¤ºªù");
	set("long", @LONG
³o¸Ì¬O½YÀs«°ªº«n«°ªùªº¤º«°ªù¡A¥u¨£«°ªù¤W¤è¬O¤T­Ó¤j¦r¡C

[1;36m                      ¦¶³¶ªù
[0m
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "southup" : __DIR__"walls1",
  "south" : __DIR__"southgate2",
  "north" : __DIR__"south_din",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
