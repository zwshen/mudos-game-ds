
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("��Ծc",({"typical war boot","boot"}) );
	set("long","�o�O���Z�}���u�éҸ˳ƪ��Ծc�C\n");
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "��");
		set("value",2300);
	}
	setup();
}
