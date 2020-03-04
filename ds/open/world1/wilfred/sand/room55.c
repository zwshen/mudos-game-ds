inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"southeast" : __DIR__"room73",
"north"     : __DIR__"room56",
]));
  setup();
}
