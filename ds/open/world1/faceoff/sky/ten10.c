#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小徑");
 set("long",@LONG
這條小徑大反十萬大山荒涼的氣氛，四周都是到你腰際
的劍草叢，在這一片劍草叢中只能勉強看到一條在劍草中的
小徑，而你實在很難相信這是一條通往山村的小路....
LONG
    );
 set("exits",([   "west":__DIR__"ten11",
               "east":__DIR__"ten6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

