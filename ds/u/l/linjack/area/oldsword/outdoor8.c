#include <room.h>
inherit ROOM;
void create()
{
 set("short","谷中平地");
 set("long",@LONG
通過了一條狹道, 來到了一個幽靜的淺谷之中, 這個谷
四周的山壁並不陡峭, 只要有適當的工具, 可以很容易的離
開這個山谷.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor9",
                "north":__DIR__"outdoor10",
                "east":__DIR__"outdoor7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}