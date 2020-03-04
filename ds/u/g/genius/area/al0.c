inherit ROOM;

void create()
{
set("short", "愛門村外");
        set("long", @LONG
你面前所見是一座座低矮的農村房舍，這裡就是純樸的愛門村了。這裡
的空氣十分地好，天空中飄著一朵朵的彩雲。你的心情十分的舒暢，步伐也
跟著輕快起來。
LONG
        );
        set("exits", ([
     "west":__DIR__"al1",
]));
        set("hide_exits", ([
        "out" : __DIR__"firstroom",
        ]));


        set("objects", ([
]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
