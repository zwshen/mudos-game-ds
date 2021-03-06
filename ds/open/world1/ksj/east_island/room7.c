#include <room.h>
inherit ROOM;

void create()
{
  set("short","街道");
  set("long",@LONG
這裡是村中的街道，在這邊已經可以看到村子裡面的一些房屋及
建築，人來人往看起來很熱鬧，不時有商家小販挑著貨物出入村子，
往東可以走出村子前往海邊。
LONG);
  set("exits",([ 
      "out":__DIR__"room6",
      "west":__DIR__"room11",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/villager":3,
     ]) );
  setup();
}            

int valid_leave(object me, string dir)
{
  if( me->query("village") )
  {
    if( dir == "out")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
