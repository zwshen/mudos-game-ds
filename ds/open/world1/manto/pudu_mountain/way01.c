#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit __DIR__"way00.c";

void create()
{
  set("short",HIG"¤s±V¥j¹D"NOR);
  set("long",(: print_mountain_msg :),);
  set("exits", ([ 
  "east" : "/open/world1/tmr/dragoncity/caodi7",
  "westup" : __DIR__"way02",  
]));
        set("outdoors","land");
        setup();
}
