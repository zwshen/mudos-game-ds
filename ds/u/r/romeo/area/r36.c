// Room: /u/k/king/area/r36.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O¤@¶¡¤p­T«Î¡A¸ò¥­±`¬Ý¨ìªº­T«Î¨S¤°»ò¤£¤@¼Ë¡A¦ý¬O·|¦b³o¸Ì
´N¬O¦³¨º»ò¤@ÂI¤£¥­±`¡A¬Ý¬Ý¤W­±¦n¹³¯}¤@­Ó¬}¡A§A¥i¥H¸ÕµÛª¦ª¦¬Ý¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r32",
  "up" : __DIR__"46",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
