inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room24",
"south"     : __DIR__"room16",
"north"    : __DIR__"room28",
]));
}
