#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
test�C

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"room6",
])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

