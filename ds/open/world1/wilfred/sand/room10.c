inherit ROOM;
void create()
{
  set ("short", "街道");
  set ("long", @LONG
鎮裡規模極小，只有一條大街，住戶也極少，街上黃沙滾滾，景
象一片淒涼，偶爾有外來客在此走動。
LONG
);
  set("exits", ([
  "north" : __DIR__"room9",
  "south" : __DIR__"room11",
]));
  set("objects",([
  __DIR__"npc/npc12" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
