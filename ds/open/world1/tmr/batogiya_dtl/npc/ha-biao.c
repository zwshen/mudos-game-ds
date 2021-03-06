#include <npc.h>
#include <ansi.h>

#define TIMEC 120       // 開船時間

void create()
{
        set_name( "哈飆", ({ "ha biao" , "biao" }) );
        set("long",@long
哈飆一看就知道是在海邊長大的，黝黑的皮膚顯露出他滿身肌肉的精華。
他是藍海號船的船長，往返於杜尼港跟巴托奇亞共合國的登托拉兩地
，如您想要搭船，請確定你已買好船票，則再登船即可。(enter 藍海號)
long
);
    set("no_fight",1);
        set_race("strength");
        set("age", 40 );
        set( "title" , "藍海號船長" );
        setup();
        call_out("start_ship2" , TIMEC,this_object());  // TIMEC 秒後開船
}

void init()
{
        if( environment()->query("where")=="batogiya_dtl" )     {
                add_action("do_enter","enter");
                return;
        } 
        if( environment()->query("where")=="duli_port" )        {
                add_action("do_enter2","enter");
                return;
        } 
}
int do_enter(string arg)
{
        // 登托拉 往 杜尼港
        object me=this_player();
        object ticket;
        
        if( arg != "藍海號" ) return 0;
        
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒有空登船。\n");
        if( !objectp( (ticket=present("_OBJECT_DTL_BOAT_TICKET_",me) ) )  )
        {
                message_vision(CYN "哈飆伸手擋住了$N的去路，說道：「你並沒有船票，想要偷渡上船？？」\n" NOR,me);
                return 1;
        }
        message_vision(CYN "$N從口袋裡拿出了一張船票，交給了哈飆船長之後，然後登上了「藍海號」。\n" NOR,me);
        tell_room(environment(me),me->query("name")+"快步地登上了登艙口。\n",me);
        destruct(ticket);       // 沒收船票
        me->move("/d/batogiya_dtl/boat/map_9_11");      //登船
        return 1;
}

int do_enter2(string arg)
{
        // 杜尼港 往 登托拉
        object me=this_player();
        object ticket;

        if( arg != "藍海號" ) return 0;

        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒有空登船。\n");
        if( !objectp( (ticket=present("_OBJECT_DTL2_BOAT_TICKET_",me) ) )  )
        {
                message_vision(CYN "哈飆伸手擋住了$N的去路，說道：「你並沒有船票，想要偷渡上船？？」\n" NOR,me);
                return 1;
        }
        message_vision(CYN "$N從口袋裡拿出了一張船票，交給了哈飆船長之後，然後登上了「藍海號」。\n" NOR,me);
        destruct(ticket);       // 沒收船票
        me->move("/d/batogiya_dtl/boat/map_9_11");      //登船
        tell_room(environment(me),me->query("name")+"快步地登上了登艙口。\n",me);
        return 1;
}

/*      從登托拉 出發   */
void start_ship(object me)
{
        if(!environment(me) ) return;
        
        message_vision(HIG "$N大聲說道：「船要開往杜尼港了，大夥兒請小心了！！」\n" NOR,me);
        message_vision(CYN "$N快步走上了藍海號。\n" NOR,me);
        me->move("/d/batogiya_dtl/boat/map_9_11");      //登船
        tell_room(environment(me),me->query("name")+"快步地登上了登艙口。\n",me);

        /* 重設船上「登艙口」的出口 */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
        ]));
        
        call_out("on_duli_port" , 60 , me);     // 60 秒後到杜尼港

        return;
}

/*      抵達杜尼港      */
void on_duli_port(object me)
{
        //  哈飆 不存在空間裡..
        if(!environment(me) ) return;
        
        message_vision(HIG "$N大聲說道：「杜尼港到了！！，要下船的旅客請快吧。」\n" NOR,me);
        message_vision(CYN "$N大步走下了杜尼港口。\n" NOR,me);
        /* 重設船上「登艙口」的出口 */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
                "down" : "/d/duli_port/duli_port",
        ]));    
        
        me->move("/d/duli_port/duli_port");     //杜尼港
        tell_room(environment(me),CYN "藍海號慢慢地靠到了岸邊，哈飆船長從船上走了下來。\n" NOR,me);

        call_out("start_ship2" , TIMEC , me);   // 300 秒後開船

        return;

}

/*      從杜尼港出發    */
void start_ship2(object me)
{
        //  哈飆 不存在空間裡..
        if(!environment(me) ) return;
        
        message_vision(HIG "$N大聲說道：「船要開往登托拉了，大夥兒請小心了！！」\n" NOR,me);
        message_vision(CYN "$N快步走上了藍海號。\n" NOR,me);
        me->move("/d/batogiya_dtl/boat/map_9_11");      //登船
        tell_room(environment(me),me->query("name")+"快步地登上了登艙口。\n",me);

        /* 重設船上「登艙口」的出口 */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
        ]));
        
        call_out("on_whale_island",60,me);      // 60 秒後出發到杜尼港
        
        return;
}

/*      抵達鯨魚島      */
void on_whale_island(object me)
{
        //  哈飆 不存在空間裡..
        if(!environment(me) ) return;
        
        message_vision(HIG "$N大聲說道：「登托拉到了！！，要下船的旅客請快吧。」\n" NOR,me);
        message_vision(CYN "$N大步走下了登托拉港口。\n" NOR,me);
        /* 重設船上「登艙口」的出口 */
        environment()->set("exits",([
                "east" : "/d/batogiya_dtl/boat/map_9_12",
                "west" : "/d/batogiya_dtl/boat/map_9_10",
                "down" : "/d/batogiya_dtl/map_7_8",
        ]));
        
        me->move("/d/batogiya_dtl/map_7_8");
        tell_room(environment(me),CYN "藍海號慢慢地靠到了岸邊，哈飆船長從船上走了下來。\n" NOR,me);

        call_out("start_ship",TIMEC,me); // 300 秒後開船出發到杜尼港

        return;

}

