#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("���Z�@��" ,({ "god wrists","wrists" }) );
        set("long","�o�O�@�ӯ��Z�Ъ��{�M�Ϊ��򥻨���C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "linen");
        set("unit", "��" );
        set("value",300);
        }
         set("armor_prop/armor", 1);
         set("armor_prop/shield", 1);
         set("armor_prop/int", 1);
        setup();
}
