#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name("��`��" , ({ "tiger dagger","dagger" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�b��`�B�J�۪��Y���P���A�ϱN�_�ӡA�w�O���ͭ��C\n");
               set("value",1000);
               set("material", "iron");
        }
    init_dagger(23);
   setup();
}
