inherit ROOM;

void create()
{

set("short","走道");
set("long", @LONG
你正站在走道中, 這是一條通往臥房的道路, 往北是趙王劉煜的房間
, 此地燈光微暗, 往東可至庭院.
LONG
);
set("light",1);
set("exits", ([                
"south" : __DIR__"aa_6.c",        
"east" : __DIR__"aa_2.c", 
"north" : __DIR__"aa_7.c",
"west" : __DIR__"aa_8.c",  

]));

setup();
}



