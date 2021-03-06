// mudao11.c 墓道
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"墓道"NOR);
        set("long", @LONG
這里是古墓中的墓道，四周密不透風，借著�暀W昏暗的燈光，你能
勉強分辨出方向。�椄O用整塊的青石砌合起來的，接合得甚是完美，難
以從中找出一絲縫隙。燈光照在青石壁上，閃爍著碧幽幽的光點。
    北邊是一扇石門(door)。
LONG    );
        set("exits", ([
//              "north" : __DIR__"xiaoting",
                "south" : __DIR__"zhengting",
        ]));
        set("item_desc", ([
                "door" : "一扇厚重的石門，光溜溜的全沒有把手。你認真看了看，發現門邊的石壁上似乎有什麼按鈕(press button)可以開門。\n",
        ]));
        set("no_clean_up", 0);
        set("coor/x", -3200);
        set("coor/y", -30);
        set("coor/z", 90);
        setup();
}

void init()
{
        add_action("do_an", "press");
}

int do_an(string arg)
{
        object room, me = this_player();

          if( !arg || arg != "button" )
        {
                message_vision("你在石壁上亂按一氣，除了一手灰，啥也沒摸著。\n", me);
                return 1;
        }
        if( query("exits/north"))
        {
                return notify_fail("石門已經是開著了\n");
        }
        if( me->query_skill("unarmed", 1) > 10)
        {
                message_vision("$N站在石門前，也不知在哪里按了一下，石門吱吱響著，緩緩打開了。\n", me);
                if( !(room = find_object(__DIR__"xiaoting")) )
                        room = load_object(__DIR__"xiaoting");
                set("exits/north", __DIR__"xiaoting");
                room->set("exits/south", __DIR__"mudao11");
                tell_room(room,"只聽得石門在吱吱聲中被緩緩打開。\n");
                remove_call_out("close");
                call_out("close", 5, me);
        }
        else
                message_vision("$N試著在石壁上按來按去，可是石門紋絲不動，只得罷了。\n", me);
        return 1;
}

void close(object me)
{
        object room;

        tell_room(this_object(), "石門緩緩地關上，恢復了原狀。\n");
        delete("exits/north");
        if( !(room = find_object(__DIR__"xiaoting")) )
                room = load_object(__DIR__"xiaoting");
        room->delete("exits/south");
        tell_room(room,"南牆的石門緩緩地關上了。\n");
}

