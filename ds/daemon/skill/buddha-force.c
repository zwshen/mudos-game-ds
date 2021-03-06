//凌雲寺：無上梵功(buddha-force)
// 日期: 1999.12.11  By DS-Acme
// update : 2000.6.4 By -Acme-
// update : 2006/10/06 Tmr

#include <ansi.h>
#define HEALER_MAX 20 //被恢復之人,加權值上限

inherit SKILL;

void armor(object me,int effect);
void delay(object me);

int exert(object me,object target, string arg)
{
    int force,buddha,heal,addexp;

    force=me->query_skill("force",2);
    buddha=me->query_skill("buddha-force",2);
    heal = (force + buddha)/2;

    if(arg=="off")
    {
        if(me->query_skill_mapped("force")=="buddha-force")
        {
            message_vision("$N站起身來，停止了修行無上梵功\。\n",me);
            me->delete_temp("is_busy/buddha");
            me->map_skill("force");
            return 1;
        } 
        return notify_fail("你並沒有在修行無上梵功\。\n");
    }

    if(!arg)
    {
        if( me->query_skill_mapped("force")=="buddha-force" )
            return notify_fail("你已正在修行無上梵功\了。\n");
        if(me->query("hp") < 10 || me->query("ap") < 10 )
            return notify_fail("你目前的身體狀況不好，無法修行無上梵功\。\n");
        if(me->is_fighting() )
            return notify_fail("你正忙著打架，沒空修行無上梵功\。\n");
        if( sizeof(me->query_temp("is_busy")) )
            return notify_fail("你現在正在忙。\n");
        return 1;
    }

    //轉AP化HP
    if(arg=="heal" )
    {
        if( me->query_skill_mapped("force")=="buddha-force" )
            return notify_fail("你正在修行無上梵功\。\n");
        if( sizeof(me->query_temp("is_busy")) )
            return notify_fail("你現在正在忙。\n");
        if(me->query("mp") < heal*10/25 )
            return notify_fail("你的魔力不足，無法使用療傷功\能。\n");
        if(me->query("hp") >= me->query("max_hp"))
            return notify_fail("你現在並沒有受傷哦。\n");

        message_vision("$N雙手合什，運氣吐納，身上傷口慢慢恢復。\n",me);
        me->receive_damage("mp",heal*10/25);

        if (me->is_fighting() )
                me->receive_heal("hp",heal);
        else
                me->receive_heal("hp",heal+heal/2);

        me->start_busy(1);
        me->improve_skill("buddha-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
    }

    if(arg=="armor")
    {
        if( me->query_skill_mapped("force")=="buddha-force" )
            return notify_fail("你正在修行無上梵功\。\n");
        if (buddha< 20 )
            return notify_fail("你的無上梵功\不夠熟練，無法施展「無上金身」。 \n");
        if(me->query("ap") < heal*3/2 )
            return notify_fail("你目前的狀態無法施展「無上金身」。\n");
        if(me->query_temp("buddha/armor")==1)
            return notify_fail("你已經在施展「無上金身」了。\n");

        me->improve_skill("buddha-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        me->receive_damage("ap",heal*3/2);
        me->set_temp("buddha/armor",1);
        me->start_busy(2);
        if( me->query_skill("buddha-skill") > 50) {
              message_vision( HIG"$N嘴裡唸著佛號，你的耳旁彷佛響起悅耳的天籟，$N"HIG"施展出"HIY"「如來金身」"HIG"了！！\n"NOR,me);


            me->add_temp("apply/armor", heal + me->query_skill("buddha-skill")/3 );
                        me->skill_active( "buddha_force",(: call_other, __FILE__, "armor", me, heal + me->query_skill("buddha-skill")/3 :), 500);
        } else {
            message_vision("$N雙手合什，嘴裡唸著佛號，四週氣流狂旋，使出"HIW"「無上金身」"NOR"。\n",me);
            me->add_temp("apply/armor", heal/2);
            me->skill_active( "buddha_force",(: call_other, __FILE__, "armor", me,heal/2:), 500);
        }

        return 1;
    }


    //助人療傷
    if(!me->is_fighting())
    {
        if(!target)
            return notify_fail("無上梵功\無此功\能，請輸入 help buddha-force 進一步得到資訊。\n");
        if(target==me)
            return notify_fail("你只能幫別人療傷，若要自行療傷請用heal。\n");
        if( sizeof(me->query_temp("is_busy")) )
            return notify_fail("你現在正在忙，無法使用療傷功\能哦。\n");
        if(me->query_skill("buddha-force") < 20 )
            return notify_fail("以你無上梵功\的造詣，是無法幫別人療傷的。\n");

        heal += me->query_sou()*250;
        if(me->query("mp") < heal/5 )
            return notify_fail("你的魔力不足，無法幫別人療傷。\n");
        if(!userp(target))
            return notify_fail("你只能對玩家使用療傷功\能哦。\n");

        message_vision(HIW "$N運氣於雙掌，拍打$n" +HIW "胸口數下，只見$n吐出了幾口黑血。\n" NOR,me,target);

        addexp = 1 + random(me->query_int()) + me->query_sou()*100;
        if(me->query("evil") < 500 )
                {
            me->add("exp", addexp);
            write("你獲得了 "+(string)addexp+" 點經驗值。\n");
        }

        target->receive_heal("hp", heal);
        me->receive_damage("mp", heal/5);
        me->improve_skill("buddha-force",force+random(me->query_int()+me->query_int()/2));
        me->improve_skill("force",me->query("level")*2+random(me->query_int()+me->query_int()/2) );
        me->start_busy(2);
        return 1;
    } else return notify_fail("你現在正在忙著戰鬥。\n");

    return notify_fail("無上梵功\無此功\能，請輸入 help buddha-force 進一步得到資訊。\n");
}

void armor(object me,int effect)
{
    if(!me) return;
    if(!me->query_temp("buddha/armor") ) return;
    message_vision(HIG "$N的四週氣流突然停止，$N的無上金身散功\了。\n"NOR,me);
    me->add_temp("apply/armor",-effect);
    me->delete_temp("buddha/armor");
    return;
}

void delay(object me)
{
    if ( !me
            ||   !me->query_temp("is_busy/buddha")
            ||    me->query_skill_mapped("force")!="buddha-force"
            ||    me->is_fighting() )
    {
        me->map_skill("buddha-force");
        return;
    }

    if(me->query("hp") < 10 || me->query("ap") < 10 )
    {
        message_vision("$N站起身來，停止了修行無上梵功\。\n",me);
        me->delete_temp("is_busy/buddha");
        me->map_skill("force");
        return;
    }
        me->improve_skill("buddha-force",me->query_int()/3+random(6)+3);
        me->improve_skill("force",me->query_int()/3+random(6)+5);
/*
    if (!me->query("linwin/forceok")
            &&   me->query_skill("buddha-force",1)==85
            &&   me->query("evil") <= -1000 )
    {
        tell_object(me,HIW "經過長年的修行，你的無上梵功\更上一層了！\n" NOR );
        tell_object(me,HIY "你的力量、體質、智慧和敏捷提高了！\n" NOR );
        me->add("addition/str", 1);
        me->add("addition/con", 1);
        me->add("addition/int", 1);
        me->add("addition/dex", 1);
        me->set("linwin/forceok",1);
    }
    else {
        me->improve_skill("buddha-force",me->query_int()/3+random(6)+3);
        me->improve_skill("force",me->query_int()/3+random(6)+5);
    }
*/

    me->receive_damage("hp",6);
    me->receive_damage("ap",6);

me->skill_active( "buddha-force",(: call_other, __FILE__, "delay", me:), 3);

    return;
}

int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
    return 1;
}

void skill_improved(object me)
{
    int b,c;
    b = me->query_skill("buddha-force",1);
    c = me->query("skill/buddha-force");

    if( b % 20==19 && b > c)
    {
        if(random(2))
        {
            tell_object(me,HIY "你的智慧提高了！\n" NOR );
            me->add("addition/int", 1);
        }
        else
        {
            tell_object(me,HIY "你的力量提高了！\n" NOR );
            me->add("addition/str", 1);
        }

        me->set("skill/buddha-force",b);
    }
    me->save();
    return;
}

