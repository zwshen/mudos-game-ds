#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
set("short",HIM"七手八腳研究室"NOR);
set("long", HIB"\n施工中......\n\n"NOR);


      set("exits", ([
      "east": "/u/g/genius/roomenter.c",
      ]));
      set("light",1);
set("objects",([
      "/u/g/genius/npc/jojo" : 1,
      ]));
      setup();
}

