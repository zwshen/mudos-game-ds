#include <room.h>
inherit ROOM;
void create()
{
 set("short","形象卦");
 set("long",@LONG
你來到了一個約莫二十尺的大五角石板上, 上面壓著一個
大型的四方形石桌, 高約三尺, 重達千斤. 你完全不知道這裡
有什麼做用, 是機關嗎? 還是....
LONG
    );
 set("exits",([ "northwest":__DIR__"outroom31",
                "southwest":__DIR__"outroom34",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
