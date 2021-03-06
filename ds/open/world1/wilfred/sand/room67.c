#include <ansi.h>
inherit ROOM;

void can_down(int index);

void create()
{
  set ("short", "陰");
  set ("long", @LONG

經過了重重險阻，你終到達了這裡，這個石室較其他為大，只見
壁上刻著數個大字：
　　　　　　　　　　得天時者，擇之為乾
　　　　　　　　　　得地利者，擇之為坤
　　　　　　　　　　得人和者，擇之為無極

在大字下方立著一塊石碑，上頭刻了些字。

LONG
);
  set("exits", ([
  "north" : __DIR__"room66",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

void can_down(int index)
{
  string temp;
  mapping exits = query("exits");

  if(!index)
  {
    set("exits", ([
  "north" : __DIR__"room66",
]));
    tell_room(this_object(),HIB"\n樓梯慢慢的關上了 ...... \n\n"NOR);
    return;
  }

  temp = __DIR__"room75";
  if(mapp(exits)) set("exits", (mapping)exits + ([ "down" : temp, ]) );
    else set("exits", ([ "down" : temp, ]));

  tell_room(this_object(),HIW"\n轟的一聲，突然出現了一個往下的樓梯！！\n\n"NOR);
  return;
}

void reset()
{
  can_down(0);
  ::reset();
}
