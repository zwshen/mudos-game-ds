#include <room.h>
inherit ROOM;
void create()
{
 set("short","石亭之中");
 set("long",@LONG
你抱著疑惑之心, 走進了著個突然出現的石亭中, 裡面空空蕩蕩
的, 什麼東西也沒有, 只有中心的地上有一塊石板, 可是你完全不知
道那塊石板是幹什麼用的.
LONG
    );
 set("exits",([ "north":__DIR__"outroom31",
                "down":__DIR__"secret1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
