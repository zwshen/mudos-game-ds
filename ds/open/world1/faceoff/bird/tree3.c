#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","森林");

 set("long",@LONG
這裡除了一成不變的樹林外, 唯一有生氣的只有你腳旁的
小動物, 你不禁疑惑這個森林到底出了什麼事? 為什麼有些殘
木看起來似乎被火燒過呢? 你腳下的道路雖然寬大, 但是好像
已經很久沒人踩過了.....
LONG
    );
 set("exits",([ "north":__DIR__"tree4",
                    "east":__DIR__"tree5",
                    "south":__DIR__"tree2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
