#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這邊已經漸漸狹窄了起來, 再往東走似乎還有一塊小空地,
向雲堂中不知道哪個房間就在你前面不遠處, 你再往東走一點
就到了. 不過這邊有一名身穿紫袍的女子站在你面前, 你不禁
好奇的想要問問他的芳名.
LONG
    );
 set("exits",([ "southwest":__DIR__"outroom16",
                "east":__DIR__"outroom19",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
