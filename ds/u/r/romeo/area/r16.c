// Room: /u/k/king/area/r16.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
³o¸Ì´N¬O°­«°¼p©Ð¡A¨âÃä³£¦³·L®zªº¿O¥ú¡A³o¸Ìªºµæ¦â¦n¹³³£¥H¤H¦×
¬°¥D¡A¨C¤@­Ó®É¨°³£·|¦³¤@¯Z¦u½Ã¨Ó¨µÅÞ¡A·Q¦b³o¸Ì¥´²V¬O¤£¥i¯àªº¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"r15",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard3" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
