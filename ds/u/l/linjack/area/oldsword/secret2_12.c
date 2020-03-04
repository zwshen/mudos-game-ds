#include <room.h>
inherit ROOM;
void create()
{
 set("short","叉路");
 set("long",@LONG
這邊是一條叉路, 仔細看看的話, 你就會覺得往西南走的
路似乎比較長一些. 不過由於十分陰暗的關係, 你無法分辨四
周路徑的狀況.
LONG
    );
 set("exits",([ "west":__DIR__"secret2_8",
                "southwest":__DIR__"secret2_15",
                "south":__DIR__"secret2_13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
