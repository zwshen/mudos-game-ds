/*
��ԤQ�� �֫ӭx�򥻤M�k
1. ��x���S     2. �W�~���S
3. ���M��X     4. ���n����
5. �@�ԥ\��     6. �央�o��
7. �L�L�`��     8. ���ͦs�`
9. �j���פ�     10. �g�{�ѤU

Tmr 2006/11/22

*/
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

#define SKILL_NAME "bloodwar-blade"
	
void delay(object me);

mapping *action = ({
                       ([
                            "action": "$N�\\�X"HIR"�i"NOR"��x���S"HIR"�j"NOR"�[�աA�±�����^�q$w"NOR"���M�y�L�L�_�X�A���a�@�M��V$n"NOR"��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�M���������ˡA�ϥX"HIR"�i"NOR"�W�~���S"HIR"�j"NOR"�@�M��$n"NOR"��$l��h",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX"HIR"�i"NOR"���M��X"HIR"�j"NOR"�A$w"NOR"�q�y���X�M���@�o���ĤH�ݤf�A�����Ʀ����A�w�ͥͬ�V$n"NOR"��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N���M�۪񨭥h�A�ϥX"HIR"�i"NOR"���n����"HIR"�j"NOR"�A$w"NOR"�M�۹B��p�N�A��a�@�n�A�V$n"NOR"��$l",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),                   
                       ([
                            "action": "$N�����j���A���H�N��ϥX"HIR"�i"NOR"�@�ԥ\\��"HIR"�j"NOR"�A�⤤$w"NOR"�@���L���a��V$n"NOR"��$l",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�_�ۼh�X���a�A�ϥX"HIR"�i"NOR"�央�o��"HIR"�j"NOR"�A�⤤$w"NOR"�j�L�Ȧa�w�O��$n"NOR"��$l�A�h",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),                   
                         ([
                            "action": "$N�M�۩��ܨϥX"HIR"�i"NOR"�L�L�`��"HIR"�j"NOR"�A�����R�ˤ⤤$w"NOR"�A���ۤ@�����A�X�T�M����$n"NOR"��$l��h",
                            "damage":                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "�u��$N�����I�Ҥ��ڨϥX"HIR"�i"NOR"���ͦs�`"HIR"�j"NOR"�A�⤤$w"NOR"�W�U���`�A²²���N�O�@�M��$n"NOR"��$l�A�h",
                            "damage":                15,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),                         
                       });


void improve_skill(object me) {
    me->improve_skill(SKILL_NAME, 1 + random(me->query_int()/2));
    me->improve_skill("blade",1 + random(me->query_int()/2));
}

/* �Z���l�� */
void damage_weapon(object me) {
    if( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp �l�a�v add by wilfred
}

/* �P�_�O�_�ݭn�ܶˮ`�Ʀr */
void show_damage(object me, object target,int damage) {
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n");
}

/* �P�_�O�_�٥��޵o�԰� */
void check_combat(object me, object target) {
    if( !objectp(me) ) return;
    if( !objectp(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(!target->is_fighting(me)) target->kill_ob(me);
}

int get_tiger_damage(object me, object target)
{
    int damage, power;
    damage = me->query_skill(SKILL_NAME) + me->query_damage();
    damage = damage + random(damage/2);
    damage = damage - target->query_armor()/3 - random(target->query_armor()/3);

    return COMBAT_D->Merits_damage(me, target, damage, "bar");
}

void clear(object me){
	if( !objectp(me) ) return;
	tell_object(me,"�A�ϥΡu�g�{�ѤU�v���l�`�w�g��_�F�C\n");
	me->delete_temp("ARMY_BLOODWAR_BLADE");
}


/* �g�{�ѤU �S�� */
void do_tiger_attack(object me, object target) {

    object weapon;
    int damage, target_d,sk;
    string msg;

    if( userp(me) && userp(target) ) me->start_busy(2);
    else me->start_busy(1);

    me->receive_daemage("ap", 50);
	me->set_temp("ARMY_BLOODWAR_BLADE",1);

    weapon=me->query_temp("weapon");
    msg = HIY "\n$N�j�ܤ@�n�ϥX�i�g�{�ѤU�j�A�⤤" + weapon->query("name") + HIY "�����}�}�A�W�~���S�A���ۡu�R�v�a�@�M�����A�V$n\n"NOR;

    damage = get_tiger_damage(me, target);
    if( damage <= 0 ) {
        msg += HIW "�i�O�o�@�M�Q�ݬ�F�A$n" HIW "�׶}�o������...\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill(SKILL_NAME);
    if( sk + random(sk/2) > random(target_d) ) {
        target->start_busy(1);
        target->receive_damage("hp",damage,me);

        msg += HIR "$n"HIR"�������M�A��h�T�B�A���W�ˤf�S�p��`�T�I" NOR;
        message_vision(msg, me, target);
        damage_weapon(me);                      // �Z���l��
        show_damage(me, target, damage);        // ��ܶˮ`�Ʀr
        message_vision("\n", me);
        COMBAT_D->report_status(target);
        improve_skill(me);
    } else {
        msg += HIW"�i�O�Q$n" HIW "���F�}�h...\n" NOR;
        message_vision(msg, me, target);
    }
	call_out("clear", 8, me);
}


int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    mapping type;
    sk = me->query_skill(SKILL_NAME);
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("�A�w�g���F�A�Ч��I�h�_���a�C\n");
    if (!weapon) return notify_fail("�A�⤤�������M�~��I�i�u��ԤQ���v�C\n");
    if(weapon->query("skill_type")!="blade") return notify_fail("�A�⤤�������M�~��I�i�u��ԤQ���v�C\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade") != SKILL_NAME)
            return notify_fail("�A�èS���ϥΡu��ԤQ���v�C\n");
        me->map_skill("blade");
        me->reset_action();
        write("�ޯ�u��ԤQ���v�w�����C\n");
        return 1;
    }

    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΡu��ԤQ���v�C\n");

    //�ĤG��exert
    if(me->query_skill_mapped("blade")==SKILL_NAME)
    {
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("�A�w���b�I�i�u��ԤQ���v�F�C\n");
        if (me->query_skill(SKILL_NAME) < 50)
            return notify_fail("�A�ثe�ٵL�k�ϥX�u�g�{�ѤU�v�����ۡC\n");
        if(me->query("ap") < 100)
            return notify_fail("�A�ثe�����l�����A�L�k�ϥX�u�g�{�ѤU�v�����ۡC\n");
	    if(me->query_temp("ARMY_BLOODWAR_BLADE") )
    	    return notify_fail("�A�u�ɶ����L�k�A�ϥΡu�g�{�ѤU�v�C\n");

        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�èS���M���b�԰����C\n");

        do_tiger_attack(me, target); // �S�� �g�{�ѤU

        return 1;
    }

if(!me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("��ԤQ�����ʧ@�٨S�����C\n");
    me->map_skill("blade", SKILL_NAME);
    me->reset_action();
    message_vision("$N�M�ۤ@�ܡA�}�l�I�i�_�u��ԤQ���v�F�C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "blade" )
    {
        me->map_skill("blade");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("blade")!=SKILL_NAME )
    {
        return;
    }
    if( me->query("ap")<10 )
    {
        me->map_skill("blade");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"����O�����L�k�~��I�i��ԤQ���C\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",5);
	me->skill_active( SKILL_NAME,(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
