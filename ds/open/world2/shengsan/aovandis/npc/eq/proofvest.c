
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ĵ�è��u�I��",({"bullet-proof vest","vest"}) );
	set("long","�o�O�@��ĵ�åΪ����u�I�ߡC\n");
	set_weight(7300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
		set("value",2700);
        	set("armor_prop/armor",10);
        	set("armor_prop/shield", 7);
        }
        setup();
}

int query_autoload() { return 1; }
