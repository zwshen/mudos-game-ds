#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("����C",({"typical long sword","long sword","sword"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����Z�}���u�ê�����C�C\n");
		set("value", 5000);
		set("material", "steel");
	}
	init_sword(15);
	setup();
}

int query_autoload() { return 1; }
