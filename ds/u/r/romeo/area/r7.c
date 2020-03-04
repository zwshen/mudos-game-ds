// Room: /u/k/king/area/r7.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
¨«µÛ¨«µÛ§A½ñ¨ì¤@Áû¤HÀY¡A§AÀ~¤F¤@¸õ¡A¤@¬Ý¬O­è­èµ¹§A³Ü¤ôªº¹A¥Á
¡A¤ß¤¤¤£§K¤@°}·P´n¡A¤ß·Q¥u¦³°£Å]¤~¥i¥H¤Æ¸Ñ²{¦bªºªº¤H¶¡ºG¼@¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r8",
  "northwest" : __DIR__"r6",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dog" : 2,
  __DIR__"npc/cool" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
