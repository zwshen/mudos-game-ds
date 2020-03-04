// Room: /u/k/king/area/r12.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
³o¸Ì¶À¨Fºuºu¡A¨ä§§Áï´º¶H¦³¦p¦¿ªe¤§®ö·Ê·Ê¤£µ´¡A¥u¨£¼Æ¥H¸U­pªº
¤H§Î¤g»sÀJ¹³¾ã»ô¦a±Æ¦¨¤@¦C¦C¡A¥u¨£¦b¤@®Ç¦³­Ó¥¨¤j¥Û¸O¡A¤WÀY¼gµÛ¡G
¡y©l¬Ó«Ò¤Q¤T¦~¡A§^¥H±o¤ÑÂk¡A§^¥H¬Ó³®¬°°O¡A¨ä³®¤¤§L°¨«M¬O¬°§^¥Á¡A
«Ò°êÅQ·~¡A¤d¬î¸U¥@¡C¡z
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"r13",
  "south" : __DIR__"r11",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard4" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
