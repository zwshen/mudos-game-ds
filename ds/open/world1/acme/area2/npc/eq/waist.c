#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name("�H�ָy�a" ,({ "human skin waist","waist" }) );
        set("long","�@�ӥΤH�ֻs�����y�a�A�W�Y�٦����������A�۷����ߡC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(600);
        set("material", "skin");
      set("unit","��");
        set("value",0);
        set("armor_prop/armor", 3);
        set("limit_str",8);
        set("armor_prop/int",2);
        set_temp("apply/hit",-3);
        }
        setup();
}
