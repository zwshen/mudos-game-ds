// Room: /u/k/king/area/42.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
³o¸Ì¬O¤Q¤j±þ¤â¤§¤@ªº¬î¥½´dºqªº¦í©Ò¡A¥u¦³¤@±i§É¡A¤@±i´Ö³Q¡A´N
¤°»ò³£¨S¦³¤F¡A¾Ú»¡¥L³£¨S¦³¤@©wªº®É¶¡¦^¨Ó¡A¥L­n±þªº¤HÁÙ¨S¦³¤@­Ó¥i¥H¬¡
©Rªº¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r33",
  "east" : __DIR__"43",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/swordgod" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
