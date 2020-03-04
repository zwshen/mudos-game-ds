inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"northwest" : __DIR__"room71",
"south"     : __DIR__"room52",
]));
  setup();
}
