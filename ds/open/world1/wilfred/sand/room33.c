inherit ROOM;
void create()
{
  set ("short", "石神廟");
  set ("long", @LONG
這是一座用石頭建成的小廟，裡面除了一尊神像之外，什麼都沒
有，外頭風沙極大，廟裡一塵不染，好像有什麼力量能避風沙。
LONG
);

  set("exits", ([
  "north" : __DIR__"room32",
]));
  set("objects",([
  __DIR__"npc/npc35" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

