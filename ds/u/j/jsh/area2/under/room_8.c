#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"¦a¤U¹Ó¥Þ"NOR);
        set("long", @LONG
test¡C

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"room8",
])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

