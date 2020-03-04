#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�H��"NOR, ({ "broken corpse","corpse" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("weight", 9999);
                set("long", "�o�O�@�ӤH������, �A�ݨ��L���W�諸���������O���F�q���x�A, �A�i�H�ݬ�(view)�L���S��ԣ��...");
                }
        setup();
}

void init()
{
       add_action("typeview","view");
}

int typeview(string arg)
{
        object me,obj,p;
        me=this_player();
        obj=this_object();

        if(arg != "corpse" && arg != "broken corpse") return 0;

        message_vision(CYN"$N�b�H�ͤW��F�@��....\n"NOR,me);

        if( random(100) > 90 )
        {
                message_vision(HIY"$N�q�H�ͤ����X�@�өx�L!!.\n"NOR,me);
                message_vision(HIB"�u��$N�ƴ��}��, �w�����ΤF..\n"NOR, this_object());
                p=new(__DIR__"west_mark");
                p->move(me);
                destruct(this_object());
                return 1;
        }
        else
        {
                message_vision(HIY"���O$N����]�S�o�{...\n"NOR, me);
                message_vision(HIB"( �g�L$N���@�f�j�d$n, $n"HIB"�w�g���w�Q�p�����Y���F.. )\n"NOR, me, this_object());
                destruct(this_object());
                return 1;
        }
}