inherit ROOM;

void create()
{

set("short","北大街");
set("long", @LONG
這裡就是神木村的北邊大街, 這裡的房屋都是用紅檜樹木做的, 所以
非常堅固.在你的東邊有家當鋪, 可供人買賣物品.往北可以出神木村, 往
南可到達中央廣場.
LONG
);
set("outdoors", "land");
set("light",1);
set("exits", ([                
        "east" : __DIR__"road_sell_shop1.c", 
        "south" : __DIR__"road_6.c", 
        "north" : __DIR__"road_13.c", 
   ]));

 setup();
}

