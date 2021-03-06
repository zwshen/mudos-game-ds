// 戰舞(combat dance)

#include <ansi.h>

inherit SKILL;
string type() { return "knowledge"; }

int exert(object me,object target, string arg)
{
    if( arg == "off" ) {
        message_vision("$N停止跳戰舞了。\n",me);
        me->delete_temp("is_busy/CombatDance");
        return 1;
    }

    if( me->query_condition("CombatDanceCD") )
        return notify_fail("你現在還不想跳戰舞。\n");

    if( me->query_temp("is_busy/CombatDance") )
        return notify_fail("你已經在跳戰舞了。\n");

    if( me->is_fightint() )
        return notify_fail("你現在忙著打架，沒空跳戰舞。\n");

    if( me->is_busy() || sizeof(me->query_temp("is_busy")) )
        return notify_fail("你現在正在忙，沒空跳戰舞。\n");

    me->apply_condition("CombatDanceCD", 240);
    me->set_temp("is_busy/CombatDance", 1);
    me->start_busy(2);

    message_vision(HIW"$N手舞足蹈，開始跳起了「戰舞」。\n"NOR,me);

    me->skill_active("combat-dance",(: call_other, __FILE__, "delay", me:), 2);

    return 1;
}

void DanceEffect(object me, object who, string condition, string type, int sk)
{
    object tmp;

    if( !who->query_condition(condition) ) {
        int effect;
        if( type == "str" || type == "con" || type == "int" || type == "dex" )
            effect = sk / 50;
        else 
            effect = sk / 5;
       who->add_temp("apply/"+type, effect);
        who->add_temp(condition, effect);

    } else {
        if( who->query_condition(condition) > 80 ) return;
    }

    tell_object(who, HIW"你跳著跳著覺得身體充滿了力量。\n"NOR);
    who->apply_condition(condition, who->query_condition(condition) + 3 + random(4) );

    // 好玩的跳舞訊息
    if( me == who ) {
        switch( random(8) ) {
            case 0: message_vision("$N：「喝！哈！」手舞足蹈跳著戰舞。\n", me); break;
            case 1: message_vision("$N同手同腳的隨便動了幾下。\n", me); break;
            case 2: message_vision("$N雙手在空中胡亂比畫。\n", me); break;
            case 3: message_vision("$N左腳踩到右腳，跌了個狗吃屎。\n", me); break;
            case 4: message_vision("$N跳了起來，在空中轉了幾圈，劃出完美的弧度。\n", me); break;
            case 5: message_vision("$N右腳用力的踏地：「喝！」\n", me); break;
            case 6: message_vision("$N扭動著身軀，擺\出自以為是舞神的嘴臉。\n", me); break;
            case 7: message_vision("$N動作甚是扭捏，一副不好意思的樣子。\n", me); break;
        }
        return;
    }

    // 有機會 me 跟 who 交換, 免得有可能一排都是xxx對yyy的動作
    if( random(100) > 50 ) {
        tmp = me;
        me = who;
        who = tmp;
    }

    switch( random(9) ) {
        case 0: message_vision("$N偷看$n的戰舞動作，有樣學樣，但動作卻相當笨拙。\n", me, who); break;
        case 1: message_vision("$N不小心踩到$n的腳，害$n跌在地上。\n", me, who); break;
        case 2: message_vision("$N自得其樂的跳著，不小心撞著了$n。\n", me, who); break;
        case 3: message_vision("$N與$n跳著戰舞，二對眼睛不時的互放秋波。\n", me, who); break;
        case 4: message_vision("$N左腳向前做了一個踢腿動作，卻踢到了$n的屁股。\n", me, who); break;
        case 5: message_vision("$N和$n同聲喝道：「哈！喝！」雙手同時舞動。\n", me, who); break;
        case 6: message_vision("$N一起和$n舞動身軀，協調的動作中帶著威猛，煞是好看。\n", me, who); break;
        case 7: message_vision("$N雙手舞的震天嘎響，卻打到$n的臉好幾下。\n", me, who); break;
        case 8: message_vision("$N一個踉蹌，作勢要向前跌倒，突然雙手急抓$n，二人雙雙翻滾跌在地上。\n", me, who); break;
    }
}

void delay(object me)
{
    int i, sk;
    object *target;

    if( !me ) return;

    if( !me->query_temp("is_busy/CombatDance") || me->is_fighting() ) {
        message_vision("$N停止跳戰舞了。\n", me);
        return;
    }

    if( me->query_condition("CombatDanceCD") <= 230 ) {
        me->delete_temp("is_busy/CombatDance");
        message_vision("$N停止跳戰舞了。\n", me);
        return;
    }

    if( !environment(me) ) return;

    target = all_inventory(environment(me));
    i = sizeof(target);

    while( i-- ) {
        if( !userp(target[i]) ) continue;
        if( !target[i]->query_temp("is_busy/CombatDance") ) continue;
        sk = target[i]->query_skill("combat-dance");

        if( sk < random(500) ) continue;
        
        switch( random(8) ) {
            case 0:
                DanceEffect(me, target[i], "CombatDanceArmor", "armor", sk);
                break;

            case 1:
                DanceEffect(me, target[i], "CombatDanceDamage", "damage", sk);
                break;

            case 2:
                DanceEffect(me, target[i], "CombatDanceHit", "hit", sk);
                break;

            case 3:
                DanceEffect(me, target[i], "CombatDanceDodge", "dodge", sk);
                break;

            case 4:
                DanceEffect(me, target[i], "CombatDanceStr", "str", sk);
                break;

            case 5:
                DanceEffect(me, target[i], "CombatDanceCon", "con", sk);
                break;

            case 6:
                DanceEffect(me, target[i], "CombatDanceInt", "int", sk);
                break;

            case 7:
                DanceEffect(me, target[i], "CombatDanceDex", "dex", sk);
                break;
        }
        target[i]->improve_skill("combat-dance", random(10) );
    }


    me->improve_skill("combat-dance", 10 + random(me->query_int()) );
    me->skill_active("combat-dance", (: call_other, __FILE__, "delay", me:), 2);

    return;
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}
