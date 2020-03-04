#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹林中");
 set("long",@LONG
你來到了林間小路的一個叉路, 有一條是往西走, 看起來光
線比較充足, 另一條是往東北走, 樹林比較濃密, 光線稍弱, 你
要走哪一條路呢?
LONG
    );
 set("exits",([ "west":__DIR__"mountroad1_1",
                "south":__DIR__"mountroad3_1",
                "northeast":__DIR__"mountroad1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}