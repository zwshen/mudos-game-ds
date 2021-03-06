// Room: /open/world1/tmr/goat_maze/stairway3.c

#include <ansi.h>
inherit ROOM;

void open_rain() {
        call_out("open_rain2", 60 + random(10) );
}

void open_rain2() {
        "/adm/daemons/event/pan_rain.c"->trigger_event();
}

void create()
{
        set("short", "羊男的迷宮 - 地底廣場");
        set("long", @LONG
在穿梭過漫長的石頭階底之後，你來到了地底廣場。這是一座正圓
形的大廣場，大概可以同時容納百來個人，在廣場的正中間佇立一座高
大的半羊人石像，除此之外，就再也沒有其它奇怪的東西，你也找不到
是否還有其它出口，看樣子要回到地上，還得再重新爬那數百階的階梯
才能回去。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"stairway3",
]));
        set("objects", ([
                __DIR__"npc/statue" : 1,
        ]) );
        set("current_light", 2);
        set("no_clean_up", 0);

        setup();
}



