inherit ROOM;

void create()
{
set("short","菜園");
        set("long", @LONG
這裡種了一些包心菜以及豌豆之類的作物，青菜的顏色正是嫩綠，令人
看了只想採收起來飽嚐一番。這裡也看的到一些美麗的小花，淡淡地點綴，
令人感到生機盎然，十分舒服。
LONG
        );
        set("exits", ([
        "northwest":__DIR__"f11",
        "east":__DIR__"f22",
        "west":__DIR__"f20",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

