#include <room.h>
inherit ROOM;

void create()
{
  set("short","街道");
  set("long",@LONG
這裡是村中的街道，在這邊已經可以看到村子裡面的一些房屋及
建築，人來人往看起來很熱鬧，往西邊可以看到村裡用來防禦敵人的
柵門及瞭望臺，東邊是一間錢莊。
LONG);
  set("exits",([ 
      "east":__DIR__"bank",
      "west":__DIR__"room20",
      "south":__DIR__"room14",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  setup();
}            
