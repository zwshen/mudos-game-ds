// 邪極宗  槍法 - 燎原槍法 (ablaze-pike)
// Tmr 2007/10/11

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

#define SKILL_NAME "ablaze-pike"
        
void delay(object me);

mapping *action = ({
                       ([
                            "action": "$N手中$w槍頭帶起數個急旋，使出起手式"+HIR"『"+NOR"火星乍現"+HIR"』"+NOR"，氣勁如粒粒火星熾屑，直取$n$l",
                            "damage":                25,
                            "attact_type":  "sou",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N手中$w槍勢大盛，使出"+HIR"『"+NOR"中流砥柱"+HIR"』"+NOR"，槍尖不偏不倚刺向$n$l",
                            "damage":                20,
                            "attact_type":  "sou",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N使出殺招"+HIR"『威凌天下』"+NOR"，$w化作千百道槍影，竟像已將$n的退路全截斷了似的，連水滴也不能通過",
                            "damage":                45,
                            "attact_type":  "sou",
                            "damage_type":  "刺傷",
                        ]),

                       ([
                            "action": "$N單足柱地使出"+HIR"『"+NOR"火狐吞天"+HIR"』"+NOR"，另一腳腳背卻架在獨立地上那腳的腿膝後，$w以奇異的波浪軌跡掃向$n$l要害",
                            "damage":                30,
                            "attact_type":  "sou",
                            "damage_type":  "劈傷",
                        ]),

                       ([
                            "action": "$N激起燎原真勁激出絕技"+HIR"『"+NOR"火蛇狂舞"+HIR"』"NOR+"，$w一槍化做千萬火蛇，直取$n$l要害",
                            "damage":                 25,
                            "attact_type":  "sou",
                            "damage_type":  "刺傷",
                        ]),
                   });

void improve_skill(object me) {
    me->improve_skill(SKILL_NAME, 1 + random(me->query_int()/2));
    me->improve_skill("fork",1 + random(me->query_int()/2));
}

/* 武器損傷 */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp 損壞率 add by wilfred
}

/* 判斷是否還未引發戰鬥 */
void check_combat(object me, object target) {
    if( !objectp(me) ) return;
    if( !objectp(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(!target->is_fighting(me)) target->kill_ob(me);
}

int get_tiger_damage(object me, object target)
{
    int damage, power;
    // 以魔性的數值為基礎
    power = CLASS_D("ancestor")->getMagicLevel(me, target);
    damage = me->query_skill(SKILL_NAME) + me->query_damage();
    damage = damage + power*70;
    damage = damage - target->query_armor()/2 - random(target->query_armor()/3);

    return COMBAT_D->Merits_damage(me, target, damage, "sou");
}

void clear(object me){
        if( !objectp(me) ) return;
        tell_object(me,"你使用「無槍勢」的損害已經恢復了。\n");
        me->delete_temp("ABLAZE_PIKE_ACT");
}


/* 無槍勢 特攻 */
void do_tiger_attack(object me, object target) {

    object weapon;
    int damage, target_d,sk;
    int power;
    string msg;

    me->start_busy(2);
    me->receive_damage("ap", 50, me);
    me->set_temp("ABLAZE_PIKE_ACT",1);

    weapon=me->query_temp("weapon");
    msg = HIM"\n$N"HIM"丈二紅槍回收身後，冷冷看著敵人，沒有人估到$N"HIM"的槍會由那個角度出手，\n"
                        "這是燎原槍法名震天下的"HIR"『無槍勢』"HIM"，由有槍變無槍，教人完全捉不到可怕的丈二紅槍下一步的變化。\n"
                        "丈二紅槍一沉一剔，千百點槍芒，火般閃跳，將$n迫得無法應對，連連敗招！！\n"NOR;

    damage = get_tiger_damage(me, target);
    if( damage <= 0 ) {
        msg += HIW "可惜被$n" HIW "躲開致命的一擊了。\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill(SKILL_NAME);
    if( sk + random(sk/2) > random(target_d) ) {
        target->receive_damage("hp",damage,me);
        target->start_busy(1);

        power = CLASS_D("ancestor")->getMagic(me, target);
        if( power > 0) {
                // 有魔性加權
                msg += HIR "$n"HIR"肩頭濺血，"+HBK "腥臭的黑血爆散出來" + HIR"，受傷相當嚴重("+damage+")！\n" NOR;
                 CLASS_D("ancestor")->deleteMagic(me, target);
        } else {
                msg += HIR "$n"HIR"肩頭濺血，臉色蒼白難看，可見受傷著實不輕("+damage+")！\n" NOR;
        }
        message_vision(msg, me, target);
        damage_weapon(me);                      // 武器損傷
        COMBAT_D->report_status(target);
        improve_skill(me);
    } else {
        msg += HIW"可是被$n" HIW "躲了開去。\n" NOR;
        message_vision(msg, me, target);
    }

     call_out("clear", 8, me);
}


int exert(object me, object target, string arg)
{
    int sk;
    object weapon;
    sk = me->query_skill(SKILL_NAME);
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("你已經死了，請快點去復活吧。\n");
    if (!weapon) return notify_fail("你要拿槍才能施展「燎原槍法」。\n");
     if(weapon->query("skill_type")!="fork") return notify_fail("你手中必須有槍才能施展「燎原槍法」。\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("fork") != SKILL_NAME)
            return notify_fail("你並沒有使用「燎原槍法」。\n");
        me->map_skill("fork");
        me->reset_action();
        write("技能「燎原槍法」已取消。\n");
        return 1;
    }

    if(me->query("ap")<10 || me->query("hp")<10) 
                return notify_fail("你的身體狀況無法使用「燎原槍法」。\n");

    //第二次exert
    if(me->query_skill_mapped("fork")==SKILL_NAME)
    {
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("你已正在施展「燎原槍法」了。\n");
        if (me->query_skill(SKILL_NAME) < 50)
            return notify_fail("你目前還無法使出「無槍勢」的殺招。\n");
        if(me->query("ap") < 100)
            return notify_fail("你目前的內勁不足，無法使出「無槍勢」的殺招。\n");
        if(me->query_temp("ABLAZE_PIKE_ACT") )
            return notify_fail("你短時間內無法再使用「無槍勢」。\n");

        //攻擊性的要特別注意要加下面兩行.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");

        do_tiger_attack(me, target); // 特攻 無槍勢

        return 1;
    }

        if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me ,5:), 10)) 
                return notify_fail("「燎原槍法」的動作還沒完成。\n");
    me->map_skill("fork", SKILL_NAME);
    me->reset_action();
    message_vision("$N鼓起燎原真勁，槍法一變，開始施展起「燎原槍法」。\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "fork" )
    {
        me->map_skill("fork");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("fork")!=SKILL_NAME )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("fork");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展「燎原槍法」。\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
     return 60 + ob->query_int();

}


