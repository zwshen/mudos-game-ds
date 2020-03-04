#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
你走在祭天壇的旁邊，也正行走在十萬大山的第一峰 --
奇倪峰的山腰上，至於奇倪峰的山頂則就是祭天壇了，而東
北方則是通往霧峰的道路，霧峰素有天下第一奇霧的名號， 
也許你該去瞻仰一下.
LONG
    );
 set("exits",([  "northwest":__DIR__"ten23",
               "southeast":__DIR__"ten5",
                   "northdown":__DIR__"ten49",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}
int valid_leave(object me, string dir)
{
        if( dir== "northdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
