inherit ROOM;
void create()
{

set("short","東大街");
set("long", @LONG
你慢慢的走到了這裡, 神木村中的東大街在這裡結束了, 這裡顯得比
剛剛還要安靜得多了, 而西邊則是往中央廣場前進, 而再往東前進就要出
了神木村.
LONG
);
set("outdoors", "land");
set("exits", ([                
"east" : __DIR__"rr_5.c", 
"west" : __DIR__"rr_1.c", 
        ]));
set("objects",([
__DIR__"npc/guard_2.c" : 1,
       ]) );

 setup();
}


