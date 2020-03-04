// Room: /u/k/king/area/44.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬OÄa³ýÀÙ¥@¡Ð®Ë©w¨¹ªº¦í©Ò¡A¬Ý°_¨Ó¨Ã¨S¦³¤°»òªF¦è¡A¥u¬O¦b¥|
©P¦³¤@¤j¹M¥¿¦bÅÎ°®ªºÃÄ¯ó¡C¯³©l¬Ó·í¦~¬°¨Dªø¥Í¤£¦Ñ¤§ÃÄ¯S§O§â®Ë©w¨¹
½Ð¨ì³o¸Ì¨Ó¡A¥u¬OÃÄ¤¦¿ð¿ð¨S¦³·Ò¦n¡A¥u¦³ºCºCµ¥¤F¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"45",
  "east" : __DIR__"r35",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fgf" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
