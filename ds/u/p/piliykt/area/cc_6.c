inherit ROOM;

void create()
{

set("short","小路");
set("long", @LONG
這裡的路雖然難走, 但已經是下坡了, 所以你走起來沒那麼累, 反而輕鬆,
你望著山下的無砂鎮, 使你的腳步越走越快
LONG
);
set("outdoors","forest");
set("exits", ([                
        "west" : __DIR__"cc_5.c", 
        "down" : __DIR__"cc_7.c",
   ]));

 setup();
}

