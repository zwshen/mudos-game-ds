inherit ROOM;
void create()
{
        set("short", "泊浪村海灘");        
        set("long",@LONG
這裡是柏浪村港口附近的海灘，海灘上有著許多的生物，常常都有
漁夫來此地捕捉一些海類，而來此的遊客也常來這裡觀景，算是海邊的
一個特色，往遠方望去一片大海藍悠悠的景色，加上天上白雲的襯托，
讓人產生一種開闊的胸懷。
LONG
        );
        set("exits", ([
   "south" : __DIR__"se3",
   "southwest" : __DIR__"se9",
   "east" : __DIR__"se7", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








