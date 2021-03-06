inherit ROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
你到了後山中的叢林中，這裡枝葉茂密樹叢遮天，自然的
生機非常蓬勃，旁邊的崖壁高聳無比，看來極為雄偉，崖壁上
流下一道山泉，淙淙水聲聽來舒暢不已，而在你的正前方有一
面山壁，看來高聳無比要攀爬可能需要很高的勇氣。
LONG
        );
  
set("exits", ([
  "westup" : __DIR__"mu20", 
]) );
set("item_desc", ([
    "山泉" : "順著崖壁自然湧出的泉，若渴的話可以喝(drink)。\n",
    "山壁" : "一面看來非常滑直的山壁，有信心的人可以攀爬(climb)看看。\n",
]));
set("objects",([__DIR__"animal/wolf" : 3,]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
  
void init()
{
  add_action("do_drink","drink");
  add_action("do_climb","climb");
}

 int do_drink(string arg)
{
        object me;
        if( !arg || arg!="山泉" ) return notify_fail("你要喝什麼東西?\n");
        me=this_player();
       if(query("water") > 500)
        {
        return notify_fail("泉水將要乾涸了，還是水源回復時再說吧！。\n");
        }
        else 
        {
        message_vision("$N喝了一口泉水，覺得有精神多了。\n",me);
        me->receive_heal("hp",me->query("max_hp")/15);
        me->receive_heal("ap",me->query("max_ap")/15);
        me->receive_heal("mp",me->query("max_mp")/15);
        add("water",1);
        return 1;
        }
}

int do_climb(string arg)
{
        object me=this_player();        
        if(arg!="山壁") 
                return notify_fail("你想要攀爬(climb)什麼？");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，無法專心應付此動作。\n");
        if(me->query_skill("dodge",2) <50)
                return notify_fail("你的輕功\造詣不足，你無法安全地跳過去。\n");
        if(!me->move(__DIR__"musun.c") )
                return notify_fail("你無法攀爬上去。\n");
        message_vision("$N使出純熟的輕功\迅捷的爬了上來。\n",me);
        return 1;
}

void reset()
{
  set("water",0);
  ::reset();
}










