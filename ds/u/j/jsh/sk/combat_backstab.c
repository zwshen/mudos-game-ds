#include <ansi.h>
#define SKILL_NAME "�԰��I��"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir)
{
        string msg;
        int damage,sk,c;
        object weapon;
        if(!me) return 0;
        if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�n�b�԰����~��ϥ�!\n");
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("��֬I�i"+SKILL_NAME+"?\n");
        if((int)me->query("mp") < 20 || (int)me->query("ap") < 20)
                return notify_fail("�A�ثe�����骬�p�L�k�ϥγo��@�P���Z�\\�T\n");
        if(!weapon=me->query_temp("weapon")) return notify_fail("�A�⤤�S���Z������I��C\n");
        if(!weapon->can_stab()) return notify_fail("�A�ҨϥΪ��Z�����A�X�ΨӭI��C\n");
//      if(!me->can_fight(target))
//              return me->can_fight(target);

        sk=me->query_skill("combat_backstab");
        c=target->query_armor();
        message_vision("\n"HIW" �y�K���z $N"HIW"�N���@�n�����M�����F�ܼv�A�����X�{�b$n"HIW"������!!\n"NOR,me,target);
        me->receive_damage("mp", 10);
        me->receive_damage("ap", 20);
        me->add_busy(1);
        if( random(me->query_dex()*3) < random(target->query_dex()+target->query_skill("dodge")))
        {
                message_vision("\n"HIW"$N���t���N�⤤��"+weapon->name()+HIW"��V$n"HIW"������A���O�Q$n"HIW"�@���ਭ�{�F�L�h!!\n"NOR,me,target);
                return 1;
        }
        else
        {
                damage = me->query_damage()*2+sk/2;
                damage = damage + random(damage/2)+(int)weapon->query("backstab_bonus");
                damage = damage - c/2 -random(c/2); 
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                message_vision("\n"HIW"$N���t���N�⤤��"+weapon->name()+HIW"��V$n"HIW"������A$n"HIW"�G�s�@�n�A"HIR"�A��q�ˤf���u��ӥX!!\n"NOR,me,target);
                target->receive_damage("hp", damage,me);
                target->add_busy(1);
                COMBAT_D->report_status(target);
                if(wizardp(target) && target->query("env/debug")) tell_object(target,"["+me->name()+"�����԰��I�� damage: "+damage+"]\n");
        }
        
//      me->set_temp("power_exert",1);  //�o�ӭȦb��������ɷ|�� 1 ..
//      call_out("delay",3,me,target);
        return 1;
}

int delay(object me,object target)
{
        int damage;
        if(!me) return 0;
        if(!me->query_temp("power_exert") || me->query_temp("power_exert") < 1) 
        {
         message_vision(HIW"$N"HIW"�]������ˮ`�ӶäF�u��, �L�k���Q�I�i"+SKILL_NAME+"�C\n"NOR,me);
         return 1;
        }
        me->delete_temp("power_exert");
        //�ĤH����(���`)
        message_vision(HIW"\n�y���i�ʮ����z�@�u��$N"HIW"�r�M�N����e���멹�e���X�T\n"NOR,me);
        if(!target)
        {
         message_vision(HIW"�@���Ѥ��O�E���Ӧ�����u�p���u��I�S�ӹL, ���������󩼤�C\n"NOR,me);
         return 1;
        }
        //�ĤH���}
        if(environment(me)!=environment(target))
        {
         message_vision(HIW"�@���Ѥ��O�E���Ӧ�����u�p���u��I�S�ӹL, ���������󩼤�C\n"NOR,me);
         return 1;
        }
        //�{�L
        if( random(me->query_dex()+me->query_skill("poken")) < random(target->query_dex()))
        {
         target->improve_skill("dodge",3);
         me->improve_skill("poken",1+random(me->query_int()/6));
         message_vision(HIW"�@���Ѥ��O�E���Ӧ�����u�p���u��q$N"HIW"���ǩI�S�ӹL�C\n"NOR,target);
         if(!target->is_fighting(me)) target->kill_ob(me);      //����
         return 1;
        }
        //�R��
        damage = 20 + me->query_skill("poken")*2;
        damage -= target->query_armor();
        if(damage < 30) damage = 30;
        if(damage > 200) damage =200;
        message_vision(HIW"�@���Ѥ��O�E���Ӧ�����u���u��r�P�����V$N, $N"HIW"�Q�_�����½��, �y��G�M�C\n"NOR,target);
        // �W�[�����ˮ`���v�T
        damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //�����ʧޯ�[�W�o��
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //�����ʧޯ�[�W�o��
                COMBAT_D->report_status(target);
        }
        me->improve_skill("poken",1+me->query_int()/10);
        target->start_busy(1);
        return 1;
}

