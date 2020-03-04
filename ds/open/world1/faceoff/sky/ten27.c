#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"龍井棧道-斷口"NOR);
 set("long",@LONG
龍井棧道在這裡就結束了, 你眼前只剩下一片峽谷, 而
龍井棧道原本在此轉角只看得到一堆石礫, 彷彿在提醒人們
這裡曾經是經商的主要途徑, 而只有眼前的山壁這靜靜傾聽
....
LONG
    );
 set("exits",([    "south":__DIR__"ten26",
       "northwest":__DIR__"moon",
    ]));
set("no_clean_up",0);
set("outdoors","land");
set("item_desc",([
      "山壁" : CYN"這山壁雖然陡峭,在輕功\上有一定程度的人應該可以爬(climb)的上去\n"NOR,
]));

 setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me,where1,where2;
        string a;
      int x;
        me = this_player();
        where1 = load_object(__DIR__"ten28");
      where2= load_object(__DIR__"ten29");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要爬到哪裡?\n");
        if( a!="山壁" )
                return notify_fail("這裡沒有這種東西給你爬\n");
        message_vision(HIW"只見$N輕輕鬆鬆的在山壁上跳躍, 忽然一個轉身失去了蹤影..?!\n"NOR,me);
       x = me->query_skill("dodge") + me->query("dex") + random(40);
       if ( me->query("level") >5 &&  x < 33 )
   {
      tell_object(me,HIR"你不小心一個失足, 跌落到山谷之中!!\n"NOR);
        me->move(where2);
    }
     else
    {
      tell_object(me,HIW"你沿著山壁爬上了龍脊峰!\n"NOR);
      me->move(where1);
    }
        return 1;
}



