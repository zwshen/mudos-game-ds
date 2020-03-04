// Room: /u/k/king/area/r4.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
³o¸Ìªº«Í°©¤@¼Ë¬O¤@°ï¤@°ïªº¡A¦ü¥G¤@®y¤s¥C¤@¼Ë¡AÅ¥»¡¥u­n¤@¥y©G
»y¡A´N¥i¥HÅý¥¦­Ì¥þ³¡´_¬¡¡A­±¹ï³o»ò¦hªº©ÇÃ~§A±N¦p¦ó¦s¬¡©O¡C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r3",
  "east" : __DIR__"r5",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dog" : 1,
  __DIR__"npc/corpse2" : 3,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
