inherit ROOM;
void create()
{
  set ("short", "磐龍城郊");
  set ("long", @LONG
你離開黃沙道，來到另一條大路前，四週都是高大林木，到了這
裡，再往北走數里的路便是磐龍城了。
LONG
);

  set("exits", ([
  "north" : __DIR__"room45",
  "south" : __DIR__"room43",
]));
  set("objects",([
  __DIR__"npc/npc4" : 4,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
