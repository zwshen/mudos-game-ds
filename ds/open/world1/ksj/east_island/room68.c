#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIM"櫻花林"NOR);
  set("long",@LONG
這裡是櫻花林中的林徑，四周都是大大小小的櫻花樹，嬌豔美麗
的櫻花隨著微風輕輕搖擺，映照出粉紅色的天空。
LONG);
  set("exits",([ 
      "northeast":__DIR__"room67",
      "southeast":__DIR__"room71",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/black-tengu":1,
     ]) );
  setup();
}            
