// Skill of CLASS: killer
// killer-instict ���⥻��
// Write by -alickyuen@ds-
#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
    int skill;

    skill = me->query_skill("killer-instinct", 1);

    tell_object(me, HIR"�A�����⥻�ʼW�j�F......\n"NOR);
    me->add("evil", -1);
}