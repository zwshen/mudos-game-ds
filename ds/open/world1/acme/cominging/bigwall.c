#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "·ÓÀð");
        set("long",@LONG

[0;1;31m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m¢[1m¨[1;41m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1;40m¢[1m©[0m
[0;1;31m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m¢[1m¨[1;41m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1;40m¢[1m©[0m
[0;1;31m [1m [1m [1m [1m [1m [1m [1m [1m [1m¢[1m¨[1;41m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1;40m¢[1m©[0m
[0;1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;47m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [0m
[0;1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;47m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [0m
[0;1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;47m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [0m
[0;1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;30m [1m [1;37m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1;47m [1m [0m
[0;1m [1;47m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;40m [0m
[0;1m [1;47m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;40m [0m
[0;1m [1;47m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;40m [0m

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"door2",
  "west" : __DIR__"door1",
  "out" : ACME_PAST+"area/smallway.c",
]));
set("objects",([
    __DIR__"npc/guard" : 2,
]));
        set("no_clean_up", 0);
        set("light",1);

        setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="out" && !userp(me) )
                return notify_fail("¨º¸Ì¥u¦³ª±®a¤~¯à¶i¥h¡C\n");
        return ::valid_leave(me, dir);
}


