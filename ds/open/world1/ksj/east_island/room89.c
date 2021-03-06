#include <room.h>
inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
這裡是山間一條崎嶇的山路，路上都是碎石子、泥巴和雜草，西
邊是一處坍坊，滑下去可以回到山腳下。
LONG);
  set("exits",([ 
      "northeast":__DIR__"room90",
      "westdown":__DIR__"room59",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_1") )
  {
    if( dir == "westdown")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
