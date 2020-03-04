// Room: /open/world1/dragoncity/northgate1.c

inherit ROOM;

void create()
{
	set("short", "¥ÈªZ¤ºªù");
	set("long", @LONG
³o¸Ì¬O½YÀs«°ªº¥_«°ªùªº¤º«°ªù¡A¥u¨£«°ªù¤W¤è¬O¤T­Ó¤j¦r¡C

[1;36m                      ¥ÈªZªù
[0m
ªñ¦~¨Óªê¤H±Ú¹ð¦¸«I¥Ç½YÀs«°¡A¬G³o¨à§â¦u¬Û·íÄY±K¡A¤@¨Ç¤Ö«Ó
­xªº©x§L­Ì¥¿¦b½L¬d­nÂ÷¶}½YÀs«°ªº¤H¡C¨âÃä¬O¤W«°ÀYªº¥Û¶¥¡A
¦V«n¶i¤J«°°Ï¡C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"north1",
  "north" : __DIR__"northgate2",
  "northup" : __DIR__"walln1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
