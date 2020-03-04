inherit ROOM;

void create()
{
        set("short", "雲端階梯");
        set("long", @LONG
你正在一處雲端階梯上，腳下踩的是團團白花花的雲朵，你也不清楚
人怎麼可能站在雲上，這的確是個不解之迷。雲端階梯往上可以通往雲端
廣場，往下可以走回到地面。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "up" : __DIR__"way4.c",
    "down" : __DIR__"way4d2.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "land");
        set("current_light", 1);

        setup();
        replace_program(ROOM);
}

