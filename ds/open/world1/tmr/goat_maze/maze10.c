#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "羊男的迷宮 - "HIG"贛林老木"NOR);
        set("long", @LONG
你正走在一個以石頭牆圍成的迷宮，似乎是幾千年前就建在這森林之
中。綠色的青苔及花草爬滿了四週一堵又一堵的石牆，與森林自然而然地
融合在一起。你雖然身處在迷宮之中，但是倒也不急著想要離開。在你眼
前正聳立一棵千年神木，你抬頭上望，只瞧見樹幹直上入天，竟看不到神
木的頂端。
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "贛林老木" : "贛林老木高聳入天，你注意到樹根處有個頗大的樹洞。
",
  "贛林樹洞" : "贛林樹洞裡面一片漆黑，你有點想要進去(enter)裡面探險。
",
]));
        set("no_clean_up", 0);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"maze5",
  "north" : __DIR__"maze11",
]));
        set("current_light", 3);

        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg) {
        if( arg != "贛林樹洞" ) return notify_fail("你想要進到哪裡？\n");
        if(this_player()->is_busy())
                return notify_fail("你正忙著。\n");
        message_vision("$N一彎身就往樹洞裡爬去。\n", this_player() );
        this_player()->move(__DIR__"tree1");
        message_vision("$N從樹洞爬了進來。\n", this_player() );
        return 1;
}


