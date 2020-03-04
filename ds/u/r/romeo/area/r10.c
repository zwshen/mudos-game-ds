// Room: /u/k/king/area/r10.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
³o¸Ì´N¬O°­«°ªº¤U¤è¤F¡A°­«°ªº³±®ð¨Ã¤£¬O´¶³qªº­«¡A¦Ó¥B°­«°¦n¹³
¬O¥Î¤HÀY¬ä¦¨±o¡A©Ò¨Ï¥Îªº¤HÀY¹ê¦bµLªk­pºâ¡AÃø©Ç¦³«ì¤§¤£¥hªº­Þ»î¦b
¥|©P±r«Þ¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r9",
  "up" : __DIR__"r11",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
