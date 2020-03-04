#include <room.h>
inherit ROOM;

void create()
{
  set("short","街道");
  set("long",@LONG
這裡是村中的街道，在這邊已經可以看到村子裡面的一些房屋及
建築，人來人往看起來很熱鬧，東邊傳來陣陣香味，原來是間料理屋
。
LONG);
  set("exits",([ 
      "east":__DIR__"room8",
      "west":__DIR__"room17",
      "south":__DIR__"room11",
      "north":__DIR__"room13",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/eq/water-pot":1,
     ]) );
  setup();
}            
