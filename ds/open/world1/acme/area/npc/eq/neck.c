#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("��]",({ "buddha's bead","bead" }) );
        set("long","�o�O�X�a�H���b��l�W�������]�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(999);
        set("material", "jade");
        set("unit", "��" );
         set("value",300)
          ;
        }
        set("armor_prop/armor", 1);
        set("armor_prop/dodge", 5);
        setup();
}
