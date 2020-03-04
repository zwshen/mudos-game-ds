// Room: /u/k/king/area/r37.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
¾Ú»¡³o¸Ì¬O¤Q¤j±þ¤â¤§¤@ªº±°­¹ªÌªº¦í³B¡A³oÃä¨ì³B³£¬O¯î¯ó¡A¦n¹³
¬O¤@³B´ËªL¡A¬Ý°_¨Ó«D±`ªº¤£µÎªA¡A¿`®ð¤S±q¥|­±¤K¤è´é¦Ü¡AÁÙ¬O§Ö°k¥Í
§a¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r38",
  "north" : __DIR__"r32",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hunter" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
