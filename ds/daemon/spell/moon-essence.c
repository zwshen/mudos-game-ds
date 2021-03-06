/*
◎ 太陰凝精 (moon-essence) - 神武教進階技能

太陰凝精是神武教最奧妙的咒術，當所招喚的孤魂
野鬼消失之際，神武教弟子可以從鬼魂身上汲取純陰性質
的「太陰凝精」，並收藏在自身體內。利用太陰凝精，神武
教弟子可以催動太陰之力，瞬間發動咒術，攻敵人一個措手
不及。

技能每5級可以多收藏1點太陰凝精，最多可儲存25點。

Last update: Tmr 2008/07/22
*/

#include <ansi2.h>
        
#define SKILL_NAME "moon-essence"

inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
        int point;
        point = me->query_temp("MOON_ESSENCE");
        tell_object(me, sprintf("你體內藏有%2d點太陰凝精。\n", point) );
        return 1;
}

// 計算可以儲存的陰精上限
int limitPoint(object me) {
        // 最多25點
        return me->query_spell(SKILL_NAME)/4;
}

// 是否可以再增加
void checkAdd(object me) {
        int points;
    if(me->query_spell("moon-essence") <1 ) return;
        if( me->query_temp("MOON_ESSENCE") > limitPoint(me) )
                return;
        points = 1 + me->query_spell("moon-essence")/33;
        tell_object(me, HBK"你從孤魂野鬼身上汲取出太陰凝精。\n"NOR);
        me->add_temp("MOON_ESSENCE", points);
        me->improve_spell(SKILL_NAME, 1 + random(me->query_int()));
}

int checkUse(object me) {
        if(me->query_temp("MOON_ESSENCE")< 1) 
                return 0;
        
        // 減少1點
        me->add_temp("MOON_ESSENCE", -1);
        return 1;
}

