
inherit ROOM;

void create()
{
        set("short", "½m¥\\©Ð");
        set("long", @LONG

        ¢y                  ¡U  ¡U        ¢k
        ¢y      [1;51;45m½m[0m      [1;57;45m¡¶[0m¡Ð[1;57;45m¡¼[0m¡Ð[1;57;45m¨¾[0m¡Ð[1;56;45m®i[0m    ¢k
        ¢y      ¡U    ¢¬    ¡U  ¡U  ¡U    ¢k
        ¢y  [1;33m¡ò[0m¡Ð[1;57;45m¡¼[0m¡Ð[1;57;45m¡¼[0m      [1;57;45m¡¼[0m  [1;56;45m¹D[0m  [1;51;45m®i[0m    ¢k
        ¢y      ¡U          ¡U            ¢k
        ¢y  [1;56;42m¤t[0m¡Ð[1;57;42m¡¼[0m¡Ð[1;57;42m¬r[0m      [1;57;45m¡¼[0m¡Ð[1;57;45m¡¼[0m¡Ð[1;57;45m¡¼[0m¡Ð¥X¢k
        ¢y                                ¢k

LONG
        );
        set("light", 1);
        set("current_light", 2);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/goldman5" : 10,
]));
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"map_5_2",
]));
        set("no_clean_up", 0);

        setup();

}
