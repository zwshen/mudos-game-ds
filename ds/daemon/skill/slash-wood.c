#include <ansi.h>
inherit SKILL;
inherit SSERVER;
mapping *action = ({
                       ([
                            "action": "$N縱身回轉, 似拙實巧的揮起$w往$n旋劈而去!",
                            "damage":                22,
                            "dodge" :                 5,
                            "parry" :                -5,
                            "attack":                -5,
                            "attact_type":  "bar",	// 設定技能的攻擊種類
                            // 種類有 生物(bio) 獸性(bar)
                            // 魔法(wit)心靈(sou)科技(tec)
                            "damage_type":  "劈傷"
                        ]),
                       ([
                            "action":"$N揮舞$w, 起身向$n連發三式, 正當$n忙著格擋之際,
                            $N突然朝$n中路直劈下去!!",
                            "damage":    10,
                            "dodge" :   -10,
                            "attack":    10,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷"
                        ]),
                       ([
                            "action":"$N一躍, 手中$w硬狠狠的往$n頭頂削去!",
                            "damage": 18,
                            "attack": -5,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷"
                        ]),
                       ([
                            "action":"$N雙手持$w, 朝$n發出又快又狠又準的一招!",
                            "damage": 11,
                            "dodge" : -5,
                            "parry" : -5,
                            "attack": 15,
                            "attact_type":  "bar",
                            "damage_type":  "劈傷"
                        ]),
                       ([
                            "action":"$N一手持$w, 向$w橫劈過去, 突然身形一轉, $N將$w換手,
                            朝$n狂殺過去, 儼如十字!!",
                            "damage":  27,
                            "parry":   -5,
                            "attack":  -5,
                            "attact_type":  "bar",
                            "damage_type":  "砍傷"
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,sk,ax,b,d,e,da,bd,force,skill,num,hit,dodge,eny;
    string msg,aa,name;
    object weapon,*enemy;
    mapping type;
    weapon=me->query_temp("weapon");
    da = me->query_damage();
    sk = me->query_skill("slash-wood");
    ax = me->query_skill("axe");
    bd = me->query_skill("blade");
    force = me->query_skill("force");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood" )
            return notify_fail(HIB"您現在並沒有在使用"HIC"破柴術"NOR"喔！\n"NOR);
        me->map_skill("axe");
        me->map_skill("blade");
        me->reset_action();
        write(HIY"你停止使用"CYN"破柴術"NOR"了。\n"NOR);
        return 1;
    }
    if(!weapon)
        return notify_fail(CYN"破柴術"YEL"必須要配合刀子或斧頭一起使用。\n"NOR);
    if(weapon->query("skill_type")!="blade" && weapon->query("skill_type")!="axe")
        return notify_fail(CYN"破柴術"YEL"必須要配合刀子或斧頭一起使用。\n"NOR);
    name = weapon->query("name");
    if(weapon->query("skill_type")=="blade") skill = sk + bd;
    if(weapon->query("skill_type")=="axe") skill = sk + ax;
    if(arg=="cross-slash")
    {
        if(!me->is_fighting())
            return notify_fail(HIW"\n您必須在戰鬥中才能使用這項特技。\n"NOR);
        if(me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood")
            return notify_fail(HIB"您現在並沒有在使用"HIC"破柴術"NOR"喔！\n"NOR);
        if(me->query_str() < 30 || force < 40 || sk < 40 )
            return notify_fail(HIW"\n您的能力還不足以使出這項特技。\n"NOR);
        if(me->query("ap") < 200)
            return notify_fail(HIW"\n您的體力已經不足以使用這項特技了。\n"NOR);
        if(me->is_busy())
            return notify_fail(HIW"\n您正在忙其他的事情喔！\n"NOR);
        enemy = me->query_enemy();
        num = random(sizeof(enemy));
        enemy[num]=present(enemy[num],environment(me));
        c=enemy[num]->query_temp("apply/armor");
        hit = random(me->query_dex()*2+sk/3);
        dodge = random(enemy[num]->query_dex()*2+enemy[num]->query_skill("dodge")/2);
        message_vision(HIC"\n$N突然發出一道強大氣勁, 手中"+name+"成十字狀揮舞,\n"
                       "劈出一道狂風, 排山倒海的衝向$n!!"NOR,me,enemy[num]);
        damage = (skill*3/2) + (da/2) + (random(da)/2) + (random(force)/2);
        damage = damage - (random(c)/2);
        if(damage < 100) damage = 80+random(30);
        if(damage > 350) damage = 300+random(80);
        if(weapon->query("skill_type")=="axe") damage = damage*5/4;
        if(hit-20 > dodge)
        {
            msg = HIR"\n唰 -- 唰 -- 兩聲，$n的胸前赫然多了兩道傷口，血流如柱！\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",random(4)+1);
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
            enemy[num]->receive_damage("hp",damage,me);
            COMBAT_D->report_status(enemy[num]);
            me->start_busy(2);
            enemy[num]->start_busy(1);
        }
        else if(hit+15 > dodge)
        {
            msg = HIB"\n$n側身一閃，可是仍被$N的強大氣勁劃傷身體。\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",random(2)+1);
            // 增加素質對傷害的影響
            damage = damage / 2;
            damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
            enemy[num]->receive_damage("hp",damage,me);
            enemy[num]->improve_skill("parry",3+random(2));
            COMBAT_D->report_status(enemy[num]);
            me->start_busy(3);
            enemy[num]->start_busy(2);
        }
        else
        {
            msg = CYN"\n但被$n閃了開去。\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",1);
            enemy[num]->improve_skill("dodge",3+random(2));
            me->start_busy(3);
            enemy[num]->start_busy(1);
        }
        me->add("ap",-30);
        if(weapon->query("skill_type")=="blade")
            me->improve_skill("blade",2);
        if(weapon->query("skill_type")=="axe")
            me->improve_skill("axe",2);
        return 1;
    }
    if(arg=="all-slash")
    {
        if(!me->is_fighting())
            return notify_fail(HIW"\n您必須在戰鬥中才能使用這項特技。\n"NOR);
        if(me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood")
            return notify_fail(HIB"您現在並沒有在使用"HIC"破柴術"NOR"喔！\n"NOR);
        if(me->query_str() < 55 || force < 70 || sk < 80 )
            return notify_fail(HIW"\n您的能力還不足以使出這項特技。\n"NOR);
        if(me->query("ap") < 300)
            return notify_fail(HIW"\n您的體力已經不足以使用這項特技了。\n"NOR);
        if(me->is_busy())
            return notify_fail(HIW"\n您正在忙其他的事情喔！\n"NOR);
        enemy = me->query_enemy();
        num = random(sizeof(enemy));
        enemy[num]=present(enemy[num],environment(me));
        c=enemy[num]->query_temp("apply/armor");
        hit = random(me->query_dex()*2+sk/3);
        dodge = random(enemy[num]->query_dex()*2+enemy[num]->query_skill("dodge")/2);
        message_vision(HIB"$N猛然將手中"+name+"向地一撇, 橫劃出約七尺長的土溝。\n\n"NOR,me,enemy[num]);
        me->start_busy(3);
        message_vision(HIC"$N側身迴旋衝向直立地上的"+name+", 靠著強大功\力\和身上的那股旋勁,\n"
                       "硬是把整著土地掀起, 發出轟隆巨響!"NOR,me);
        for(eny=0;eny<sizeof(enemy);eny++)
        {
            damage = (random(skill)/2) + (random(da)/2) + (force/2);
            if(damage < 30) damage = 25+random(15);
            if(damage > 180) damage = 160+random(40);
            if(weapon->query("skill_type")=="axe") damage = damage*5/4;
            if(hit+15 > random(enemy[eny]->query_dex()*2+enemy[eny]->query_skill("dodge")/2))
            {
                msg = HIY"\n結果$n閃躲不及，被挾帶強大勁道的土石擊中！\n"NOR;
                message_vision(msg, me, enemy[eny]);
                me->improve_skill("slash-wood",random(2)+1);
                damage = damage - ((enemy[eny]->query_armor())/2);
                // 增加素質對傷害的影響
                damage = COMBAT_D->Merits_damage(me,enemy[eny],damage,"bar");
                enemy[eny]->receive_damage("hp",damage,me);
                COMBAT_D->report_status(enemy[eny]);
                enemy[eny]->start_busy(2);
            }
            else
            {
                msg = YEL"\n$n翻身一轉，有驚無險的躲開了飛射而來的土石。\n"NOR;
                message_vision(msg, me, enemy[eny]);
                me->improve_skill("slash-wood",1);
                enemy[eny]->improve_skill("dodge",3+random(2));
                enemy[eny]->start_busy(1);
            }
        }
        me->start_busy(2);
        me->add("ap",-(eny*9));
        message_vision(HIR"土中凌厲的氣破土而出，直向$n逼去!!!"NOR,me,enemy[num]);
        damage = (random(skill)/2) + (skill/2) + (random(da)/3*2) + (da/3*2) + (force*2/3);
        damage = damage - random(c/2);
        if(damage < 150) damage=140+random(20);
        if(damage > 400) damage=380+random(50);
        if(weapon->query("skill_type")=="axe") damage = damage*5/4;
        if(hit-8 > dodge)
        {
            msg = HIY"瞬間$n的鮮血狂飆而出！\n"NOR;
            message_vision(msg, me, enemy[num]);
            me->improve_skill("slash-wood",random(3)+2);
            // 增加素質對傷害的影響
            damage = COMBAT_D->Merits_damage(me,enemy[num],damage,"bar");
            enemy[num]->receive_damage("hp",damage,me);
            COMBAT_D->report_status(enemy[num]);
            me->start_busy(2);
            enemy[num]->start_busy(1);
        }
        else
        {
            msg = YEL"卻給$n閃了個狼狽模樣。\n" NOR;
            message_vision(msg, me, enemy[num]);
            enemy[num]->improve_skill("dodge",2);
            me->improve_skill("slash-wood",1);
            me->start_busy(2);
        }
        me->add("ap",-33);
        if(weapon->query("skill_type")=="blade")
            me->improve_skill("blade",3);
        if(weapon->query("skill_type")=="axe")
            me->improve_skill("axe",3);
        return 1;
    }
    if(weapon->query("skill_type")=="blade")
    {
        if(me->query_skill("blade")<15)
            return notify_fail(HIR"你的刀法太爛了！\n"NOR);
    }
    if(weapon->query("skill_type")=="axe")
    {
        if(me->query_skill("axe")<8)
            return notify_fail(HIR"你的斧術太爛了！\n"NOR);
    }
    if(me->query("ap")<30 || me->query("hp")<30)
        return notify_fail(HIR"你已經沒力了啦∼∼！\n"NOR);
    //第二次exert
    if(me->query_skill_mapped("axe")=="slash-wood" && me->query_skill_mapped("blade")=="slash-wood")
    {
        if( !target ) target = offensive_target(me);
        if(!target) 	return notify_fail(HIG"你已經在使用破柴術了。\n"NOR);
        //攻擊性的要特別注意要加下面兩行.
        if(!me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target)) me->kill_ob(target);
        if( !target->is_fighting(me)) target->kill_ob(me);
        c = target->query_armor();
        if(sk > random(225) && me->query("str") > 30 && me->query("ap")>50 && sk > 35)
        {
            message_vision(HIR"\n$N狂喝一聲，手持"+name+"躍至空中向$n狂劈而下！\n"NOR,me,target);
            if(weapon->query("skill_type")=="blade")
                damage = sk + bd;
            if(weapon->query("skill_type")=="axe")
                damage = sk + ax;
            damage = sk + da;
            damage -= (random(c)/2);
            if(damage<50) damage=30+random(30);
            if(damage>220) damage=170+random(70);
            if(weapon->query("skill_type")=="axe")
                damage = damage*5/4;
            if(random(me->query_dex()*2+sk/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0 )
            {
                msg = RED"唰 ---- 的一聲，$n的鮮血濺的$N滿臉都是！\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("slash-wood",random(3)+1);
                // 增加素質對傷害的影響
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                me->start_busy(1);
                target->start_busy(2);
            }
            else
            {
                msg = YEL"但$n轉身一閃，閃開了$N個猛烈攻勢。\n" NOR;
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                me->improve_skill("slash-wood",random(2));
                me->start_busy(2);
            }
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            me->add("ap",-15);
            if(weapon->query("skill_type")=="blade")
                me->improve_skill("blade",1);
            if(weapon->query("skill_type")=="axe")
                me->improve_skill("axe",1);
            return 1;
        }
        else
        {
            message_vision(HIC"$N奮力的舉起手中"+name+"砍向$n!"NOR,me,target);
            if(weapon->query("skill_type")=="blade")
                damage = (sk/2) + (bd/2) + (da/2);
            if(weapon->query("skill_type")=="axe")
                damage = (sk/2) + (ax/2) + (da/2);
            damage = (random(damage)/2) + damage/3*2;
            damage -= (random(c)/2);
            if(weapon->qeury("skill_type")=="axe")
                damage = damage*5/4;
            if( damage < 30 ) damage = 20 + random(15);
            if( damage > 120 ) damage = 100 + random(30);
            if( random(me->query_dex()*2+sk/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0)
            {
                msg = HIY"結果一招命中，造成$n十分嚴重的劈傷!!\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("slash-wood",2+random(2));
                // 增加素質對傷害的影響
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                target->start_busy(1);
                me->start_busy(2);
            }
            else
            {
                msg = YEL"但是卻被$n給躲開了。\n"NOR;
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                me->improve_skill("slash-wood",random(2));
                me->start_busy(2);
            }
            me->add("ap",-9);
            me->start_busy(1);
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            if(weapon->query("skill_type")=="blade")
            {
                me->improve_skill("slash-wood",1+random(me->query_int()/8));
                me->improve_skill("blade",1+random(me->query_int()/8));
            }
            if(weapon->query("skill_type")=="axe")
            {
                me->improve_skill("slash-wood",2);
                me->improve_skill("axe",2);
            }
            return 1;
        }
    }
if(!me->skill_active( "slash-wood",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("你收招的動作還沒完成。\n");
    me->map_skill("blade","slash-wood");
    me->map_skill("axe","slash-wood");
    me->reset_action();
    message_vision("\n"HIC"$N拿起手中"+name+"，揮起"HIR"破柴術"NOR"。\n"NOR,me);
    me->add("ap",-10);
    me->start_busy(1);
me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
    return 1;
}
void delay(object me,int cost)
{
    object weapon;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("blade");
        me->map_skill("axe");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="blade" && weapon->query("skill_type")!="axe")
    {
        me->map_skill("axe");
        me->map_skill("blade");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("blade")!="slash-wood" && me->query_skill_mapped("axe")!="slash-wood")
    {
        return;
    }
    if(me->query("ap")<40)
    {
        me->map_skill("axe");
        me->map_skill("blade");
        me->reset_action();
        tell_object(me,HIW"\n你已經不夠力用破柴術了喔。\n"NOR);
        return ;
    }
    if( me->is_fighting() ) me->add("ap",-5); //luky
me->skill_active( "slash-wood",(: call_other, __FILE__, "delay", me, 6 :), 10);
}
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
    int a,b,c;
    a=ob->query_skill("axe");
    b=ob->query_skill("blade");
    c=(a+b)/2;
    if(c>85) c=85;
    return c;
}
