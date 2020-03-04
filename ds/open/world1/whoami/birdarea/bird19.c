// Room: /open/world1/whoami/birdarea/bird19.c

inherit ROOM;

void create()
{
	set("short", "[1;36m¤Ñ±ú±Ð[0m¤º°ó");
	set("long", @LONG
³o¸Ì¬O¤Ñ±ú±Ðªº¤º°ó, §AÀôÅU¤F¥|©P, µo²{¦³¥|®Ú¥Î¤j²z¥Û
°µªº¤Ñ±ú¥Û¬W, ¦aªO©M¤ÑªáªO¤]¬O¤j²z¥Û°µªº, ¦b¤jÆU¥¿¤¤¥¡¦³
¤@±i¥Û´È, ¤W­±§¤µÛ¤@­Ó¤H, §A·Q¼g¨º¦å¬õ¦â¦rªº¤HÀ³¸Ó´N¬O¥L
¤F¡C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fon" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bird19n",
  "west" : __DIR__"bird18",
]));
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("light", 1);

	setup();
	replace_program(ROOM);
}
