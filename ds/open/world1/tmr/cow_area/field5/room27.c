inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room26",
"south"     : __DIR__"room20",
]));
}
