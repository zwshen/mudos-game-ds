inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room5",
"west"      : __DIR__"room3",
"north"    : __DIR__"room10",
]));
}
