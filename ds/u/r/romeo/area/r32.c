// Room: /u/k/king/area/r32.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O¯«¯µ²ÕÂ´¤T¤ÀÁ_ªº²Ä¤G®Ú¾Ú¦a¡A¦W¤ê¡G¥ú©ú«°¡A·í¦~¤é¸¨¤s¤@
§Ð«á¡A¥ú©ú«°¸ò¯³©l¬Ó­q¤U¬ù©w¡A¥ú©ú«°­t³d¦u½Ã¬Ó³®¡AµM«á¯³©l¬Ó«OÃÒ
¥ú©ú«°ªº¦w¥þ¡A©Ò¥H¯³©l¬Óªº³¡¤U¤]³£·q¥ú©ú«°ªº¤H¤T¤À¡C
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"r35",
  "north" : __DIR__"r34",
  "south" : __DIR__"r37",
  "east" : __DIR__"r33",
  "northwest" : __DIR__"r36",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
