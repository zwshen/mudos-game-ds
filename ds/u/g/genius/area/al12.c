 inherit ROOM;

void create()
{
set("short", "愛門村小路");
        set("long", @LONG
這裡是愛門村北邊的小路，沿著這條路過去就可以走上西邊的丘陵。這
裡有著比其他地方更濃郁的香氣，附近一戶農舍的後院種了一整片的花卉。
這片花園是由農舍主人的女兒細心維護經營而成的，有時她也會將自己的花
拿到街上賣，散播幸福的氣息。
LONG
        );
        set("exits", ([
     "east":__DIR__"al13",
     "west":__DIR__"al11",
     "north":__DIR__"r7",
]));
        set("objects", ([
        __DIR__"npc/sellgirl" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
