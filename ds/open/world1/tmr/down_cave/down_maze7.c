// File: /d/down_cave/down_maze7.c
// Updated by tmr (Mon Aug 18 02:30:49 2003)

inherit ROOM;

void create()
{
          set("short", "空洞穴");
          set("long", @LONG
你正在一個空空如也的洞穴中，四周黑漆漆的，看的不是很清楚。
LONG
          );
          set("exits", ([ /* 5 element(s) */
        "east" : __DIR__"down_maze1",
        "up" : __DIR__"map_13_16",
        "west" : __DIR__"down_maze1",
        "down" : __DIR__"down_maze1",
        "north" : __DIR__"down_maze1",
]));

        set("objects",([
                __DIR__"npc/bandit2" : 4
        ]) );
        setup();
          replace_program(ROOM);
}

