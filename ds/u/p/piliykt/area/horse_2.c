inherit ROOM;

void create()
{
        set("short", "趙王府");
        set("long", @LONG
這裡是王府大門, 在門口上方有個匾額, 在王府大門的二旁各站了個
個守衛, 在王府的四處都被圍牆給包了起來, 給人一種神秘感, 讓你很想
進入王府一看就竟. 
LONG
);
set("light",1);
set("exits", ([ 
               "out" : __DIR__"road_4.c", 
               "north" : __DIR__"aa_1.c.c",     

]));
set("objects",([
__DIR__"npc/guard_1.c" : 2,
       ]) );

        set("no_clean_up", 0);

setup();
}   
int valid_leave(object me, string dir)
{
       if( dir=="out" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}


