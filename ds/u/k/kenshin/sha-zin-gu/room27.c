// Room: /u/k/kenshin/sha-zin-gu/room27.c

inherit ROOM;

void create()
{
	set("short", "¤jÆU[0m");
	set("long", @LONG
¨«¨ì¤F¤jÆU¡A¬Ý¨ì³\¦hÁ`±ÐÀYÆ{´eªº¼Ë¤l¡A¤£ª¾¬O¬°¦ó¡AÀ³¸Ó­n
¦n¦nªº°Ý²M·¡¤~¬O¡C¤@¶i¨Ó¡A´N¯à¬Ý¨ì³\¦h§L¾¹Äa±¾¦bÀð¤W¡AÁÙ¦³¤@
¨Ç§L¶°©ñ¦b¥ª«á¤èªº¸m®ÑÂd¨º¡A¥i¥O¤H·Q¨ì°£¤F±Ð¾É§Ì¤l¡A¦Û¤v¤]¦³
¶ñ¥RÂIª¾ÃÑ¡C
LONG
	);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room28",
  "south" : __DIR__"room26",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
