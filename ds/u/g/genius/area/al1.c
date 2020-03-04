inherit ROOM;

void create()
{
set("short", "愛門村口");
        set("long", @LONG
這是愛門村的入口，在你的左手邊有一片草地，上面佈滿了多采多姿的
鮮花，右手邊則是一座防禦性的瞭望塔，大約有五層樓高，用來俯瞰這附近
森林的動態。一些村姑準備走出村外採集香菇，經過你的身旁，對你親切地
微笑。你感覺到一份人情味的氣息。

LONG
        );
        set("exits", ([
     "east":__DIR__"al0",
     "southwest":__DIR__"al2",
]));

        set("objects", ([
        __DIR__"npc/girl" : 2,

]));
        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

