inherit __DIR__"std_room.c";
void create()
{
  set("exits", ([
"west"      : __DIR__"room26",
"south"     : __DIR__"room20",
"north"    : __DIR__"room32",
]));
}
int valid_leave(object me, string dir)
{
  if( dir == "north" && !userp(me) && me->query("id") != "ghost") return notify_fail("那裡只有玩家才能進去。\n");
  return ::valid_leave(me, dir);
}

