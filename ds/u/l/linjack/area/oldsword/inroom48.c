#include <room.h>
inherit ROOM;
void create()
{
 set("short","護堂武侍鋪");
 set("long",@LONG
這裡是向雲堂的護堂侍衛寢室, 你可以看到裡面的四個
護堂武侍都有比較厚重的裝備. 他們這階層的人是維持整個
向雲堂的安全為責任的人員, 在正常情況下, 向雲堂內大小
侍衛和部份弟子都是由他們管理.
LONG
    );
 set("exits",([ "north":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
