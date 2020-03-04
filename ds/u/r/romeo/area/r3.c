// Room: /u/k/king/area/r3.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
¤@°ï°ïªº«ÍÅé¤£¸T¤SÅý§A¦R¤F¦n¤[¡AµM¦Ó³o¨Ç«ÍÅé«o¬O©ÇÃ~³Ì³ßÅwªº
­¹ª«¤F¡A§A­n¬O¨S¦³¨¬°÷ªº¥\¤O¡A§A«Ü§Ö´N·|ÅÜ¦¨¤@¹D©ÇÃ~ªº¨ÎÀa¤F¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r2",
  "south" : __DIR__"r4",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/corpse" : 2,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
