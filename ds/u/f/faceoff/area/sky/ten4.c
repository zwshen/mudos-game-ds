#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
你從強勢的風砂中可以勉強看見你的西北方幾步遠處有，
一座赤色的雕像，同時你也可以看見西邊山下的情景，從這裡
往下望，有一種超脫世俗的感覺...
LONG
    );
 set("exits",([   "northwest":__DIR__"ten6",
               "southeast":__DIR__"ten2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

