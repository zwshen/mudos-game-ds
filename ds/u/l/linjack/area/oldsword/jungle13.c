#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
野獸的叫聲越來越大了....可是你現在還無法看見那些野獸
到底在哪裡, 你也無法分辨這到底是哪一種的猛獸, 在你記憶中
似乎沒有聽過這種野獸的叫聲....難到....!?
LONG
    );
 set("exits",([ "east":__DIR__"jungle14",
                "southwest":__DIR__"jungle12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}