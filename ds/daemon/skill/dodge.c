// dodge.c

inherit SKILL;
string type() { return "basic"; }

string *dodge_msg = ({
                         "�i�O���F�X�o�C\n",
                         "���O$n���F�a���}�F�C\n",
                         "$n���l�@���A�{�F�}�h�C\n",
                         "$n�ߨ�����A�ή��׶}�C\n",
                         "���O$n�w���ǳơA���W���������}�C\n",
                     });



string query_dodge_msg()
{
    return dodge_msg[random(sizeof(dodge_msg))];
}