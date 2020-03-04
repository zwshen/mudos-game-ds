#include <room.h>
inherit ROOM;

void create()
{
  set("short","岩石丘");
  set("long",@LONG
這裡是由一些巨大的岩石堆成的小山丘，山丘中有許多岩縫，有
的岩縫外散落一些骨頭，這裡雖然沒有濃密的樹林，陰森的感覺也較
輕，但卻令人有種緊張的感覺，連空氣似乎都帶有血腥味。
LONG);
  set("exits",([ 
      "east":__DIR__"room54",
      "west":__DIR__"room52",
      "south":__DIR__"room48",
      "northeast":__DIR__"room56",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
     ]) );
  setup();
}            
