#include <room.h>
inherit ROOM;
void create()
{
 set("short","往山腰的路上");
 set("long",@LONG
這裡有個小小的花園, 不知道是誰照顧的, 十分漂亮.
這邊似乎原來有另一條路, 仔細的看就可以看出路的軌跡,
只是已經被陡斜的山坡和長在山坡上的濃密樹林擋住了去
路.
LONG
    );
 set("exits",([ "north":__DIR__"mountdown3",
                "east":__DIR__"mountdown5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
