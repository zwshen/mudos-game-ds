#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG
來到這裡，你發覺周圍開始有風了，而且受到陽光照射的面
積開始減少了，東北邊有間武器店，如果你有需要的話，也可以
去那邊看看。

LONG
    );

       set("exits",([
       "northeast":__DIR__"town26",
       "west":__DIR__"town7",
       "south":__DIR__"town13",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

