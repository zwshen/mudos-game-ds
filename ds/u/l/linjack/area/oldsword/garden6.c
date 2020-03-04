#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 隔一道牆就到
客房之中了, 不過客房中沒有窗戶, 所以你也不能從這邊進到
屋子裡. 地上有些紅色的靈芝, 不知道有什麼功用.
LONG
    );
 set("exits",([ "west":__DIR__"garden3",
               "north":__DIR__"garden2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
