#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"東迴廊"NOR);

 set("long",@LONG
你又向前跨了好幾十公尺遠, 身旁的浮雕依然連綿不斷, 你
的前方約十公尺處有一點陽光, 顯然出口已近在咫尺, 你回頭望
向你的來路, 只見一片連壁的浮雕, 除此之外似乎一無所有, 可
見這條東迴廊的長度了....
LONG
    );
 set("exits",([ "east":__DIR__"eastroad3",
                "west":__DIR__"eastroad1",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
