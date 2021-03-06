// Room: /open/world1/tmr/frost/depositary3f.c

inherit ROOM;

void create()
{
        set("short", "藏經閣三樓");
        set("long", @LONG
多數道教宮觀的建築為傳統的木結構建築，即以木架為骨幹，牆壁用
磚砌，用瓦蓋屋頂，而牆壁隔扇僅作為內外間隔之用，不負屋頂重量。而
藏經閣則是屬於這類建築，樓高七層，藏書萬卷，為觀內的主要建築之一
，平常是不准外人任意進出。而這兒是藏經閣的三樓。
LONG
        );
        set("current_light", 3);
        set("objects", ([ /* sizeof() == 1 */
                      __DIR__"npc/book1" : 4,
        ]));

        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"depositary2f",
  "up" : __DIR__"depositary4f",
]));

        setup();
}


int valid_leave(object me, string dir)
{
        ::valid_leave();
   
   if( dir == "up"
                && objectp( present("_MORALITY_BOOK_", this_object()) ) ) {
                        message_vision( "道德部擋在$N面前不讓$N上樓。\n", me);
                        return 0;
        }
        return ::valid_leave(me,dir);
}

