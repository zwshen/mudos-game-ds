inherit ROOM;

void create()
{

set("short","大街");
set("long", @LONG
這裡是中央廣場的南邊, 你走在大街上感覺非常舒服, 你看了看大街
,才知道街道兩側掛上了燈籠, 原來你的左邊有家百花樓, 燈火通天,讓整
個街道金光閃閃.往南到達大街.
LONG
);
set("outdoors", "land");
set("light",2);
set("exits", ([                
        "south" : __DIR__"road_8.c", 
        "east"  : __DIR__"sex_1.c",
        "north" : __DIR__"road_6.c",
   ]));
set("objects",([
__DIR__"npc/dog1.c" : 1,
       ]) );

 setup();
}

