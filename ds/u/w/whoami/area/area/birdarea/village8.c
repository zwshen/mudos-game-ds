#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"獵狐村"HIW+BLK"─"HIW"小棧亭"NOR);
        set("long", @LONG
你來到了獵狐村的客棧--小棧亭, 你看到這裡有四張大桌子
, 桌子旁還有幾張椅子, 你可以在這裡暫時休息(rest), 假使你
真的很累的話, 你也可以上樓睡個覺再出發.
LONG
        );
        set("exits", (["east": __DIR__"village7",
                       "up" : __DIR__"village9",
                      ]));
        set("objects", ([__DIR__"npc/waiter4" : 1,
        ]));
      
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="up" )return ::valid_leave(me, dir);

        if( dir=="up" && me->query_temp("sleep") <=0 || !me->query_temp("sleep") )
                return notify_fail("你還沒向店小二訂房間！\n");

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_rest","rest");
}

int do_rest(string arg)
{
        object me;
        me = this_player();
        if( me->is_busy() )
                return notify_fail("你還在忙吧, 應該沒時間去歇息. \n");
        if( me->query_temp("rest") <= 0 )
        {
                write("你所能歇息的次數已用光了！\n");
                return 1;
        }
        if( me->query_temp("is_busy/sitting") )
        {
                write("你正在靜坐。\n");
                return 1;
        }
        message_vision("$N在這裡找了一個位子坐了下來，開始靜坐了起來。\n",me);
        me->add_temp("rest",-1);
        me->set_temp("is_busy/sitting","你正在靜坐。");
        me->start_busy(10);
        call_out("sleep",0,1,me);
        call_out("sleep",10,2,me);
        return 1;
}

void sleep(int c,object me)
{
        switch(c) {
        case 1:
                tell_object(me,HIC"你漸漸開始進入心空的狀態，什麼都不想．．\n"NOR);
                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
                tell_object(me,HIG"你漸漸睜開眼睛，把心給收了回來。\n"NOR);
                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int());
                me->delete_temp("is_busy/sitting");
        break;
        }
}

