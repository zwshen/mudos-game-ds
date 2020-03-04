inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room65",
"north"     : __DIR__"room50",
"southeast" : __DIR__"room59",
]));
  setup();
}
