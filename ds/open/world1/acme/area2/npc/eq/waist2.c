#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name("�I�A�y�a" ,({ "marsh waist","waist" }) );
        set("long","�o�O���Z���@�k���@�I�A�N�Ҩ������y�a�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "skin");
        set("unit", "��" );
       set("value",1000);
        set_temp("apply/armor", 3);
        set("armor_prop/con",2);
        set_temp("apply/hit",-8);
        }
        setup();
}
