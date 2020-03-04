inherit ROOM;

void create()
{
        set("short", "九天之地");
        set("long", @LONG
一睜開雙眼就被眼前的景色所吸引住，無邊無繼的空間裡，似乎還隱藏
著什麼，你回頭一看，只見身後是深不見底的藍海，而前方是一道橘色的
大門，使你好奇的想進去瞧瞧。
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"enter-room",
]));
        set("no_clean_up", 0);
        set("world", "undefine");
        set("outdoors", "lands");

        setup();
        replace_program(ROOM);
}

