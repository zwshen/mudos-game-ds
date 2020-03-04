#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
 set("short",HIC"Object´ú¸Õ³B"NOR);
set("exits", ([
"west":__DIR__"workroom1.c",
 ]) );
set("objects",([
]));
set("light",1);
setup();
        replace_program(ROOM);
}
