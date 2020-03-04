// Room: /u/k/king/area/r20.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
³o¬O¤@­Ó¦a¶Õ¤è¾ã¡A¼s¤jµL¤ñªº³®¹ì¡A¯¸¦b²Ä¤@­ÓÀJ¹³¤§«e¡A¶Z³Ì
«áªºÀJ¹³«K¦³¦Ê¨Ó¤V»·¡A³®«e¦³¬ù¤Q¯Åªº¶¥±è¡A¤@¯Å¦³¥b­Ó¤H°ª¡A¨ä§»
¤jªº®ð¶Õ¥O¤H§éªA¡A¥¨¹³«e«á³£¦³¥Û¬W¡A¤W­±¨è¤F³\¦hªá¯¾¡A¬Û·íºë¬ü
¡A¦¹¬Ó³®¬°¨Ñ©^¬Ó¥@¾ú¥N¯ª¥ý¡A±q¤Ó¯ª°Ó´ö¡A¤Ó¤A¡A¦¨ª÷¡A¤pÜH¡A«Ò¤A
¡A«Ò¥³§¢¡A©ú¦i¡A¤j¦³¡A«Ò¤þ¡A«Ò¨¯¡A¤Ó¨¯¡AÂk©f¡A¬JÀÙ¡AºÌ¡A«Ò«w¡A
Îl¡A¦b¬u¡A«Ò¤¡¥¼¡A«Ò¥f¨»¡A«Ò¨°¤x¡A«Ò¦¨¶§¡A¿Ý¡A«Ò¤p¥Ò¡A¤Ö¶§¡A¦¨
´ö¡A¬ö¾ú¡A«Ò¥è¡C¦Ó¤¤¶¡³Ì¤jªº¤@´LÀJ¹³¡A«K¬O²Ä¤j°Ó´Â¤G¤Q¤K¥N¬Ó«Ò
¡A¡i¬ô¡j¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"r21",
  "north" : __DIR__"r19",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wind" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
