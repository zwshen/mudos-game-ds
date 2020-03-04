inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"northwest" : __DIR__"room58",
"south"     : __DIR__"room60",
]));
  setup();
}
