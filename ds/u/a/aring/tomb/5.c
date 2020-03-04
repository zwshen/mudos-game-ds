// Room: /u/a/aring/tomb/5.c

inherit ROOM;

void create()
{
      set("short", "¤j¹Ó¶é¡ÐªF°¼¤jªù");
	set("long", @LONG
    ³o¸Ì¬O¤j¹Ó¶éªº¤jªù¡Aªù¤fªº¥ÛÀJ«ýªù¤w¸g·´Ãaªº³Ñ¤U¤@ÂI¬W¸}
¡A¥|©P¹s´²¦a´²¸¨¤@¨Ç¥ÛÀJ¹³ªº¸H¤ù¡A©¹¸Ì­±±æ¥h¤j¹Ó¶é§e¤¤¥¡·L°ª
ÀôÂ¶¤p¸ôªº¦a§Î¡A±q³o¸Ì¥i¥H¬Ý¥X¾ã­Ó¹Ó¶é³Q[32m²Hºñ¦â[1;36mªºÃú®ðÅ¢¸n¦í¡C

LONG
	);
	set("no_clean_up", 0);
	set("light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"4",
  "southeast" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
