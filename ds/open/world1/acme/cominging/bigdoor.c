#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "¤jªù");
	set("long",
"\n"
HIR"          ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢©\n"
HIR"        ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢©\n"
HIR"      ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢©\n"
HIR"    ¢¨¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢©\n"NOR
WHT"         ¢¨¢i¢i"CYN"¢«"NOR"            "CYN"¢ª"WHT"¢i¢i¢©\n"NOR
CYN"       ¢¨"HIW"¢i¢i¢i                ¢i¢i¢i"NOR""CYN"¢©\n"NOR
CYN"     ¢¨¢«"NOR""WHT"¢ª¢i¢«                ¢ª¢i¢«"CYN"¢ª¢©\n"NOR
WHT" ¢©¢¨¢i¢©¢¨¢i¢©                ¢¨¢i¢©¢¨¢i¢©¢¨\n"NOR
HIW" ¢i¢i¢i¢i¢i¢i¢i                ¢i¢i¢i¢i¢i¢i¢i\n"NOR
WHT" ¢i¢i¢i¢i¢i¢i¢«                ¢ª¢i¢i¢i¢i¢i¢i\n\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"way1",
  "south" : __DIR__"passage2",
]));
set("objects",([
    __DIR__"npc/guard" : 2,
]) );
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
