inherit ROOM;

void create()
{
        set("short", "海岸");
        set("long", @LONG
這裡是港口的海岸邊，腳底下是用石塊鋪成的道路，岸邊放有許多
    大岩石用來抵擋海浪的侵襲，岩縫中躲著一些小魚慌張地竄逃。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room14",
  //"west" : __DIR__"room4",
  "north" : __DIR__"room12",
  "east" : __DIR__"room32",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}

