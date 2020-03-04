// Room: /u/k/king/area/43.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O¤Q¤j±þ¤â¤§¤@ªº¨D¤ßªº¦í©Ò¡A¬Ý°_¨Ó¤Q¤Àªº»¨µØ¡Aªù«e¨âÀYªº
¥Û·à¤l¡A¬Ý°_¨Ó®Ý®Ý¦p¥Í¡A¥[¤W¦¶¬õ¦âªº¤jªù¡A¤@¬Ý´Nª¾¹D¬O¦³¿ú¤H¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"42",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yulo" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
