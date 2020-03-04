// Room: /u/k/king/area/r11.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
¡i¦w¼Ö®c¡j§¤¸¨¥þ®c®Ö¤ß¡A¥ª¥k¬O¨â­Ó°¾·µ¡A¦U¦³¤@±ø¬ù¤G¤Q¤Vªøªº
´Y¹D¬Û³s¡A¨ä¶Õ¦p¨âÃä­¸¥X¤§¶­Ál¡A¨â­Ó°Æ·µ¡A¥H¡i¥ª¶­Ál·µ¡j¥H¤Î¡i¥k
¶­Ál·µ¡j¬°¦W¡A®c«eÅ@·¾²`¼s¡A¤Þ¶i´Â¤Ñ´òªº¤ô·½¡A¦¨¬°¤ÑµMªº«Ì»Ù¡C
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"r18",
  "west" : __DIR__"r15",
  "north" : __DIR__"r12.c",
  "down" : __DIR__"r10.c",
  "east" : __DIR__"r14",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard7" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
