#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");

 set("long",@LONG 
你現在進入了東北澤林, 四周的鳥鳴使你覺得很舒服, 大樹
一棵接著一棵聳立著, 枝葉蓋過了你的頭頂, 你腳下的土地踩起
來鬆鬆軟軟的, 小路一直延著東北方延續下去。
LONG
    );
 
 set("exits",(["northeast":__DIR__"en3",
               "southwest":__DIR__"en1",
       ]));
 set("outdoors","forest");
 setup();
}           

