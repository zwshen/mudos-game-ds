inherit ROOM;

void create()
{
        set("short", "晴子的廁所");
        set("long", @LONG
這裡是晴子平日所用的廁所。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" :"/u/b/basic/rooms/room1",
  "west" : "/u/b/basic/rooms/room3",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
