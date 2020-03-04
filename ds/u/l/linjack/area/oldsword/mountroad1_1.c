#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹林的盡頭");
 set("long",@LONG
你在這片林中走了好一段時間, 往前一望, 總算看到了樹林的
出口, 不禁慶幸. 這邊已經偶爾有看到兩三個樵夫或是路人在行走,
你覺得已經快到到達向雲堂了. 往東走可以走到下山的路上.
LONG
    );
 set("exits",([ "east":__DIR__"mountroad1_2",
                "northwest":__DIR__"mountroad3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}