#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("���r���u" ,({ "hao chi boots","boots" }) );
        set("long","�o�O�@���x�L�`��¦���u�C\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "��" );
		set("value",500);
        }
         set("armor_prop/armor", 3);
         set("armor_prop/dodge", 2);
        setup();
}
