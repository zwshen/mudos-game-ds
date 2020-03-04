// Room: /u/k/king/area/r34.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O¥|©P³£°ïº¡¤FªZ¥\¯µÓD¡A¥u¯d¤U¤@±ø¤p¤pªº³q¹D¡A¦b§AªºÀY³»
ªº¥¿¤W¤è¦³¤@¶ô°ÐÃB¡A¤W­±¼gµÛ¡G¡uªZ¥\¤§®a¡v¡A­ì¨Ó³o¸Ì¬O¥ú©ú«°©Ò¤À
µoªº²ÕÂ´¤§¤@¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r32",
  "north" : __DIR__"r40",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tammi" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
