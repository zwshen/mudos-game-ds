#include <room.h>
inherit ROOM;
void create()
{
 set("short","廢棄的營地");
 set("long",@LONG
又通過了一段樹林, 來到了另一塊林間空地上, 不久前這邊
似乎有人在此紮營, 可是現在你所見只剩一些殘餘的木樁, 和一
些殘餘樹枝製成的架子.
LONG
    );
 set("exits",([ "east":__DIR__"bandit8",
                "southwest":__DIR__"bandit6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}