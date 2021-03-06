/*
井中八法 少帥軍 進階刀法
1. 不攻 所謂無恃其不來，恃吾有以待也；無恃其不攻，恃吾有所不攻。故名不攻。
2. 擊奇 所謂善出奇者，無窮如天地，不竭如江河，營而離之，並而擊之是也。
3. 用謀 用兵之法，以謀為本，是以欲謀疏陣，先謀地利；欲謀勝敵，先謀固己。
4. 兵詐 名之為一招，其實卻是另八招虛則實之，實則虛之，兵不厭詐的招數。
5. 棋奕 出刀如落子，看敵人如何反應，沒有固定招式。
6. 戰定 非必取不出眾，非全勝不交兵，緣是萬舉萬當，一戰而定
7. 速戰 其疾如風，其徐如林，侵掠如火，不動如山，難知如陰，動如雷震，故兵貴勝，不貴久
8. 方圓 方為陽，圓為陰;陰為方，陽為圓。陰陽應象，天人合一，再不可分

Tmr 2007/05/02

*/
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

#define SKILL_NAME "wellmoon-blade"
        
void delay(object me);

mapping *action = ({
                       ([
                            "action": "$N擺\出"HIR"【"NOR"不攻"HIR"】"NOR"架勢，無恃其不來，恃吾有以待也，一刀如流星電閃似地砍向$n"NOR"的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "$N刀法出奇有如無窮之天地，一招"HIR"【"NOR"擊奇"HIR"】"NOR"往$n"NOR"的$l劈去",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),
                       ([
                            "action": "$N以謀為本，使出"HIR"【"NOR"用謀"HIR"】"NOR"，$w"NOR"從不可思議的角度出刀，又化成側劈硬是砍向$n"NOR"的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),
                       ([
                            "action": "$N轉瞬間連攻八刀，卻是刀刀虛招，原來竟是"HIR"【"NOR"兵詐"HIR"】"NOR"，手中$w"NOR"忽轉為實招劈向$n"NOR"的$l",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),                   
                       ([
                            "action": "$N出刀如落子，在看清$n"NOR"的出招之後，使出"HIR"【"NOR"棋奕"HIR"】"NOR"，手中$w"NOR"不偏不移劈向$n"NOR"的$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),
                       ([
                            "action": "$N非必取不出眾，非全勝不交兵，使出"HIR"【"NOR"戰定"HIR"】"NOR"，手中$w"NOR"一戰而定硬是往$n"NOR"的$l劈去",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),                   
                         ([
                            "action": "$N不動如山、動如雷震，竟是"HIR"【"NOR"速戰"HIR"】"NOR"，手中$w疾如風、徐如林"NOR"似地砍往$n"NOR"的$l去",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷",
                        ]),
                       ([
                            "action": "只見$N刀招以方為陽，圓為陰，使出"HIR"【"NOR"方圓"HIR"】"NOR"，手中$w"NOR"有如陰陽應象，天人合一，往$n"NOR"的$l劈去",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷",
                        ]),                         
                       });


string *acts = ({
        "不攻", "擊奇", "用謀", "兵詐", "棋奕", "戰定", "速戰", "方圓"
});

// 亂數選一招
string random_act() {
        return acts[ random(8) ];
}

void improve_skill(object me) {
    me->improve_skill(SKILL_NAME, 1 + random(me->query_int()/2));
    me->improve_skill("blade",1 + random(me->query_int()/2));
}

/* 武器損傷 */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp 損壞率 add by wilfred
}

/* 判斷是否需要示傷害數字 */
void show_damage(object me, object target,int damage) {
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me,"  造成"+damage+"點傷害!!\n");
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
     int damage;
    damage = me->query_skill(SKILL_NAME) + me->query_damage();
    damage = damage - target->query_armor()/2 - random(target->query_armor()/2);

    return COMBAT_D->Merits_damage(me, target, damage, "bar");
}

void clear(object me){
        if( !objectp(me) ) return;
        tell_object(me,"你可以再使用「井中月」了。\n");

        me->delete_temp("ARMY_WELL_MOON_BLADE");
}


/* 井中月 特攻 */
void do_tiger_attack(object me) {

    object weapon;
        object *targets;
    int damage, target_d, sk;
        int i, j, k, s, max;
    string msg;

     me->start_busy(1);
     me->receive_damage("ap", 50, me);
     me->set_temp("ARMY_WELL_MOON_BLADE",1);

    weapon=me->query_temp("weapon");
    message_vision(
                HIC "\n$N心化成了井中之水，無思無礙，只是客觀地反映著大宇宙神祕的一面。\n"NOR, me);

    sk = me->query_skill(SKILL_NAME);
        max = 1;
        if(sk>=90) max += 1;
        if(sk>=70) max += 1;    // 最多三個人

        targets = me->query_enemy();
        s = sizeof(targets);
        for(i=0, j=0; i < s && j < max;i++, j++) {
         if(!targets[i]) continue;
         if( !me->is_fighting(targets[i]) ) continue;
         if( environment(me) != environment(targets[i]) ) continue;
            target_d = -COMBAT_D->dodge_factor(targets[i],"dodge")*10/15;

                // 出三刀
                for(k=0;k<3;k++) {
                    if( sk + random(sk/2) > random(target_d) ) {
                        damage = get_tiger_damage(me, targets[i]);
                        if( damage <= 0 ) {
                                message_vision(CYN "但是$N刀招無力，無法發揮攻擊的效果。\n" NOR, me, targets[i]);
                        } else {
                                msg = HIR "$N使出井中八法之"HIY"【" + random_act() +"】"HIR"，$n" HIR"命中此招，急退三步，臉上忽青忽紅，內傷不輕！！" NOR;
                                message_vision(msg, me, targets[i]);
                                targets[i]->receive_damage("hp",damage,me);
                                damage_weapon(me);                      // 武器損傷
                                show_damage(me, targets[i], damage);        // 顯示傷害數字
                                message_vision("\n", me);
                                COMBAT_D->report_status(targets[i]);
                        }
                    } else {
                        message_vision(CYN "但是$N刀招遲滯，錯過了攻擊的時機。\n" NOR, me, targets[i]);
                    }
                }
        }
        improve_skill(me);


        if(!userp(me)) {
                // for master
                call_out("clear", 4, me);
                return;
        }

        if(me->query_bio() < 6 )
                call_out("clear", 20-me->query_bio(), me);
        else
                call_out("clear", 8, me);
}


int exert(object me, object target, string arg)
{
        int sk;
    object weapon;
    sk = me->query_skill(SKILL_NAME);
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("你已經死了，請快點去復活吧。\n");
    if (!weapon) return notify_fail("你手中必須有刀才能施展「井中八法」。\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("你手中必須有刀才能施展「井中八法」。\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade") != SKILL_NAME)
            return notify_fail("你並沒有使用「井中八法」。\n");
        me->map_skill("blade");
        me->reset_action();
        write("技能「井中八法」已取消。\n");
        return 1;
    }

    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用「井中八法」。\n");

    //第二次exert
    if(me->query_skill_mapped("blade")==SKILL_NAME)
    {
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("你已正在施展「井中八法」了。\n");
        if (me->query_skill(SKILL_NAME) < 50)
            return notify_fail("你目前還無法使出「井中月」殺招。\n");
        if(me->query("ap") < 100)
            return notify_fail("你目前的內勁不足，無法使出「井中月」殺招。\n");
            if(me->query_temp("ARMY_WELL_MOON_BLADE") )
            return notify_fail("你短時間內無法再使用「井中月」。\n");

        //攻擊性的要特別注意要加下面兩行.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你並沒有和對方在戰鬥中。\n");

        do_tiger_attack( me ); // 特攻 井中月

        return 1;
    }

        if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("你井中八法的動作還沒完成。\n");
    me->map_skill("blade", SKILL_NAME);
    me->reset_action();
    message_vision("$N施展起「井中八法」，刀招有如陰陽應象，天人合一，再不可分。\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    return 1;
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

    if( me->query_skill_mapped("blade")!=SKILL_NAME )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展井中八法。\n"NOR,me);
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
     return 60 + ob->query_str();

}

