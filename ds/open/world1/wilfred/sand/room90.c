#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "至中殿");
  set ("long", @LONG
至中殿坐落建築物之核心，左右是兩個偏殿，各有一條約二十丈
長的廊道相連，其勢如兩邊飛出之蛟龍，因此將兩個副殿，以左磐龍
殿以及右磐龍殿為名，殿前護溝深廣，引進朝天湖的水源，成為天然
的屏障。
LONG
);
  set("exits", ([
  "west" : __DIR__"room92",
  "east" : __DIR__"room91",
  "south" : __DIR__"room89",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
//  replace_program(ROOM);
}

// 2003.4.10 新增阻擋功能 by ksj
int valid_leave(object me, string arg)
{
  object guard;
  if(arg == "west" || arg == "east")
  {
    if( objectp(guard=present("blue-eye white dragon", this_object())) && userp(me))
    {
      if(!guard->visible(me))
        message_vision(HIW"當$N偷偷摸摸的想從角落旁通過$n"HIW"時，卻被$n"HIW"用尾巴擋住了。\n"NOR,me,guard);
      else
        message_vision(HIW"當$N試圖從$n"HIW"的身旁通過時，被$n"HIW"狠狠的擋了回來！！\n"NOR,me,guard);
      write(HIG"[看來必需打倒牠了，否則別想通過這裡]\n"NOR);
      if(!random(4))
      {
        message_vision(HIR"$N大吼一聲，青色的雙眼精光大盛，狠狠的朝著$n的頭就是一爪！！\n"NOR,guard,me);
        guard->kill_ob(me);
      }
      return notify_fail("");
    }
  }
  return ::valid_leave(me, arg);
}
