#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIR"小麥草無上心法v1.01(正式版)"NOR,({ "sexking book","book" }) );
  set("long",HIG"一本超強的變態心法..裡面藏著sexking花費數十年所創的絕世武功\\n"HIR"內含的絕世武功\有:\n"HIC"無敵變態搔癢功\(scr) 某人\n"HIY"抓狂放屁(pupu) 某人\n"HIG"最終奧義->"HIM"變態大集合(and) 某人。"NOR);
  set("unit","本"); 
  setup();
}
void init()
{
 add_action("do_scratch","scr");
 add_action("do_pupu","pupu");
 add_action("do_and","and");
}
int do_scratch(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("你想要搔誰的癢 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("這裡沒有這個人。\n");
        if( me->is_busy() )
        return notify_fail("你還在忙,不能搔人癢..\n");
        if(obj==me)
        return notify_fail("你的手太短不能搔自己癢\n");
        message_vision(HIW"\n$N蹦蹦跳跳的跳到$n的背後:陰險的說道:對著$n說:嘿嘿!今天你已經逃不過我的魔掌了...\n\n"NOR,me,obj);
        me->start_busy(5);
        call_out("no",5,me,obj);
        call_out("no2",8,me,obj);
        call_out("no3",9,me,obj);
        call_out("no4",14,me,obj);
        return 1;
}
int do_pupu(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("你想要對誰放出你又香又甜的屁﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("這裡沒有這個人。\n");
        if( me->is_busy() )
        return notify_fail("你還在忙,不能放屁.\n");
        if(obj==me)
        return notify_fail("你的屁並不會臭死自己\n");
        message_vision(HIY"\n$N嘿嘿嘿的笑了幾聲..接著慢慢的把褲子脫了下來....\n\n"NOR,me,obj);
        me->start_busy(5);
        call_out("pupu1",5,me,obj);
        call_out("pupu2",8,me,obj);
        call_out("pupu3",13,me,obj);
        return 1;
}
int do_and(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("你想要結束誰的生命﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("這裡沒有這個人。\n");
        if( me->is_busy() )
        return notify_fail("你還在忙ㄛ...\n");
        if(obj==me)
        return notify_fail("如果你死了..sexking就後繼無人了..\n");
        message_vision(HIM"\n$N突然拿起了化妝盒..拿起口紅在嘴上抹來抹..還上了一堆粉\n\n"NOR,me,obj);
        me->start_busy(5);
        call_out("and1",5,me,obj);
        call_out("and2",8,me,obj);
        return 1;
}
void no(object me,object obj)
{
     if(!me) return;
     message_vision(HIR"接著$N伸出淫賤的手..伸到$n的掖下瘋狂的搔癢..。\n"NOR,me,obj);
     return;
}
void no2(object me,object obj)
{
     message_vision(HIY"$N越搔越起勁..而$n卻已經翻起了白眼.口吐白沫..。\n"NOR,me,obj);
     return;
}
void no3(object me,object obj)
{
     message_vision(HIG"$n漸漸的軟趴趴的跪了下來,尿了滿地都是..尿失禁了..好豬ㄛ。\n"NOR,me,obj);
     return;
}
void no4(object me,object obj)
{
     message_vision(HIC"面對如此豐碩的成果..$N不禁淫笑了起來..呵呵呵呵。\n"NOR,me,obj);
     obj->set_temp("temp/death_type",HIC"[笑到死]"NOR);
     obj->die();
     return;
}
void pupu1(object me,object obj)
{
     message_vision(HIG"沒多久..$N已經將光溜溜的屁屁給露了出來.....\n"NOR,me,obj);
     return;
}
void pupu2(object me,object obj)
{
     message_vision(HIR"突然一聲巨響:ㄆㄨㄆㄨㄆㄨ..$n一個不小心..中了這招....\n"NOR,me,obj);
     return;
}
void pupu3(object me,object obj)
{
     message_vision(WHT"漸漸的$n感到體力透支..腦海閃過一道陰影..倒地不起了..\n"NOR,me,obj);
     obj->set_temp("temp/death_type",HIY"[被臭死的]"NOR);
     obj->die();
     return;
}
void and1(object me,object obj)
{
     message_vision(HIR"$N突然亂不ㄜ心的轉過頭來:對著$n說:小寶貝!我來囉...\n"NOR,me,obj);
     return;
}
void and2(object me,object obj)
{
   if(random(3))
{
  message_vision(HIY"$N猛力衝向$n..$n機靈的一個閃身,躲開了$N這個ㄜ心的人。\n"NOR,me,obj);
  call_out("miss",3,me,obj);
}
  else    
{
  message_vision(HIG"$N猛力衝向$n..將$n抱的緊緊的..並且不斷的在$n身上"HIM"種草莓...\n"NOR,me,obj);
  call_out("and3",5,me,obj);
}
return ;
}
void and3(object me,object obj)
{
     message_vision(WHT"$n因受不了這種ㄜ心變態的刺激..終於咬舌自盡.結束了自己的生命\n"NOR,me,obj);
     obj->set_temp("temp/death_type",HIG"[被ㄜ心到死]"NOR);
     obj->die();
     return;
}
void miss(object me,object obj)
{
     message_vision(HIR"$N失去了重心..一直往前衝..踩到了香蕉皮摔了個倒頭栽..倒在地上一動也不動了..\n"NOR,me,obj);
     me->set_temp("temp/death_type",HIM"[摔死的]"NOR);
     me->die();
     return;
}
int query_autoload() { return 1; }
