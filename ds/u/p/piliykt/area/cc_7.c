inherit ROOM;

void create()
{

set("short","小山路");
set("long", @LONG
這裡離無砂鎮越來越近, 你已經可以聞到海的味道, 使你不自覺的興
奮, 心裡有一種歸心似箭的衝動 .
LONG
);
set("outdoors","forest");
set("exits", ([                
        "up" : __DIR__"cc_6.c", 
        "eastdown" : __DIR__"cc_8.c",
   ]));

 setup();
}

