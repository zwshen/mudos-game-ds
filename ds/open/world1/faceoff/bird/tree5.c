#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小徑");

 set("long",@LONG
你向腳下看了一看, 只見這個小徑上的痕跡比剛才的路多
了很多, 可見這裡所走過的人更多, 你似乎在北方遠處看到了
一棟小屋, 而在東方卻似乎有一樣高的出奇的樹木, 你心念一
動, 那該不會就是參天古木吧....?
LONG
    );
 set("exits",([ "west":__DIR__"tree3",
                 "north":__DIR__"tree7",
                 "northeast":__DIR__"tree9",
    ]));
 set("objects", ([__DIR__"npc/woodguard" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
