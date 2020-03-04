//u/c/chiaa/world2/blackly_forest/causeway1.c

#include <ansi.h>    
inherit ROOM;

void create()
{
        set("short", "石子路");
        set("long", @LONG
你正在一條由碎石子鋪成的路上,崎嶇難行,很容易跌倒,
往北不遠處,彌漫了陣陣白茫茫的霧氣,越是過去,似乎霧氣越盛!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "north"  : __DIR__"road6",       //霧中小路6
    "east"   : __DIR__"parting",     //分歧路
    "south"  : __DIR__"path2",       //小徑2
]));
       
            setup();
replace_program(ROOM);
}
