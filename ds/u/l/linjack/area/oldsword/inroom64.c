#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這邊是正廳的左下方, 你可以看到仍然有一兩個人在進食,
有一些侍衛也在旁邊待命. 有一些在進食的人是向雲堂的弟子
們, 他們大都不太敢接近正廳中央, 那邊都是給一些外賓坐的.
LONG
    );
 set("exits",(["north":__DIR__"inroom67",
                "east":__DIR__"inroom4",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
