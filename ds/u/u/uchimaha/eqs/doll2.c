// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��������",({"death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("unit","��");
                set("long","  �@�Ӹ޲����v�����C�����⪺�Ȥl�W���۳\\�h�զ⪺�p���I,\n"
                          +"�R�����������F��...�A���G�ݨ�o�b������!? �o...\n"
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v����, $N���W��$n��M�ĥX�צ��F�o�P�R�@��!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }
