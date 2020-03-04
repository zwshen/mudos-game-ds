// mob �M��sp
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string arg)
{
    string msg;

    if( !target ) target = offensive_target(me);
    if( !target ) return 0;
    if((int)me->query("mp") < 20 || (int)me->query("ap") < 20)	return 0;
    if(!me->can_fight(target)) return 0;
    if(arg=="sacer")
    {
        message_vision("\n"HIW" �y�q���z $N"HIW"��M�@�ʤ]���ʪ��n��$n�A�Q�b��y�����v���V�~���i..\n"NOR,me,target);
        me->receive_damage("mp", 20);
        me->start_busy(1);
        me->set_temp("exert",10);	//�o�ӭȦb��������ɷ|�� 1 ..
        call_out("sacer_delay",2,me,target);
        return 1;
    }
    if(arg=="moonmonster")
    {
        message_vision("\n"HIW" �y ����� �z $N"HIW"�����Ƭ��@�D�H�����g$n!!\n"NOR,me,target);
        me->receive_damage("ap", 15);
        me->start_busy(1);
        me->set_temp("exert",3);	//�o�ӭȦb��������ɷ|�� 1 ..
        call_out("moonmonster_delay",0,me,target);
        return 1;
    }
    return 1;
}

int sacer_delay(object me,object target)
{
    int damage,armor;
    if(!me) return 0;
    if(!me->query_temp("exert") || me->query_temp("exert") < 1)
    {
        message_vision(HIW"  $N"HIW"�]���`�Ȧӫ�h�F�@�I�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("exert");
    //�ĤH����(���`)
    if(!target)
    {
        message_vision(HIW"  $N"HIW"������_�����`�ũM���ˤl�C\n"NOR,me);
        return 1;
    }
    //�ĤH���}
    if(environment(me)!=environment(target))
    {
        message_vision(HIW"  $N"HIW"������_�����`�ũM���ˤl�C\n"NOR,me);
        return 1;
    }
    //�{�L
    if( random(me->query_dex()*3) < random(target->query_dex()+target->query_skill("dodge")))
    {
        target->improve_skill("dodge",2);
        me->improve_skill("mob_bite",1+random(me->query_int()/6));
        message_vision(HIW"  $N"HIW"�@�D�ӤW�A���$n"HIW"�@�f�r�F�U�h�A���O$n"HIW"�ܧ֪���������}�F�C\n"NOR,me,target);
        me->start_busy(1);
        if(!target->is_fighting(me)) target->kill_ob(me);	//����
        return 1;
    }
    //�R��
    damage = me->query_damage()+me->query_skill("mob_bite")*2;
    armor = target->query_armor();
    damage = damage/2+random(damage/2) - armor/2 - random(armor/2);
    if(damage < 50) damage = 50;
    if(damage > 373) damage =373;
    target->apply_condition("blooding", target->query_condition("blooding")+4);
    message_vision(HIW"  $N"HIW"�@�D�ӤW�A���$n"HIW"�@�f�r�F�U�h�A�K��"HIR"���|�q"HIW"!!\n  $n"HIW"�h���G�s�@�n�A�y��o�աC\n"NOR,me,target);
    // �W�[�����ˮ`���v�T
    damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
    target->receive_damage("hp", damage, me );
    if(target->query("hp")>0)
    {
        if(!target->is_fighting(me)) target->kill_ob(me);	//�����ʧޯ�[�W�o��
        COMBAT_D->report_status(target);
    }
    me->improve_skill("mob_bite",1+me->query_int()/10);
    return 1;
}

int moonmonster_delay(object me,object target)
{
    int damage,armor;
    if(!me) return 0;
    if(!me->query_temp("exert") || me->query_temp("exert") < 1)
    {
        message_vision(HIW"  �@�}�R�q����A���~�����^�_��$N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("exert");
    //�ĤH����(���`)
    if(!target)
    {
        message_vision(HIW"  �@�}�R�q����A���~�����^�_��$N�C\n"NOR,me);
        return 1;
    }
    //�ĤH���}
    if(environment(me)!=environment(target))
    {
        message_vision(HIW"  �@�}�R�q����A���~�����^�_��$N�C\n"NOR,me);
        return 1;
    }
    //�{�L
    if( random(me->query_dex()*3) < random(target->query_dex()+target->query_skill("dodge")))
    {
        target->improve_skill("dodge",2);
        me->improve_skill("mob_bite",1+random(me->query_int()/6));
        message_vision(HIW"  $n"HIW"�@���S�ݡA�@�D�Ӱ_�A�n����$N"HIW"���F�ӪšC\n"NOR,me,target);
        me->start_busy(1);
        if(!target->is_fighting(me)) target->kill_ob(me);	//����
        return 1;
    }
    //�R��
    damage = me->query_damage()+me->query_skill("mob_bite")*2;
    armor = target->query_armor();
    damage = damage/2+random(damage/2) - armor/2 - random(armor/2);
    if(damage < 100) damage = 90+random(50);
    if(damage > 500) damage =490+random(100);
    target->apply_condition("blooding", target->query_condition("blooding")+5);
    message_vision(HIW"  $N"HIW"�{�פ��ΡA�u���H���z���ӹL�A"HIR"���q�K��"HIW"!!\n\n"NOR,target);
    // �W�[�����ˮ`���v�T
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp", damage, me );
    if(target->query("hp")>0)
    {
        if(!target->is_fighting(me)) target->kill_ob(me);	//�����ʧޯ�[�W�o��
        COMBAT_D->report_status(target);
    }
    me->improve_skill("mob_bite",1+me->query_int()/10);
    return 1;
}
