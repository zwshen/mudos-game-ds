inherit ROOM;

void create()
{
        set("short", "ªø«°");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room14", 
  "north" : __DIR__"room17", 
  //"east" : __DIR__"room15",
]));
set("light",1);

        setup();
}

