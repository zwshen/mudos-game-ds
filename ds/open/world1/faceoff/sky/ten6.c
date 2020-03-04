#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
有一座赤銅色的雕像聳立在這裡，從它的外型看來，它
似乎是用赤銅所打造而成，你可以輕易的看出它是一隻有著
長尾的巨鳥，不過奇怪的事，雖然它的體積巨大，但看上去
反而有一股祥和之氣，似乎希望往東前往平台的人能夠戾氣
盡去，同時這裡有一座路牌，也許你該看看它....
LONG
    );
 set("exits",([  "northeast":__DIR__"ten22",
              "east":__DIR__"ten8",
               "southeast":__DIR__"ten4",
              "west":__DIR__"ten10",
    ]));
set("item_desc",([
        "路牌":HIG"上面寫著 : 往西 : 苗家村, 往東 : 十萬祭天壇\n"NOR
    ]));
 set("objects", ([__DIR__"npc/sky_guard" : 1,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
        if( dir== "west" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}

