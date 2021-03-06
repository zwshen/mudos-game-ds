// 紫陽山第一層
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "紫陽山");
        set("long", @LONG
走著走著，山路上突然出現了棵茂盛的大樹，奇怪的是附近也沒有
更高大的樹了，應該可以到那去歇息歇息，繼續往前走仍是山路，崎嶇
陡然，不好走的樣子。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"1f4.c",
  "northwest" : __DIR__"1f2.c",
]));
        set("item_desc", ([
  "大樹" : "這是一棵茂盛的大樹，並不怎麼很高大，上面有些空曠的地方。\n",
]));
        set("world", "past");
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();
        if( arg != "大樹" && arg != "tree" ) return 0;
        if( me->can_move(__DIR__"tree.c") )
        {
                message_vision(WHT"$N小心翼翼的爬上樹．．．\n"NOR,me);
                me->move(__DIR__"tree.c");
		tell_room( environment(me) , me->name()+"從樹下爬了上來，跟你擠成一團。\n", ({ me }));
                me->start_busy(1);
                return 1;
        }
        else return notify_fail("你好像沒辦法上去樹上！\n");
}
