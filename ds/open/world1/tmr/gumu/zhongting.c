// Room: /d/gumu/zhongting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "中廳");
        set("long", @LONG
這處是古墓派弟子參見掌門之處，此刻古墓傳人小龍女及神雕大俠
楊過早已名頌江湖，這對璧人不但武功已成一派宗師，兩人矢志不渝之
深情更令世人傾慕不已。廳內只一張長桌，兩把石椅。
    廳上方有一塊匾額(board).
LONG    );
        set("exits", ([
                "east"  : __DIR__"mudao06",
          "west"  : __DIR__"mudao05_e",
                "south" : __DIR__"mudao08",
                "north" : __DIR__"mudao17",
        ])); 
        set("item_desc", ([
                "board" :  HIR"
             ※※※※※※※※※※※※※※※※
             ※※　                      ※※
             ※※    此情不悔 天荒地老   ※※
             ※※                        ※※
             ※※※※※※※※※※※※※※※※\n"NOR
       "你瞧見若大一塊匾額，後頭似乎還有些空間，你思索是否要跳(jump)上去。\n",
        ]));
        setup();

}

void init()
{ 
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if (arg!="board")
                return notify_fail("要往哪里跳？\n");
        message_vision(HIY"$N凝氣守中，平空拔起數丈，輕輕落在匾額之後。\n"NOR,me);
        me->move(__DIR__"bianhou"); 
        return 1; 
}

