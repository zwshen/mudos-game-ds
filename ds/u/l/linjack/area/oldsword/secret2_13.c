#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這裡再往東南繞去可以看到一點光線, 可能是什麼出口,
你可以過去看看......
LONG
    );
 set("exits",([ "southeast":__DIR__"secret2_14",
                "north":__DIR__"secret2_12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
