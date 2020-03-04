#include <room.h>
inherit ROOM;
void create()
{
 set("short","谷中平地");
 set("long",@LONG
這個谷四周的山壁並不陡峭, 只要有適當的工具, 可以很
容易的離開這個山谷, 你的北方不遠處似乎有一個通路.
LONG
    );
 set("exits",([ "north":__DIR__"outdoor11",
                "east":__DIR__"outdoor8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}