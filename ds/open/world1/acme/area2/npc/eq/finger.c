#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name("��Χ�" ,({ "tiger finger","finger" }) );
        set("long","�o�O�@�u�W�Y��۲r��ˤl���٫��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "jade");
        set("unit", "�u" );
       set("value",750);
        set("armor_prop/armor", 1);
        set("limit_int",10);
        set("armor_prop/con",2);
        set("armor_prop/str",-1);
        }
        setup();
}
