
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ĵ�ò���",({"patrol armor","armor"}) );
	set("long","�o�O�@��ĵ�åΪ����ҡC\n");
	set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
		set("value",2360);
        	set("armor_prop/armor",13);
        }
        setup();
}

int query_autoload() { return 1; }
