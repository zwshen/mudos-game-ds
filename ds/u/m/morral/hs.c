//horse-steps (�K���ϰ�) by tmr PM 07:32 1999/4/16

#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{

        if(arg=="off" )
        {
		if(!me->query_temp("is_busy/horse-steps")) return notify_fail("�A�èS���b�ϰ��a....\n");
	        message_vision("\n"HIW"$N�`�I�@�f��A�����ϰ����ʧ@�A���_���ӵ��P�w�h�֤��������}�C\n"NOR,me);
		me->delete_temp("is_busy/horse-steps");
                return 1;
        }
	if(me->is_ghost() ) return notify_fail("�A�O���C�A���Ӫ��}...:P\n");
	if(me->is_fighting() ) return notify_fail("�A���b���[���A�S���Ųϰ��a..\n");
	if(me->is_busy() ) return notify_fail("�A�����ۡA�S���Ű���L�ơC\n");
	
	if(me->query("hp")<10 || me->query("mp")<10 ) return notify_fail("�A�{�b����O���n�A����ϰ��A�K�o����..P\n");
        
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���C\n");

        message_vision("\n"HIW"�u��$N�ߨ������B��⳻�V�B�G�إ����B���[�����A���}�l�ϰ_���B�A�H�m�}�O�C\n"NOR,me);
        me->receive_damage("mp", 5);
        me->receive_damage("hp", 5);
        me->set_temp("is_busy/horse-steps","�A���b�m�ϰ����ಾ�ʡC");
        me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 3);
        return 1;
}

void delay(object me,int cost)
{
        if(!me) return;
        if(!me->query_temp("is_busy/horse-steps") )
        {
	         return;
        }

        if(me->query("mp")<5 || me->query("hp") <5)
        {
                message_vision("\n"HIB"�u��$N�`�I�@�f��A�����ϰ����ʧ@�A���_���ӵ��P�w�h�֤��������}�C\n"NOR,me);
	        me->delete_temp("is_busy/horse-steps");
                return ;
        }
        me->receive_damage("mp",5);
        me->receive_damage("hp",5);
        me->improve_skill("horse-steps",1 + random(1+me->query_int()/3) + random(1+me->query_con()/4) );	
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 3);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }