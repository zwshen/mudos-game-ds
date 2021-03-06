#include <ansi.h>

void do_common_issue(object me);        // 使用念能力

void c_race_strength(object me);   // 強化系
void c_race_emit(object me);       // 放出系
void c_race_variation(object me);  // 變化系
void c_race_operation(object me);  // 操作系
void c_race_concrete(object me);   // 具現系
void c_race_specical(object me);   // 特質系

void do_issue(object me)
{
    object enemy;

    if( !me ) return;
    if( !objectp(me) ) return;

    switch( me->query_race() ) {
        case "strength":  c_race_strength(me);  break;
        case "emit":      c_race_emit(me);      break;
        case "variation": c_race_variation(me); break;
        case "operation": c_race_operation(me); break;
        case "concrete":  c_race_concrete(me);  break;
        case "specical":  c_race_specical(me);  break;
    }
}

void c_race_strength(object me)    // 強化系
{
    switch( me->skill_mapped("psychical") ) {
        default: break;
    }
}

void c_race_emit(object me)        // 放出系
{
    switch( me->skill_mapped("psychical") ) {
        default: break;
    }
}

void c_race_variation(object me)   // 變化系
{
    switch( me->skill_mapped("psychical") ) {
        default: break;
    }
}

void c_race_operation(object me)   // 操作系
{
    switch( me->skill_mapped("psychical") ) {
        case "dragon four feat":         // skill: 蒼龍四型訣
          command("issue dragon-kiss");
        break;
    }
}

void c_race_concrete(object me)    // 具現系
{
    switch( me->skill_mapped("psychical") ) {
        case "chamber nina-fish":        // skill: 密室念魚
            if( random(100) > 50 ) command("issue concrete");
            else if( me->query_temp("damage_shield/hp") <= 0 ) command("issue fish-scale");
        break;
    }
}

void c_race_specical(object me)    // 特質系
{
    switch( me->skill_mapped("psychical") ) {
        case "the-time":
            command("issue strength");
        break;
    }
}
