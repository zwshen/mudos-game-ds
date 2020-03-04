#include <room.h>
inherit ROOM;
void create()
{
 set("short","林間空地");
 set("long",@LONG
經歷千辛萬苦你終於通過了那片迷宮般的森林, 來到了一
處空地, 北邊也是一塊空地, 而往西南走有另一條路, 似乎是
下山的. 
LONG
    );
 set("exits",([ "east":__DIR__"forest1",
                "north":__DIR__"mountroad3_4",
                "southwest":__DIR__"mountroad6_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}