#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "馬槽");
  set ("long",NOR""+
"相當不起眼的小型馬槽，陳設老舊，房屋破爛，"HIC"裡面只養著幾匹\n"+
"劣馬，看來是環境所致，培育不出良馬。\n"NOR);

  set("exits", ([
  "east" : __DIR__"room13",
]));
  set("objects",([
  __DIR__"npc/npc31" : 1,
]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

