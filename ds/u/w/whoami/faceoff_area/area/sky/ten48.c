#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"異界祭壇"NOR);
 set("long",@LONG
你跨入了光芒，終於看到了一個實體的東西，你的前方
是一座祭壇，四四方方的有如一具棺材，上面也有一個跟神
廟一樣的銅環，不一樣的是上面刻滿的看起來很有威力的銀
色咒文，你開始考慮要不要去碰(touch)它，銅環的旁邊是一
些頗為特異的雕花，你忽然發現一個實際的問題，你要怎麼
出去呢.....?
LONG
    );
set("item_desc",([
        "銅環" : HIG"不知道為什麼，這個銅環可以讓你感覺到一股很強的力量，讓你想碰(touch)它...\n"NOR,
      "雕花" : HIG"你發現雕花上有一個不太明顯的機關，看起來可以壓下(press)的樣子....\n"NOR,
]));

set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
        add_action("do_press","press");
      add_action("do_touch","touch");

}
int do_press(string arg)
{
        object me, p;
       string a;
        object room = environment(this_player());
        me = this_player();
            if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式： press <東西> .\n");
   if( a!="機關" )
                return notify_fail(" 這裡沒有這種東西!\n");
        if(room->query("take_leg") == 0)
        {
                message_vision(HIC"$N按下雕花上的機關，忽然一個事物掉到了$N的身上。\n"NOR  ,me);
                p=new(__DIR__"eq/uchimaha_gloves.c");
                p->move(this_player());
                room->set("take_leg",1);
        }
        else
        {
                tell_object(me,HIR"你發現機關壓不下去，大概是故障了吧....\n"NOR);
        }
        return 1;
}

int do_touch(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten44");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要碰觸什麼?\n");
        if( a!="銅環" )
                return notify_fail("有這種東西嗎?\n");
        message_vision(HIW"忽然一個裂口湧進了這個無光的空間，$N被吞噬進去了...!! \n"NOR,me);
          me->move(where1);
        return 1;
}



