#include <room.h>
inherit ROOM;

void create()
{
  set("short","ksj 的放牧場");
  set("long",@LONG
一片青綠的大草原，適合放養動物。
LONG
);
  set("exits",([ 
      "south": __DIR__"room4.c",
      "east": __DIR__"room2.c",
     ]));
  set("light",1);
  setup();
}
