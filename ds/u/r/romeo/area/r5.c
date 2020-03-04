// Room: /u/k/king/area/r5.c

inherit ROOM;

void create()
{
	set("short", "[1;31m¾Ô°ê[1;33m¬Ó³®[2;37;0m-¤£Âk­ß¸ô");
	set("long", @LONG
¨ì¤F³o¸Ì¡A§A¬Ý¨ì¤@°¦°¦ªº©Çª«¡A¥¿°Ù»kµÛ­è­è¤~­n±þ¼ÄªºªZªÌ¡A¤@
­Ó­Ó³£¬OªZªLªºË³Ë³ªÌ¡A¦p¤µ³£ÅÜ¦¨¤F­¹ª«¡A¬Ý¨Ó§A¤]®t¤£¦hÂP¡C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r6",
  "west" : __DIR__"r4",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/dog" : 1,
  __DIR__"npc/bat" : 1,
  __DIR__"npc/corpse" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
