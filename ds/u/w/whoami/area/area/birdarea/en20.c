#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");

 set("long",@LONG
你好不容易在峭壁上找到一處稍微凸出的岩石, 於是你決定
你現在來到東北澤林的深處, 這附近沒有什麼東西, 只有兩
旁的樹叢, 和路上的幾根小草, 前方看起來沼氣很重, 可能快到
沼澤地帶了, 這條路一直往東方延伸下去。
LONG
    );
 
 set("exits",(["west":__DIR__"en19",
               "east":__DIR__"en21",
             ]));
 set("no_clean_up", 0); 
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}           

