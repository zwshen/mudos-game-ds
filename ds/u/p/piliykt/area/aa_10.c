inherit ROOM;

void create()
{

set("short","武鬥場");
set("long", @LONG
你一來到這裡, 就被前方的彪型大漢給愣住了, 你稍微觀察了一下,
才知道他就是武鬥場的主人, 有許多的弟子都像他學習武藝, 讓你不竟手
養想跟他比比看武藝.
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                
"west" : __DIR__"aa_9.c", 

]));
set("objects",([
__DIR__"npc/master_1.c" : 1,
              ]) );

setup();
}

