#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("���r�Y��" ,({ "hao chi hat","hat" }) );
        set("long","�o�O�@�өx�L�`�����������Y���C\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "iron");
        set("unit", "��" );
         set("value",700);
set("volume",2);
        }
          set("armor_prop/armor", 6);
        setup();
}
