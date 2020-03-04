// Room: /open/world1/whoami/birdarea/bird19n.c

inherit ROOM;

void create()
{
	set("short", "[1;36m¤Ñ±ú±Ð[0m¤º°ó");
	set("long", @LONG
³o¸Ì¬O¤Ñ±ú±Ðªº¤º°ó¡A§AÀôÅU¤F¥|©P¡Aµo²{¦³¥|®Ú¥Î¤j²z¥Û
°µªº¤Ñ±ú¥Û¬W¡A¦aªO©M¤ÑªáªO¤]¬O¤j²z¥Û°µªº¡A³o¤º°ó¤¤ªº¦a¤W
Â\º¡¤F¦U¦¡¦U¼ËªºÃÄ¯ó¡AÁÙ¦³¤@¦aªºÃÄ¯ó¬ÛÃöÂå®Ñ¡C¿@¿@ªºÃÄ¯ó
¨ý¥Rº¡¾ã¶¡¤º°ó¡C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fon2" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"bird19",
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("light", 1);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
