inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"east"      : __DIR__"room50",
"southwest" : __DIR__"room70",
]));
  setup();
}
