
#include <armor.h>
inherit HANDS;

void create()
{
	set_name("���M",({"typical gloves","gloves"}));
	set("long","�o�O���Z�}���u�éҸ˳ƪ���M�C\n");
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",400);
		set("material", "cloth");
        	set("armor_prop/armor", 2);
        }
        setup();
}

int query_autoload() { return 1; }
