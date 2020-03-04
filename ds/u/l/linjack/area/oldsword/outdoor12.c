#include <room.h>
inherit ROOM;
void create()
{
 set("short","山道小屋");
 set("long",@LONG
你好不容易了經過山道而爬上這裡, 來到一個空小屋之中,
小屋內到處都是蜘蛛網, 有一尊神像在這邊, 不過不知道是什
麼神. 除此之外, 小屋中坐了一個披髮老人. 再往北走可以通
過小屋往一處山壁走去.
LONG
    );
 set("exits",([ "southdown":__DIR__"outdoor11",
                "north":__DIR__"outdoor13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}