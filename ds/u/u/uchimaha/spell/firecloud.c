#include <ansi.h>
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
        if(mk <25 ) cost =6; //保障新手
        if(mk >25 ) cost =3; //保障新手
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


        message_vision("$N口中喃喃唸道:"HIY"「"HIR"火燄之神海菲斯特"NOR"啊, 我向你祈求, 將你所掌控的火燄之力賜與給我吧, 請您讓來自地獄的"HIR"火雲"HIY"吞噬任何意圖阻饒我的人吧!!"HIY"」\n"NOR);

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
        message_vision("\n一道強大火燄自$N雙手間併射而出, 以萬馬奔騰之勢向$n襲捲而來！！"NOR,me,target);

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
                        message_vision(GRN"  $N就地一個打滾，狼狽萬狀的躲開了火雲術的襲捲。\n"NOR);
                }
        }
        else {
                me->improve_spell("elemental-firecloud", 1);
                message_vision(GRN"  $N捲入了炙熱的火雲之中, 但似乎連$N的一根毛都動不到。\n"NOR);
        }

        if( !target->is_fighting(me) ) target->kill_ob(me);
        if( !me->is_fighting(target) ) me->kill_ob(target);


        return 1;
}
