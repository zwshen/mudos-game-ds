#include <room.h>
inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
這裡是出雲山山腳的小山路，山路雜亂而曲折，是野獸走動所形
成的小路，兩旁都是雜草及樹叢，山壁上坍落了許多石塊，堵住了上
山的路，必需要有很好的輕身功夫才有辦法攀越。
LONG);
  set("exits",([ 
      "southwest":__DIR__"room58",
      "eastup":__DIR__"room89",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/eq/big-stone":1,
     ]) );
  setup();
}            

int valid_leave(object me, string dir)
{
  object stayer;

  if( objectp(stayer=present("big stone", this_object())) && dir == "eastup" )
  {
    message_vision("$N想要往山裡頭前進，但是因巨石擋道而無可奈何。\n"
                   "除非找來力大無比的人來移走巨石，否則是無法前進了。\n",me);
    return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
