inherit ROOM;

void create()
{
        set("short", "¾ô¤W");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/world1/wilfred/sand/room45",
  "north" : __DIR__"room1",
]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

