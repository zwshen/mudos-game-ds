// Room: /open/world1/acme/bonze/b19.c
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "鑄劍谷");
        set("long", @LONG
山谷右側，依山建造一棟茅屋，背後山腰，有著數處瀑布，匹練
也似地，直往一處絕澗飛瀉，顯得秀麗絕俗。高空中涮下來數道水流
，尤如一片錦布橫越半空，令人心醉，盡滌俗慮。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"b18",
]));
set("objects",([
    __DIR__"npc/hua" : 1,
]) );
        set("outdoors","land");
set("item_desc",([
        "瀑布":"仔細一看，瀑布後面似乎有個山穴，可以進去(enter)看一看。\n",
        "茅屋":"一間頗為破爛的茅屋，不時有數道水滴濺上屋頂。\n",
]) );

        setup();
}

void init()
{
/// close by tmr 
// 玩家lestat 不願意再提供 地底遺跡區域
//        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        int invis;
        object me;
        me=this_player();
        if(me->is_busy()) return notify_fail("你的上一個動作還沒完成。\n");
        if(arg != "瀑布" && arg != "waterfall") return notify_fail("你要進入哪裡?\n");
        invis=me->query_temp("invis")+me->query_temp("hide");
        if(!invis) message_vision("$N進入了瀑布。\n",me);
        me->move(GROUND_TEMPLE"room-47.c");
        if(!invis) tell_room(environment(me),me->name()+"從瀑布外跳了進來，全身都濕透了十分狼狽。\n",({me}));
        me->water_effect(); //定義在char.c
        return 1;
}

