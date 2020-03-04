#include <room.h>
inherit ROOM;

void create()
{
 set("short","街道");
 set("long",@LONG
這裡是村中的街道，在這邊已經可以看到村子裡面的一些房屋及
建築，人來人往看起來很熱鬧，西邊一處廣闊的空地是村民的訓練場
。
LONG
    );
   set("exits",([ 
       "east":__DIR__"room7",
       "west":__DIR__"room16",
       "north":__DIR__"room12",
   ]));
   set("objects",([
      __DIR__"npc/dog":2,
     ]) );
   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
