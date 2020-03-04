inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room7",
"north"    : __DIR__"room15",
]));
}
