
#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("��@�u",({"typical wrists","wrists"}) );
	set("long","�o�O���Z�}���u�éҸ˳ƪ��@�u�C\n");
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "steel");
		set("value",1900);
        	set("armor_prop/dodge", 1);
	}
	setup();
}
