#include <ansi.h>
inherit ROOM;

void create()
{
set("short","愛門村小路");
        set("long", @LONG
al8..............暫無敘述
LONG
        );
        set("exits", ([
     "east":__DIR__"al7",
     "north":__DIR__"al9",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
