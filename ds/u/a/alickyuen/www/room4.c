#include <ansi.h>
inherit ROOM;
string *exit = ({
       __DIR__"becloud1", __DIR__"becloud2",
       __DIR__"becloud3", __DIR__"becloud4",
       __DIR__"becloud5", __DIR__"becloud6",
       __DIR__"becloud7"
});

void create()
{
    set ("short", HIW"濃霧"NOR);
    set ("long", @LONG
所見四週盡是濃霧彌漫，濃厚的霧氣讓人完全不知道
要往何處走。
LONG);
    set("exits", ([
        "south"   : __DIR__"room2"]));
    set("outdoors","forest");
    set("no_map", 1);
    set("no_horse_member",1);
    set("no_clean_up", 0);
    setup();
}

void init()
{
    object me = this_player();
    if(interactive(me) && !me->query_temp("safe") && random(10) == 1)
    { 
        message_vision(HIY"突然吹來一陣強大的風，硬是把$N吹走。\n"NOR,me);
        tell_room(__DIR__"room2",HIY"突然一陣強風吹過，"+me->query("name")+"應聲落下。\n"NOR);
        me->receive_damage("hp",50+random(100));
        me->start_busy(2);
        me->move(__DIR__"room2");
        write(HIR"你被重重的摔到地上！\n"NOR);
    }
    set("exits", ([
        "south" : exit[random(sizeof(exit))],
        "north" : exit[random(sizeof(exit))],
        "east"  : exit[random(sizeof(exit))],
        "west"  : exit[random(sizeof(exit))]
    ]));
    return;
}
