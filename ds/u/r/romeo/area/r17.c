// Room: /u/k/king/area/r17.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
¬Ó³®¦û¦a·¥¼s¡A·µ»Õ«F»O¶¡¡A®ð¶HµÂ´Ë¡A¨Ì¦a¶Õ¦Ó«Ø¡A­I¾a¤s±^¥D®c
¡i¥¿®ð·µ¡j¡A¥ç¬O¬Ó³®¡y©l¬Ó«Ò¡z±o¦W¤§¨Ó¥Ñ¡C¬Ó³®¥D®c°ªÁq¤Ñ»Ú¡A¨q¥X
©ó¸s®c¤§¤W¡A¨Ï¬Ó³®¥D®c¡i¥¿®ð·µ¡j¶¯µø¾ã­Ó³®¦a¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"r14",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard2" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
