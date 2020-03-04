#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ªù");
	set("long",
HIW"\n                   ¡´            ¡´\n"
HIW"                   ¢i            ¢i\n"
HIW"                   ¢i            ¢i\n"
HIW" ¢c¢c¢f¢f¢g¢g¢h¢h¢i¢i            ¢i¢i¢h¢h¢g¢g¢f¢f¢c¢c\n"
HIW" ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i            ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i\n"
HIW" ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i            ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i\n"
HIW" ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i            ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i\n\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bigwall.c",
  "north" : __DIR__"passage1",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
