#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name("�D�֤�M" ,({ "snake gloves","gloves" }) );
        set("long","�o�O�@�ӥΤd�~�������֩��_�s������M�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "skin");
        set("unit", "��" );
       set("value",1000);
               set("armor_prop/armor", 3);
        set("limit_dex",6);
        set("armor_prop/str", 2);
        set("armor_prop/con", -1);
        }
        setup();
}
