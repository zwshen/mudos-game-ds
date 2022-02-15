// ����N flybird-steps
// Tmr 2006/11/22

#include <ansi.h>
#define SKILL_NAME "flybird-steps"
inherit SKILL;

string *dodge_msg = ({
	"\n$n���y�b�a���@�I�A���Ωަa�Ӱ_�A"HIC"�u���F�K��v"NOR"���}�F�o�@�ۡC\n",
	"\n$n�H��$N��Ӫ��ۦ��@��"HIW"�u����s�šv"NOR"�ƤF�_�ӡA�N�p�@���L�������h���@��C\n",
	"\n$n�ϥX"HIY"�u�Ѧ�P�ܡv"NOR"�A���Υ��@�̡B�k�@�{�A������򪺡A�q���������ؤ��p�F�X�ӡC\n",
	"\n$n�ϥX"HIM"�u�^����ȡv"NOR"�A�����I�a�a��¶$N�s¶�T�Ӥj��A��$N�o�@���פF�}�h�C\n",
	"\n$n�s�ۼƭӤj��A��ۤS�O�@�Ӥj��A�B�_����N��"HIC"�u��ˮ���]�v"NOR"�A���ΰ����a�ޤF�_�ӡC\n",
	"\n$n�����ƯB�A���S½���A�@��"HIW"�u�X���J�L�v"NOR"�A���P�ۦp�a�׶}�F$N����աC\n",
	"\n$n�V���伳�X�A���դ@�u�A�{��@��C\n",
	"\n$n��M�@�ӫ��ਭ�A$N���o�@�۷ƨ�F�@��C\n",
                     });

int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge") != SKILL_NAME)
            return notify_fail("�A�èS���ϥΡi����N�j�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N���Ϋ�_���`�F�C\n"NOR,me);
        write("�ޯ�i����N�j�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<10) return notify_fail("�A�����\\��¦����(10��)�L�k�ϥΡi����N�j�C\n");
    if(me->query_skill_mapped("dodge")==SKILL_NAME)
        return notify_fail("�A�w�g�b�ϥΡi����N�j�C\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�ثe�����骬�p�L�k�ϥΡi����N�j�C\n");

if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("�A������N���۰ʧ@�٨S�����C\n");

    me->map_skill("dodge", SKILL_NAME);
    me->reset_action();

    message_vision(HIW"$N�ϥX�i����N�j�A���λ��p�����A�y��p�N�C\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    if(!me) return;

    if(me->query_skill_mapped("dodge")!=SKILL_NAME)
    {
        //remove_call_out("delay");
        return;
    }

    if(me->query("ap")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N���Ϋ�_���`�F�C\n"NOR,me);
        tell_object(me,"�A����O�����L�k�~��ϥΡi����N�j�C\n");
        return ;
    }
    if(me->is_fighting()) me->receive_damage("ap",2);
        me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
