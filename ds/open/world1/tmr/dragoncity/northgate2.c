// Room: /open/world1/dragoncity/northgate2.c

inherit ROOM;

void create()
{
	set("short", "¥ÈªZ¥~ªù");
	set("long", @LONG
³o¸Ì¬O½YÀs«°ªº¥_«°ªùªº¥~«°ªù¡A¥u¨£«°ªù¤W¤è¬O¤T­Ó¤j¦r¡C

[1;36m                      ¥ÈªZªù
[0m
ªñ¦~¨Óªê¤H±Ú¹ð¦¸«I¥Ç½YÀs«°¡A¬G³o¨à§â¦u¬Û·íÄY±K¡A¤@¨Ç¤Ö«Ó
­xªº©x§L­Ì¥¿¦b½L¬d­nÂ÷¶}½YÀs«°ªº¤H¡C¨âÃä©¹¥_©µ¦ù¬O¤@±æµL
»Úªº¤j¯ó­ì¡C
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"caodi4",
  "west" : __DIR__"caodi5",
  "south" : __DIR__"northgate1",
  "north" : __DIR__"caodi1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
