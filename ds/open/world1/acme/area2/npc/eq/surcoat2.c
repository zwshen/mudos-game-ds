#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("���ѩܭ�" ,({ "sky surcoat","surcoat" }) );
        set("long","�o�O���Z���@�k���@���ѱN�Ҭ�۪��ܭ��A���ۤ����Q��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",15);
        set_weight(8000);
        set("material", "skin");
        set("unit", "��" );
       set("value",2250);
        set("armor_prop/armor", 5);
        set_temp("apply/damage",10);
		set("volume",4);
        set_temp("apply/hit",-5);
        set("armor_prop/str",2);
        }
        setup();
}
