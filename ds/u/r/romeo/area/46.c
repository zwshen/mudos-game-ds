// Room: /u/k/king/area/46.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m°­¤ý·µ");
	set("long", @LONG
³o¸Ì¬O¾Ô°ê¬Ó³®ªº¥½ºÝ¸ô®|¡A¨ì³BÂø¯óÂO¥Í¡A³Q­·¤@§j«á¡A§óÅãªº®æ
¥~ªº®£©Æ¡A¦n¹³ÀH®É³£·|¦³¦º¤h±q¯ó°ï¸Ì¶]¥X¨Ó§ðÀ»§A¡A³Ì¦nÁÙ¬O¤p¤ß¬°
¤Wµ¦¡A¤£µM«Ü®e©ö¦º±¼ªº³á¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"47",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
