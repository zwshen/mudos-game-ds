#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","村道");
 set("long",@LONG
你走在位於廣場西北角的道路上, 這條道路似乎通往你
東方的一座茅屋, 這座茅屋不同於一般, 顯得特別的精緻, 
也許是因為住在裡面的人身分不同於一般?
LONG
    );
 set("exits",([   "east":__DIR__"ten19",
               "southeast":__DIR__"ten17",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

