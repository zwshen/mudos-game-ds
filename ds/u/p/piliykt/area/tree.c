inherit ROOM;

void create()
{

set("short","神木");
set("long", @LONG
你正站在神木上, 觀看你的四周, 都是巨大的樹枝和樹葉, 不竟讓你
非常懷疑這棵樹活了多久, 地上隱約有一條小路, 彎彎曲曲不知道通道哪
裡.
LONG
);
set("outdoors", "desert");
set("exits", ([                
        "south" : __DIR__"lll.c", 
        "up"  : __DIR__"tree1.c",
   ]));

 setup();
}



