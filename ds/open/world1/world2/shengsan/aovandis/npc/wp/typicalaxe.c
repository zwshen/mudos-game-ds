#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��ԩ�",({"typical axe","typical","axe"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "�o�O�@����Z�}���u�ê���ԩ�C\n");
		set("value", 5000);
		set("material", "steel");
	}
	init_axe(32);
	setup();
}

int query_autoload() { return 1; }
