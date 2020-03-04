// Room: /u/k/king/area/47.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m°­¤ý·µ");
	set("long", @LONG
³q©¹¬Ó³®ªº¤j¤p¹D¸ô¡A¥þ³Q¼h¼h±KªL«Ê°_¡A­¸³¾Ãø´ç¡A¬Ó³®¦W°Æ¨ä¹ê
ªº»P¥~¬ÉÂ_µ´¤FÃö«Y
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"48",
  "south" : __DIR__"46",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
