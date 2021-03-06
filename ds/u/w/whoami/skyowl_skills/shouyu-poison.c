/*
毒術 - 獸羽毒經 (shouyu-poison) 

       被動技能 每 20 sk 為一個階段 每過一個階段 毒的威力就會提升 並且能夠使用新的毒傷
                
          奇異寒毒(cold-poison)      sk 20  持續性削減敵人 ap & mp & hp            (每次削減 sk*2) 
          奇異熱毒(hot-poison)       sk 40  削減敵人 max_hp & max_mp & max_ap      (固定扣 sk*10)     
          五線蠱毒(gu-poison)        sk 60  削減敵人 str & con & int & dex         (固定扣 sk/10) 
          三蜈五蟆煙(scotoad-poison) sk 80  削減敵人 攻擊力 & 防禦力 & 心靈抵抗力  (固定扣 sk/2) 
          化血腐骨毒(body-decayed)   sk 100 機率性削減敵人 merits                  (bar bio wit tec sou 擇一種扣一點) 
           
           持續時間由 tec 決定並且不斷施展會不停的累計 
           命中率由本身 skills 和對方 dodge & dex 決定 
           毒抗性太低 會被反噬 
*/

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("combat")!="shouyu-poison") return notify_fail("你並沒有使用『獸羽毒經』。\n");
        me->map_skill("combat");
        me->reset_action();
        message_vision(CYN "原先環繞在$N周遭的濃霧漸漸散開，起初詭異的感覺也消失的無影無蹤。\n" NOR,me);
        write("技能『獸羽毒經』已取消。\n");
        return 1;
    }
//    讓玩家指定自己想施放的毒術 
    if( me->query_skill_mapped("combat")=="shouyu-poison"){
        switch( arg ){
                case "cold-poison":
                     if( me->query_skill("shouyu-poison") < 19 ) return notify_fail("你對獸羽毒經的領悟還不夠深厚，尚未能夠施展奇異寒毒。\n"); 
                     msg += HIB "環繞著$N四周的濃霧，變成更詭異的深藍色了………\n" NOR;
                     if( me->query_skill("anti_poison") < 19 ) target->apply_condition(arg, 1+random(5));      
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "hot-poison":
                     if( me->query_skill("shouyu-poison") < 39 ) return notify_fail("你對獸羽毒經的領悟還不夠深厚，尚未能夠施展奇異熱毒。\n"); 
                     msg += RED "環繞著$N四周的濃霧，變成更詭異的深紅色了………\n" NOR;
                     if( me->query_skill("anti_poison") < 39 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "gu-poison":
                     if( me->query_skill("shouyu-poison") < 59 ) return notify_fail("你對獸羽毒經的領悟還不夠深厚，尚未能夠施展五線蠱毒。\n"); 
                     msg += MAG "環繞著$N四周的濃霧，變成更詭異的深紫色了………\n" NOR;
                     if( me->query_skill("anti_poison") < 59 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "scotoad-poison":
                     if( me->query_skill("shouyu-poison") < 79 ) return notify_fail("你對獸羽毒經的領悟還不夠深厚，尚未能夠施展三蜈五蟆煙。\n"); 
                     msg += BLK+GRN "環繞著$N四周的濃霧，變成更詭異的深綠色了………\n" NOR;
                     if( me->query_skill("anti_poison") < 79 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "body-decayed":
                     if( me->query_skill("shouyu-poison") < 99 ) return notify_fail("你對獸羽毒經的領悟還不夠深厚，尚未能夠施展化血腐骨毒。\n"); 
                     msg += HIW+BLK "環繞著$N四周的濃霧，變成更詭異的深黑色了………\n" NOR;
                     if( me->query_skill("anti_poison") < 99 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                     }
                message_vision(msg, me);
    }

    if(me->query("ap")<50 || me->query("hp")<50) return notify_fail("你的身體狀無法使用『獸羽毒經 』。\n");
    if(!me->skill_active( "shouyu-poison",(: call_other, __FILE__, "delay", me :), 4)) return notify_fail("你的獸羽毒經收招動作還沒完成。\n");

    me->map_skill("combat", "shouyu-poison"); 
    me->reset_action();

    message_vision(MAG "$N全身經脈逆行，獸羽毒經的效力在$N的四周漸漸擴散，$N周遭滿佈詭異的濃霧。\n" NOR,me);
    me->receive_damage("ap",15);
    me->receive_damage("hp",30);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    object target;
    string msg, arg = me->query_temp("shouyu-poison");
    int tec, sk, effect;
    if( !me ) return;
    if( me->query_skill_mapped("combat")!="shouyu-poison" ) return; 
    me->receive_damage("ap", 15); //不管有有沒有命中，都扣 ap 15 
    if( me->query("ap") < 50 )
    {
        me->map_skill("combat");
        me->reset_action();
        message_vision(CYN "原先環繞在$N周遭的濃霧漸漸散開，起初詭異的感覺也消失的無影無蹤。\n" NOR, me);
        tell_object(me, "你的體力不足無法繼續使用『獸羽毒經』。\n");
        return ;
    }
    if( me->is_fighting() ){
        if( !target ) target = offensive_target(me);
        tec = me->query_tec();
        sk = me->query_skill("shouyu-poison");
//shouyu-poison 的熟練度增加的同時 anti-poison 也會跟著提升熟練度 
        me -> improve_skill("shouyu-poison", 1+random(me->query_int()));
        me -> improve_skill("anti_poison", me->query_int()*2);
//發動的機率性
        if( random(me->query_tec()*4) < random(20) ) return;        
        msg += HIC "轉眼間環繞在$N四周的霧海朝$n傾洩而去，";
        if( (sk*2) > (random(target->query_dex()/2)+random(target->query_skill("dodge"))) ){
            msg += "$n一個恍神，就被霧海給活生生的吞了下去。\n" NOR;
            if( arg == "cold-poison" ) effect = tec*2;
            if( arg == "hot-poison" ) effect = tec*2;
            if( arg == "gu-poison" ) effect = tec;
            if( arg == "scotoad-poison" ) effect = tec/2;
            if( arg == "body-decayed" ) effect = tec/4;
            if( target->query_temp("shouyu-poison/"+arg+"/effect") < sk ) target->set_temp("shouyu-poison/"+arg+"/effect", sk); 
            effect += target->query_condition(arg);
            if( effect > 49 ) effect = 49; //最多49 tick 
            target->apply_condition(arg, effect);             
            target->receive_damage("hp", random(effect)+1); //一點點的毒傷 
        } else {
            msg += "$n輕輕一躍，閃過了這個要命的霧氣。\n" NOR; 
          }         
        message_vision(msg, me, target);
        }
        me->skill_active( "shouyu-poison",(: call_other, __FILE__, "delay", me :), 4);
}

int valid_learn(object me){ return 1; }
int practice_skill(object me){ return 1; }

int improve_limite(object me)
{
    if( !me->query("quest/shouyu-poison") ){ return 75; }
    else { return 100; }
}


