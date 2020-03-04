#include <ansi2.h>
inherit ROOM;
void create()
{
  set ("short", YEL"黃沙平原"NOR);
  set ("long", @LONG
這裡是一望無際的大沙漠，除了零星分佈的耐旱植物外，再也見
不到什麼值得注目的東西，一陣風沙吹來，將四周吹得迷霧朦朧，有
如身墮五里沙霧。
LONG
);

  set("exits", ([
  "north" : __DIR__"room24",
  "south" : __DIR__"room26",
]));
  set("objects",([
  __DIR__"npc/npc1" : 2,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
