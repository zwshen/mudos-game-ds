#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("�ѧ��ܭ�" ,({ "devil surcoat","surcoat" }) );
        set("long","�o�O�@�󦳦p�����ͧΪ��ܭ��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(6000);
        set("material", "skin");
        set("unit", "��" );
set("value",2400);
	set("volume",2);
     set("armor_prop/armor",10);
        set("limit_dex",3);
        set("armor_prop/str",2);
        set_temp("apply/dodge",-5);
        }
        setup();
}
