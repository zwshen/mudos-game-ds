#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"北市街"NOR);
 set("long",@LONG
這裡是廣場北方的街道, 沿街有賣些小吃, 精品的攤位, 小
販都笑嘻嘻的看著你, 好似希望你買些他們的東西, 不過價錢好
像有點....
LONG
    );
 
 set("exits",(["north":__DIR__"village13",
               "south":__DIR__"village4",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

