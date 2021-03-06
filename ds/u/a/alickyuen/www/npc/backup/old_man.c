#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name(HIW+BLK"倒吊的老人"NOR, ({ "oldman","man" }) ); 
    set("long","詭異的老人\n"NOR);
    set("level",1);
    set("age",500);
    set("gender", "男性"); 
    set("race", "human");        
    set("no_fight",1);
    setup(); 
    this_object()->set_temp("define_look"," 懸吊在此");
}

void init()
{       
    object me;
    ::init();
    if( interactive(me = this_player()) && !is_fighting() )
    {
       remove_call_out("meeting");
       call_out("meeting",6,me);
    }
}

void meeting(object me)
{
    object mob;
    mob = this_object();

    if(!me || environment(me) != environment()) return;
    if(!me->query("level") <30)
    {
       message_vision("\t$N說：這位"+RANK_D->query_respect(me)+"，這裡是通往異度空間的入口。\n",mob);
       message_vision("\t$N說：我告訴你，進入後可是無法再回頭的阿！\n"NOR,mob);
       message_vision("\t$N說：你是否要進入此處？ ["HIY"say 進入 / 離開"NOR"]\n"NOR,mob);
    }
    else
    { 
       message_vision("$N對著$n說：你沒有資格進去裡面。\n",mob,me);
    }
//    call_out("leave",100,mob);
    return;
}

void relay_say(object me, string str)
{
    object mob;
    mob = this_object();

    if( !userp(me) ) return;
    if( me->is_busy() ) return write("你正在忙。\n");
    if( strsrch(str,"進入") != -1 )
    {
       if(me->query("level") <25)
       {
          message_vision("$N說：我不能讓您白白去送死...還是請回吧。\n",mob);
          return;
       }
       me->start_busy(4);
       mob->set("info",1);
       call_out("msg",1,me,mob);
       return;
    }

    if( strsrch(str,"離開") != -1 )
    {
       message_vision("$N說：這樣子呀...那等你準備好了再來吧。\n",mob);
       message_vision(HIR"[一股力量將你推往井口。]\n"NOR,me);
       me->start_busy(3);
       me->move("/u/f/fedex/room3");
       return;
    }
    return;
}

int msg(object me)
{
    int i;
    object mob;
    mob = this_object();
    i = mob->query("info");
    switch(i)
    {
       case 1:
            message_vision("\t$N說：看樣子你已經準備好了。\n\n",mob);
            mob->set("info",i+1);
            call_out("msg",2,me);
            break;
       case 2:
            message_vision("\t只見$N嘴裡唸唸有辭，渾身散發綠色的光芒。\n\n",mob);
            mob->set("info",i+1);
            call_out("msg",3,me);
            break;
       case 3:
            message_vision(HIG"數道光芒瞬間將$N包圍。\n"NOR,me);
            me->move(__DIR__"../room2");
            tell_room(__DIR__"../room2",HIG"數道光芒閃過過，"+me->query("name")+"出現在這裡。\n"NOR);
            mob->delete("info");
            destruct(mob);
            break;
    }
    return 1;
}
/*
void leave(object mob)
{
    message_vision("$N突然消失在你的眼前。\n",mob);
    destruct(mob);
    return;
}
*/
