// Room: /u/k/king/area/r8.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
³o¸Ì¤w¸g§Ö¨ì°­«°ªºªù¤f¤F¡A¥|©P³£¦³¤H¨«°ÊªºÁn­µ¡A¤£ª¾¹D¬O¾Ô¤Í
ÁÙ¬O¼Ä¤H¡AÁÙ¬O¤p¤ßªº«e©¹¤ñ¸û¦n¡C¤£µMÀH®É³£¦³¤@°ï©Çª«¨Ó±þ§A¡C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r7.c",
  "east" : __DIR__"r9",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ccoo" : 1,
  __DIR__"npc/bat" : 2,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
