// Room: /u/k/king/area/r6.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
¨«¤F¨º»ò¤[¡A±þ¤F¨º»ò¦híL«Í¡A¦ý¬O¸ô«o¤@ª½¨S¦³ºÉÀY¡A¥|©Pªº´º¦â
¤S¬O¨º»òªº©ü·t¡A¨­¤Wªº©]©ú¯]¦³¨S¦³¤FÀ³¦³ªº¥ú½÷¤F¡C»·»·¬Ý¥h¦n¹³¦³
¤@®y«°¡AÁÙ¬O§Ö§Ö¹L¥h§a¡C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r7",
  "north" : __DIR__"r5",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/child" : 2,
  __DIR__"npc/corpse" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
