#include <weapon.h>

inherit FORK;

void create()
{
        set_name("���t�j", ({"speed lance","speed","lance"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��y�U�L�񪺭��t�j�C\n");
		set("value", 10500);
		set("material", "steel");
	}
	init_fork(24);

	setup();
}

int query_autoload() { return 1; }
