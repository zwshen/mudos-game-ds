// Room: /u/k/king/area/r13.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
³o¸Ì¶À¨Fºuºu¡A¨ä§§Áï´º¶H¦³¦p¦¿ªe¤§®ö·Ê·Ê¤£µ´¡A¥u¨£¼Æ¥H¸U­p
ªº¤H§Î¤g»sÀJ¹³¾ã»ô¦a±Æ¦¨¤@¦C¦C¡A¥u¨£¦b¤@®Ç¦³­Ó¥¨¤j¥Û¸O¡A¤WÀY¼g
µÛ¡G¡y©l¬Ó«Ò¤Q¤T¦~¡A§^¥H±o¤ÑÂk¡A§^¥H¬Ó³®¬°°O¡A¨ä³®¤¤§L°¨«M¬O¬°
§^¥Á¡A«Ò°êÅQ·~¡A¤d¬î¸U¥@¡C¡z
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"r12",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
