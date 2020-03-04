// Room: /u/k/king/area/r15.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
³o¸Ì¬O¥¿·µªº°Æ®c¡A¦b·í®É¤]´N¬O©Ò¿×ªº¦æ®c¡A³o¸Ì¬O¤åªZ¦Ê©x¤W´Â
®É¡A¥Î¨Ó«Ý©R¤§³B¡A³o¸Ì¦³­±Àð¬O¬°¶À¦âÆ^®Øªº¡A¤WÀY±¾¤F³\¦h¤ìªO¤ù¡A
¦bÀð¤W¼g¤F¥|­Ó¤j¦r¡u³¹¡v¡u«µ¡v¡uªí¡v¡uÄ³¡v¡A¦¹¦r¬°¤p½f¡A§â¾ã­±Àð
¤À¬°¥|¤j³¡¤À¡A¬Ý¨Ó¦ü¥G¬O¬°¤F°Ï¤À³o¨Ç¤ìªO¤ùªº¥\¥Î¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r11",
  "northwest" : __DIR__"r16",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard6" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
