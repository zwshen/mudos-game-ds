// �E�Ȥj�k (nine-mystery)
// Tmr 2006/11/22

#include <ansi.h>
#define SKILL_NAME "nine-mystery"
	
inherit SKILL;


int exert(object me,object target, string arg)
{
    int force,sk,heal;

    force=me->query_skill("force",2);
    sk=me->query_skill(SKILL_NAME,2);
    heal=(force+sk)/2;

    //���˥\��
    if(arg =="heal" )
    {
        if( me->query_skill_mapped("force")==SKILL_NAME) return notify_fail("�A���b�׷ҤE�Ȥj�k�C\n");
        if(me->query("hp") >= me->query("max_hp") ) return notify_fail("�A�����d���p�w�F�A�p�C\n"); 
        if(me->query("ap") < heal/2 ) return notify_fail("�A�ثe�����骬�p�A����ϥ����˥\\��C\n");
        if (me->is_fighting() ) return notify_fail("�A�����۾԰��A�S��������");

        message_vision( "$N�ϥX�E�Ȥj�k"HIW"�u������"NOR"�A�i�J���ѩI�l�A�B�����ˡC\n" ,me); 
        me->receive_damage("ap", heal/2);
		me->receive_heal("hp", heal);
        me->start_busy(1);
        me->improve_skill(SKILL_NAME,1+random(force/4)+me->query_int()/5 );
        me->improve_skill("force",1+random(me->query("level"))+me->query_int()/5 );
        return 1;
    }

    return notify_fail("�E�Ȥj�k���\\�঳�Gheal �C\n");

}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}


