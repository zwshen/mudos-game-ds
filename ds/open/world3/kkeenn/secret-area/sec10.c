#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城北道");
        set("long", @LONG
這裡是一條長長的街道，在街道的四周有許多分岔的小路，不過都
可只容得下一個人左右，南邊是往地下城的城中央的部分，而在北邊則
是往北城門，在這裡有一些垃圾回收器，正在努力的幫街道保持乾淨。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec5.c",
     "west":__DIR__"court.c",
     "north":__DIR__"sec11.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
