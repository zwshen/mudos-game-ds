#include <room.h>
inherit ROOM;

void create()
{
  set("short","岩頂");
  set("long",@LONG
這裡是岩石丘的上方，腳下的石面蠻乾淨平整的，好像有經過修
整，岩頂上建了座祭壇，祭壇外擺了一個大鍋，鍋子旁邊放了些柴火
正在燃燒。
LONG);
  set("exits",([ 
      "down":__DIR__"room56",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/cat-oldwoman":1,
      __DIR__"npc/eq/big-pot":1,
     ]) );
  setup();
}            
