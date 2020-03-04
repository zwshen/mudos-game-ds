// File: /d/dead_forest/temple2.c
// Updated by tmr (Wed May 26 23:32:04 2004)

inherit ROOM;

void create()
{
          set("short", "神殿");
          set("long", @LONG
這是座神殿遺跡，四週只剩下殘破不堪的柱子跟雕像，也長滿青苔雜
草，但仍然可以感受到平和安靜的氣氛。
LONG
          );
          set("objects", ([ /* 1 element(s) */
        __DIR__"npc/kulasaier" : 1,
]));
          set("exits", ([ /* 1 element(s) */
                "out" : __DIR__"map_4_9",
        ]));

        setup();
        replace_program(ROOM);
}

