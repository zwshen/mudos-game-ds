inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
看來這裡經過了一番開拓，才將高及肩的雜草給清除，並且
在上面鋪上碎石，以方便軍用的運輸車隊通行。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"ten9",
  "east" : __DIR__"camp002",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

