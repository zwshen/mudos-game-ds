//god-benison ��}��. by Acme 2000.1.21
//��}II  -by Tmr- for �o�����B�ժ��͡A�N�D
//PM 11:30 2000/1/24

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cure_all(object me,int sk,int inn);
int attack_b(object me,object target,int sk,int inn);

int cast(object me, object target)
{
     int sk,inn,cost;

    sk=me->query_spell("god-benison");
    inn=me->query_int();

    //    return notify_fail("���Z���R���A�Ȯ������C\n"); //By tmr
    if(sk < 20)
        return notify_fail("�A���u����ë�g�v�٥������J�A�|�L��O�ϥΡC\n");
    if(me->query("ap") < 100 || me->query("mp") < 100)
        return notify_fail("�A�{�b�����骬�p�L�k�ϥΡu����ë�g�v�C\n");
    if(me->is_fighting() )
    {
        if(!target )
            target = offensive_target(me);
        if(!me->can_fight(target))
            return me->can_fight(target);
        message_vision(
            "\n$N�q��"HIM"�u����ë�g�v"NOR"��"HIC"�u���͡v"NOR"�Z�G\n\n"
            +"      �u�j�v�����A�U�����l�C�v\n"
            +"      �u�ܫv�[���A�U�����͡C�v\n"
            +HIC"\n$N���⥪�k�e��A�x�X�H�Ť����A�K���ť��|���A�ιγ�¶��$n�C\n"NOR,me,target);
        cost=(sk*5+inn*2)/8;
        me->start_busy(2);
        call_out("attack_b",1,me,target,sk,inn);
        me->receive_damage("mp",cost);
        me->set_temp("power_cast",1+sk/20);
    } //end of is_fighting()
    else
    {
        message_vision(
            "\n$N�q��"HIM"�u����ë�g�v"NOR"��"HIW"�u�N�D�v"NOR"�Z�G\n\n" NOR
            +"      �u�Ѫ���g�m���}�A�j���x�����E���C�v\n"
            +"      �u�U���@�ɪg�t�ơA�a�͹��R�K�����C�v\n" NOR,me);

        me->receive_damage("mp",(sk*2+inn)/3 );
        me->start_busy(3);
        call_out("cure_all",3,me,sk,inn);
    }

    return 1;
}

int cure_all(object me,int sk,int inn)
{
    if(!me) return 0;

    if( !me->is_fighting() && random(sk) > random(30)  )
    {
        message_vision(HIW"\n$N�����W�U��¶�ۤ@�}�ե��A�M�ấ�����h�C\n" NOR,me);
        me->receive_curing("all",sk/20+inn/8);
        me->improve_spell("god-benison",random(2+inn/5) );
        return 1;
    }
    tell_object(me,"���G����Ʊ����S�o�͡C\n");
    tell_room( environment(),me->query("name")+"�n�n�Y, ���檺�ĤF�@�f��C\n",({me}) );
    return 1;
}

int attack_b(object me,object target,int sk,int inn)
{
    int damage,i;

    if(!me)
        return 0;
    if(!target)
        return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1)
    {
        message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");

    if(random(target->query_skill("dodge")*2)/3+random(target->query_shield())+1 < random( sk*2 )/3+inn )
    {
        damage = (sk*3+inn)/2;
        damage -=target->query_shield();
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");

        if(target->query("mp") >= damage ) i=1;
        else if(me->query("mp")+50>me->query("max_mp")) i=2;
        else if(target->query("ap") >= damage) i=2;
        else if(me->query("ap")+50>me->query("max_ap")) i=3;
        else i=3;

        switch( i ) {

        case 1:
            message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A$n�y�ɺ믫�@�}�鱫�A�K�������q$n���X�A�Q$N�l���F�C\n"NOR,me,target);
            target->receive_damage("mp",damage,me);
            me->receive_heal("mp",damage);
            break;

        case 2:
            message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A$n��ı���l�@���d���A�K�������q$n���X�A�Q$N�l���F�C\n"NOR,me,target);
            target->receive_damage("ap",damage,me);
            me->receive_heal("ap",damage/3);
            break;

        case 3:
            message_vision(HIC"�H�Ŧ�����"NOR"�ĤJ$n�餺�A�K�������q$n�餺�|���K��g�X�A$n�g�R�F�\\�h�A��C\n"NOR,me,target);
            COMBAT_D->report_status(target);         //���target���A
            target->receive_damage("hp",damage*5/2,me);
            break;
        }

        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage")  )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        if(wizardp(me) && me->query("env/debug"))
            tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n");

        target->start_busy(1);
    }
    else	  message_vision(HIC"�H�Ŧ�����"HIG"�ĦV$n�A���O$n�W�W�i�i�A����k�ҡA�k�X�F�ť�����¶�C\n\n"NOR,me,target);

    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    me->improve_spell("god-benison",random(2+me->query("level")/2)+inn/7);
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    else return 100;
}