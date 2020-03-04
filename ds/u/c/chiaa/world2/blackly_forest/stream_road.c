//u/c/chiaa/world2/blackly_forest/stream_road.c

#include <path.h>    //小徑通道

inherit ROOM;
void create()
{
        set("short", "溪邊小路");
        set("long", @LONG
你走一條沿著小溪的道路,水流潺潺,不時可看到肥美的魚兒在水中游動,
還有幾個小孩子在溪裡戲水玩耍，往東邊走去就是"黑暗森林"了!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east"  : __DIR__"forest_entranceway",     //森林入口處
]));
       
            setup();
replace_program(ROOM);
}

