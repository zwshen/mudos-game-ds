// Room: /u/t/tmr/room/room1.c

inherit ROOM;

void create()
{
	set("short", "[1;35m¯»¬õ¦âªº©Ð¶¡[0m");
	set("long", @LONG
³o¬OÂPÂP¦Ìªº©Ð¶¡¡A¥|¶gº£¤W²H¯»¦â±mªºªoº£¡A©Ð¶¡¨ì³BÂ\º¡¤F
¥i·Rªº¥¬«½«½ª±°¸¡A©Ð¤º¦³±i¤j¤jªºÂù¤H§É¡A¥Î¥Õ¯½³ò°_¨Ó¡A¥Rº¡¥i
·RÅw¼Öªº®ðª^¡C
LONG
	);
	set("current_light", 1);
        set("valid_startroom", "1");

	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"square",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
