#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坪上");
 set("long",@LONG
這是一處蠻幽靜的草坪, 有些小動物偶爾會在這邊出沒,
完全沒有人聲喧鬧的聲音, 有條溪流從這邊經過, 好像是往
向雲堂那邊流過去. 
LONG
    );
 set("exits",([ "west":__DIR__"outroom7",
                "east":__DIR__"outroom9",
               "south":__DIR__"outroom10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
