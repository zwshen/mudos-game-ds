#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你現在來到了東北澤林的入口處, 東北澤林這個地
方的氣候非常潮濕, 看起來不像森林, 反而比較像沼澤,
你腳下的土地踩起來鬆鬆軟軟的, 四周的樹木蓋住的陽
光, 使得這裡有些陰暗, 往東北通往東北澤林。
 
LONG
    );
 
 set("exits",(["northeast":__DIR__"en2",
       ]));
 set("outdoors","land");
 setup();
}           
