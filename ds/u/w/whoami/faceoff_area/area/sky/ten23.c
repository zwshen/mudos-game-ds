#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
奇倪峰就到這裡結束了，而往北的山路就是著名的龍井
棧道了，由於已經過了奇倪峰，這裡再也感覺不到奇倪峰上
強烈的風砂了，而往南的道路則會回到奇倪峰.
LONG
    );
 set("exits",([  "north":__DIR__"ten24",
               "southwest":__DIR__"ten22",
             "southeast":__DIR__"ten21",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

