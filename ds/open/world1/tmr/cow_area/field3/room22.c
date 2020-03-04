inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room21",
"south"     : __DIR__"room15",
]));
}
