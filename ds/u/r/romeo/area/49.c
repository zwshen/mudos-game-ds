// Room: /u/k/king/area/49.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m°­¤ý·µ");
	set("long", @LONG
¨«¨ì³o¸Ì§A±æ±æ¥|©P¦n¹³³£¦³¤H¦b¬ÝµÛ§A¡A¤@°¦°¦ªº°­½Ã§L¸ò¥X½æ¦Û
¤wÆF»îªº¤HÃþ«q®{¤]³£¤w¸g¨Ï§A¹½­Â¡A²{¦bªº§A¥u·Q¤@¤ß¤@·Nªº¥´­Ë¯³©l
¬Ó¡A±N¥¦¦A«×«Ê¦L°_¨Ó¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r60",
  "south" : __DIR__"48",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/vvp" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
