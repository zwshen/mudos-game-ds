#include <ansi.h>
inherit ROOM;
void create()
{
        set("short"," "HIC"男用的間"NOR" ");
        set("long",@LONG
這裡是男生們專用的澡堂， 四處散怖著清香，還沒泡澡，你的精神
已恢復了一大半看樣子這家澡堂果然名不虛傳...應該可以泡的很舒
服吧...你已忍不住想跳到大浴池裡了。
LONG       
);
        set("exits", ([
  "north" : __DIR__"bath_2",
]));
set("objects",([
__DIR__"tub" :1,

]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_in","in");
}
int do_in(string arg)
{
       object me,where;
       me = this_player();
       if( me->query_temp("armor") )
       {
       return notify_fail("為了衛生起見..請把你身上的裝備都卸(rem)下在進去泡澡吧！\n");
       return 1;
       }
       if( me->query_temp("suds") <= 0 )
       {
                write("沒付錢想接近浴池?門兒都沒有！\n");
                return 1;
       }
       if( me->query_temp("weapon") )
       {
       return notify_fail("為了衛生起見..請把身上的武器都卸(uwi)下在進去泡澡吧！\n");
       return 1;
       }
        {
        if( me->is_busy() )
        return notify_fail("你還在忙ㄝ...\n");
        if( me->is_fighting() )
        return notify_fail("你還在戰鬥中，沒有空去泡澡ㄛ\n");
        message_vision("$N滿心歡喜的跑向大浴池裡跑了過去。\n",me);
        me->start_busy(2);
        me->move(__DIR__"boy_bath");
        return 1;
       }
  }


