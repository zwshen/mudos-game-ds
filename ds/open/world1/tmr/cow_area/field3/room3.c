inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room4",
"north"    : __DIR__"room9",
]));
}
