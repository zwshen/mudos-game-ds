#include <room.h>
inherit ROOM;
void create()
{
 set("short","翠碧樓");
 set("long",@LONG
這裡又和對面的霞雁閣略有不同, 裡面比較精緻, 而且有個小樓閣
可以往上走, 不知道可以通往哪裡, 似乎是觀賞大漠風景的好地方, 也
許你該往上走看看. 這邊還沒有人住, 你可以好好的在這邊稍事休息.
LONG
    );
 set("exits",([ "north":__DIR__"inroom27",
                   "up":__DIR__"inroom35",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
