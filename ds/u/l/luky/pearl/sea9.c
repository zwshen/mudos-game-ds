// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "海神塔");
set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
);
set("exits", ([ 
  "east" : __DIR__"sea3",
  "north" : __DIR__"sea1",
]));
set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
