inherit ROOM;
void create()
{
        set("short", "小溪");
        set("long", @LONG
這裡就是在天池下的小溪，自天山頂上盤旋而下，寬有十數丈，水流
不疾，水亦不深，約只有一尺餘。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"l2",
  "south" : __DIR__"l4",
]));
set("item_desc", ([
    "小溪" : "哇！這清澈的小溪，最適合不太會游泳的人來練習(practice)游泳了。\n",
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        if( this_player()->query_temp("Swim") )
                this_player()->delete_temp("Swim");
        add_action("do_practice","practice");
        add_action("do_go","go");
}
int room_effect(object me)
{
   me=this_player();
   if(me->query_temp("Swim")) 
   {
     if(me->query("swim")>20) return notify_fail("你的泳技在這水淺的地方，已經無法進步了。\n");
     if(me->query("ap")<10) return notify_fail("你的體力不夠了，無法再練習游泳。\n");
     message_vision("$N在水上努力的練習游泳，似乎頗有心得。\n",me);
     me->improve_skill("swim", random(me->query_int()+5)+1);
   }   
}
int do_practice(string arg)
{
        object me;
        me=this_player();
        if(arg != "swim")  return notify_fail("你只能在這裡練習游泳(swim)。\n");
        if( me->over_encumbranced() ) return notify_fail("你的負荷過重﹐動彈不得。\n");
        if( me->query("wound/foot") > 10 ) return notify_fail("你的雙腳傷勢過重，無法游泳。\n");
        if( me->query("wound/hand") > 10 ) return notify_fail("你的雙手傷勢過重，無法游泳。\n");
        if( me->query("wound/head") > 10 ) return notify_fail("你的頭部傷勢過重，無法游泳。\n");
        if( me->query("wound/body") > 10 ) return notify_fail("你的身體傷勢過重，無法游泳。\n");
        if(me->query("ap") <10) return notify_fail("你的體力不夠，無法繼續練習游泳。\n");
        if( me->query_temp("Swim"))
                return notify_fail("你已經在練習游泳了。\n");
        if( me->is_fighting() )
                return notify_fail("你正忙著打架，沒空練習游泳。\n");
        if( me->is_ghost() )
                return notify_fail("都死了，難道你要當個水鬼害人？\n");
        if( me->is_busy() )
                return notify_fail("你正忙著，沒有空練習游泳。\n");
        if( me->query_skill("swim",1) > 20 )
                return notify_fail("在這種水淺，你的泳技無法進步了。\n");
        message_vision("$N深深吸了一口氣，開始練習游泳了。\n",me);
        me->set_temp("Swim",1);
        return 1;
}
int do_go(string arg)
{
        object me;
        me=this_player();
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        if(me->query_skill("swim") <20 )
        {
         tell_object(me,"你的游技不夠純熟，往前去將會有生命危險。\n");
        }
        else {
         message_vision("$N使出純熟的游技，緩緩的往前游去。\n",me);
         me->move(__DIR__"l2");
        }
        return 1;
}
