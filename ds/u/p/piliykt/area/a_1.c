inherit ROOM;

void create()
{

set("short","大廳");
set("long", @LONG
這裡是趙王府的大廳, 四周牆上掛了許多名畫, 和書法詩詞, 正前方
坐的正是趙王劉煜, 他的兩旁都有護衛保護著他, 你看他正忙著處理事務
便覺得別去打擾他好了.
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                

"south" : __DIR__"aa_3.c",
]));
set("objects",([
__DIR__"npc/pikemaster.c" : 1,
__DIR__"npc/axemaster.c" : 1,
__DIR__"npc/blademaster.c" : 1,


              ]) );

setup();
}

