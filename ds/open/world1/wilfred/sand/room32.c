inherit ROOM;
void create()
{
  set ("short", "山崗上");
  set ("long", @LONG
好不容易爬上這山，你從山上往下望，才發現這是由一堆堆大小
不等的石頭所堆起的山丘，令人納悶的是，顯然這是由人工堆成的，
但又有誰有這等能耐，在如此荒僻之地堆了這座山丘？從這裡可以看
到原來黃沙鎮在山的東邊直行十里處。
LONG
);

  set("exits", ([
  "west" : __DIR__"room31",
  "south" : __DIR__"room33",
  "eastdown" : __DIR__"room93",
]));
  set("objects",([
  __DIR__"npc/npc11" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("stone beast", this_object())) && dir == "south" )
  {
    message_vision("咻的一聲，$n忽然動了起來，"+"只見牠以極快的速度擋在$N面前，不讓$N過去。\n",me , guard);
	return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
