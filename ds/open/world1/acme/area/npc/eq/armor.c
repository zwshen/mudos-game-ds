#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("���r�ԥ�" ,({ "hao chi armor","armor" }) );
        set("long","�o�O�@�󨾿m�O���z���ԥҡA���۷�I���C\n");
         set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "iron");
        set("unit", "��" );
        set("limit_con",20);
		set("value",2000);
set("volume",3);
        }
set("armor_prop/armor",20);
        setup();
}
