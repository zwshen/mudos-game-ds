// Room: /u/k/king/area/r2.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
³o¸Ì¥|©P³£¬O»GÄêªº«ÍÅé¡A³£¦n¹³¤~¦º¨S´X¤Ñ¡A±q¨ì³B´²¸¨ªºªZ¾¹¬Ý
¨Ó¡A¥L­ÌÀ³¸Ó³£¬OªZªÌ¡A¦Ó¥BªZ¥\¤]³£ÁÙ¤£¿ù¡A¨Ï¥Îªº³£¬O¤@¨Ç¦W¶QªºªZ
¾¹¡A§Ö§ä§ä¬Ý¡A¤£¤@©w¦³§A¦X¾AªºªZ¾¹³á¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r1",
  "east" : __DIR__"r3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dog" : 3,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
