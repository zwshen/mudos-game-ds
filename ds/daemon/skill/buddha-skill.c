// 如來九式(buddha-skill) 新版本
// -Tmr 2006/10/18 
        
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({

        ([
        "action": "$N手抖$w"NOR"，使出"HIW"「佛光乍現」"NOR"，一眨眼之間，就舞出數十個杖頭影像朝$n的$l猛然揮去",
        "damage":                25,
        "attact_type":  "sou",  // 設定技能的攻擊種類
                                // 種類有 生物(sou) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "搥傷",
        ]),

        ([
        "action": "$N身上氣流狂旋，使出"HIW"「金頂佛燈」，"NOR"$w"NOR"散發出迫人的氣勢，接著朝$n的$l猛然敲去",
        "damage":                25,
        "attact_type":  "sou",  // 設定技能的攻擊種類
                                // 種類有 生物(sou) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "撞傷",
        ]),
                
        ([
        "action": "$N大喝一聲使出"HIW"「佛動山河」"NOR"，四週的空氣登時凝結起來，$N一杖揮出，猶如萬奔騰，銳不可擋似地朝$n的$l揮去",
        "damage":                35,
        "attact_type":  "sou",  // 設定技能的攻擊種類
                                // 種類有 生物(sou) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "撞傷",
        ]),
                
        ([
        "action": "$N提氣躍上半空，使出"HIW"「佛問迦藍」"NOR"，遠方不知何處傳來一陣佛音"NOR"，$N緊緊握住$w"NOR"，氣勢萬千地朝$n的天靈蓋\敲去",
        "damage":                25,
        "attact_type":  "sou",  // 設定技能的攻擊種類
                                // 種類有 生物(sou) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "撞傷",
        ]),
                
                

});

void delay(object me,int cost);

void improve_skill(object me) {
    me->improve_skill("buddha-skill",1 + random(me->query_int()/2));
    me->improve_skill("staff",1 + random(me->query_int()/2));
}

/* 武器損傷 */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); 
}

/* 判斷是否需要示傷害數字 */
void show_damage(object me, object target,int damage) {
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
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
    damage = me->query_skill("buddha-skill") + me->query_damage();
    damage = damage + random(damage/2);
    damage = damage - target->query_armor()/3 - random(target->query_armor()/3);
      if( me->query_temp("buddha-body")) damage +=  damage/2;
    return COMBAT_D->Merits_damage(me, target, damage, "sou");
}


/* 迎佛西天 特攻 */
void do_tiger_attack(object me, object target) {

    int damage, target_d,sk;
    string msg;

    if( userp(me) && userp(target) ) me->start_busy(2);
    else me->start_busy(1);

    me->receive_daemage("ap", 50);
    
    msg = HIM "$N右杖左掌地結起金頂佛印，身周彷彿幻化起聖潔綺麗的琉璃佛燈，不斷盤旋！！\n" NOR;
    msg += HIW "$N幻化成如來形相，駕馭一把碧綠剔透的"HIG"琉璃法杖"HIW"，挾風雷之勢攻向$n！！\n" NOR;
    damage = get_tiger_damage(me, target);
    if( damage <= 0 ) {
        msg += HIW "可是這一擊卻是軟弱無力，無法對$n" HIW "造成任何傷害...\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill("buddha-skill");
    if( sk + random(sk/2) > random(target_d) ) {
        target->add_busy(1+random(2));
        target->receive_damage("hp",damage,me);

        msg += HIR "$n"HIR"被此招「迎佛西天」狠狠擊中胸口，全身如遭電殛﹗！" NOR;
        message_vision(msg, me, target);
        damage_weapon(me);                      // 武器損傷
        show_damage(me, target, damage);        // 顯示傷害數字
        message_vision("\n", me);
        

        COMBAT_D->report_status(target);
                improve_skill(me);
    } else {
        msg += CYN"$n" CYN "雖然被此招擊中了，但並沒有造成明顯的傷害.....\n" NOR;
        message_vision(msg, me, target);
    }
}

/* 連擊的攻擊力 */
int get_continue_attack_damage(object me, object target) {
    int damage;
    damage = (me->query_skill("buddha-skill") + me->query_damage())/3;
    damage -= target->query_armor()/2 - random(target->query_armor()/2);
    if(damage < 1 ) damage = 1;
    return COMBAT_D->Merits_damage(me,target,damage,"sou");
}



/* 佛光普照 */
void do_continue_attack(object me, object target)
{
      int sk, attack_times, a, target_d, damage;
    mapping type;
    string msg;

    sk =  me->query_skill("buddha-skill");
    if( sk < 20) attack_times = 1;
    else    if( sk < 40) attack_times = 1 + random(2);
    else    if( sk < 60) attack_times = 2 + random(2);
    else    if( sk < 80) attack_times = 2 + random(3);
    else    attack_times = 3 + random(3);

    me->receive_damage("ap",attack_times*8);

    if(userp(me) && userp(target)) me->start_busy(2);
    else me->start_busy(1);

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    for( a = 0; a < attack_times; a++ )
    {
        if ( a > 0) msg = HIW"$N身上光芒四射，$n"HIW"顯得措手不及，露出錯愕的神情！\n"NOR;
        else msg ="";
        type = action[ random(sizeof(action)-1) ];
        msg += "$N快疾凌厲一杖就直接往$n身上要害揮去。";

        damage = get_continue_attack_damage(me, target);

        if( damage < 1 ) damage = 1 + random(5);

        if( sk/2+random(sk) > random(target_d)  )       //連擊有較高的命中率
        {
            msg += RED"結果造成$n"RED"一處撞傷！！"NOR;
            message_vision(msg, me, target);

            damage_weapon(me);          // 武器損傷

            target->receive_damage("hp",damage,me);
            show_damage(me, target, damage);
            message_vision("\n", me);
            improve_skill(me);
        }
        else        {
            msg += "可是被$n給閃了開去。\n";
            message_vision(msg, me, target);
        }
    }

    COMBAT_D->report_status(target);
}

/* 第二次做exert 就是施展特攻 */
int do_exert(object me, object target) {
    int sk;

    if( !target ) target = offensive_target(me);
    if( !target)
        return notify_fail("你已經在使用「如來九式」了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("你試圖攻擊的敵人已經不在了。\n");

    //攻擊性的要特別注意要加下面兩行.
    if(!me->can_fight(target)) return 0;
    if(target->is_corpse()) return notify_fail("看清楚，對方己經死了。\n");

    sk = me->query_skill("buddha-skill");
    if( sk > 59 && random(sk) > random(150) ) {
        do_tiger_attack(me, target);    // 5. 迎佛西天
    } else {
        do_continue_attack(me, target); // 6. 佛光普照
    }

    check_combat(me, target);
    
    return 1;
}

int exert(object me, object target, string arg)
{
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("staff")!="buddha-skill")
                        return notify_fail("你並沒有使用如來九式\n");
                me->map_skill("staff");
                me->reset_action();
                write("技能[如來九式]已取消。\n");
                return 1;
        }
        if(!weapon) return notify_fail("使用如來九式必須手中要有根杖。\n");
        if(weapon->query("skill_type")!="staff") return notify_fail("使用如來九式必須手中要有根杖。\n");
            //第一次exert --> 施展特攻
                if(me->query("ap")<10 || me->query("hp")<10 )
                        return notify_fail("你的身體狀況無法使用如來九式。\n");

            //第二次exert --> 施展特攻
        if(me->query_skill_mapped("staff")=="buddha-skill")
               return do_exert(me, target);        

        if(!me->skill_active( "buddha-skill",(: call_other, __FILE__, "delay", me ,6:), 10))
          return notify_fail("你的收招動作還沒完成。\n");
        me->map_skill("staff", "buddha-skill");
        me->reset_action();
         message_vision( "$N口宣佛號，散發出神聖莊嚴的氣勢，開始施展『如來九式』。\n",me);
        me->receive_damage("ap",5);
        me->start_busy(1);
  
      //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
        return 1;
}

void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");

        if(!weapon)   {
                me->map_skill("staff");
                me->reset_action();
                return;
        }
        if(weapon->query("skill_type")!="staff")
        {
                me->map_skill("staff");
                me->reset_action();
                return;
        }
        if(me->query_skill_mapped("staff")!="buddha-skill")
        {
         return;
        }
            if(me->query("ap")<20)
        {
                me->map_skill("staff");
                me->reset_action();
                  message_vision("$N的體力不夠無法繼續使用如來九式, 只好改用一般招式。\n"NOR,me);
                return ;
   
             }
    if( me->is_fighting() )
        me->receive_damage("ap",5); //luky
     me->skill_active( "buddha-skill",(: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }


