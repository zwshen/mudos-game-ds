#include <room.h>
inherit ROOM;
void create()
{
 set("short","八陣圖中");
 set("long",@LONG
你在這個由通道所佈成的八陣圖中行走, 完全無法分辨你所在
的方位, 只能憑著直覺來走路, 更奇怪的是在這個狹小的通道中竟
佈滿煙霧, 令你十分難受, 若不再快點出去, 恐怕要死在裡面了.
LONG
    );
 set("exits",([ "west":__DIR__"secret6_2",
                "east":__DIR__"secret6_2",
                "north":__DIR__"secret6_2",
                "south":__DIR__"secret6_5",
                "northeast":__DIR__"secret6_2",
                "northwest":__DIR__"secret6_3",
                "southwest":__DIR__"secret6_1",
                "southeast":__DIR__"secret6_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
