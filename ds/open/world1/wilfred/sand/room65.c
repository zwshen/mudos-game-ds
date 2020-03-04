inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room58",
"southwest" : __DIR__"room64",
"southeast" : __DIR__"room66",
]));
  setup();
}
