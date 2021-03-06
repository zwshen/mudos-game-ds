
#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([  "action":   "當$n攻擊$N身體時，$N突然使出一式「"HIC"順水推舟"NOR"」，全身力量灌注於雙掌，順勢往$n身上推去。",
        "dodge":      20,
        "parry":      90,
        "damage":     80,
        "force":     250,
        "damage_type":  "嚴重瘀傷，並跌了個四腳朝天",
    ]),
   ([  "action":   HIW"$N以靜制動，$n見機不可失，往$N的身上拍了一掌，沒想到$N一招「"HIY"借力使力"HIW"」，$n反遭自家掌法反撲。"NOR,
        "dodge":      50,
        "parry":      90,
        "damage":     90,
        "force":     300,
        "damage_type":  "瘀傷",
    ]),
   ([  "action":   HIW"$N不動如山，$n立即搶攻，$N突然使出「"HIR"四兩"HIY"撥"HIC"千斤"HIW"」，無窮大的威力往$n的$l擊去。"NOR,
        "dodge":     10,
        "parry":     50,
        "damage":   150,
        "force":    400,
        "damage_type":  "瘀傷",
    ]),
   ([  "action":   "$n露出極大的破綻，$N一見機不可失，立即施展身法，一瞬間已經到了$n的眼前，一式「"HIW"白猿獻果"NOR"」，$n的雙眼遭到有如千斤之力的攻擊。"NOR,
        "dodge":     -20,
        "parry":      30,
        "damage":     80,
        "force":     250,
        "damage_type":  "瘀傷，雙眼跟熊貓一樣，走起路來也開始搖搖晃晃的",
    ]),
   ([  "action":   "$N腳踏太極八卦陣，身影突然糢糊的起來，突然一式，「"HIG"青龍探爪"NOR"」，$n毫無預警的，背部已猛然中招",
        "dodge":       20,
        "parry":       50,
        "damage":      70, 
        "force":      300,
        "damage_type":  "瘀傷，並由口中吐出鮮血",
    ]),
   ([  "action":   HIW"$N運起強勁的內力，一式「"HIC"風捲"HIG"荷葉"HIW"」，無形中這些蘊含殺傷力的內力往$n的身上疾射而去。"NOR,
        "dodge":      20,
        "parry":      50,
        "damage":     70,
        "force":     250,
        "damage_type":  "數道割傷",
    ]),

});
int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("學太極拳必須要空手唷。\n");
    if( (int)me->query("max_force") < 50 )
        return notify_fail("你的內力太低了吧！去練到五十再來學。\n");
    return 1;
}

int valid_enable(string usage)
{
    return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("sen") < 30  )
        return notify_fail("你的精神無法集中了﹐休息一下再練吧。\n");
    if( (int)me->query("force") < 5 )
        return notify_fail("你的內力不夠﹐沒有辦法練習太極拳。\n");
    if( (int)me->query("kee") < 30 )
        return notify_fail("你的氣不夠﹐沒有辦法練習太極拳。\n");

    me->receive_damage("kee", 30);
    me->add("force", -5);
    return 1;
}


