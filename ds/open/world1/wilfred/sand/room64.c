inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room56",
"northeast" : __DIR__"room65",
"south"     : __DIR__"room63",
]));
  setup();
}
