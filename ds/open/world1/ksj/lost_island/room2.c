#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－  "HIG"獸原"NOR);
        set("long", @LONG
這裡是一望無際的大草原，長滿及膝的青翠雜草，還有許多不知
名的花草植物，草原上飛舞著七彩蝴蝶和奇異的昆蟲，遠遠可以看到
珍禽異獸在草原中奔跑覓食，放眼望去渺無人煙，儼然是動物的世外
桃源，南面是一片陡峭的岩壁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room3",
  "north" : __DIR__"room6",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("item_desc", ([
        "岩壁" : "高約數丈的一片岩壁，陡峭而濕滑。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me=this_player();        
        if(arg!="岩壁") 
                return notify_fail("你想要跳(jump)過什麼？");
        if(me->is_busy() )
                return notify_fail("你正忙著，無法專心應付此動作。\n");
        if(me->query_skill("dodge",2) <60)
                return notify_fail("你無法安全地跳過去。\n" );
        if(!me->move(__DIR__"room1") )
                return notify_fail("你無法跳過缺口。\n");
  tell_room(me,HIW"$N提氣一躍而上，雙足輕踩岩壁，幾次借力後身影消失在岩壁的另一方。\n"NOR,me);

        return 1;
}
