#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
        ([
        "action": "$N一揮手中的劍，瘋魔劍訣第一招『"HIR"群魔亂舞"NOR"』\n劍化成數點白光向$n的身體

刺去",
        "damage": 50,
        "dodge" : 140,
        "attact_type":  "bar", 
        "damage_type":  "刺傷",
        ]),                                                            
        ([
        "action": "$N使出瘋魔劍訣第二招『"HIW"道消魔長"NOR"』，左手反轉一招，\n右手立刻趁$n不注意

之際砍向$n的頭部",
        "damage":                80,
        "dodge" :                100,
        "parry" :               20,
        "attact_type":  "bar",
        "damage_type":  "砍傷",
        ]),

        ([
        "action": "$N一個馬步揮出瘋魔劍訣第三招『"HIB"妖魔橫行"NOR"』，\n  手中的劍忽然消失向$n的

背後殺去",
        "damage":                100,
        "dodge" :                150,
        "parry" :                -40,
        "attact_type":  "bar",
        "damage_type":  "劍傷",
        ]),

        ([
        "action": "$N昂天一飛，瘋魔劍訣第四招『"HIG"天魔極樂"NOR"』，\n全身內力集中在劍中，向$n的

雙手攻去",
        "damage":                160,
        "dodge" :                -30,
        "parry" :                -5,
        "attact_type":  "bar",
        "damage_type":  "內傷",
        ]),
});

int exert(object me, object target, string arg)
{
        int a,c,i,j,k,damage,sk,lvtest,pcost,basicd;
        string msg;
        object weapon, wp;
        mapping type;
    
        weapon=me->query_temp("weapon");
        if( !weapon || weapon->query("skill_type")!="sword")
        // change by alick
                 return notify_fail("瘋魔劍訣沒有劍，使不出來？\n");
        if(arg=="off" )
        {
        if( me->query_skill_mapped("sword")!="masen_sword")
            return notify_fail("你並沒有使用「瘋魔劍訣」。\n");
        me->map_skill("sword");
        me->reset_action();
        write("劍訣「瘋魔劍」已取消。\n");
        return 1;
        }

        if(me->query_skill("sword")< 10) 
                return notify_fail("你的劍類武器知識不足以使用「瘋魔鞭」。\n");
        if(me->query("ap")<30 || me->query("hp")<100) 
                return notify_fail("你的身體狀況無法使用瘋魔劍訣。\n");

        //第二次exert
        if(me->query_skill_mapped("sword")=="masen_sword")
        {
        if( !target ) target = offensive_target(me);
        if(!target)   return notify_fail("你已經在使用「瘋魔劍訣」了。\n");
       
        //攻擊性的要特別注意要加下面兩行.
if( !weapon || weapon->query("skill_type")!="sword") return notify_fail("你用天外飛仙不用劍歐？

\n");
        if(!me->can_fight(target)) return 0;
        if( !me->is_fighting(target) ) return notify_fail("你並沒有跟"+target->query("name")+"戰

鬥中。\n");
    if(target->is_corpse()) return notify_fail("看清楚，對方己經死了。\n");
        sk=me->query_skill("masen_sword");
    if(sk < 80) return notify_fail("憑你現在的功\力，還無法領會這招的真諦。\n");
    if(me->query_skill("sword") < 70) return notify_fail("你的劍類知識，尚未擎至如此的絕對功\力。

\n");
    if(me->query_skill("force") <40) return notify_fail("你的內力，無法支援住如此強大的攻擊之所需

。\n");
    if(me->query_temp("masen") > 0) return notify_fail("你無法再短時間內放出第二次的絕招。\n");
        damage = 300 + random(sk + me->query_damage());
message_vision(HIR"\n$N一飛沖天，施展出超強絕技，傳說中瘋魔劍訣必殺技【天外飛仙】！\n"NOR,me);
message_vision(HIR"飛天向$N擊出第壹擊『"HIR"群魔亂舞"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"轉身向$N擊出第貳擊『"HIW"道消魔長"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"往前向$N擊出第參擊『"HIB"妖魔橫行"NOR"』，造成$N身體一處劍傷！\n"NOR,target);  
message_vision(HIR"連續向$N擊出第肆擊『"HIG"天魔極樂"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"飛天向$N擊出第壹擊『"HIR"群魔亂舞"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"轉身向$N擊出第貳擊『"HIW"道消魔長"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"往前向$N擊出第參擊『"HIB"妖魔橫行"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"連續向$N擊出第肆擊『"HIG"天魔極樂"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"飛天向$N擊出第壹擊『"HIR"群魔亂舞"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"轉身向$N擊出第貳擊『"HIW"道消魔長"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"往前向$N擊出第參擊『"HIB"妖魔橫行"NOR"』，造成$N身體一處劍傷！\n"NOR,target);  
message_vision(HIR"連續向$N擊出第肆擊『"HIG"天魔極樂"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"飛天向$N擊出第壹擊『"HIR"群魔亂舞"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"轉身向$N擊出第貳擊『"HIW"道消魔長"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"往前向$N擊出第參擊『"HIB"妖魔橫行"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"連續向$N擊出第肆擊『"HIG"天魔極樂"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"飛天向$N擊出第壹擊『"HIR"群魔亂舞"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"轉身向$N擊出第貳擊『"HIW"道消魔長"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"往前向$N擊出第參擊『"HIB"妖魔橫行"NOR"』，造成$N身體一處劍傷！\n"NOR,target);  
message_vision(HIR"連續向$N擊出第肆擊『"HIG"天魔極樂"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"飛天向$N擊出第壹擊『"HIR"群魔亂舞"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"轉身向$N擊出第貳擊『"HIW"道消魔長"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"往前向$N擊出第參擊『"HIB"妖魔橫行"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIR"連續向$N擊出第肆擊『"HIG"天魔極樂"NOR"』，造成$N身體一處劍傷！\n"NOR,target);
message_vision(HIW"\n〈共造成$N"HIR+damage+HIW"點傷害，並留了一股氣在$N體內！〉\n"NOR,target);
        target->start_busy(1);
     target->receive_damage("hp",damage, me);
     target->set("wound/head",random(3));
     me->set_temp("masen",1);
     call_out("stop_masen", 18, me);
        me->start_busy(3);
        me->receive_damage("ap",random(30)+ 10);
//       call_out("nine",12,me,target,1,damage);
                target->apply_condition("sword_gas", 

target->query_condition("sword_gas")+1+random((me->query_skill("masen_sword")/10)-1));
        return 1;
        }
        if(!me->skill_active( "masen_sword",(: call_other, __FILE__, "delay", me ,1:), 2))
        return notify_fail("你的滅神鞭法還沒完成。\n");
        me->map_skill("whip", "masen_whip");
        me->reset_action();
message_vision("\n"HIY"$N聚集全身內力，隨手舞了一個劍花，便開始施展『瘋魔劍訣』！\n"NOR,me);
                me->receive_damage("ap",10);
        me->start_busy(1);
        return 1;
}
void nine(object me,object target,int l,int damage)
{
       string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       l=me->query_skill("masen_sword");
       msg = "只見$n渾身顫抖，口中吐出一口鮮血，$N的殺著"HIY"【"CYN"天外飛仙"HIY"】"NOR"，\n";
       msg += "金光爆射，$n的身體裡爆出了一條強大的黃金殺氣！\n\n";
       msg += HIY"─────────────"HIW"【"CYN"天外•飛仙"HIW"】"HIY"─────────

─────→\n";
       message_vision(msg, me, target);
       if( l/3 + random(l) > random(target->query_skill("dodge")) )
       {
damage = me->query_skill("sword") + random(me->query("str")) -     target->query_armor()/2 - 

random(target->query_armor()/2) - (target->query("con"));
         if(damage<20) damage=15+random(8);
message_vision(HIR "\n結果從$n身上爆出的金光上隱隱帶有一股血氣，看來受傷不輕。\n" NOR,me,target);
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            target->receive_damage("hp",damage,me);
            target->receive_damage("ap",random(damage));
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                 tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                 tell_object(target,HIR"("+damage+")"NOR+" 

("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);
       }
       else {
message_vision(HIW "\n$n大驚失色，在一瞬間，展現出一身不凡的功\力，順手狂點，阻止了身上的金光繼續        a=75+a;
        return a;
}

洩出。\n" NOR,me,target)
       if(!me->is_fighting(target)) me->kill_ob(target);     
       
int valid_learn(object me) {    return 1;   
mapping query_action(object me, object weapon
    return action[random(sizeof(action))]
void stop_masen(object me
        if( !me ) return
        me->delete_temp("masen")
int practice_skill(object me) { return 1; 
int improve_limite(object ob
        int a
        a=ob->query_int()
