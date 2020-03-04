// Room: /u/s/slency/area/ugelan/road5.c

inherit ROOM;

void create()
{
	set("short", "[1;33m«Õ¾BÄõ¤j¹D[2;37;0m");
	set("long", @LONG
³o¸Ì¬O³o¾ã®y«°ªº¤¤¤ßÂI¡A³s±µ®c§Ê»P«°Âíªº¤¤¤ß¦a°Ï¡A³o¸Ì¤]¬O
¦UºØ¦æ·~ªº¶°´²¤¤¤ß¡A©¹¥_«K¬O³q©¹¬Ó®cªº§»°¶¦Q¾ô¡A¥Ñ¦¹©¹ªF¦³¤@¶¡
±Ð°ó¡A©¹¦è¥i¥H¨ì«Õ¾BÄõ«°¥~ªº­¥°Ï¡A©¹«n«h¬O¤@®y¤j«¬¼s³õ¡C
LONG
	);
	set("outdoors", "land");	
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road13",
  "north" : __DIR__"pontlevis",
  "east" : __DIR__"road6",
  "south" : __DIR__"road18",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
