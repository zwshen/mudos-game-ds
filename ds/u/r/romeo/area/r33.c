// Room: /u/k/king/area/r33.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O¤Q¤j±þ¤â¤§¤@ªº¶³Ãf¼C¹¬ªº¦í©Ò¡A¯³©l¬Ó¬Ý¤¤¥LªºªZ¥\¡A´N±N
¥L¦¬¨ì¦Û¤vªº»â°ì¸Ì¡A¨C·í¶³Ãf¼C¹¬³Q¤³®a°l±þ®É¡A¯³©l¬Ó³£·|¥X­±À°¥L
Â\¥­¡A©ó¬O¶³Ãf¼C¹¬¤]ªø¦~¦í¦b³o¸Ì¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r32",
  "east" : __DIR__"42",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pkman" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
