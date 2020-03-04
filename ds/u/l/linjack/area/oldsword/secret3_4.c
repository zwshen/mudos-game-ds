#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
你的西邊有一道石門, 而通路則是往南邊延伸過去, 這邊
竟然還有一點風, 你不禁有點訝異.
LONG
    );
 set("exits",([ "south":__DIR__"secret3_5",
                "west":__DIR__"secret3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
