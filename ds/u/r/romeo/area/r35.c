// Room: /u/k/king/area/r35.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬OÃú®ð³Ì­«ªº¦a¤è¡A§¹§¹¥þ¥þ¬Ý¤£¨ì¤@¤BÂIªºªF¦è¡A¤£¤p¤ßÁÙ½ð
¨ì¥ÛÀY¡Aµh¨ì²´²\³£§Ö¬y¥X¨Ó¤F¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"44",
  "east" : __DIR__"r32",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
