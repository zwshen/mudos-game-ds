#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","湯屋");
  set("long",@LONG
這裡是個蠻大的溫泉澡堂，整個澡堂使用木板搭建，旁邊有個櫃
台，大浴池中是熱騰騰的溫泉，對於消除疲勞療傷止痛非常有效。
LONG);
  set("exits",([ 
      "east":__DIR__"room12",
      "enter":__DIR__"bathroom",
     ]));
  set("light", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up",0);
  set("valid_startroom", 1);
  set("map","hotel");
  set("objects",([
      __DIR__"npc/bath-lady":1,
     ]) );
  setup();
}      

int valid_leave(object me, string dir)
{
  if( dir!="enter" )return ::valid_leave(me, dir);
  if( dir=="enter" && me->query_temp("bathe") <=0 || !me->query_temp("bathe") )
    return notify_fail("你還沒付泡湯的費用呢！\n");
  return ::valid_leave(me, dir);
}
