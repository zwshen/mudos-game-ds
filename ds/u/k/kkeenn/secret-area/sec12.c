#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城北端");
        set("long", @LONG
這裡是地下城的盡頭，在街道的右邊有一家氣派輝煌的住家，散發
的一壯大之美，原來是鼎鼎大名的特殊道具店，南邊是往地下城的南走
道部分，而在北邊則是一面巨大的牆壁，在上面有一些缺德旅客的流言
。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec11.c",
     "east":__DIR__"house.c",
     
]));
        set("light",1);

        setup();
        replace_program(ROOM);

}
