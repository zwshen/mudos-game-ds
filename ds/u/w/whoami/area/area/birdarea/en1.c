#include <room.h> 
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");

 set("long",@LONG
你現在來到了東北澤林的入口處, 東北澤林這個地方的氣候
非常潮濕, 看起來不像森林, 反而比較像沼澤, 你腳下的土地踩
起來鬆鬆軟軟的, 四周的樹木蓋住的陽光, 使得這裡有些陰暗, 
往東北通往東北澤林。
LONG
    );
 
 set("exits",(["northeast":__DIR__"en2",
       ]));
 set("outdoors","forest");
 setup();
}           

