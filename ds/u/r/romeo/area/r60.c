// Room: /u/k/king/area/r60.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m°­¤ý·µ");
	set("long", @LONG
³o¸Ì´N¬O¤j·µ¤F¡A¬O©P³±·t¼Ò½k¡A¨âÃäªº¨â®Ú¨è¦³Àsªº¹Ï®×ªº¬W¤l¬O
¤ä¼µ³o¸Ìªº¤ä¬W¡A¥u­n¤@­Ë¬Ý¨Ó³o¸Ì´N·|ÅÜ¦¨¤@°ï¯î¶ï¤F¡C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "¬W¤l" : "¤@®Ú¨èµÛ­¸¤Ñ¯«Àsªº¬W¤l¡A¨âÃäªº¯Í»H¬O¥Î¶Àª÷©Ò»s³y¡A¬Ý°_¨Ó¬Û·í­È¿ú¡A
¤U­±ªº¸}«ç»ò¬Ý°_¨Ó¦n¹³¤@­Ó§â¤â©O¡C
",
]));
	set("no_recall", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"49",
  "north" : __DIR__"r61",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pur" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
