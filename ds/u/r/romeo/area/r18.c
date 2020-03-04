// Room: /u/k/king/area/r18.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
¦b³o«M¹³¤§¶¡¦³µÛ¬Û·í¦hªº¤p¹D¡A¬Ý¥h¥u¨£¤@¤ù³£¬O¤@­Ó¼Ò¤l¦L¥X¨Ó
ªº±í§L¡A¥u¨£¬Ó³®«°ªù¤f³B¨º¥¨¤jªº¥Û¸O¤vº¥º¥»·¥h¡A¤£¸T¥O¤H¤ßµJ¡A
¦b³o¸Ì±N­n°g¸ô¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r19",
  "north" : __DIR__"r11",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mman" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
