inherit ROOM;

void create()
{

set("short","長廊走道");
set("long", @LONG
這是一條橫貫東西的長廊, 長廊邊擺放了許多小盆栽, 給人一種綠意
盎然的感覺, 兩旁各有一條走道, 都是通往臥房. 
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                
         "south" : __DIR__"aa_1.c", 
         "north" : __DIR__"aa_3.c", 
         "west" : __DIR__"aa_4.c", 
         "east" : __DIR__"aa_5.c", 
   ]));
set("objects",([
__DIR__"npc/guard_3.c" : 1,
              ]) );

setup();
}

