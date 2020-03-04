// Room: /u/k/king/area/r14.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[1;37m-[1;35m°­«°[2;37;0m");
	set("long", @LONG
¸ò¥ª¶­Ál·µ¬Û¤ñ¡A³o¸Ì¥k¶­Ál·µªº®æ§½«KÅã±o¯U¤p¡A«Î¤º¬ù¤­¤Q¤Ø¨£
¤è¡A¦b¥¿¤¤¥¡¦³­Ó¤j¤¦Äl¡A¤¦Äl¥~ÀY³Qæa¥H¶Àª÷¦â¯»¡A¦b´£¦Õ³¡¤À¦³µÛ¨â
°¦¶ÀÀs¡AÄl°ª¬ù¤K¤Ø¡A¬Ý¨Ó³o¬O©l¬Ó±ß¦~¥Î¥H½m¤¦¤§ª«¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"r17",
  "west" : __DIR__"r11",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard5" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
