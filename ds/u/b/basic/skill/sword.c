#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "name":         HIC"青龍出海"NOR,
        "action":
        "$N"HIW"突起飛身，一招「"+HIC"青龍出海"+HIW"」手中的$w"HIW
        "急向$n"HIW"的$l刺去。" NOR,
//      "dodge":        -20,
        "damage":       35,
        "damage_type":  "刺傷"
    ]),
    ([  "name":         MAG"彩筆畫眉"NOR,
u"
        "$N"HIW"的劍刃堪堪畫到$n"HIW"的雙目之上。"NOR,
//      "dodge":        -10,
        "damage":       10,
        "damage_type":  "割傷"
    ]),
    ([  "name":         BLU"浪跡天涯"NOR,
        "action":       "$N"HIW"身體微向前傾，一式「"+BLU"浪跡天涯"+HIW
        "」，揮劍直向$n"HIW"的$l劈了過去。"NOR,
        "dodge":        -30,
        "damage":       50,
        "damage_type":  "刺傷"
    ]),
    ([  "name":         HIM"花前月下"NOR,
        "action":       "$N"HIW"單劍顫動，如鮮花招展風中，來回揮削，一招「"+HIM
        "花前月下"+HIW"」只晃得$n"HIW"眼花撩亂，\n"
        "同時$N"HIW"旋起手中的$w"HIW"突然削向$n"HIW"的$l。"NOR,
//      "dodge":        -20,
        "damage":       20,
        "damage_type":  "割傷"
    ]),
    ([  "name":         HIG"清飲小酌"NOR,
        "action":       "$N"HIW"劍柄提起，劍尖上翻，一式「"+HIG"清飲小酌"+HIW
        "」，竟是指向自己櫻唇，宛似舉杯自飲一般。\n"+
"NOR,
        "dodge":        -30,
        "damage":       40,
        "damage_type":  "刺傷"
    ]),
    ([  "name":         HIG"撫琴按蕭"NOR,
        "action":       "$N"HIW"身體微向前蹲，將劍美妙的畫了個弧停滯胸前，"
蕭"
        +HIW"」將手中$w"HIW"'往$n"HIW"的$l一畫。"NOR,
        "dodge":        -15,
        "damage":       20,
        "damage_type":  "割傷"
    ]),
    ([  "name":         HIY"掃雪烹茶"NOR,
"
        "竟似蠻不在乎無心較勁一般，\n"
HIY
        "掃雪烹茶"+HIW"」直刺向$n"HIW"的下盤。"NOR,
        "dodge":        -10,
        "damage":       20,
        "damage_type":  "割傷"
    ]),
    ([  "name":         HIC"松下對弈"NOR,
        "action":       "$n攻向$N的$l不擊，$N轉身回刺$n的$l不中，"
  "，正當$n想再攻向$N時，\n$N"HIW"斜劍下指，一式「" + HIC
        "松下對弈"+HIW"」，手中$w"HIW"化成層層劍影，刺向$n"HIW"的諸身穴道。"NOR,
        "dodge":        -20,
        "damage":       20,
        "damage_type":  "刺傷"
    ]),
    ([  "name":         HIM"池邊調鶴"NOR,
        "action":       "$N"HIW"舉劍向$n"HIW"的$l直劈過去，$n"HIW
        "側身閃過隨即向$N"HIW"的$l攻了過來"
        "\n，$N"HIW"慢妙的舞姿在地上點了兩點，一招「"+HIM"池邊調鶴"+HIW
        "」，將手中的$w"HIW"刺向$n"HIW"的$l。"NOR,
        "dodge":        -10,
        "damage":       15,
        "damage_type":  "割傷"
    ]),
    ([  "name":         HIG"小園藝菊"NOR,
"
        "$n"HIW"見機出手攻向$N"HIW"的$l，\n但見$N"HIW"抬起頭來微微一笑，"
        "手中$w"HIW"抖動，一式「"+HIG"小園藝菊"+HIW"」，點向$n"HIW"的$l。"NOR,
        "dodge":        -10,
        "damage":       25,
        "damage_type":  "割傷"
    ]),
   ([  "name":         HIY"茜窗夜話"NOR,
        "action":       "$N"HIW"以優雅的姿態轉劍畫了個半圓，$n"HIW
        "一看正想趁勢點向$N"HIW"的$l之時，\n$N"HIW
R,
        "dodge":        -10,
        "damage":       25,
        "damage_type":  "刺傷"
    ]),
    ([  "name":         HIY"柳蔭聯句"NOR,
吤X"
        "準備還擊時，\n$N"HIW"手起劍刃，一式「"+HIY"柳蔭聯句"+HIW
        "」，手中$w"HIW"已順勢點向$n"HIW"的$l。"NOR,
        "dodge":        -15,
        "damage":       25,
        "damage_type":  "刺傷"
    ]),
    ([  "name":         HIR"竹簾臨池"NOR,
        "action":       "$N"HIW"面露微笑，旋轉身軀並持劍向下揮舞出層層，"
        "看似薄紗般的劍影護住全身，\n當$n"HIW"想找機會進攻之時，$N"HIW"突變一式"
        "「"+HIR"竹簾臨池"+HIW"」，搖擺\劍身，"
        "\n手中$w"HIW"劃出了一道弧光斬向$n"HIW"的$l"NOR,
        "dodge":        -15,
        "damage":       25,
       "damage_type":  "割傷"
    ]),
});
int valid_learn(object me)
{
    object ob;

    if( (int)me->query("max_force") < 50 )
        return notify_fail("你的內力不夠﹐沒有辦法練玉女劍法。\n");
    if( !(ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必須先找一把劍才能練劍法。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
int practice_skill(object me)
{

    if( (int)me->query("kee") < 30
    ||  (int)me->query("force") < 3 )
        return notify_fail("你的內力或氣不夠﹐沒有辦法練習玉女劍法。\n");
    me->receive_damage("kee", 30);
    me->add("force", -3);
    return 1;
}

