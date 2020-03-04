#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit __DIR__"way00.c";

void create()
{
  set("short", "¤s±V¤p®|");
  set("long",(: print_mountain_msg :),);
  set("exits", ([ 
  "south" : __DIR__"way05",  
  "north" : __DIR__"way05n2",  
]));
        set("outdoors","land");

        setup();
}


