#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
         set_name(HIR"���A�y�a"NOR,({"red waist","waist"}) );
        set("long","�o�O�@���§ʸ̴M�`���T�x�Ҩظ�������C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(60);
        set("material", "linen");
        set("unit", "��" );
         set("value",1000);
        }
          set("armor_prop/armor", 3);
        set("armor_prop/dodge", 1);
        setup();
}
