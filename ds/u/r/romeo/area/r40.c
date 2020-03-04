// Room: /u/k/king/area/r40.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m¤C¬PªL");
	set("long", @LONG
¸g¹L¤@¬qº©ªøªº¸ô«á¡A¦b§A²´«e¦³¤@®°¬õ¦â¤jªù¡A¤W­±²M·¡ªº¼gµÛ¡Ð
¡uµL©À±Ð¡v¡A¬Ý°_¨Ó¤Q¤ÀªºÄ£²´¡A¤£·\¬O¤Q¤jªù¬£¤§¤@¡A¦³µÛ²øÄYªº®ð¶Õ
¡A¸ò¯«¯µªº®ð®§¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"41",
  "south" : __DIR__"r34",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
