#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("�ϥִU" ,({ "wool hat","hat"}) );
        set("long","�o�O�@���Ѧϥ֩��_���Ӧ����U�l�C\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "fur");
        set("unit","��");
		set("value",200);
        }
         set("armor_prop/armor", 2);
        setup();
}
