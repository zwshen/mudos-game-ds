inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room29",
"south"     : __DIR__"room23",
]));
}
