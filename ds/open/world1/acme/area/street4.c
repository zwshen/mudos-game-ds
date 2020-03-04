// Room: /u/a/acme/area/street4.c
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "街道");
        set("long", @LONG
這裡是天城東邊的街道，筆直的橫貫整個天城，西邊可看到天城的
大廣場，往東遙望可看見城門。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
"enter" : ACME_PAST"area2/p.c",
  "west" : __DIR__"street3",
  "east" : __DIR__"street5",
]));
    set("objects",([
       __DIR__"npc/man" : 1,
    ]));
        set("no_clean_up", 0);
    set("outdoors","land");
        setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="enter" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

