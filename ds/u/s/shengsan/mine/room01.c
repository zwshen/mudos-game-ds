// room01.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "[1;36m¥ð¾Í®x°|¨«´Y[0m");
	set("long", @LONG
³o­Ó¨«´Y¥Rº¡µÛ°ª¶Qªº®ðª^¡A¨«´Y¥~ªº¨â®ÇºØµÛªø«C¾ð¡B¬f¾ð¡BªQ¾ð
¥H¤ÎÁÙ¦³¤@¤j¤ùªºÆ{ª÷­»ªá¶é¡C
LONG
	);

	set("exits", ([ /* sizeof() == 7 */
		"east" : __DIR__"room02",
		"west" : SHENGSAN+"workroom",
		"north": __DIR__"sendroom",
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/u/s/shengsan/npc/suya" : 1,
		"/u/s/shengsan/npc/robot01" : 1,
	]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
