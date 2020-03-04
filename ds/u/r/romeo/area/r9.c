// Room: /u/k/king/area/r9.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
³o¸Ìªº¦a¤W¦³¤@°ï¦ÇÂu¡AÀ³¸Ó¬O¦³¤H¨Ó¹L¡A¤@Ãä¦n¹³µe¦³°­«°ªº¦a¹Ï
¡A¦ý¬O§A¬Ý¤FÁÙ¬O¬Ý¤£À´¡AÁÙ¬O§O®ö¶O®É¶¡¤F¡A§Ö¶i¤J°­«°§a¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r8",
  "south" : __DIR__"r10",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lee" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
