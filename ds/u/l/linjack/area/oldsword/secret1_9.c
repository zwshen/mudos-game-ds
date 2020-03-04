#include <room.h>
inherit ROOM;
void create()
{
 set("short","長廊");
 set("long",@LONG
你走到一條長廊上來, 看起來滿長的, 你看不到這個長廊
的盡頭到底在哪裡, 為了安全起見, 你最好小心一點走比較安
全.
LONG
    );
 set("exits",([ "southwest":__DIR__"secret1_7",
                "north":__DIR__"secret3_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
