inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"southeast" : __DIR__"room71",
"west"      : __DIR__"room57",
"south"     : __DIR__"room58",
]));
  setup();
}
