#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你即將進入沼澤區, 你看到地下有一些些黏黏的泥土
, 同時也看到了一個非常殘破的告示牌, 似乎是某個路過
的旅行者留立的. 

LONG
    );
 set("item_desc",([
        "告示牌":"再往裡面走就是東北澤林的黑暗地帶了。\n",
     ]));
 set("exits",(["east":__DIR__"en50",
               "south":__DIR__"en53",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
