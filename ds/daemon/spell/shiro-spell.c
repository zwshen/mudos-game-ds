//Edit By Moon From -Firecloud-
//Shiro-spell
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int cast(object me, object target)
{
    int inn,sk,cost,mk,busy,i,damage,shield;
    if(!me) me=this_player();
    inn=me->query_int();
    mk=me->query_spell("shiro-spell");
    sk=mk/10+1;
    if(mk <10 ) cost =10; //保障新手
    if(mk <15 ) cost =15; //保障新手
    else cost=(mk*5+inn*3)/12;

    if(environment(me)->query("no_cast"))
        return notify_fail("這裡不能施法。\n");
    if( (int)me->query("mp") < cost )
        return notify_fail("你的法力不夠。\n");
    if ( !me->is_fighting() )
        return notify_fail("你並沒有在戰鬥中。\n");
    if ( !target )
        target = offensive_target(me);
    if ( !target )
        return notify_fail("你找不到可以施法的對像。\n");
    if ( target == me )
        return notify_fail("想死...打suicide就好了...你不覺得自己打自己很麻煩嗎？\n");
    if( !me->can_fight(target)) return me->can_fight(target);
    if( !me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");


    message_vision(HIW" $N運氣於掌且結手印，釀出"HIY"修羅印"HIW"：『"HIG"臨"HIR"•"HIG"兵"HIR"•"HIG"鬥"HIR"•"HIG"者"HIR"•"HIG"皆"HIR"•"HIG"陣"HIR"•"HIG"列"HIR"•"HIG"在"HIR"•"HIG"前"HIW"』\n"NOR,me);

    me->start_busy(2); //施法動作時間
    me->receive_damage("mp",cost); //施法扣MP
    me->set_temp("power_cast",1+mk/25);
call_out( (:delay,target,me:) , 2);
    return 1;
}
int delay(object target,object me)
{
    int inn,sp,damage,shield,lv;

    if(!me) return 0;
    if(!target) return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");

    me->delete_temp("power_cast");
    sp=me->query_spell("shiro-spell");
    inn=me->query_int();
    lv=me->query("level");
    shield=target->query_shield();

    damage = (sp*4+inn*2)/2;  //Max damage=300
    damage -= shield -random(shield/2);

    // 增加素質對傷害的影響
    damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
    message_vision(HIW"\t\t\n$N喃道：『孔•雀•明•王　岌滅敵』！！\n"
                   HIW"\t\t\n大片光芒由$N的背後綻放，雪白金鳳徐翔翱空•••\n"
                   HIW"\t\t\n九道"HIY"金光"HIW"疾出！！\n"
                   HIR"\t\t\n殺的$n措手不及\n"NOR,me,target);

    if( damage > 0 )
    {
        //              if( random(sp*3) > random(100) )   //Max 九成命中率
        if( random(sp*4)+sp/10 > random(100) )
        {
            target->receive_damage("hp", damage, me );

            message_vision(HIR"只見$N閃避不及，瞬間被九道"HIW"光芒"HIR"籠罩，發出淒凌的哀嚎！"NOR,target);

            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"( 傷害: "+damage+")"NOR);
            if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            if(wizardp(me) && me->query("env/debug"))
                tell_object(me,"(debug):  造成"+damage+"點傷害!!\n");
            COMBAT_D->report_status(target);         //顯示target狀態
            me->improve_spell("shiro-spell",random(inn)+1);
        }
        else
        {
            target->improve_skill("dodge", 1);
            me->improve_spell("shiro-spell", 1);
            message_vision(HIM"$N左閃右閃，閃過了那九道光芒\n"NOR,target);
        }
    }
    else {
        me->improve_spell("shiro-spell", 1);
        message_vision(HIM"$N不為所動，巧妙的化解數道光茫。\n"NOR,target);
    }

    if( !target->is_fighting(me) ) target->kill_ob(me);
    if( !me->is_fighting(target) ) me->kill_ob(target);

    return 1;
}


