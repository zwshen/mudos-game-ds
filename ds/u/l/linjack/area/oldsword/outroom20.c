#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這一塊草坪還算滿大的, 再往北走去就到山壁腳下了,
你可以看到附近有些小動物出沒. 你從這裡看山壁, 似乎
隱隱的可以看到山壁上有寫一些大字.
LONG
    );
 set("exits",([ "southup":__DIR__"inroom19",
                "north":__DIR__"outroom21",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
