inherit ROOM;

void create()
{

set("short","走道");
set("long", @LONG
這裡是走道的盡頭, 往前方是到達大廳, 旁邊有個小房間不知是有何
用處, 讓你不竟好奇的想去瞧瞧.
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                

"north" : __DIR__"a_1.c", 
"east"  : __DIR__"a_2.c",
"south" : __DIR__"aa_2.c",
]));

setup();
}


