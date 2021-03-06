// Room: /open/world1/tmr/bagi/cave1.c

inherit ROOM;

void create()
{
        set("short", "山洞內");
        set("long", @LONG
你正站在此岩洞的洞口處，往外即可離開這個岩洞。雖是在高山之上
，但這邊已經不見有任何積雪，周遭的溫度也沒有洞外的那般酷寒，看樣
子在這裡避避風雪也不無小可。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"ghat13",
]));
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 2 */
  "西面石壁" :@long
這面石壁的色澤和其它三面略有不同，由於洞內昏黑，你一時也瞧不
清，或許可以試著碰觸(touch)看看。
long
,
]));
        set("current_light", 3);
        setup();
}

void init()
{
        add_action("do_touch","touch");
        add_action("do_push","push");
}

int do_touch(string arg)
{
        object me=this_player();
        if(!arg || arg!="西面石壁") return 0;
        message_vision("$N伸出雙手對著石壁敲敲推推.....\n",me);
        tell_object(me,"你發覺這面石壁似乎是一道可以推開的活門！？\n");
        return 1;
}

int do_push(string arg)
{
        object me =this_player();
        if(!arg || arg!="西面石壁") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒有空做其它事。\n");
        message_vision("$N對著石壁用力一推，忽然整個人隨著石壁翻轉到另一邊去了！！？？\n",me);
        me->move(__DIR__"area/1f/map_3_7.c");
        tell_room(me,"一陣聲響過後，$N忽然出現在你面前。\n",({ me }));
        return 1;
        
}

