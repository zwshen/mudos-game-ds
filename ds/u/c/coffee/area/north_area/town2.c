#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"入口"NOR);
 set("long",@LONG 
當你的腳踏進大門時，深吸一口氣，精神突然好了起來，這
裡的空氣真是新鮮。你四處張望，發覺這裡的人十分的活潑好動
，待客也十分熱情。你突然發現，部落裡的人們穿的衣服都跟你
所見過的衣服完全不一樣，你心想：這裡真是特別••。
LONG
    );

 set("exits",(["north":__DIR__"town3",
               "south":__DIR__"town1",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
