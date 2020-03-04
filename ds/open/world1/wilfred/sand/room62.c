inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room61",
"northwest" : __DIR__"room63",
"south"     : __DIR__"room54",
]));
  setup();
}
