#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("���c" ,({ "bonze's boots" , "boots" }) );
        set("long","�o�O�@���M�|�諸�c�l�A�õL�S�O���B�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "linen");
        set("unit", "��" );
        set("value",200);
        }
        set("armor_prop/armor", 3);
        set("armor_prop/dodge", 8);
        setup();
}
