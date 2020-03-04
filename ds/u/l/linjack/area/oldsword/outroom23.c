#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這邊已經是接近山壁的垂直方向了, 再往裡面走就到山
壁下面的凹槽了. 有許多小動物都在這邊出沒, 這邊正處於
山谷之中, 你的西方是一個較矮的山壁, 山壁之上還有向雲
堂的建築物.
LONG
    );
 set("exits",([ "north":__DIR__"outroom24",
                "east":__DIR__"outroom21",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
