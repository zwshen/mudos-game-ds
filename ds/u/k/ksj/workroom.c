#include <room.h>
inherit ROOM;

void create()
{
  set("short","ksj 的工作室");
  set("long",@LONG
一間狹窄的工作室，四周的牆壁上掛滿了土木工具及五金器材，
牆角放著一台轟隆作響，冒著蒸氣的不知名機器，前方牆壁上的大黑
板上寫滿了設計圖樣及計算式。
LONG
);
  set("exits",([
      "east":__DIR__"room1.c",
      "north":__DIR__"temp-room.c",
      "east_island":__DIR__"east_island/room1.c",
      "lost_island":"/open/world1/ksj/lost_island/room1.c",
      "cyaneous":__DIR__"cyaneous/room1.c",
     ]));
  set("light",1);
  set("objects",([
      __DIR__"robot.c":1,
     ]) );
  setup(); 
  load_object("/obj/board/ksj_b");
}
