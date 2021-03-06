#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void ccc(object me,object target,int z,int damage);
mapping *action = ({
([
        "action":"$N使出宗本式二刀流之"HIC"「二段突刺」"NOR"，使左手上的刀向$n疾速突刺，另一把也隨及而到 "NOR,
        "damage":    15,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "刺傷"
]),
([
        "action":"$N使出宗本式二刀流之"HIG"「十字突刺」"NOR"，將兩把刀交叉突刺向$n的心窩 "NOR,
        "damage": 22,
        "parry" : 5,
        "attact_type":  "wit",
        "damage_type":  "刺傷"
]),
([
        "action":"$N使出宗本式二刀流之"HIR"「疾速亂刺」"NOR"，雙手拿著$w不斷的向$n疾速亂刺"NOR,
        "damage": 24,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "刺傷"
]),
([
        "action":"$N使出宗本式二刀流之"HIR"「上顏迅刺」"NOR"，一刀插地，一刀瞬間以下朝上刺向$N面部"NOR,
        "damage": 25,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "面部刺傷"
]),
([
        "action":"$N使出宗本式二刀流之精義"HIM"「飛燕翔空斬」"NOR"，身輕如飛燕翔空，又如疾風般斬向$n"NOR,
        "damage": 40,
        "dodge" : 20,
        "attact_type":  "bar",
        "damage_type":  "斬傷"
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
        if (!weapon) return notify_fail("「宗本式二刀流」得要有刀才可施展。\n");
        if(weapon->query("skill_type")!="blade") return notify_fail(HIC"宗本式二刀流"NOR"乃需有刀才能施展。\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="left-blade")
                return notify_fail("你沒有施展"HIM"「宗本式二刀流」"NOR"。\n");
                me->map_skill("blade");
                me->reset_action();
                write("你將「宗本式二刀流」之劍氣散去。\n");
                return 1;
        }
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("你的身體狀況無法施展"HIC"「宗本式二刀流」"NOR"。\n");
        //第二次exert
        if(me->query_skill_mapped("blade")=="left-blade")
        {
        if( me->is_ghost() ) return notify_fail("你已是鬼魂無法施展武功\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("你已在運行「宗本式二刀流」了。\n");
                if (me->query_skill("left-blade") < 50)
                return notify_fail("你到目前為止還無法領會到"HIC"宗本式二刀流"NOR"之奧義。\n");
                if(me->query("ap")<50) 
                return notify_fail("你目前的內勁不足，無法使用奧義。\n");
                if(!me->can_fight(target)) return me->can_fight(target);
                if(!me->is_fighting(target) ) return notify_fail("你並無在戰鬥中\n");
                message_vision(HIR"$N突然將手中之刀反手交叉，做好架勢，氣燄逼人...\n\n"NOR,me,target);
                me->receive_damage("ap",15+random(32));
                me->start_busy(1+random(2));
                call_out("ccc",1,me,target,1,damage);
                return 1;
        }
        if(!me->skill_active( "left-blade",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("你「暗影迅切流」的動作還沒完成。\n");
        me->map_skill("blade", "left-blade");
        me->reset_action();
        message_vision(HIG"$N將雙刀交叉揮舞,在天空畫了個圓,施展出"HIC"宗本式二刀流"HIG"...。\n"NOR,me);
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
       z=me->query_skill("left-blade");
       msg = HIC"\n$N突然兩腳一瞪，使出"HIR"【奧義】"HIY"【狂烈天左十六斬】!!!\n"NOR;
       msg +=HIC"\n突然一陣刀光劍影...劍氣之聲響如悍天!!\n"NOR;
       target->start_busy(2);
       message_vision(msg, me, target);
       if( z >= random(target->query_skill("dodge")) )
       {
        message_vision(HIR"\n\n$n在這一剎那挨了幾刀數也數不清..頓時刀傷累累.." NOR,me,target); 
       damage = me->query_skill("left-blade")+random(me->query("str")*2) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
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
          message_vision(HIG"\n\n$n見形勢不對，及刻跳開，但還是被挨了幾刀。" NOR,me,target);   
       damage = me->query_skill("left-blade")*1/2+random(me->query("str")) +random(target->query("str"))-target->query_armor()/5 - random(target->query_armor()/5);
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

        if( me->query_skill_mapped("blade")!="left-blade" )
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
        me->skill_active( "left-blade",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{return action[random(sizeof(action))];}
int practice_skill(object me) { return 1; }
