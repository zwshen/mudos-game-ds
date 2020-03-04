#include <room.h>
inherit ROOM;
void create()
{
 set("short","巨石門前");
 set("long",@LONG
經過了一段好長的山路, 你終於來到了向雲堂之前! 你的前方
不遠處, 就是向雲堂最主要的防衛設施----巨大的石門! 這邊已經
可以看到有幾位江湖過客在這裡喧嘩, 有些要出去, 也有些是要進
去的. 你或許可以和他們一起進去.
LONG
    );
 set("exits",([ "north":__DIR__"outdoor1",
                "southeast":__DIR__"mountroad2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}