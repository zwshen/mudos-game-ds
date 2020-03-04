#include <room.h>
inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
這裡是山間一條崎嶇的山路，路上都是碎石子、泥巴和雜草，往
上就是出雲山的山腰部份了，從這裡看過去，山腰籠罩著淡淡的雲氣
。
LONG);
  set("exits",([ 
      "northeast":__DIR__"room99",
      "up":__DIR__"room102",
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
    if( dir == "up")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}  
