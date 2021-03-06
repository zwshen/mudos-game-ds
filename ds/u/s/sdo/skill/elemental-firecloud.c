#include <ansi2.h>
inherit SSERVER;
inherit SKILL;

int delay(object target,object me);
int delay2(object target,object me,int damage);

int cast(object me, object target)
{
        int inn,sk,cost,mk,busy,i,damage,shield;
        if(!me) me=this_player();
        inn=me->query_int();
        mk=me->query_spell("elemental-firecloud");
        sk=mk/10+1;
        if(mk <25 ) cost =3; //保障新手
        if(mk <40 && mk >= 25) cost =6; //保障新手
        else{
        cost=(mk+inn)/5;}
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
              return notify_fail("想死...打suicide就好了...你不覺得自己打自己很麻煩嗎?\n");
        if( !me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");


        message_vision(
        HIY"$N"HIY"口中喃喃唸道：「"HIR"火焰精靈沙羅曼蛇"HIY"啊，履行遠古契約的時候到了！\n"
        HIY"讓來自地獄的"HIR"火雲"HIY"吞噬阻撓我的敵人吧!!"HIY"」\n"NOR,me);

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
        if(!target) return notify_fail("你要打的人勞跑了...\n");      
        if( environment(me) != environment(target) )       
                return notify_fail("目標離開了你的施法範圍。\n");

        me->delete_temp("power_cast");
        sp=me->query_spell("elemental-firecloud");
        inn=me->query_int();    
        lv=me->query("level");
        shield=target->query_shield();

        damage = (sp*4+inn*1)/2;  //Max damage=120
        damage -= shield -random(shield/2);

        // 增加素質對傷害的影響
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
        message_vision("\n一道強大火燄自$N了手間併射而出, 瞬間吞沒了$n！！"NOR,me,target);

        if( damage > 0 )
        {
//              if( random(sp*3) > random(100) )   //Max 九成命中率
                if( random(sp*4)+sp/10 > random(100) )   
                {
                        target->receive_damage("hp", damage, me ); 

                        message_vision("  "HIW"只見$N閃避不及, 瞬間被捲入"HIR"火雲"HIW"之中, 在熊熊大火中發出淒凌的哀嚎！"NOR,target);
                        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                tell_object(me,HIY"( 傷害: "+damage+")"NOR);
                        if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                                tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                        message_vision("\n",target);
                        if(wizardp(me) && me->query("env/debug")) 
                                tell_object(me,"(debug):  造成"+damage+"點炙熱的灼傷!!\n"); 
                        COMBAT_D->report_status(target);         //顯示target狀態
                        me->improve_spell("god-fire",random(inn)+1);
                }
                else
                {
                        target->improve_skill("dodge", 1);
                        me->improve_spell("elemental-firecloud", 1);
                        message_vision(GRN"  $N就地一個打滾，狼狽萬狀的躲開了火雲術的襲捲。\n"NOR,target);
                }
        }
        else {
                me->improve_spell("elemental-firecloud", 1);
                message_vision(GRN"  $N站在炙熱的火雲之中, 但是他週身的魔法力量將火焰隔絕在外。\n"NOR,target);
        }
        if( !target->is_fighting(me) ) target->kill_ob(me);
        if( !me->is_fighting(target) ) me->kill_ob(target);

        // 續攻
        if( me->query_spell("elemental-firecloud") > 79 && inn > random(120) )
        {
                call_out((:delay2,target,me,damage:),2+random(3) );
                me->start_busy(1);
        }
        return 1;
}

int delay2(object target,object me,int damage)
{
        int sp;
        if(!me) return 1;
        sp=me->query_spell("elemental-firecloud");
        if( !me || !target) return 1;
        if( environment(me) != environment(target) ) return 1;

        message_vision(HIR"忽然$N"HIR"的魔力誘發了快要熄滅的火雲，讓火雲忽然再度在$n"HIR"身邊炸裂開來！"NOR,me,target);

        if(me->query_int() > target->query_int() )
                damage-=target->query_shield()/4; //減弱續攻威力
        else    
                damage-=target->query_shield()/3;   //減弱續攻威力


        if( damage<0 )
        {
                message_vision(GRN"  $N"GRN"身邊炸裂開來的火雲，似乎沒有對$N"GRN"造成絲毫的傷害。\n"NOR,target);
                return 1;
        }

        if( random(sp*2) > random(100) ) {
                message_vision(HIC"  $N"HIC"被強大的力量所攝，忘了閃避，被火雲燒傷了！"NOR,target);
                target->receive_damage("hp",damage,me);  
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"("+damage+")"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                message_vision("\n",target);
                if(wizardp(me) && me->query("env/debug")) 
                        tell_object(me,"  造成"+damage+"點傷害!!\n"); 
                COMBAT_D->report_status(target);         //顯示target狀態
        }
        else message_vision(GRN"\n  只見$N"GRN"一個閃身，離開了火雲的燃燒範圍。\n"NOR,target);

        me->improve_spell("elemental-firecloud",random( me->query_int()/2 ));
        return 1;
}
