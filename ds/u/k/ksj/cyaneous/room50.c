inherit ROOM;

void create()
{
        set("short", "碎石子路");
        set("long", @LONG
這段路上的碎石子所剩無幾，大部份都被雨水沖刷掉了，整個路面變成黃土
    路面，幾根小草稀疏地長著。
LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"room51",
  "north" : __DIR__"room49",
  //"north" : __DIR__"room34",
  //"west" : __DIR__"room47",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

