// tmr 2007/02/28

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�d�~�j�}�`�h";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�d�~�j�}�`�h���Y�H�����~�A�������Ʊ�A�������M���o�ǳ��~�C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 35;
}

/* �������Ȫ��e�m����A�i��O
        1. ���ŻݨD
        2. ¾�~�ݨD
        3. �رڻݨD
        4. �w�����Y�ǥ��ȻݨD
    �����A���i�H�ۥѵo���~�O�C
    �^�ǫD�s�Ȫ��ܲŦX����C
 */
int preCondition(object player) {
        if( player->query("level") < 35 ) return 0;
       if( player->isSolved("/open/quest/north_bar_q1.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/north_bar/npc/mayor.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/north_bar/npc/mayor.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�d�~�j�}�`�h���Y�H�����~�A�������Ʊ�A�������@���A�M���o�ǳ��~�C\n",
        "$N���$n���D�G�d�~�j�}�N�b���l���_��k���̡C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/north_bar/npc/anthropophagi-monster.c": 3,
        "/open/world1/tmr/north_bar/npc/horn-monster.c": 3,
        "/open/world1/tmr/north_bar/npc/predator-monster.c": 3,
        "/open/world1/tmr/north_bar/npc/rough-monster.c": 3,
        "/open/world1/tmr/north_bar/npc/single-monster.c": 3,
    ]);
    return item;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
  return ([]);
}


// �������Ȫ����󰣤F�t�δ��Ѫ�
// 1. �j�����~
// 2. ���F�����ƶq���Ǫ����~
// ���ݭn���ܡA�٥i�H�ۭq�������ȱ���
// return 1, ����������, return 0;������
int postCondition(object player, object npc)
{
    return 1;
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���I�I�A�u�O�F���Ӧn�F�I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 100,000 �I�C\n";
    msg += "�n�� 8 �I�C\n";
    msg += "�԰����N 10 �I�C\n";
    msg += "���U�T�ɪO�C\n";
    return msg;
}

/*  ���ȼ��y
    ���y���ӯ�ۥѵo���A�p�G
        1. ��o�g��
        2. ��o���~
        3. ��o�u��Buff
        4. �߱o�Y�ޯ�
        5. ��缾�a���A, ex: ��¾
 */
void reward(object player, object npc) {
    player->add("exp", 100000);
    tell_object(player, HIY"(�A��o�F 100,000 �I�g��ȡC)\n"NOR);
    player->add("bank/past", 50000);
    tell_object(player, HIY"(�A��o�F ���U�T�ɪO�C)\n"NOR);
    player->add("popularity", 8);
    tell_object(player, HIY"(�A��o�F 8 �I�n��C)\n"NOR);
    player->add("war_art", 10);
    tell_object(player, HIY"(�A��o�F 10 �I�԰����N�C)\n"NOR);
}
