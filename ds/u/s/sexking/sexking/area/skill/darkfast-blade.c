#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void ccc(object me,object target,int z,int damage);
mapping *action = ({
([
        "action":"$N對$n使出"HIM"「暗影三式--衝切閃」"NOR"，以極快之速如光閃般晃過$n眼前 "NOR,
        "damage":    15,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "斬傷"
]),
([
        "action":"$N對$n使出"HIM"「暗影三式--翔切閃」"NOR"，以極快之速如光閃般晃過$n眼前 "NOR,
        "damage": 22,
        "parry" : 5,
        "attact_type":  "wit",
        "damage_type":  "斬傷"
]),
([
        "action":"$N對$n使出"HIM"「暗影三式--迫切閃」"NOR"，以極快之速如光閃般晃過$n眼前"NOR,
        "damage": 21,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "穿傷"
]),
([
        "action":"$N使出"HIM"「暗影秘式--突擊牙閃」"NOR"，毫無贅招的直逼$n "NOR,
        "damage": 21,
        "dodge" : 10,
        "attact_type":  "bar",
        "damage_type":  "刺傷"
]),
([
        "action":"$N使出"HIM"「暗影怒式--風車崩」"NOR"，身形百變，刀光劍影不段招呼在$n身上"NOR,
        "damage": 21,
        "dodge" : 20,
        "attact_type":  "bar",
        "damage_type":  "削傷"
]),
([
        "action":"$N使出"HIM"「暗影外式--神鬼迅切開」"NOR"，劍氣發出轟的一聲巨響逼進$n"NOR,
        "damage": 45,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "巨大傷口"
]),
});
int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("sea-blade");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("鬼殺人...?\n");
        if (!weapon) return notify_fail("「暗影迅切流」得要有刀才可施展。\n");
        if(weapon->query("skill_type")!="blade") return notify_fail(HIM"暗影迅切流"NOR"乃需有刀才能施展。\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="darkfast-blade")
                return notify_fail("你沒有施展"HIM"「暗影迅切流」"NOR"。\n");
                me->map_skill("blade");
                me->reset_action();
                write("你將「暗影迅切流」之劍氣散去。\n");
                return 1;
        }
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("你的身體狀況無法施展"HIM"「暗影迅切流」"NOR"。\n");
        //第二次exert
        if(me->query_skill_mapped("blade")=="darkfast-blade")
        {
        if( me->is_ghost() ) return notify_fail("你已是鬼魂無法施展武功\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("你已在運行「暗影迅切流」了。\n");
                if (me->query_skill("darkfast-blade") < 60)
                return notify_fail("你到目前為止還無法領會到"HIM"暗影迅切流"NOR"之奧義。\n");
                if(me->query("ap")<50) 
                return notify_fail("你目前的內勁不足，無法使用奧義。\n");
                if(!me->can_fight(target)) return me->can_fight(target);
                if(!me->is_fighting(target) ) return notify_fail("你並無在戰鬥中\n");
                message_vision(HIR"不知怎麼著?$n的胸口突然冒出了一道血窟窿,鮮紅的血不斷的湧出來....\n\n"NOR,me,target);
                me->receive_damage("ap",15+random(32));
                me->start_busy(1+random(2));
                call_out("ccc",1,me,target,1,damage);
                return 1;
        }
        if(!me->skill_active( "darkfast-blade",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("你「暗影迅切流」的動作還沒完成。\n");
        me->map_skill("blade", "darkfast-blade");
        me->reset_action();
        message_vision(HIC"$N緊按手中之刀柄，兩腳紮出準備施展"HIM"「暗影迅切流」"HIC"之架式。\n"NOR,me);
        me->receive_damage("ap",15);
        me->start_busy(2);
        return 1;
}
void ccc(object me,object target,int z,int damage)
{
       string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       z=me->query_skill("darkfast-blade");
       msg = HIG"$N低聲說道:"HIM"「暗影迅切流」"HIC"<---瞬---劍--->......."NOR;
       msg +=HIC"\n\n<---瞬---劍--->"HIY"瞬劍之快連肉眼都無法瞧見,$n挨了這擊著實不輕"NOR;
       target->start_busy(2);
       message_vision(msg, me, target);
       if( z >= random(target->query_skill("dodge")) )
       {
       message_vision(HIR"\n\n$n跪倒在地...血流不止!!!\n" NOR,me,target);   
       damage = me->query_skill("darkfast-blade")+random(me->query("str")*2) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
      
       }
       else {
      message_vision(HIG"\n\n但$n已預感不對，向後跳躍大幅降低了"HIC"<---瞬---劍--->"HIG"之威力。\n" NOR,me,target);   
                damage = me->query_skill("darkfast-blade")+random(me->query("str")) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
     
       }
if(!me->is_fighting(target)) me->kill_ob(target);   
}
void delay(object me)
{
        object weapon;
        if( !me ) return;
        
        weapon=me->query_temp( "weapon" );

        if( !weapon || weapon->query("skill_type") != "blade" )
        {

                me->map_skill("blade");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("blade")!="darkfast-blade" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {
                me->map_skill("blade");
                me->reset_action();
                message_vision(NOR"\n$N吐了幾口鮮血，看樣子已內勁全無。\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "darkfast-blade",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{return action[random(sizeof(action))];}
int practice_skill(object me) { return 1; }

