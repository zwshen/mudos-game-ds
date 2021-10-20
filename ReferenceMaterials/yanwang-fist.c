// �F���� (yanwang_fist)
// copy from dragon_fist.c
// Bluerex 2007/10/11
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N�j�n�q�w�u�U��N���h�A�ߦ��~�H���v�A���x�H�_�����������V$n",
        "damage":                20,
        "attack":                20,
        "attact_type":  "bar",
            "damage_type":  "�x��",
        ]),

        ([
        "action": "$N�t���q�q�u�X�u���Ѫo���d�����A�d�t�H���@���ۡv�A��M�����s�Ʀ������������k���V$n",
        "damage":                20,
        "dodge" :               -15,
        "parry" :               -10,
        "attact_type":  "bar",
            "damage_type":  "����",
        ]),

        ([
        "action": "$N���ηL�y�A�C�n�ۥX�u�C�O�p���d��o�A���Ӷ¤ߵL�D�H�v�A�k�ⴤ��������$n��$l���h",
        "damage":                20,
        "dodge" :                20,
        "attack":               -15,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

        ([
        "action": "$N�����z���A�޻�㥸�u�H�̳y�@�o�~�A��u�U���������~�v�A���⴫�Ʀ��L�ƴx�v���V$n��$l",
        "damage":                20,
        "dodge" :                5,
        "parry" :                5,
        "attact_type":  "bar",
        "damage_type":  "�x��",
        ]),

        ([
        "action": "$N�@�ܤ@�ۡu�Ǥ��w�D�A\�\\��t��ѡv�A������p�Q�C�A�w�O��$n��$l�����A�U",
        "damage":                20,
        "attack":                20,
        "parry" :                20,
        "attact_type":  "bar",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�Q���{�A�u�ۡu�y�L�q�~�A�o�L��o�v���l�A���v�a�N���⤧�O�D���V$n",
        "damage":                25,
        "dodge" :               -15,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;

        weapon=me->query_temp("weapon");
        if(weapon)
        {
                if(weapon->query("skill_type")!="unarmed")
                        return notify_fail("�A�⤤�ҫ����Z���A���A�X�Φb�F�����C\n");
        }
        if(arg=="off" )
        {
                if( me->query_skill_mapped("unarmed")!="yanwang-fist")
                        return notify_fail("�A�èS���b�ϥΡu�F�����v�C\n");
                me->map_skill("unarmed");
                me->reset_action();
                write("�A����ϥ��F�����F�C\n");
                return 1;
        }
  

        if( me->query_skill_mapped("unarmed") == "yanwang-fist")
                        return notify_fail("�A�w�g�b�ϥΡu�F�����v�F�C\n");
        if(me->query_skill("unarmed")<50) 
                return notify_fail("�A���{��i���ݭn50�šA�~��ϥ��F�����C\n");
   if(me->query("ap")<20 || me->query("hp")<30) 
                return notify_fail("�A�����骬�p���}�A����ϥ��F�����C\n");
        me->map_skill("unarmed", "yanwang-fist");
        me->reset_action();
        message_vision(HIG "$N�����o�X���p�z���B�n�A�I�i�X�F�����C\n"NOR,me);
    me->receive_damage("ap",10);
        me->start_busy(2);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
        return ob->query_str() + 30;
}

