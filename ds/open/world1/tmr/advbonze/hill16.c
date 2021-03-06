// Room: /open/world1/tmr/advbonze/hill16.c

inherit ROOM;

void create()
{
        set("short", "凌雲峰-上天梯缺口處");
        set("long", @LONG
你正站在上天梯的一處缺口處，你清楚看到上天梯到此之後竟然缺
了一個大斷口，距離此斷口往北約十數丈外才見到另一處斷口，二個缺
口之間尤如隔了個大懸崖一旁，稍一失足，就有可能直摔到山谷裡，你
不禁考慮著自已的輕功造詣，是否能跳(jump)的過去。
LONG
        );
        set("current_light", 5);
        set("no_clean_up", 0);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 1 */
          "southdown" : __DIR__"hill15",
        ]));
        set("item_desc", ([
          "缺口" : "一個十幾丈見寬的大缺口，你可以看凌雲峰山腰下的情況。\n"
        ]));

        setup();
}

void init()
{
    ::init();
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me=this_player();        
        if(arg!="缺口") 
                return notify_fail("你想要跳(jump)過什麼？");
        if(me->is_busy() )
                return notify_fail("你正忙著，無法專心應付此動作。\n");
          if(me->query_skill("dodge") < 10)
                return notify_fail("你的輕功\造詣不足，你無法安全地跳過去。\n");
        if(!me->move(__DIR__"hill17.c") )
                return notify_fail("你無法跳過缺口。\n");
        tell_room(environment(me), me->name()+"一提氣跳過了缺口，輕巧巧地落在地上。\n");

        return 1;

}


